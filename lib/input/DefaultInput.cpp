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

#include "spvCfg.hpp"
#include "DefaultInput.hpp"
#include <iostream>
#include <tuple>

#if STD_FILESYSTEM_IS_EXPERIMENTAL
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#else
#include <filesystem>
namespace fs = std::filesystem;
#endif

using namespace spirvPacker;
using namespace std;

bool DefaultInput::initializeStage() {
  auto &lCfg = getStageBaseConfigSection();

  lCfg.addEntry("baseName", ""_str);
  lCfg.addEntry("directory", ""_str, [](ConfigEntry const *e) { return !e->valStr().empty(); });

  auto &lExtSec = lCfg.addSection("extensions");
  lExtSec.addArrayEntry("vertex", {ConfigEntry::STR_TYPE, {"vert"_str}});
  lExtSec.addArrayEntry("tessControl", {ConfigEntry::STR_TYPE, {"tese"_str}});
  lExtSec.addArrayEntry("tessEval", {ConfigEntry::STR_TYPE, {"tesc"_str}});
  lExtSec.addArrayEntry("geometry", {ConfigEntry::STR_TYPE, {"geom"_str}});
  lExtSec.addArrayEntry("fragment", {ConfigEntry::STR_TYPE, {"frag"_str}});
  lExtSec.addArrayEntry("compute", {ConfigEntry::STR_TYPE, {"comp"_str}});

  return true;
}

StageResult DefaultInput::run(Shader *_shader) {
  auto  lLogger = getLogger();
  auto &lCfg    = getStageBaseConfigSection();
  auto &lExtSec = lCfg["extensions"];

  string lName = lCfg("baseName").valStr();
  if (lName.empty()) {
    lName = getRootConfigSection()["base"]("name").valStr();
  }

  string   lDir     = lCfg("directory").valStr();
  fs::path lDirPath = lDir;
  if (!fs::exists(lDirPath) || !fs::is_directory(lDirPath)) {
    lLogger->error("Directory '{}' does not exist", lDir);
    return StageResult::IO_ERROR;
  }

  for (auto i : ShaderModule::getAllShaderTypes()) {
    auto &         lEntry = lExtSec(ShaderModule::shaderType2Str(i));
    vector<string> lExts;

    // Extract extensions from the config
    for (size_t j = 0; j < lEntry.size(); ++j)
      lExts.push_back(get<string>(lEntry[j]));

    for (auto j : lExts) {
      fs::path lToTest = lDir + "/" + lName + "." + j;
      if (fs::exists(lToTest) && fs::is_regular_file(lToTest)) {
        lLogger->info("Found module {}", lToTest.string());
        ShaderModule &lModule = _shader->getModule(i);

        try {
          lModule.setSourceCode(readSourceContent(lToTest.string()));
        } catch (...) { return StageResult::IO_ERROR; }

        lModule.setType(i);
      }
    }
  }

  return StageResult::SUCCESS;
}
