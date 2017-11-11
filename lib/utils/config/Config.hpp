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
#include "ConfigVisitor.hpp"
#include <functional>
#include <string>
#include <variant>
#include <vector>

namespace spirvPacker {

// Prevent string casting to bool in variant asignment
inline std::string operator"" _str(const char *s) { return std::string(s); }
inline std::string operator"" _str(const char *s, std::size_t) { return std::string(s); }

class ConfigNode {
 protected:
  ConfigNode *vParent = nullptr;
  std::string vName;

 public:
  ConfigNode() = delete;
  ConfigNode(ConfigNode *vParent, std::string _name);
  virtual ~ConfigNode();

  ConfigNode(ConfigNode const &) = default;
  ConfigNode &operator=(const ConfigNode &) = default;

  ConfigNode(ConfigNode &&) = default;
  ConfigNode &operator=(ConfigNode &&) = default;

  virtual bool       validate() const        = 0;
  virtual bool       accept(ConfigVisitor *) = 0;
  inline std::string getName() const noexcept { return vName; }
  inline ConfigNode *getParent() const noexcept { return vParent; }
  std::string        genPath() const noexcept;
};



class ConfigEntry final : public ConfigNode {
 public:
  typedef std::function<bool(ConfigEntry const *)>          FUNCTION;
  typedef std::variant<std::string, long int, double, bool> VAL_TYPE;

 private:
  VAL_TYPE vDefaultValue;
  VAL_TYPE vValue;
  FUNCTION vValidata;

 public:
  ConfigEntry(ConfigNode *_parent, std::string _name, VAL_TYPE _devVal, FUNCTION _validate);

  ConfigEntry(ConfigEntry const &) = default;
  ConfigEntry &operator=(const ConfigEntry &) = default;

  ConfigEntry(ConfigEntry &&) = default;
  ConfigEntry &operator=(ConfigEntry &&) = default;

  ConfigEntry &operator=(const VAL_TYPE &_val);

  inline VAL_TYPE defaultValue() const noexcept { return vDefaultValue; }
  inline VAL_TYPE value() const noexcept { return vValue; }
  inline VAL_TYPE operator*() const noexcept { return vValue; }

  bool accept(ConfigVisitor *_vis) override;
  bool validate() const override;
};



class ConfigSection final : public ConfigNode {
 private:
  std::vector<ConfigSection> vSubSections;
  std::vector<ConfigEntry>   vEntries;

  ConfigSection(ConfigNode *_parent, std::string _name);

 public:
  ConfigSection(std::string _name = "config");

  ConfigSection(ConfigSection const &) = default;
  ConfigSection &operator=(const ConfigSection &) = default;

  ConfigSection(ConfigSection &&) = default;
  ConfigSection &operator=(ConfigSection &&) = default;

  ConfigSection &operator[](std::string _name);
  ConfigEntry &  operator()(std::string _name);

  ConfigEntry &addEntry(std::string           _name,
                        ConfigEntry::VAL_TYPE _devVal,
                        ConfigEntry::FUNCTION _validate = [](ConfigEntry const *) { return true; });

  ConfigSection &addSection(std::string _name);

  bool accept(ConfigVisitor *_vis) override;
  bool validate() const override;
};

} // namespace spirvPacker
