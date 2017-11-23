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

#include "CompilerBase.hpp"
#include <catch.hpp>

using namespace spirvPacker;
using namespace Catch;
using namespace Catch::Matchers;
using namespace std;

typedef std::vector<ShaderType> TypeList;

class TestCompiler final : public CompilerBase {
 public:
  StageResult vResult         = StageResult::SUCCESS;
  StageResult vLinkerRes      = StageResult::SUCCESS;
  TypeList    vCompilerRanFor = {};
  bool        vLinkerRan      = false;
  bool        vCleanupRan     = false;

  StageResult compileShaderModule(ShaderModule &m) override {
    vCompilerRanFor.push_back(m.getType());
    return vResult;
  }

  spirvPacker::StageResult link(spirvPacker::Shader *) override {
    vLinkerRan = true;
    return vLinkerRes;
  }

  void cleanup() override { vCleanupRan = true; }

  std::string getName() const noexcept override { return "TestCompiler"; }
  bool        initializeStage() override { return true; }
};

SCENARIO("Testing the Compiler base class", "[compiler]") {
  GIVEN("a test compiler and a shader") {
    TestCompiler lComp;
    Shader       lShader;

    lShader[ShaderType::VERTEX].setType(ShaderType::VERTEX);
    lShader[ShaderType::GEOMETRY].setType(ShaderType::GEOMETRY);
    lShader[ShaderType::FRAGMENT].setType(ShaderType::FRAGMENT);

    lShader[ShaderType::VERTEX].setSourceCode("This is the vertex shader source code");
    lShader[ShaderType::GEOMETRY].setSourceCode("This is the geometry shader source code");
    lShader[ShaderType::FRAGMENT].setSourceCode("This is the fragment shader source code");

    THEN("running the compiler succeeds") {
      REQUIRE(lComp.run(&lShader) == StageResult::SUCCESS);
      REQUIRE(lComp.vCompilerRanFor == TypeList{ShaderType::VERTEX, ShaderType::GEOMETRY, ShaderType::FRAGMENT});
      REQUIRE(lComp.vLinkerRan == true);
      REQUIRE(lComp.vCleanupRan == true);
    }

    WHEN("compilation fails") {
      lComp.vResult = StageResult::COMPILER_ERROR;
      THEN("the run function errors") {
        REQUIRE(lComp.run(&lShader) == StageResult::COMPILER_ERROR);
        REQUIRE(lComp.vCompilerRanFor == TypeList{ShaderType::VERTEX});
        REQUIRE(lComp.vLinkerRan == false);
        REQUIRE(lComp.vCleanupRan == true);
      }
    }

    WHEN("linking fails") {
      lComp.vLinkerRes = StageResult::LINKER_ERROR;
      THEN("the run function errors") {
        REQUIRE(lComp.run(&lShader) == StageResult::LINKER_ERROR);
        REQUIRE(lComp.vCompilerRanFor == TypeList{ShaderType::VERTEX, ShaderType::GEOMETRY, ShaderType::FRAGMENT});
        REQUIRE(lComp.vLinkerRan == true);
        REQUIRE(lComp.vCleanupRan == true);
      }
    }

    WHEN("using nullptr") {
      THEN("the run function errors imediately") {
        REQUIRE(lComp.run(nullptr) == StageResult::ERROR);
        REQUIRE(lComp.vCompilerRanFor == TypeList{});
        REQUIRE(lComp.vLinkerRan == false);
        REQUIRE(lComp.vCleanupRan == false);
      }
    }
  }
}
