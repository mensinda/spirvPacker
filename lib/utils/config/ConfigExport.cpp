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

#include "ConfigExport.hpp"

#define GET(type, val) std::get<ConfigEntry::type>(val)

using namespace spirvPacker;

ConfigExport::ConfigExport() { reset(); }
std::string ConfigExport::getResult(int _indent, char _char) const noexcept { return vRoot.dump(_indent, _char); }
void        ConfigExport::reset() noexcept {
  vStack = std::stack<json *>();
  vRoot  = json({});
  vStack.push(&vRoot);
}

bool ConfigExport::visit(ConfigEntry *_entry) {
  auto  lValue = _entry->value();
  json *lCurr  = vStack.top();
  json &lEntry = (*lCurr)[_entry->getName()];

  switch (lValue.index()) {
    case ConfigEntry::STR_TYPE: lEntry = GET(STR_TYPE, lValue); break;
    case ConfigEntry::INT_TYPE: lEntry = GET(INT_TYPE, lValue); break;
    case ConfigEntry::DOUBLE_TYPE: lEntry = GET(DOUBLE_TYPE, lValue); break;
    case ConfigEntry::BOOL_TYPE: lEntry = GET(BOOL_TYPE, lValue); break;
    case ConfigEntry::ARRAY_TYPE:
      lEntry = json(json::value_t::array);
      for (auto &i : GET(ARRAY_TYPE, lValue).array) {
        switch (GET(ARRAY_TYPE, lValue).index) {
          case ConfigEntry::STR_TYPE: lEntry.push_back(GET(STR_TYPE, i)); break;
          case ConfigEntry::INT_TYPE: lEntry.push_back(GET(INT_TYPE, i)); break;
          case ConfigEntry::DOUBLE_TYPE: lEntry.push_back(GET(DOUBLE_TYPE, i)); break;
          case ConfigEntry::BOOL_TYPE: lEntry.push_back(GET(BOOL_TYPE, i)); break;
        }
      }
      break;
  }

  return true;
}

bool ConfigExport::visitEnter(ConfigSection *_section) {
  json *lCurr    = vStack.top();
  json &lNextSec = (*lCurr)[_section->getName()];
  lNextSec       = json({});

  vStack.push(&lNextSec);
  return true;
}

bool ConfigExport::visitLeave(ConfigSection *) {
  vStack.pop();
  return true;
}
