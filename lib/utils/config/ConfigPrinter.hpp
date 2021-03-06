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

#pragma once

#include "spvCfg.hpp"
#include "Config.hpp"
#include "ConfigVisitor.hpp"

namespace spirvPacker {

class ConfigPrinter final : public ConfigVisitor {
 private:
  std::string vData;
  std::string vCurrIndent;
  std::string vIndentStr;

 public:
  ConfigPrinter(std::string _indent = "  ");

  bool visit(ConfigEntry *_entry) override;
  bool visitEnter(ConfigSection *_section) override;
  bool visitLeave(ConfigSection *_section) override;

  std::string getResult() const noexcept;
  void        reset() noexcept;
};

} // namespace spirvPacker
