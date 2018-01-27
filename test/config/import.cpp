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
#include "ConfigImport.hpp"

using namespace spirvPacker;
using namespace Catch;
using namespace Catch::Matchers;

inline std::string getBadStr() {
  return R"(
{
  asdf: asd3435,
})";
}

inline std::string getGoodStr() {
  return R"(
{
  "config": {
    "boolTest": false,
    "rootEntry": 20,
    "testSec": {
      "arrayBool": [
        true,
        true,
        false,
        false
      ],
      "arrayDouble": [],
      "arrayInt": [
        21,
        42,
        84,
        168
      ],
      "arrayStr": [
        "Test -- new",
        "qwert"
      ],
      "content": {
        "bool": true,
        "double": 1.0,
        "int": 12,
        "str": "TMPddd"
      }
    }
  }
})";
}

inline std::string getMehStr() {
  return R"(
{
  "config": {
    "boolTest": "Ha Ha no bool",
    "rootEntry": false,
    "testSec": {
      "arrayBoolll": [
        true
      ],
      "arrayDouble": [1.0, 2.4],
      "arrayInt": [
        false,
        42.4,
        "HA HA HA"
      ],
      "arrayStr": "HAHA"
    }
  }
})";
}


SCENARIO("Importing a config to JSON", "[cfg]") {
  GIVEN("a basic config structure and a importer visitor") {
    Config       lRoot;
    ConfigImport lImporter;

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

    THEN("Setting a bad source string fails") { REQUIRE(lImporter.setRawJSON(getBadStr()) == false); }

    WHEN("Setting a valid JSON string") {
      REQUIRE(lImporter.setRawJSON(getGoodStr()) == true);
      REQUIRE(lRoot.accept(&lImporter) == true);

      THEN("Values are changed") {
        REQUIRE(lRoot("rootEntry").valInt() == 20);
        REQUIRE(lRoot("boolTest").valBool() == false);

        REQUIRE(lRoot["testSec"]("arrayBool").size() == 4);
        REQUIRE(lRoot["testSec"]("arrayDouble").size() == 0);
        REQUIRE(lRoot["testSec"]("arrayInt").size() == 4);
        REQUIRE(lRoot["testSec"]("arrayStr").size() == 2);

        REQUIRE(lRoot["testSec"]["content"]("str").valStr() == "TMPddd");
      }
    }

    WHEN("Setting a valid JSON string (that only has somwhat in common with the config tree)") {
      REQUIRE(lImporter.setRawJSON(getMehStr()) == true);
      REQUIRE(lRoot.accept(&lImporter) == true);

      THEN("Values are changed") {
        REQUIRE(lRoot("rootEntry").valInt() == 12);
        REQUIRE(lRoot("boolTest").valBool() == true);

        REQUIRE(lRoot["testSec"]("arrayBool").size() == 2);
        REQUIRE(lRoot["testSec"]("arrayDouble").size() == 2);
        REQUIRE(lRoot["testSec"]("arrayInt").size() == 1); // Only one valid integer in the new JSON
        REQUIRE(lRoot["testSec"]("arrayStr").size() == 2); // No arry --> Nothing changes

        REQUIRE(lRoot["testSec"]["content"]("str").valStr() == "TMP");
      }
    }
  }
}
