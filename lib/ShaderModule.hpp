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
#include <string>

namespace spirvPacker {

/*!
 * \brief Defines enumerations for all supported shader stages
 */
enum class ShaderType {
  VERTEX = 0, //!< The Vertex shader stage
  TESS_CON,   //!< The tesselation control shader stage
  TESS_EVA,   //!< The tesselation evaluation shader stage
  GEOMETRY,   //!< The geometry shader stage
  FRAGMENT,   //!< The fragment shader stage
  COMPUTE,    //!< The compute shader stage
  __NUM__,    //!< Last shader stage (= number of shader stages) or undefined
};

/*!
 * \brief Stores all information of a shader module
 *
 * A shader module object is valid when its type is not ShaderType::__NUM__
 */
class ShaderModule final {
 private:
  ShaderType  vType = ShaderType::__NUM__;
  std::string vSourceFilePath;

 public:
  ShaderModule() = default;

  inline void setType(ShaderType _t) noexcept { vType = _t; }
  inline void setSourcePath(std::string _path) noexcept { vSourceFilePath = _path; }

  inline ShaderType  getType() const noexcept { return vType; } //!< Returns the type of the shader (see ShaderType)
  inline std::string getSourcePath() const noexcept { return vSourceFilePath; }
  inline bool        isValid() const noexcept { return vType != ShaderType::__NUM__; }
};

} // namespace spirvPacker
