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

#include "ConfigImport.hpp"

#define GET(type, val) std::get<ConfigEntry::type>(val)

using namespace spirvPacker;
using namespace std;

ConfigImport::ConfigImport() { reset(); }
void ConfigImport::reset() noexcept {
  vStack = std::stack<json *>();
  vRoot  = json({});
  vStack.push(&vRoot);
}

bool ConfigImport::setRawJSON(std::string _data) noexcept {
  try {
    vRoot = json::parse(_data);
  } catch (json::parse_error e) {
    auto lLogger = getLogger();
    lLogger->error("Failed to parse JSON config imput:");
    lLogger->error(e.what());
    reset();
    return false;
  }

  vStack = std::stack<json *>();
  vStack.push(&vRoot);

  return true;
}


bool ConfigImport::visit(ConfigEntry *_entry) {
  auto  lValue = _entry->value();
  json *lCurr  = vStack.top();

  if (!lCurr || lCurr->count(_entry->getName()) == 0)
    return true;

  json &lEntry = lCurr->at(_entry->getName());

  switch (lValue.index()) {
    case ConfigEntry::STR_TYPE:
      if (lEntry.is_string())
        *_entry = lEntry.get<std::string>();

      break;
    case ConfigEntry::INT_TYPE:
      if (lEntry.is_number())
        *_entry = lEntry.get<long int>();

      break;
    case ConfigEntry::DOUBLE_TYPE:
      if (lEntry.is_number())
        *_entry = lEntry.get<double>();

      break;
    case ConfigEntry::BOOL_TYPE:
      if (lEntry.is_boolean())
        *_entry = lEntry.get<bool>();

      break;
    case ConfigEntry::ARRAY_TYPE:
      if (!lEntry.is_array())
        break;

      _entry->clear();
      auto lLogger = getLogger();
      for (auto i : lEntry) {
        switch (GET(ARRAY_TYPE, lValue).index) {
          case ConfigEntry::STR_TYPE:
            if (i.is_string())
              *_entry += i.get<std::string>();

            break;
          case ConfigEntry::INT_TYPE:
            if (i.is_number())
              *_entry += i.get<long int>();

            break;
          case ConfigEntry::DOUBLE_TYPE:
            if (i.is_number())
              *_entry += i.get<double>();

            break;
          case ConfigEntry::BOOL_TYPE:
            if (i.is_boolean())
              *_entry += i.get<bool>();

            break;
        }
      }
      break;
  }

  return true;
}

bool ConfigImport::visitEnter(ConfigSection *_section) {
  auto  lLogger = getLogger();
  json *lCurr   = vStack.top();

  // Push nullptr if the section does not exist in the JSON or the parent is already nullptr
  if (!lCurr || lCurr->count(_section->getName()) == 0) {
    vStack.push(nullptr);
    return true;
  }
  lLogger->info("ENTER {}", _section->getName());

  vStack.push(&lCurr->at(_section->getName()));
  return true;
}

bool ConfigImport::visitLeave(ConfigSection *_section) {
  auto lLogger = getLogger();
  if (vStack.top())
    lLogger->info("LEAVE {}", _section->getName());

  vStack.pop();
  return true;
}
