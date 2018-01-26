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

#pragma once

#include "spvCfg.hpp"
#include "Config.hpp"
#include "ConfigVisitor.hpp"
#include "json.hpp"
#include <stack>

namespace spirvPacker {

using json = nlohmann::json;

class ConfigExport final : public ConfigVisitor {
 private:
  json               vRoot = json({});
  std::stack<json *> vStack;

 public:
  ConfigExport();

  bool visit(ConfigEntry *_entry) override;
  bool visitEnter(ConfigSection *_section) override;
  bool visitLeave(ConfigSection *_section) override;

  std::string getResult(int _indent = 2, char _char = ' ') const noexcept;
  void        reset() noexcept;
};

} // namespace spirvPacker
