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
#include "SPIRVOperands.hpp"
#include <spirv.hpp>
#include <string>
#include <vector>

namespace spirvPacker {
namespace dis {

struct GeneratorInfo {
  uint32_t    value   = 0;
  std::string vendor  = "<UNDEFINED>";
  std::string comment = "<UNDEFINED>";
  std::string tool    = "<UNDEFINED>";
};

struct Instruction {
  spv::Op op;

  std::vector<uint32_t>                 rawBinary;
  std::vector<std::shared_ptr<Operand>> operands;
};

struct DisassemblyData {
  uint32_t      magicNumber = 0;
  uint32_t      version     = 0;
  GeneratorInfo generator;
  uint32_t      bound = 0;

  std::vector<uint32_t> headRaw;

  std::vector<Instruction> instructions;

  inline uint32_t getVersionMajor() const noexcept { return (version & 0x00FF0000) >> 16; }
  inline uint32_t getVersionMinor() const noexcept { return (version & 0x0000FF00) >> 8; }
};

} // namespace dis
} // namespace spirvPacker
