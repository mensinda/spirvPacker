/*
 * Copyright (C) 2018 Daniel Mensinger
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

#include "ReflectorBase.hpp"
#include "Enum2Str.hpp"

using namespace spirvPacker;

ReflectorBase::~ReflectorBase() {}

StageResult ReflectorBase::run(Shader *_shader) {
  auto        lLogger = getLogger();
  StageResult lRes    = StageResult::SUCCESS;

  if (!_shader) {
    lLogger->error("The shader may not be null.");
    return StageResult::ERROR;
  }

  for (auto i : ShaderModule::getAllShaderTypes()) {
    ShaderModule &lModule = _shader->getModule(i);
    if (lModule.isValid()) {
      std::string lShaderType = lModule.shaderType2Str(lModule.getType());
      lLogger->info("Reflecting [{:^12}] shader module", lShaderType);
      lRes = reflectModule(lModule);

      if (lRes != StageResult::SUCCESS) {
        lLogger->error("Reflecting [{:^12}] shader module failed", lShaderType);
        lLogger->error("Error code: {}", Enum2Str::toStr(lRes));
        break;
      }
    }
  }

  if (lRes == StageResult::SUCCESS)
    lRes = reflectShader(_shader);

  return lRes;
}
