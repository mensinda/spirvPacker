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

#include "DisassemblerBase.hpp"
#include <catch.hpp>
#include "InputBase.hpp"

using namespace spirvPacker;
using namespace Catch;
using namespace Catch::Matchers;
using namespace std;

class TestDisassembler final : public DisassemblerBase {
 public:
  StageResult vRes = StageResult::SUCCESS;
  bool        vRan = false;

  StageResult disassembleModule(ShaderModule &) override {
    vRan = true;
    return vRes;
  }

  bool        initializeStage() override { return true; }
  std::string getName() const noexcept override { return "TestDis"; }
};

SCENARIO("testing the base disassembler", "[disassembler]") {
  GIVEN("a test disassembler and a shader") {
    TestDisassembler lDis;
    Shader           lShader;

    lShader[ShaderType::VERTEX].setType(ShaderType::VERTEX);
    lShader[ShaderType::FRAGMENT].setType(ShaderType::FRAGMENT);

    REQUIRE(lDis.getStageType() == StageType::DISASSEMBLER);

    THEN("running the disassembler succeeds") {
      lDis.vRan = false;
      REQUIRE(lDis.run(&lShader) == StageResult::SUCCESS);
      REQUIRE(lDis.vRan == true);
    }

    WHEN("the shader is invalid") {
      THEN("the disassembler will not run") {
        REQUIRE(lDis.run(nullptr) == StageResult::ERROR);
        REQUIRE(lDis.vRan == false);
      }
    }

    WHEN("the disassembler fails") {
      lDis.vRes = StageResult::DISASSEMBLER_ERROR;
      THEN("the disassembler will not run") {
        REQUIRE(lDis.run(&lShader) == StageResult::DISASSEMBLER_ERROR);
        REQUIRE(lDis.vRan == true);
      }
    }
  }
}
