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
#include "SpirvPacker.hpp"

using namespace spirvPacker;

bool SpirvPacker::initializeStages(std::shared_ptr<ConfigSection> _rootCfg) {
  if (vIsInitialized) {
    //! \todo log this
    return false;
  }

  vRootCfg = _rootCfg;

  if (!vRootCfg) {
    //! \todo log this
    return false;
  }

  auto &lCfgLog = vRootCfg->addSection("logging");
  lCfgLog.addEntry("spdlogLevel", 2l, [](ConfigEntry const *e) { return e->valInt() >= 0 && e->valInt() <= 5; });
  lCfgLog.addEntry("enable", true);
  lCfgLog.addEntry("writeToFile", false);
  lCfgLog.addEntry("logFile", ""_str);

  for (auto &i : vStages) {
    if (!i->initialize(_rootCfg)) {
      //! \todo log this
      return false;
    }
  }

  vIsInitialized = true;
  return true;
}

/*!
 * \brief Adds a stage to the packer process
 */
bool SpirvPacker::addStage(std::shared_ptr<StageBase> _stage) {
  if (vIsInitialized) {
    //! \todo log
    return false;
  }

  if (!_stage) {
    //! \todo log this
    return false;
  }

  for (auto &i : vStages) {
    if (i->getName() == _stage->getName()) {
      //! \todo log this
      return false;
    }
  }

  vStages.push_back(_stage);

  return true;
}



SpirvExecuteResult SpirvPacker::run(int argc, char *argv[]) {
  auto lRes = vCMDParser.parse(argc, argv);
  switch (lRes) {
    case CMDParseResult::ERROR: return SpirvExecuteResult::ERROR;
    case CMDParseResult::EXIT_OK: return SpirvExecuteResult::SUCCESS;
    case CMDParseResult::OK: break;
  }

  return SpirvExecuteResult::SUCCESS;
}
