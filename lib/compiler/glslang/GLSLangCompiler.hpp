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

#pragma once

#include "spvCfg.hpp"
#include "CompilerBase.hpp"
#include <ShaderLang.h>
#include <memory>
#include <vector>

namespace spirvPacker {

class GLSLangCompiler final : public CompilerBase {
 private:
  struct Data {
    std::unique_ptr<glslang::TShader> shader;
    ShaderType                        type;
    EShLanguage                       glslangStage;
  };

  std::vector<Data> vModules;

  void             initResources(ConfigSection &_sec);
  TBuiltInResource getResources(ConfigSection &_sec);

 public:
  GLSLangCompiler();
  ~GLSLangCompiler() override;

  StageResult compileShaderModule(ShaderModule &m) override;
  StageResult link(Shader *_shader) override;
  void        cleanup() override;

  inline std::string getName() const noexcept override { return "glslang"; }
  bool               initializeStage() override;
};

} // namespace spirvPacker
