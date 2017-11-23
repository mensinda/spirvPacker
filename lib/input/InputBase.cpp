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
#include "InputBase.hpp"

using namespace spirvPacker;
using namespace std;

/*!
 * \brief Trys to read the source file content
 * \returns The source file content
 * \throws std::runtime_error When opening the file fails
 */
string InputBase::readSourceContent(string _file) {
  FILE *fp = fopen(_file.c_str(), "rb");

  if (!fp)
    throw std::runtime_error("Unable to read source file " + _file);

  string lContents;
  fseek(fp, 0, SEEK_END);
  lContents.resize(static_cast<size_t>(ftell(fp)));
  rewind(fp);
  fread(&lContents[0], 1, lContents.size(), fp);
  fclose(fp);
  return lContents;
}
