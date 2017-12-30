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
#include "Disassembler.hpp"
#include "BinaryOpParser.hpp"
#include "Enum2Str.hpp"
#include "ToolMagicNumber.hpp"
#include <spirv.hpp>
#include <algorithm>

using namespace spirvPacker;
using namespace spv;
using namespace std;

Disassembler::~Disassembler() {}

bool Disassembler::initializeStage() {
  auto &lCfg = getStageBaseConfigSection();
  (void)lCfg;

  return true;
}

StageResult Disassembler::disassembleModule(ShaderModule &_mod) {
  auto                         lLogger = getLogger();
  std::vector<uint32_t> const &lData   = _mod.getSPIRVBinaryRef();
  dis::DisassemblyData &       lDis    = _mod.getDisassemblyDataRef();

  if (lData.size() <= 6) {
    lLogger->error("Size of the SPIRV binary ({} words) is to small", lData.size());
    return StageResult::DISASSEMBLER_ERROR;
  }

  if (lData[0] != MagicNumber) {
    lLogger->error("Invalid SPIR-V magic number {} (required: {})", lData[0], MagicNumber);
    return StageResult::INVALID_SPIRV;
  }

  auto lGenData = getToolDeskFromMagicNumber((lData[2] & 0xFFFF0000) >> 16);

  lDis.magicNumber       = lData[0];
  lDis.version           = lData[1];
  lDis.generator.value   = lData[2];
  lDis.generator.vendor  = lGenData.vendor;
  lDis.generator.comment = lGenData.comment;
  lDis.generator.tool    = lGenData.tool;
  lDis.bound             = lData[3];

  lDis.headRaw.resize(5);
  copy_n(begin(lData), 5, begin(lDis.headRaw));

  lLogger->debug("Magic number:   {:x}", lDis.magicNumber);
  lLogger->debug("Version:        {}.{}", lDis.getVersionMajor(), lDis.getVersionMinor());
  lLogger->debug("Generator val:  {:x}", lDis.generator.value);
  lLogger->debug("Generator info: {}: {}", lDis.generator.vendor, lDis.generator.tool);
  lLogger->debug("Generator desc: {}", lDis.generator.comment);
  lLogger->debug("Bound:          {}", lDis.bound);

  auto lCurr = begin(lData) + 5; // First instruction is at lData[5]

  while (lCurr < end(lData)) {
    uint32_t lWordCount = (*lCurr & 0xffff0000) >> 16;
    uint32_t lOpCode    = (*lCurr & 0x0000ffff) >> 0;

    if (lWordCount == 0) {
      lLogger->error("Invalid word count of 0");
      return StageResult::INVALID_SPIRV;
    }

    if (lWordCount > end(lData) - lCurr) {
      lLogger->error("Invalid word count of {} (biger than the remaining file size)", lWordCount);
      return StageResult::INVALID_SPIRV;
    }

    lDis.instructions.emplace_back();
    dis::Instruction &lInst = lDis.instructions.back();

    lInst.op = static_cast<Op>(lOpCode);
    lInst.rawBinary.resize(lWordCount);
    copy_n(lCurr, lWordCount, begin(lInst.rawBinary));

    if (!parseInstruction(lInst)) {
      lLogger->error("Invalid instruction (OpCode: {} == {}). Disassembler failed", lOpCode, Enum2Str::toStr(lInst.op));
      return StageResult::INVALID_SPIRV;
    }

    lLogger->debug("OP: {}; Words: {}; Operands: {}", Enum2Str::toStr(lInst.op), lWordCount, lInst.operands.size());

    lCurr += lWordCount;
  }

  return StageResult::SUCCESS;
}
