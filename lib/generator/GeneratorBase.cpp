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
#include "GeneratorBase.hpp"

using namespace spirvPacker;

GeneratorBase::~GeneratorBase() {}

bool GeneratorBase::writeFile(std::string _filePath, const std::string &_data) {
  FILE *fp = fopen(_filePath.c_str(), "wb");

  if (!fp) {
    getLogger()->error("Failed to open '{}' for writing", _filePath);
    return false;
  }

  fwrite(_data.data(), 1, _data.size(), fp);
  fclose(fp);
  return true;
}
