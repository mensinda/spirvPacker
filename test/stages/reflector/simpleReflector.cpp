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

#include "SimpleReflector.hpp"
#include <catch.hpp>
#include "Disassembler.hpp"

using namespace spirvPacker;
using namespace Catch;
using namespace Catch::Matchers;
using namespace std;

SCENARIO("Testing the simple reflector", "[reflector]") {
  GIVEN("SPIRV vertex data") {
    Disassembler    lDis;
    SimpleReflector lRef;
    Shader          lShader;
    ShaderModule &  lMod = lShader.getModule(ShaderType::VERTEX);

    FILE *fp = fopen((SOURCE_DIR + "/test/data/vert.spv"_str).c_str(), "rb");

    REQUIRE(fp != nullptr);

    vector<uint32_t> lContents;
    fseek(fp, 0, SEEK_END);
    lContents.resize(static_cast<size_t>(ftell(fp)) / sizeof(uint32_t));
    rewind(fp);
    fread(&lContents[0], 1, lContents.size() * sizeof(uint32_t), fp);
    fclose(fp);

    REQUIRE(lContents.empty() == false);
    REQUIRE(lRef.initialize(make_shared<Config>()) == true);
    REQUIRE(lDis.initialize(make_shared<Config>()) == true);

    lMod.setType(ShaderType::VERTEX);
    lMod.getSPIRVBinaryRef() = lContents;

    THEN("Reflecting a non disassembled shader fails") {
      REQUIRE(lRef.reflectModule(lMod) == StageResult::PREVIOUS_STAGE_MISSING);
    }

    // ===============================================================================
    // === TODO      Do not use a dissassembler stage in this unit test       TODO ===
    // === TODO Hardcode some data or write a serializer to JSON or something TODO ===
    // ===============================================================================

    WHEN("Dissassembling the SPIRV succeeds") {
      REQUIRE(lDis.disassembleModule(lMod) == StageResult::SUCCESS);

      THEN("reflecting also works") {
        REQUIRE(lRef.reflectModule(lMod) == StageResult::SUCCESS);
        auto &lIDs = lMod.getIdInformationMapRef();
        REQUIRE(lIDs.size() == 38);
        for (auto &i : lIDs) {
          REQUIRE(i.second.type != info::IDType::Unknown);
          switch (i.second.type) {
            case info::IDType::Function:
            case info::IDType::Type:
            case info::IDType::Variable:
              REQUIRE(i.second.typeInfo);
              REQUIRE_NOTHROW(i.second.typeInfo->type());
              REQUIRE_NOTHROW(i.second.typeInfo->size());
              break;
            case info::IDType::Constant:
              REQUIRE(i.second.constant);
              REQUIRE_NOTHROW(i.second.constant->value());
              REQUIRE(i.second.constant->type());
              break;
            default: break;
          }

          for (auto &j : i.second.decorations) {
            auto &lDec = j.second;
            switch (lDec.dec) {
              case spv::Decoration::InputAttachmentIndex:
              case spv::Decoration::Offset:
              case spv::Decoration::MatrixStride:
              case spv::Decoration::DescriptorSet:
              case spv::Decoration::Binding:
              case spv::Decoration::Location: REQUIRE(lDec.i0 != UINT32_MAX); break;
              default: break;
            }
          }
        }
      }

      WHEN("messing with the dissassembled data") {
        // OpName %main "main" --> OpName "upps" "main"
        lMod.getDisassemblyDataRef().instructions[5].operands[0] = std::make_shared<dis::LiteralString>("upps", "");

        THEN("the Reflector breaks") { REQUIRE(lRef.reflectModule(lMod) == StageResult::REFLECTOR_ERROR); }
      }

      WHEN("The reflection is complete") {
        REQUIRE(lRef.reflectModule(lMod) == StageResult::SUCCESS);

        THEN("Passing nullptr fails") { REQUIRE(lRef.reflectShader(nullptr) == StageResult::ERROR); }

        THEN("Using a valid shader succeeds") { REQUIRE(lRef.reflectShader(&lShader) == StageResult::SUCCESS); }
      }
    }
  }

  GIVEN("SPIRV fragment data") {
    Disassembler    lDis;
    SimpleReflector lRef;
    Shader          lShader;
    ShaderModule &  lMod = lShader.getModule(ShaderType::VERTEX);

    FILE *fp = fopen((SOURCE_DIR + "/test/data/frag.spv"_str).c_str(), "rb");

    REQUIRE(fp != nullptr);

    vector<uint32_t> lContents;
    fseek(fp, 0, SEEK_END);
    lContents.resize(static_cast<size_t>(ftell(fp)) / sizeof(uint32_t));
    rewind(fp);
    fread(&lContents[0], 1, lContents.size() * sizeof(uint32_t), fp);
    fclose(fp);

    REQUIRE(lContents.empty() == false);
    REQUIRE(lRef.initialize(make_shared<Config>()) == true);
    REQUIRE(lDis.initialize(make_shared<Config>()) == true);

    lMod.setType(ShaderType::VERTEX);
    lMod.getSPIRVBinaryRef() = lContents;

    // ===============================================================================
    // === TODO      Do not use a dissassembler stage in this unit test       TODO ===
    // === TODO Hardcode some data or write a serializer to JSON or something TODO ===
    // ===============================================================================

    WHEN("Dissassembling the SPIRV succeeds") {
      REQUIRE(lDis.disassembleModule(lMod) == StageResult::SUCCESS);

      THEN("reflecting also works") { REQUIRE(lRef.reflectModule(lMod) == StageResult::SUCCESS); }
    }
  }
}
