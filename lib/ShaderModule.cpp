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
#include "ShaderModule.hpp"
#include <cstdio>

using namespace spirvPacker;
using namespace std;

string ShaderModule::shaderType2Str(ShaderType _t) noexcept {
  switch (_t) {
    case ShaderType::VERTEX: return "vertex";
    case ShaderType::TESS_CON: return "tessControl";
    case ShaderType::TESS_EVA: return "tessEval";
    case ShaderType::GEOMETRY: return "geometry";
    case ShaderType::FRAGMENT: return "fragment";
    case ShaderType::COMPUTE: return "compute";
    default: return "<UNKNOWN>";
  }
}

vector<ShaderType> ShaderModule::getAllShaderTypes() noexcept {
  return {ShaderType::VERTEX,
          ShaderType::TESS_CON,
          ShaderType::TESS_EVA,
          ShaderType::GEOMETRY,
          ShaderType::FRAGMENT,
          ShaderType::COMPUTE};
}
