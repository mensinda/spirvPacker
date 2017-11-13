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
#include "CommandLineParser.hpp"
#include "Config.hpp"
#include "StageBase.hpp"

namespace spirvPacker {

enum class SpirvExecuteResult { SUCCESS, ERROR };

class SpirvPacker final {
 private:
  CommandLineParser                       vCMDParser;
  std::vector<std::shared_ptr<StageBase>> vStages;
  std::shared_ptr<ConfigSection>          vRootCfg = nullptr;

  bool vIsInitialized = false;

 public:
  SpirvPacker() = default;

  SpirvPacker(SpirvPacker const &) = delete;
  SpirvPacker &operator=(const SpirvPacker &) = delete;

  SpirvPacker(SpirvPacker &&) = delete;
  SpirvPacker &operator=(SpirvPacker &&) = delete;

  bool initializeStages(std::shared_ptr<ConfigSection> _rootCfg);
  bool addStage(std::shared_ptr<StageBase> _stage);

  inline bool getIsInitialized() const noexcept {
    return vIsInitialized;
  } //!< Returns whether all stages are initialzed

  SpirvExecuteResult run(int argc, char *argv[]);
};

} // namespace spirvPacker
