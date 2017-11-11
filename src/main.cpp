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

#include "Config.hpp"
#include "ConfigPrinter.hpp"
#include "SpirvPacker.hpp"
#include <iostream>

using namespace spirvPacker;
using namespace std;

int main(int argc, char *argv[]) {
  SpirvPacker   lPacker;
  ConfigSection lCfg;
  ConfigPrinter lPrinter;

  auto &lSec = lCfg.addSection("basic");
  lSec.addEntry("verbose", false);
  lSec.addEntry("version", false);
  lSec.addEntry("outName", "Help"_str);

  lCfg["basic"]("verbose") = true;

  lCfg.accept(&lPrinter);

  cout << lPrinter.getResult() << endl;

  return lPacker.run(argc, argv) == SpirvExecuteResult::SUCCESS ? 0 : 1;
}
