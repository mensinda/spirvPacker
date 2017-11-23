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
#include "GLSLangCompiler.hpp"
#include "InputBase.hpp"

using namespace spirvPacker;
using namespace Catch;
using namespace Catch::Matchers;
using namespace std;

SCENARIO("Compiling something with GLSLang", "[compiler]") {
  GIVEN("a compiler and vertex shader") {
    GLSLangCompiler lCompiler;
    Shader          lShader;
    auto &          lModule = lShader[ShaderType::VERTEX];
    auto            lCfg    = make_shared<Config>();

    REQUIRE(lCompiler.initialize(lCfg) == true);
    lModule.setType(ShaderType::VERTEX);
    lModule.setSourceCode(InputBase::readSourceContent(SOURCE_DIR + "/test/data/triangle1.vert"_str));

    THEN("compiling succeeds") {
      REQUIRE(lCompiler.run(&lShader) == StageResult::SUCCESS);
      REQUIRE(lModule.getSPIRVBinaryRef().empty() == false);
    }

    WHEN("the source is not valid") {
      lModule.setSourceCode("adfgafdggerergergergergaerg");

      THEN("Compilation fails") {
        REQUIRE(lCompiler.run(&lShader) == StageResult::COMPILER_ERROR);
        REQUIRE(lModule.getSPIRVBinaryRef().empty() == true);
      }
    }

    THEN("using nullptr as parameter does not crash") { REQUIRE(lCompiler.link(nullptr) == StageResult::ERROR); }
  }
}
