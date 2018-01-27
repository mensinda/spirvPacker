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
#include "SPIRVDisassembly.hpp"
#include <map>
#include <string>

namespace spirvPacker {

/*!
 * \brief Defines enumerations for all supported shader stages
 */
enum class ShaderType {
  VERTEX = 0,    //!< The Vertex shader stage
  TESS_CON,      //!< The tesselation control shader stage
  TESS_EVA,      //!< The tesselation evaluation shader stage
  GEOMETRY,      //!< The geometry shader stage
  FRAGMENT,      //!< The fragment shader stage
  COMPUTE,       //!< The compute shader stage
  __UNDEFINED__, //!< The shader stage is indefined and / or not set
};

//! \brief The format of the source files
enum class SourceFormat {
  GLSL, //!< \brief The source format of the input is GLSL
  HLSL  //!< \brief The source format of the input is HLSL
};

//! \brief All information of a SPIRV ID
struct IdInfoSPIRV {
  uint32_t    id   = UINT32_MAX;
  std::string name = "<UNDEFINED>";
};

/*!
 * \brief Stores all information of a shader module
 *
 * A shader module object is valid when its type is not ShaderType::__UNDEFINED__
 */
struct ShaderModule final {
 public:
  typedef std::map<uint32_t, IdInfoSPIRV> ID_MAP;

 private:
  ShaderType            vType   = ShaderType::__UNDEFINED__;
  SourceFormat          vFormat = SourceFormat::GLSL;
  std::string           vSourceCode;
  std::vector<uint32_t> vSPIRVBinary;
  dis::DisassemblyData  vDisassemblyData;
  ID_MAP                vIDInfo;

 public:
  ShaderModule() = default;

  inline void setType(ShaderType _t) noexcept { vType = _t; }
  inline void setSourceFormat(SourceFormat _f) noexcept { vFormat = _f; }
  inline void setSourceCode(std::string _src) noexcept { vSourceCode = _src; }

  inline ShaderType             getType() const noexcept { return vType; }
  inline SourceFormat           getSourceFormat() const noexcept { return vFormat; }
  inline std::string            getSourceCode() const noexcept { return vSourceCode; }
  inline std::vector<uint32_t> &getSPIRVBinaryRef() noexcept { return vSPIRVBinary; }
  inline dis::DisassemblyData & getDisassemblyDataRef() noexcept { return vDisassemblyData; }
  inline ID_MAP &               getIdInformationMapRef() noexcept { return vIDInfo; }
  inline bool                   isValid() const noexcept { return vType != ShaderType::__UNDEFINED__; }

  static std::string             shaderType2Str(ShaderType _t) noexcept;
  static std::vector<ShaderType> getAllShaderTypes() noexcept;
};

} // namespace spirvPacker
