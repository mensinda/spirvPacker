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

#include <catch.hpp>
#include "Config.hpp"
#include "ConfigExport.hpp"

using namespace spirvPacker;
using namespace Catch;
using namespace Catch::Matchers;

SCENARIO("Exporting a config to JSON", "[cfg]") {
  GIVEN("a basic config structure and a printer visitor") {
    Config       lRoot;
    ConfigExport lExporter;

    lRoot.addEntry("rootEntry", 12l);
    lRoot.addEntry("boolTest", true);

    lRoot.addSection("testSec");
    lRoot["testSec"].addSection("content");
    lRoot["testSec"]["content"].addEntry("str", "TMP"_str);
    lRoot["testSec"]["content"].addEntry("int", 12l);
    lRoot["testSec"]["content"].addEntry("double", 1.0f);
    lRoot["testSec"]["content"].addEntry("bool", true);
    lRoot["testSec"].addArrayEntry("arrayStr", {ConfigEntry::STR_TYPE, {"Test"_str, "asdf"_str}});
    lRoot["testSec"].addArrayEntry("arrayInt", {ConfigEntry::INT_TYPE, {21l, 42l, 84l}});
    lRoot["testSec"].addArrayEntry("arrayDouble", {ConfigEntry::DOUBLE_TYPE, {1.1}});
    lRoot["testSec"].addArrayEntry("arrayBool", {ConfigEntry::BOOL_TYPE, {true, false}});

    WHEN("the printer prints the config") {
      lRoot.accept(&lExporter);

      THEN("the result string is correct") {
        auto lRes = lExporter.getResult();
        REQUIRE(lRes.empty() == false);
        REQUIRE_THAT(lRes, Contains("rootEntry") && Contains("12"));
        REQUIRE_THAT(lRes, Contains("arrayInt") && Contains("84"));
      }

      AND_WHEN("the printer is reset") {
        lExporter.reset();

        THEN("the generated JSON string is empty") { REQUIRE(lExporter.getResult() == "{}"); }
      }
    }


    WHEN("setting new values") {
      lRoot["testSec"]["content"]("double") = 5.1;
      lRoot["testSec"]["content"]("str")    = "Hello World"_str;
      lRoot["testSec"]["content"]("int")    = 42l;

      REQUIRE(lRoot.validate() == true);

      lRoot.accept(&lExporter);

      THEN("these values should appear in the printed string") {
        auto lRes = lExporter.getResult();
        REQUIRE(lRes.empty() == false);
        REQUIRE_THAT(lRes, Contains("rootEntry") && Contains("12"));
        REQUIRE_THAT(lRes, Contains("int") && Contains("42"));
        REQUIRE_THAT(lRes, Contains("str") && Contains("\"Hello World\""));
      }
    }
  }
}
