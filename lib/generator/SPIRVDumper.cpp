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
#include "SPIRVDumper.hpp"
#include <string.h>

#if STD_FILESYSTEM_IS_EXPERIMENTAL
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#else
#include <filesystem>
namespace fs = std::filesystem;
#endif

using namespace spirvPacker;

SPIRVDumper::~SPIRVDumper() {}

bool SPIRVDumper::initializeStage() {
  auto &lCfg = getStageBaseConfigSection();
  lCfg.addEntry("directory", ""_str, [](ConfigEntry const *e) { return !e->valStr().empty(); });

  return true;
}

StageResult SPIRVDumper::run(Shader *_shader) {
  auto &lRoot   = getRootConfigSection();
  auto &lCfg    = getStageBaseConfigSection();
  auto  lLogger = getLogger();
  if (!_shader) {
    lLogger->error("Invalid shader pointer");
    return StageResult::ERROR;
  }

  std::string lDir     = lCfg("directory").valStr();
  fs::path    lDirPath = lDir;

  if (!fs::exists(lDirPath) || !fs::is_directory(lDirPath)) {
    lLogger->error("Output directory '{}' does not exist.", lDirPath.string());
    return StageResult::IO_ERROR;
  }

  for (auto i : ShaderModule::getAllShaderTypes()) {
    auto &                 lStage = _shader->getModule(i);
    std::vector<uint32_t> &lData  = lStage.getSPIRVBinaryRef();

    if (lData.empty())
      continue;

    std::string lBinData;
    std::string lFileName = lRoot["base"]("name").valStr() + "." + lStage.shaderType2Str(i) + ".spirv";
    lBinData.resize(lData.size() * sizeof(uint32_t));
    memcpy(lBinData.data(), lData.data(), lData.size() * sizeof(uint32_t));
    if (!writeFile(lDir + "/" + lFileName, lBinData)) {
      lLogger->error("Generation failed");
      return StageResult::IO_ERROR;
    }
  }

  return StageResult::SUCCESS;
}
