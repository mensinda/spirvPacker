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

namespace spirvPacker {

class ConfigEntry;
class ConfigSection;

class ConfigVisitor {
 public:
  ConfigVisitor() = default;
  virtual ~ConfigVisitor();

  virtual bool visit(ConfigEntry *)        = 0;
  virtual bool visitEnter(ConfigSection *) = 0;
  virtual bool visitLeave(ConfigSection *) = 0;
};

} // namespace spirvPacker
