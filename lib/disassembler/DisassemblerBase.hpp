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
#include "StageBase.hpp"

namespace spirvPacker {

class DisassemblerBase : public StageBase {
 public:
  DisassemblerBase() = default;
  ~DisassemblerBase() override;

  virtual StageResult disassembleModule(ShaderModule &_mod) = 0;

  StageType   getStageType() const noexcept override { return StageType::DISASSEMBLER; }
  StageResult run(spirvPacker::Shader *_shader) override;
};

} // namespace spirvPacker
