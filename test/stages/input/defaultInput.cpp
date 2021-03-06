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

#include "DefaultInput.hpp"
#include <catch.hpp>

using namespace spirvPacker;
using namespace Catch;
using namespace Catch::Matchers;
using namespace std;

SCENARIO("testing the DefaultInput", "[input]") {
  GIVEN("a config and the default input and a shader object") {
    DefaultInput lInput;
    Shader       lShader;
    auto         lCfg = make_shared<Config>();
    (*lCfg).addSection("base").addEntry("name", "triangle1"_str);

    REQUIRE(lInput.initialize(lCfg) == true);

    WHEN("everything in the config is setup correctly") {
      (*lCfg)["input"]["defaultInput"]("directory") = SOURCE_DIR + "/test/data"_str;
      REQUIRE(lCfg->validate() == true);

      THEN("the 2 shader files are found") {
        string lVertexSRC   = InputBase::readSourceContent(SOURCE_DIR + "/test/data/triangle1.vert"_str);
        string lFragmentSRC = InputBase::readSourceContent(SOURCE_DIR + "/test/data/triangle1.frag"_str);

        REQUIRE(lInput.run(&lShader) == StageResult::SUCCESS);
        REQUIRE(lShader[ShaderType::VERTEX].isValid() == true);
        REQUIRE(lShader[ShaderType::VERTEX].getType() == ShaderType::VERTEX);
        REQUIRE(lShader[ShaderType::VERTEX].getSourceCode() == lVertexSRC);
        REQUIRE(lShader[ShaderType::FRAGMENT].getSourceCode() == lFragmentSRC);
        REQUIRE(lShader[ShaderType::GEOMETRY].getSourceCode() == "");
        REQUIRE(ShaderModule::shaderType2Str(static_cast<ShaderType>(42)) == "<UNKNOWN>");
      }
    }

    WHEN("the directory is invalid") {
      (*lCfg)["input"]["defaultInput"]("directory") = "/asdfasfd/fhhhhagfagaergags"_str;
      REQUIRE(lCfg->validate() == true);

      THEN("the 2 shader files are found") {
        REQUIRE(lInput.run(&lShader) == StageResult::IO_ERROR);
        REQUIRE(lShader[ShaderType::VERTEX].isValid() == false);
      }
    }
  }

  WHEN("Reding source from a file that does not exist") {
    THEN("An error is thrown") { REQUIRE_THROWS(DefaultInput::readSourceContent("/dfadfsag/fgafg/fffasd.txt")); }
  }
}
