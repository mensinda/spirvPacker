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

#include "SPIRVDumper.hpp"
#include <catch.hpp>
#include "InputBase.hpp"
#include "tempFileHandler.hpp"

using namespace spirvPacker;
using namespace Catch;
using namespace Catch::Matchers;
using namespace std;

SCENARIO("dumpung generated SPIRV to disc", "[generator]") {
  GIVEN("the generator, a config and some test data") {
    SPIRVDumper lGen;
    Shader      lShader;
    TempDir     lDir;
    auto &      lModule = lShader[ShaderType::VERTEX];
    auto        lCfg    = make_shared<Config>();

    lModule.getSPIRVBinaryRef().push_back(21);
    lModule.getSPIRVBinaryRef().push_back(42);

    REQUIRE(lGen.initialize(lCfg) == true);

    lCfg->addSection("base").addEntry("name", "ttt1"_str);
    (*lCfg)["generator"]["SPIRVDumper"]("directory") = lDir.getPath();
    REQUIRE(lCfg->validate() == true);

    THEN("running dumps something") {
      REQUIRE(lGen.run(&lShader) == StageResult::SUCCESS);
      REQUIRE(fs::exists(lDir.getPath() + "/ttt1.vertex.spirv") == true);
      REQUIRE(fs::is_regular_file(lDir.getPath() + "/ttt1.vertex.spirv") == true);
      REQUIRE(fs::is_empty(lDir.getPath() + "/ttt1.vertex.spirv") == false);
    }

    THEN("using nullptr does not crash") { REQUIRE(lGen.run(nullptr) == StageResult::ERROR); }

    THEN("using invalid directory fails") {
      (*lCfg)["generator"]["SPIRVDumper"]("directory") = "fgafgafga/sdg"_str;
      REQUIRE(lGen.run(&lShader) == StageResult::IO_ERROR);
    }

    THEN("root directory fails (no permissions)") {
      (*lCfg)["generator"]["SPIRVDumper"]("directory") = "/"_str;
      REQUIRE(lGen.run(&lShader) == StageResult::IO_ERROR);
    }
  }
}
