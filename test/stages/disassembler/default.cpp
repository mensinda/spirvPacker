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

#include <catch.hpp>
#include "Disassembler.hpp"
#include "InputBase.hpp"

using namespace spirvPacker;
using namespace Catch;
using namespace Catch::Matchers;
using namespace std;

SCENARIO("disassembling data", "[disassembler]") {
  GIVEN("a shader and the disassembler") {
    Disassembler lDis;
    ShaderModule lMod;

    FILE *fp = fopen((SOURCE_DIR + "/test/data/vert.spv"_str).c_str(), "rb");

    REQUIRE(fp != nullptr);

    vector<uint32_t> lContents;
    fseek(fp, 0, SEEK_END);
    lContents.resize(static_cast<size_t>(ftell(fp)) / sizeof(uint32_t));
    rewind(fp);
    fread(&lContents[0], 1, lContents.size() * sizeof(uint32_t), fp);
    fclose(fp);

    REQUIRE(lContents.empty() == false);

    lMod.setType(ShaderType::VERTEX);

    THEN("disassembling an empty module fails") {
      REQUIRE(lDis.disassembleModule(lMod) == StageResult::DISASSEMBLER_ERROR);
    }

    THEN("disassembling the data succeeds") {
      lMod.getSPIRVBinaryRef() = lContents;
      REQUIRE(lDis.disassembleModule(lMod) == StageResult::SUCCESS);
      auto &lData = lMod.getDisassemblyDataRef();
      REQUIRE(lData.magicNumber == 0x7230203);
      REQUIRE(lData.bound == 61);
      REQUIRE(lData.generator.value == 0x80002);
      REQUIRE(lData.generator.tool == "Glslang Reference Front End");
      REQUIRE(lData.generator.vendor == "Khronos");
      REQUIRE(lData.generator.comment.empty() == false);
      REQUIRE(lData.headRaw.empty() == false);
      REQUIRE(lData.instructions.size() == 109);

      auto &lEntryP = lData.instructions[3];
      REQUIRE(lEntryP.op == spv::Op::OpEntryPoint);
      REQUIRE(lEntryP.rawBinary.empty() == false);
      REQUIRE(lEntryP.operands.size() == 10);
      REQUIRE(lEntryP.operands[2]->kind() == dis::Kind::LiteralString);
      dis::LiteralString *lOP = dynamic_cast<dis::LiteralString *>(lEntryP.operands[2].get());
      REQUIRE(lOP != nullptr);
      REQUIRE(lOP->valStr() == "main");
    }

    WHEN("the magic number is invalid") {
      lContents[0]             = 42;
      lMod.getSPIRVBinaryRef() = lContents;
      THEN("the disassembler fails") { REQUIRE(lDis.disassembleModule(lMod) == StageResult::INVALID_SPIRV); }
    }

    WHEN("the word cound of an instruction is 0") {
      lContents[5]             = 0x00000011;
      lMod.getSPIRVBinaryRef() = lContents;
      THEN("the disassembler fails (invalid word count)") {
        REQUIRE(lDis.disassembleModule(lMod) == StageResult::INVALID_SPIRV);
      }
    }

    WHEN("the word cound of an instruction is to big") {
      lContents[5]             = 0xffff0011;
      lMod.getSPIRVBinaryRef() = lContents;
      THEN("the disassembler fails (invalid word count)") {
        REQUIRE(lDis.disassembleModule(lMod) == StageResult::INVALID_SPIRV);
      }
    }

    WHEN("an instruction is invalud") {
      lContents[5]             = 0x00021234;
      lMod.getSPIRVBinaryRef() = lContents;
      THEN("the disassembler fails") { REQUIRE(lDis.disassembleModule(lMod) == StageResult::INVALID_SPIRV); }
    }
  }
}
