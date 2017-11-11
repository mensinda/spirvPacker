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
#include "CommandLineParser.hpp"
#include "StringHash.hpp"
#include <iostream>

using namespace spirvPacker;
using namespace std;

void CommandLineParser::printUsage() {
  cout << "spirvPacker [options]" << endl
       << endl
       << "Options:" << endl
       << "  -h       | --help           Print this help message and exit" << endl
       << "  -v       | --version        Print the version and exit" << endl
       << "  -c <cfg> | --config <cfg>   Load the config file <cfg>" << endl
       << endl;
}

void CommandLineParser::printVersion() {
  cout << "spirvPacker Version: " << SPIRV_PACKER_VERSION_MAJOR << "." << SPIRV_PACKER_VERSION_MINOR << "."
       << SPIRV_PACKER_VERSION_PATCH << " +" << SPIRV_PACKER_LAST_TAG_DIFF << " [" << SPIRV_PACKER_COMMIT << "]"
       << endl;
}



CMDParseResult CommandLineParser::parse(vector<string> _params) {
  for (auto &i : _params) {
    switch (hashFunc(i.c_str(), i.size())) {
      case "-h"_h:
      case "--help"_h: printUsage(); return CMDParseResult::EXIT_OK;

      case "-v"_h:
      case "--version"_h: printVersion(); return CMDParseResult::EXIT_OK;

      case "-c"_h:
      case "--config"_h: break;

      default:
        cerr << "ERROR: Unknown parameter: " << i << endl;
        printUsage();
        return CMDParseResult::ERROR;
    }
  }

  return CMDParseResult::OK;
}

CMDParseResult CommandLineParser::parse(int argc, char *argv[]) {
  vector<string> lParams;

  for (int i = 1; i < argc; ++i)
    lParams.emplace_back(argv[i]);

  return parse(lParams);
}
