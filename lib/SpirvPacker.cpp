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

bool SpirvPacker::initializeStages(std::shared_ptr<Config> _rootCfg) {
  auto lLogger = getLogger();

  if (vIsInitialized) {
    lLogger->error("SpirvPacker is already initialized");
    return false;
  }

  vRootCfg = _rootCfg;

  if (!vRootCfg) {
    lLogger->error("Invalid configuration");
    return false;
  }

  auto &lBase = vRootCfg->addSection("base");
  lBase.addEntry("name", ""_str, [](ConfigEntry const *e) { return !e->valStr().empty(); });

  auto &lStages = vRootCfg->addSection("stages");

  for (StageType i : {StageType::INPUT_FINDER,
                      StageType::COMPILER,
                      StageType::OPTIMIZER,
                      StageType::DISASSEMBLE,
                      StageType::REFLECTOR,
                      StageType::GENERATOR}) {
    lStages.addEntry(StageBase::stageTypeToString(i), ""_str);
  }


  for (auto &i : vStages) {
    if (!i->initialize(_rootCfg)) {
      lLogger->error("Initializing {} stage '{}'", StageBase::stageTypeToString(i->getStageType()), i->getName());
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
  auto lLogger = getLogger();

  if (vIsInitialized) {
    lLogger->error("SpirvPacker is already initialized");
    return false;
  }

  if (!_stage) {
    lLogger->error("Invalid stage pointer");
    return false;
  }

  for (auto &i : vStages) {
    if (i->getName() == _stage->getName()) {
      lLogger->warn("Stage {} already exists", i->getName());
      return false;
    }
  }

  vStages.push_back(_stage);

  return true;
}



SpirvExecuteResult SpirvPacker::run(Shader *_s) {
  auto lLogger = getLogger();

  if (!_s) {
    lLogger->error("Shader may not be nullptr");
    return SpirvExecuteResult::ERROR;
  }

  if (!vRootCfg->validate()) {
    lLogger->error("Invalid configuration");
    return SpirvExecuteResult::INVALID_CONFIG;
  }

  for (StageType i : {StageType::INPUT_FINDER,
                      StageType::COMPILER,
                      StageType::OPTIMIZER,
                      StageType::DISASSEMBLE,
                      StageType::REFLECTOR,
                      StageType::GENERATOR}) {
    string lStageStr = StageBase::stageTypeToString(i);
    string lStageID  = (*vRootCfg)["stages"](lStageStr).valStr();

    if (lStageID.empty())
      continue;

    // Get the stage pointer from the config string
    StageBase *lStage = nullptr;
    auto lFindResult  = find_if(begin(vStages), end(vStages), [=](auto const &t) { return lStageID == t->getName(); });
    if (lFindResult == end(vStages)) {
      lLogger->error("Stage '{}' not found", lStageID);
      return SpirvExecuteResult::STAGE_NOT_FOUND;
    }

    lStage = lFindResult->get();
    if (lStage->getStageType() != i) {
      lLogger->error("Stage '{}' is a {} stage but a {} stage is expected",
                     lStage->getName(),
                     StageBase::stageTypeToString(lStage->getStageType()),
                     lStageStr);
      return SpirvExecuteResult::STAGE_NOT_FOUND;
    }

    // Run the stage
    lLogger->info("Running {} stage: {}", lStageStr, lStageID);

    if (lStage->run(_s) != StageResult::SUCCESS) {
      return SpirvExecuteResult::ERROR;
    }
  }

  return SpirvExecuteResult::SUCCESS;
}
