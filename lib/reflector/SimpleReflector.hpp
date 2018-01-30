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
#include "ReflectorBase.hpp"

namespace spirvPacker {

/*!
 * \brief Simple SPIRV reflector. Useful for extracting uniform and shader input output information
 */
class SimpleReflector : public ReflectorBase {
 protected:
  bool initializeStage() override;

  static void decorate(dis::Decoration *_dec, info::IdInfoSPIRV::DEC_MAP &_out);
  void        getIdInfo(dis::DisassemblyData &_data, ShaderModule::ID_MAP &_map);

 public:
  SimpleReflector() = default;
  ~SimpleReflector() override;

  StageResult reflectModule(ShaderModule &_mod) override;
  StageResult reflectShader(Shader *_shader) override;

  std::string getName() const noexcept override { return "SimpleReflector"; }
};

} // namespace spirvPacker
