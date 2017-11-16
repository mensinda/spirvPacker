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

#include "Config.hpp"
#include <catch.hpp>

using namespace spirvPacker;
using namespace Catch;
using namespace Catch::Matchers;

SCENARIO("Setting and reading config entries", "[cfg]") {
  GIVEN("an empty, default config structure") {
    ConfigSection lRoot;

    THEN("it should be default initialized") {
      REQUIRE(lRoot.getParent() == nullptr);
      REQUIRE(lRoot.getName() == "config");
      REQUIRE(lRoot.getName() == lRoot.genPath());
      REQUIRE_THROWS_WITH(lRoot["notExists"], Contains("Subsection 'notExists'") && Contains("does not exist"));
      REQUIRE_THROWS_WITH(lRoot("notExists"), Contains("Config entry 'notExists'") && Contains("does not exist"));
    }

    WHEN("adding sections and entries") {
      auto &lSec   = lRoot.addSection("test");
      auto &lEntry = lRoot.addEntry("test2", true);

      THEN("the structure should be valid") {
        REQUIRE(lSec.getName() == "test");
        REQUIRE(lEntry.getName() == "test2");
        REQUIRE_NOTHROW(lRoot["test"]);
        REQUIRE_NOTHROW(lRoot("test2"));
        REQUIRE_THROWS_WITH(lRoot["test2"], Contains("Subsection 'test2'") && Contains("does not exist"));
        REQUIRE_THROWS_WITH(lRoot("test"), Contains("Config entry 'test'") && Contains("does not exist"));
      }
    }
  }

  GIVEN("a basic config structure") {
    ConfigSection lRoot;

    lRoot.addEntry("rootEntry", 12l, [](ConfigEntry const *e) { return std::get<long int>(e->value()) > 0; });
    lRoot.addEntry("boolTest", true);

    lRoot.addSection("testSec");
    lRoot["testSec"].addSection("content");
    lRoot["testSec"]["content"].addEntry("str", "TMP"_str, [](ConfigEntry const *e) { return !e->valStr().empty(); });
    lRoot["testSec"]["content"].addEntry("int", 12l, [](ConfigEntry const *e) { return e->valInt() > 0; });
    lRoot["testSec"]["content"].addEntry("double", 1.0f, [](ConfigEntry const *e) { return e->valDouble() < 10; });
    lRoot["testSec"]["content"].addEntry("bool", true, [](ConfigEntry const *e) { return e->valBool(); });
    lRoot["testSec"].addArrayEntry(
        "array", {ConfigEntry::STR_TYPE, {"Test"_str}}, [](ConfigEntry const *e) { return !e->empty(); });

    THEN("the default values should be set") {
      REQUIRE(lRoot.validate() == true);
      REQUIRE(lRoot("rootEntry").valInt() == 12);
      REQUIRE(lRoot("boolTest").valBool() == true);
      REQUIRE(lRoot["testSec"]["content"]("int").valInt() == 12);
      REQUIRE(std::get<std::string>(lRoot["testSec"]("array")[0]) == "Test");
    }

    THEN("invalid access should fail") {
      REQUIRE_THROWS_AS(lRoot["testSec"]["content"]("str").valDouble(), std::bad_variant_access);
      REQUIRE_THROWS_AS(lRoot["testSec"]["content"]("str").clear(), std::bad_variant_access);
      REQUIRE_NOTHROW(lRoot["testSec"]["content"]("int") = -1l);
      REQUIRE_NOTHROW(lRoot["testSec"]["content"]("double") = false);
      REQUIRE(lRoot.validate() == false);
    }

    WHEN("modifying an array") {
      lRoot["testSec"]("array") += "asd"_str;
      lRoot["testSec"]("array") += "fff"_str;

      THEN("the values should be stored") {
        REQUIRE(lRoot["testSec"]("array").size() == 3);
        REQUIRE(lRoot.validate() == true);
        REQUIRE(std::get<std::string>(lRoot["testSec"]("array")[1]) == "asd");
      }

      AND_WHEN("clearing the test array") {
        lRoot["testSec"]("array").clear();
        THEN("the custom validation function should fail") {
          REQUIRE(lRoot["testSec"]("array").empty() == true);
          REQUIRE(lRoot.validate() == false);
        }
      }

      AND_WHEN("adding a differnet type to the array") {
        lRoot["testSec"]("array") += false;

        THEN("the validation should fail") { REQUIRE(lRoot.validate() == false); }
      }
    }

    WHEN("setting new values") {
      lRoot["testSec"]["content"]("double") = 5.1;
      lRoot["testSec"]["content"]("str")    = "Hello World"_str;
      lRoot["testSec"]["content"]("int")    = 42l;

      THEN("these values should be set") {
        REQUIRE(lRoot["testSec"]["content"]("double").valDouble() > 5.0);
        REQUIRE(lRoot["testSec"]["content"]("double").valDouble() < 5.2);
        REQUIRE(lRoot["testSec"]["content"]("str").valStr() == "Hello World");
        REQUIRE(lRoot["testSec"]["content"]("int").valInt() == 42l);
      }
    }
  }
}
