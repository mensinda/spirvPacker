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
#include "Config.hpp"

#if STD_FILESYSTEM_IS_EXPERIMENTAL
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#else
#include <filesystem>
namespace fs = std::filesystem;
#endif

using spirvPacker::operator""_str;

class TempDir final {
 private:
  int         vCounter = 0;
  std::string vPath    = SOURCE_DIR + "/build/temp"_str;

 public:
  TempDir();
  ~TempDir();

  inline std::string getPath() const noexcept { return vPath; }
};

TempDir::TempDir() {
  fs::path lPath = vPath;
  while (fs::exists(lPath)) {
    vPath = SOURCE_DIR + "/build/temp"_str + std::to_string(vCounter++);
    lPath = vPath;
  }

  fs::create_directory(lPath);
}

TempDir::~TempDir() {
  fs::path lPath = vPath;
  if (fs::exists(lPath))
    fs::remove_all(lPath);
}
