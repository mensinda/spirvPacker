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

#pragma once

#include "spvCfg.hpp"
#include "Config.hpp"
#include "Shader.hpp"
#include <memory>

namespace spirvPacker {

enum class StageType {
  INPUT_FINDER, //!< \brief Assembles the input files of the shader
  COMPILER,     //!< \brief Compiles the source code into SPIR-V
  OPTIMIZER,    //!< \brief Optimizes the compiled SPIR-V binary
  DISASSEMBLER, //!< \brief Disassembles the compiled SPIR-V binary into data structures
  REFLECTOR,    //!< \brief Reflects on the disassembled code and generates more useful data for the generators
  GENERATOR     //!< \brief Generates the output
};

enum class StageResult {
  SUCCESS,                //!< \brief Everything went fine
  ERROR,                  //!< \brief Some generic error occurred.
  DATA_MISSING,           //!< \brief A previous stage was skipped or has not written any / enough data.
  IO_ERROR,               //!< \brief Reading / writing data failed
  COMPILER_ERROR,         //!< \brief compiling the shader stages failed
  LINKER_ERROR,           //!< \brief Linking the shader stages failed
  DISASSEMBLER_ERROR,     //!< \brief Disassembling SPIR-V binary data failed
  INVALID_SPIRV,          //!< \brief The SPIR-V binary data is not valid
  REFLECTOR_ERROR,        //!< \brief The Reflector stage encounterd a problem
  PREVIOUS_STAGE_MISSING, //!< \brief The stage requires the results of a previous stage
};

/*!
 * \brief Base class for all processing stages.
 *
 * See StageType for all available types.
 *
 * Furthermore, a processing stage should not store any state between runs. All the necessary state must be stored in
 * the shader object.
 */
class StageBase {
 private:
  std::shared_ptr<Config> vRootCfg = nullptr;

 protected:
  virtual bool initializeStage() = 0;

 public:
  StageBase() = default;
  virtual ~StageBase();

  virtual std::string getName() const noexcept      = 0;
  virtual StageType   getStageType() const noexcept = 0;
  virtual StageResult run(Shader *_shader)          = 0;

  bool initialize(std::shared_ptr<Config> _rootCfg);

  static std::string stageTypeToString(StageType _type);

  ConfigSection &getStageBaseConfigSection();
  Config &       getRootConfigSection();
};

} // namespace spirvPacker
