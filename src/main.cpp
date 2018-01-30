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
#include "ConfigExport.hpp"
#include "ConfigImport.hpp"
#include "ConfigPrinter.hpp"
#include "DefaultInput.hpp"
#include "Disassembler.hpp"
#include "GLSLangCompiler.hpp"
#include "SPIRVDumper.hpp"
#include "SimpleReflector.hpp"
#include "SpirvPacker.hpp"
#include <iostream>

using namespace spirvPacker;
using namespace std;

int main(int argc, char *argv[]) {
  SpirvPacker   lPacker;
  auto          lCfg = make_shared<Config>();
  ConfigPrinter lPrinter;
  ConfigExport  lExporter;
  ConfigImport  lImporter;
  Shader        lShader;
  auto          lLogger = getLogger();

  (void)argc;
  (void)argv;

  lPacker.addStage(make_shared<DefaultInput>());
  lPacker.addStage(make_shared<GLSLangCompiler>());
  lPacker.addStage(make_shared<SPIRVDumper>());
  lPacker.addStage(make_shared<Disassembler>());
  lPacker.addStage(make_shared<SimpleReflector>());
  lPacker.initializeStages(lCfg);

  (*lCfg)["base"]("name")                          = "triangle1"_str;
  (*lCfg)["stages"]("input")                       = "defaultInput"_str;
  (*lCfg)["stages"]("compiler")                    = "glslang"_str;
  (*lCfg)["stages"]("disassembler")                = "Disassembler"_str;
  (*lCfg)["stages"]("generator")                   = "SPIRVDumper"_str;
  (*lCfg)["stages"]("reflector")                   = "SimpleReflector"_str;
  (*lCfg)["input"]["defaultInput"]("directory")    = SOURCE_DIR + "/test/data"_str;
  (*lCfg)["generator"]["SPIRVDumper"]("directory") = SOURCE_DIR + "/build"_str;

  if (!lCfg->validate()) {
    lLogger->error("Validation of the configuration failed!");
  }

  lLogger->set_level(spdlog::level::debug);

  //   lCfg->accept(&lExporter);
  //   cout << lExporter.getResult() << endl;

  return lPacker.run(&lShader) == SpirvExecuteResult::SUCCESS ? 0 : 1;
}
