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

#include "SpirvPacker.hpp"
#include <catch.hpp>

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

SCENARIO("testing the SpirvPacker class initialisation", "[framework]") {
  GIVEN("a packer and a stage") {
    auto        lCfg    = std::make_shared<ConfigSection>();
    auto        lStage  = std::make_shared<StageImpl>();
    auto        lStage2 = std::make_shared<StageImpl>();
    SpirvPacker lPacker;

    THEN("normaly adding the stage and initializing will work") {
      REQUIRE(lPacker.addStage(lStage) == true);
      REQUIRE(lPacker.initializeStages(lCfg) == true);
      REQUIRE(lPacker.getIsInitialized() == true);
    }

    THEN("feeding nullptr's to SpirvPacker will fail but not crash") {
      REQUIRE(lPacker.initializeStages(nullptr) == false);
      REQUIRE(lPacker.addStage(nullptr) == false);
      REQUIRE(lPacker.getIsInitialized() == false);
    }

    WHEN("the initialization of a stage failes") {
      lStage->vInitializeReturnValue = false;

      THEN("the initialization of the packer also fails") {
        REQUIRE(lPacker.addStage(lStage) == true);
        REQUIRE(lPacker.initializeStages(lCfg) == false);
      }
    }

    THEN("double initialization fails") {
      REQUIRE(lPacker.addStage(lStage) == true);
      REQUIRE(lPacker.initializeStages(lCfg) == true);
      REQUIRE(lPacker.getIsInitialized() == true);
      REQUIRE(lPacker.initializeStages(lCfg) == false);
      REQUIRE(lPacker.getIsInitialized() == true);
    }

    THEN("adding stages after initialization fails") {
      REQUIRE(lPacker.addStage(lStage) == true);
      REQUIRE(lPacker.initializeStages(lCfg) == true);
      REQUIRE(lPacker.getIsInitialized() == true);
      REQUIRE(lPacker.addStage(lStage2) == false);
      REQUIRE(lPacker.getIsInitialized() == true);
    }

    THEN("adding the same stages twice fails") {
      REQUIRE(lPacker.addStage(lStage) == true);
      REQUIRE(lPacker.addStage(lStage) == false);
    }
  }
}
