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

#define GET(type, val) std::get<ConfigEntry::type>(val)

using namespace spirvPacker;

ConfigPrinter::ConfigPrinter(std::string _indent) : vIndentStr(_indent) {}

bool ConfigPrinter::visit(ConfigEntry *_entry) {
  vData += vCurrIndent + "--> ";

  auto lVal = _entry->value();
  auto lDev = _entry->defaultValue();

  if (lVal.index() != lDev.index()) {
    vData += "Inconsistent data.\n";
    return false;
  }

  switch (lVal.index()) {
    case ConfigEntry::STR_TYPE:
      vData += "[STRING] " + _entry->getName() + ": ";
      vData += "\'" + GET(STR_TYPE, lVal) + "\' (\'" + GET(STR_TYPE, lDev) + "\')";
      break; // std::string
    case ConfigEntry::INT_TYPE:
      vData += "[L INT]  " + _entry->getName() + ": ";
      vData += std::to_string(GET(INT_TYPE, lVal)) + " (" + std::to_string(GET(INT_TYPE, lDev)) + ")";
      break; // long int
    case ConfigEntry::DOUBLE_TYPE:
      vData += "[DOUBLE] " + _entry->getName() + ": ";
      vData += std::to_string(GET(DOUBLE_TYPE, lVal)) + " (" + std::to_string(GET(DOUBLE_TYPE, lDev)) + ")";
      break; // double
    case ConfigEntry::BOOL_TYPE:
      vData += "[BOOL]   " + _entry->getName() + ": ";
      vData += GET(BOOL_TYPE, lVal) ? "true " : "false";
      vData += " (";
      vData += GET(BOOL_TYPE, lDev) ? "true" : "false";
      vData += ")";
      break; // bool
    case ConfigEntry::ARRAY_TYPE:
      vData += "[ARRAY]  " + _entry->getName() + ": (size: " + std::to_string(_entry->size()) + ")\n";
      for (auto &i : GET(ARRAY_TYPE, lVal).array) {
        vData += vCurrIndent + vIndentStr + "- ";

        switch (GET(ARRAY_TYPE, lVal).index) {
          case ConfigEntry::STR_TYPE:
            vData += "\'" + GET(STR_TYPE, i) + "\'";
            break; // std::string
          case ConfigEntry::INT_TYPE:
            vData += std::to_string(GET(INT_TYPE, i));
            break; // long int
          case ConfigEntry::DOUBLE_TYPE:
            vData += std::to_string(GET(DOUBLE_TYPE, i));
            break; // double
          case ConfigEntry::BOOL_TYPE:
            vData += "[BOOL]   " + _entry->getName() + ": ";
            vData += GET(BOOL_TYPE, i) ? "true " : "false";
            break;
        }

        vData += "\n";
      }
      break;
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
