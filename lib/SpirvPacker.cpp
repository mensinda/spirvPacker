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
#include <algorithm>
#include <iostream>

using namespace spirvPacker;
using namespace std;

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

  auto &lBase = vRootCfg->addSection("base");
  lBase.addEntry("name", ""_str, [](ConfigEntry const *e) { return !e->valStr().empty(); });

  auto &lStages = vRootCfg->addSection("stages");

  for (StageType i : {StageType::INPUT_FINDER,
                      StageType::COMPILER,
                      StageType::OPTIMIZER,
                      StageType::DISASSEMBLE,
                      StageType::INTERPRETER,
                      StageType::GENERATOR}) {
    lStages.addEntry(StageBase::stageTypeToString(i), ""_str);
  }


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



SpirvExecuteResult SpirvPacker::run(Shader *_s) {
  if (!_s) {
    cerr << "Shader may not be nullptr" << endl;
    return SpirvExecuteResult::ERROR;
  }

  if (!vRootCfg->validate()) {
    cerr << "Invalid configuration" << endl;
    return SpirvExecuteResult::INVALID_CONFIG;
  }

  for (StageType i : {StageType::INPUT_FINDER,
                      StageType::COMPILER,
                      StageType::OPTIMIZER,
                      StageType::DISASSEMBLE,
                      StageType::INTERPRETER,
                      StageType::GENERATOR}) {
    string lStageStr = StageBase::stageTypeToString(i);
    string lStageID  = (*vRootCfg)["stages"](lStageStr).valStr();

    if (lStageID.empty())
      continue;

    // Get the stage pointer from the config string
    StageBase *lStage = nullptr;
    auto lFindResult  = find_if(begin(vStages), end(vStages), [=](auto const &t) { return lStageID == t->getName(); });
    if (lFindResult == end(vStages)) {
      cerr << "Stage " << lStageID << " not found" << endl;
      return SpirvExecuteResult::STAGE_NOT_FOUND;
    }

    lStage = lFindResult->get();
    if (lStage->getStageType() != i) {
      cerr << "Stage '" << lStage->getName() << "' is a " << StageBase::stageTypeToString(lStage->getStageType())
           << " stage not a " << lStageStr << " stage" << endl;
      return SpirvExecuteResult::STAGE_NOT_FOUND;
    }

    // Run the stage
    cout << "Stage " << lStageStr << ": " << lStageID << endl;

    if (lStage->run(_s) != StageResult::SUCCESS) {
      return SpirvExecuteResult::ERROR;
    }
  }

  return SpirvExecuteResult::SUCCESS;
}
