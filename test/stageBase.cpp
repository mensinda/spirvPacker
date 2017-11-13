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
#include "SpirvPacker.hpp"

using namespace spirvPacker;
using namespace Catch;
using namespace Catch::Matchers;

class StageImpl final : public StageBase {
 public:
  std::string vName                  = "Test";
  StageType   vType                  = StageType::INPUT_FINDER;
  bool        vInitializeReturnValue = true;
  StageResult vRunReturnValue        = StageResult::SUCCESS;

 public:
  StageImpl() = default;
  std::string getName() const noexcept override { return vName; }
  StageType   getStageType() const noexcept override { return vType; }
  bool        initializeStage() override { return vInitializeReturnValue; }
  StageResult run(spirvPacker::Shader *) override { return vRunReturnValue; }
};

SCENARIO("Using the StageBase class", "[framework]") {
  GIVEN("all diferent kind of stages") {
    StageImpl lInput;
    StageImpl lCompiler;
    StageImpl lOptimizer;
    StageImpl lDiss;
    StageImpl lInterpreter;
    StageImpl lGenerator;

    lInput.vName       = "Input_1";
    lInput.vType       = StageType::INPUT_FINDER;
    lCompiler.vName    = "Compiler_2";
    lCompiler.vType    = StageType::COMPILER;
    lOptimizer.vName   = "Optimizer_3";
    lOptimizer.vType   = StageType::OPTIMIZER;
    lDiss.vName        = "DISS_4";
    lDiss.vType        = StageType::DISASSEMBLE;
    lInterpreter.vName = "Interp_5";
    lInterpreter.vType = StageType::INTERPRETER;
    lGenerator.vName   = "GENERATOR_6";
    lGenerator.vType   = StageType::GENERATOR;

    WHEN("initializing them") {
      auto lRoot = std::make_shared<ConfigSection>();
      for (auto i : {&lInput, &lCompiler, &lOptimizer, &lDiss, &lInterpreter, &lGenerator}) {
        i->initialize(lRoot);
      }

      THEN("the config sections are correctly generated") {
        REQUIRE_NOTHROW((*lRoot)["input"]["Input_1"]);
        REQUIRE_NOTHROW((*lRoot)["compiler"]["Compiler_2"]);
        REQUIRE_NOTHROW((*lRoot)["optimizer"]["Optimizer_3"]);
        REQUIRE_NOTHROW((*lRoot)["disassemble"]["DISS_4"]);
        REQUIRE_NOTHROW((*lRoot)["interpreter"]["Interp_5"]);
        REQUIRE_NOTHROW((*lRoot)["generator"]["GENERATOR_6"]);
      }
    }
  }

  GIVEN("a stage and a SpirvPacer") {
    StageImpl lStage;

    THEN("incoretly accessing stage / packer should fail") {
      REQUIRE(lStage.initialize(nullptr) == false);
      REQUIRE_THROWS_WITH(lStage.getRootConfigSection(), Contains("not yet initialized"));
      REQUIRE_THROWS_WITH(lStage.getStageBaseConfigSection(), Contains("not yet initialized"));
    }
  }
}
