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

namespace spirvPacker {

/*!
 * \brief Defines enumerations for all supported shader stages
 */
enum class ShaderType {
  VERTEX,   //!< The Vertex shader stage
  TESS_CON, //!< The tesselation control shader stage
  TESS_EVA, //!< The tesselation evaluation shader stage
  GEOMETRY, //!< The geometry shader stage
  FRAGMENT, //!< The fragment shader stage
  COMPUTE   //!< The compute shader stage
};

/*!
 * \brief Stores all information of a shader module
 */
class ShaderModule final {
 private:
  ShaderType vType;

 public:
  ShaderModule() = delete;
  ShaderModule(ShaderType _type);

  inline ShaderType getType() const noexcept { return vType; } //!< Returns the type of the shader (see ShaderType)
};

} // namespace spirvPacker
