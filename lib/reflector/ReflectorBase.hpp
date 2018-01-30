/*
 * Copyright (C) 2018 Daniel Mensinger
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

/*!
 * \brief Base class for all reflectors
 *
 * The run method runs the following virtual functions in this order:
 *  1. reflectModule() // for every shader module
 *  2. reflectShader() // to combine generated information from every module
 */
class ReflectorBase : public StageBase {
 public:
  ReflectorBase() = default;
  ~ReflectorBase() override;

  virtual StageResult reflectModule(ShaderModule &_mod) = 0;
  virtual StageResult reflectShader(Shader *_shader)    = 0;

  inline StageType getStageType() const noexcept override { return StageType::REFLECTOR; }
  StageResult      run(Shader *_shader) override;
};

} // namespace spirvPacker
