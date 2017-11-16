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

/*!
 * \brief Default input finder
 *
 * Searches for all shader stage files in a directory. This is done by looking for files with the format
 * [baseName].extension .
 *
 * The shader stage is also automatically determined by the file extension
 *
 * ### Config:
 *
 * Configuration structure for "input.defaultInput"
 *
 * |  value    |  Type  |  Description                                                                      |
 * | :-------- | :----: | :-------------------------------------------------------------------------------- |
 * | baseName  | String | base filename of the shader. The Shader name ("base.name") will be used if empty  |
 * | directory | String | Directory where to search for the files. Value may not be empty                   |
 * | extensions.vertex      | String Array | Extensions for the vertex shader stage                 |
 * | extensions.tessControl | String Array | Extensions for the tesselation control shader stage    |
 * | extensions.tessEval    | String Array | Extensions for the tesselation evaluation shader stage |
 * | extensions.geometry    | String Array | Extensions for the geometry shader stage               |
 * | extensions.fragment    | String Array | Extensions for the fragment shader stage               |
 * | extensions.compute     | String Array | Extensions for the compute shader stage                |
 */
class DefaultInput final : public StageBase {
 public:
  inline StageType   getStageType() const noexcept override { return StageType::INPUT_FINDER; }
  inline std::string getName() const noexcept override { return "defaultInput"; }

  bool        initializeStage() override;
  StageResult run(Shader *_shader) override;
};

} // namespace spirvPacker
