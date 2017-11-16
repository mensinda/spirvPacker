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
#include "StageBase.hpp"

using namespace spirvPacker;

StageBase::~StageBase() {}

/*!
 * \fn StageBase::getName
 * \brief Returns the name of the stage
 */

/*!
 * \fn StageBase::getStageType
 * \brief Returns the type of the stage
 */

/*!
 * \fn StageBase::run
 * \brief Executes the processing stage
 * \param _shader The shader to process
 *
 * \note Implementations of this function should only rely on the state stored in _shader
 *
 * \returns StageResult::SUCCESS on success
 */

/*!
 * \brief Initializes the stage
 * \param _rootCfg The root of the config tree
 */
bool StageBase::initialize(std::shared_ptr<ConfigSection> _rootCfg) {
  vRootCfg = _rootCfg;
  if (!vRootCfg) {
    //! \todo log
    return false;
  }

  getStageBaseConfigSection(); // generate the config section for the stage

  return initializeStage();
}

/*!
 * \brief Returns the root entry of the config tree
 * \throws std::runtime_error when not yet initialized
 */
ConfigSection &StageBase::getRootConfigSection() {
  if (!vRootCfg) {
    throw std::runtime_error(getName() + " not yet initialized");
  }

  return *vRootCfg;
}

std::string StageBase::stageTypeToString(StageType _type) {
  switch (_type) {
    case StageType::INPUT_FINDER: return "input";
    case StageType::COMPILER: return "compiler";
    case StageType::OPTIMIZER: return "optimizer";
    case StageType::DISASSEMBLE: return "disassemble";
    case StageType::INTERPRETER: return "interpreter";
    case StageType::GENERATOR: return "generator";
  }
  return "<UNKNOWN>"; // should be unreachable but gcc complains
}

/*!
 * \brief Returns the base config section of the stage
 * \throws std::runtime_error when not yet initialized
 */
ConfigSection &StageBase::getStageBaseConfigSection() {
  if (!vRootCfg) {
    throw std::runtime_error(getName() + " not yet initialized");
  }

  std::string lCategoryName = stageTypeToString(getStageType());

  // Add section wil also return an already existing section
  return vRootCfg->addSection(lCategoryName).addSection(getName());
}
