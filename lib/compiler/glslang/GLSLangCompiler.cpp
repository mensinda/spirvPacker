/*
 * Copyright (C) 2017 Daniel Mensinger
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "spvCfg.hpp"
#include "GLSLangCompiler.hpp"
#include "Enum2Str.hpp"
#include <spirv.hpp>
#include <SPIRV/GlslangToSpv.h>

using namespace spirvPacker;
using namespace glslang;

EShLanguage getLanguageFromStage(ShaderType _t);

GLSLangCompiler::GLSLangCompiler() { InitializeProcess(); }
GLSLangCompiler::~GLSLangCompiler() {
  cleanup();
  FinalizeProcess();
}

bool GLSLangCompiler::initializeStage() {
  auto &lCfg     = getStageBaseConfigSection();
  auto &lCompSec = lCfg.addSection("compiler");
  auto &lLinkSec = lCfg.addSection("linker");

  lCompSec.addEntry("vulkanClientVersion", 100l);
  lCompSec.addEntry("autoMapBindings", false);
  lCompSec.addEntry("autoMapLocations", false);
  lCompSec.addEntry("flattenUniformArrays", false);
  lCompSec.addEntry("noStorageFormat", false);

  // No idea what this does. Comment in glslang sais: use 100 for ES environment, 110 for desktop
  lCompSec.addEntry("defaultVersion", 100l);

  lLinkSec.addEntry("generateDebugInfo", false);
  lLinkSec.addEntry("disableOptimizer", true);
  lLinkSec.addEntry("optimizeSize", false);

  auto &lRes = lCfg.addSection("builtinResources");
  initResources(lRes);

  return true;
}

EShLanguage getLanguageFromStage(ShaderType _t) {
  switch (_t) {
    case ShaderType::VERTEX: return EShLangVertex;
    case ShaderType::TESS_CON: return EShLangTessControl;
    case ShaderType::TESS_EVA: return EShLangTessEvaluation;
    case ShaderType::GEOMETRY: return EShLangGeometry;
    case ShaderType::FRAGMENT: return EShLangFragment;
    case ShaderType::COMPUTE: return EShLangCompute;
    default: return EShLangCount;
  }
}

StageResult GLSLangCompiler::compileShaderModule(ShaderModule &m) {
  auto &lCfg = getStageBaseConfigSection();
  auto &lSec = lCfg["compiler"];
  Data  lMod;

  std::string lData;         // Will store the raw source data
  const char *lData_cstr[1]; // Will point to the data

  lMod.type         = m.getType();
  lMod.glslangStage = getLanguageFromStage(lMod.type);

  EShSource lSourceFormat = [=]() {
    switch (m.getSourceFormat()) {
      case SourceFormat::GLSL: return EShSourceGlsl;
      case SourceFormat::HLSL: return EShSourceHlsl;
    }

    return EShSourceNone;
  }();

  lData         = m.getSourceCode();
  lData_cstr[0] = lData.c_str();

  lMod.shader = std::make_unique<TShader>(lMod.glslangStage);
  lMod.shader->setStrings(lData_cstr, 1);
  lMod.shader->setEnvInput(
      lSourceFormat, lMod.glslangStage, EShClientVulkan, static_cast<int>(lSec("vulkanClientVersion").valInt()));
  lMod.shader->setEnvClient(EShClientVulkan, static_cast<int>(lSec("vulkanClientVersion").valInt()));
  lMod.shader->setEnvTarget(EshTargetSpv, SPV_VERSION);
  lMod.shader->setAutoMapBindings(lSec("autoMapBindings").valBool());
  lMod.shader->setAutoMapLocations(lSec("autoMapLocations").valBool());
  lMod.shader->setFlattenUniformArrays(lSec("flattenUniformArrays").valBool());
  lMod.shader->setNoStorageFormat(lSec("noStorageFormat").valBool());

  TBuiltInResource lResources = getResources(lCfg["builtinResources"]);

  bool lRes = lMod.shader->parse(&lResources, static_cast<int>(lSec("defaultVersion").valInt()), false, EShMsgDefault);
  if (!lRes) {
    getLogger()->warn("Compiler message:\n{}", lMod.shader->getInfoLog());
    return StageResult::COMPILER_ERROR;
  }

  vModules.push_back(std::move(lMod));
  return StageResult::SUCCESS;
}

StageResult GLSLangCompiler::link(Shader *_shader) {
  auto &lCfg    = getStageBaseConfigSection();
  auto  lLogger = getLogger();
  if (!_shader) {
    lLogger->error("Invalid shader object");
    return StageResult::ERROR;
  }

  TProgram lProg;
  for (auto &i : vModules)
    lProg.addShader(i.shader.get());

  bool lRes = lProg.link(EShMsgDefault);
  if (!lRes) {
    lLogger->error("Linker error message:\n{}", lProg.getInfoLog());
    return StageResult::LINKER_ERROR;
  }

  SpvOptions lOpts;
  lOpts.generateDebugInfo = lCfg["linker"]("generateDebugInfo").valBool();
  lOpts.disableOptimizer  = lCfg["linker"]("disableOptimizer").valBool();
  lOpts.optimizeSize      = lCfg["linker"]("optimizeSize").valBool();

  for (auto i : {ShaderType::VERTEX,
                 ShaderType::TESS_CON,
                 ShaderType::TESS_EVA,
                 ShaderType::GEOMETRY,
                 ShaderType::FRAGMENT,
                 ShaderType::COMPUTE}) {
    auto *lInt = lProg.getIntermediate(getLanguageFromStage(i));
    if (!lInt)
      continue;

    auto &lSPIRVBinary = _shader->getModule(i).getSPIRVBinaryRef();
    GlslangToSpv(*lInt, lSPIRVBinary, &lOpts);
  }

  return StageResult::SUCCESS;
}

void GLSLangCompiler::cleanup() { vModules.clear(); }
