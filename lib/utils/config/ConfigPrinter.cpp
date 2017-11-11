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
#include "ConfigPrinter.hpp"

using namespace spirvPacker;

ConfigPrinter::ConfigPrinter(std::string _indent) : vIndentStr(_indent) {}

bool ConfigPrinter::visit(ConfigEntry *_entry) {
  vData += vIndentStr + "--> ";

  auto lVal = _entry->value();
  auto lDev = _entry->defaultValue();

  if (lVal.index() != lDev.index()) {
    vData += "Inconsistent data.\n";
    return false;
  }

  switch (lVal.index()) {
    case 0:
      vData += "[STRING] " + std::get<0>(lVal) + " (" + std::get<0>(lDev) + ")";
      break; // std::string
    case 1:
      vData += "[L INT]  " + std::to_string(std::get<1>(lVal)) + " (" + std::to_string(std::get<1>(lDev)) + ")";
      break; // long int
    case 2:
      vData += "[DOUBLE] " + std::to_string(std::get<2>(lVal)) + " (" + std::to_string(std::get<2>(lDev)) + ")";
      break; // double
    case 3:
      vData += "[BOOL]   ";
      vData += std::get<3>(lVal) ? "true " : "false";
      vData += " (";
      vData += (std::get<3>(lDev) ? "true" : "false");
      vData += ")";
      break; // bool
    default: vData += "[UNKNOWN]";
  }

  vData += "\n";
  return true;
}

bool ConfigPrinter::visitEnter(ConfigSection *_section) {
  vData += vCurrIndent + _section->getName() + ":\n";
  vCurrIndent += vIndentStr;
  return true;
}

bool ConfigPrinter::visitLeave(ConfigSection *) {
  // Something went wrong...
  if (vCurrIndent.size() < vIndentStr.size())
    return false;

  vCurrIndent.resize(vCurrIndent.size() - vIndentStr.size());
  return true;
}

std::string ConfigPrinter::getResult() const noexcept { return vData; }

void ConfigPrinter::reset() noexcept {
  vCurrIndent.clear();
  vData.clear();
}
