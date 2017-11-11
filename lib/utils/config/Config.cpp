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
#include "Config.hpp"
#include <algorithm>
#include <iostream>

using namespace spirvPacker;
using namespace std;

ConfigNode::ConfigNode(ConfigNode *_parent, std::string _name) : vParent(_parent), vName(_name) {}
ConfigNode::~ConfigNode() {}

std::string ConfigNode::genPath() const noexcept {
  if (!vParent)
    return vName;

  return vParent->genPath() + "." + vName;
}




ConfigEntry::ConfigEntry(ConfigNode *_parent, std::string _name, VAL_TYPE _devVal, FUNCTION _validate)
    : ConfigNode(_parent, _name), vDefaultValue(_devVal), vValue(vDefaultValue), vValidata(_validate) {}

ConfigEntry &ConfigEntry::operator=(VAL_TYPE const &_val) {
  vValue = _val;

  if (!validate()) {
    vValue = vDefaultValue;
    throw std::runtime_error("Validation for config entry '" + genPath() + "' failed");
  }
  return *this;
}

bool ConfigEntry::accept(ConfigVisitor *_vis) { return _vis->visit(this); }

bool ConfigEntry::validate() const {
  if (vValue.index() != vDefaultValue.index()) {
    std::cerr << "Config validation failed: Invalid type for " << genPath() << std::endl;
    return false;
  }

  bool lRes = vValidata(this);

  if (!lRes)
    std::cerr << "Config validation failed: Custom validation function failed for " << genPath() << std::endl;

  return lRes;
}



ConfigSection::ConfigSection(ConfigNode *_parent, std::string _name) : ConfigNode(_parent, _name) {}
ConfigSection::ConfigSection(std::string _name) : ConfigNode(nullptr, _name) {}

ConfigEntry &ConfigSection::operator()(std::string _name) {
  auto lFindRes = find_if(begin(vEntries), end(vEntries), [=](auto const &t) { return _name == t.getName(); });

  if (lFindRes == end(vEntries))
    throw std::runtime_error("Config entry '" + _name + "' does not exist in '" + genPath() + "' failed");

  return *lFindRes;
}

ConfigSection &ConfigSection::operator[](std::string _name) {
  auto lFindRes = find_if(begin(vSubSections), end(vSubSections), [=](auto const &t) { return _name == t.getName(); });

  if (lFindRes == end(vSubSections))
    throw std::runtime_error("Subsection '" + _name + "' does not exist in '" + genPath() + "' failed");

  return *lFindRes;
}

bool ConfigSection::accept(ConfigVisitor *_vis) {
  if (_vis->visitEnter(this)) {

    for (auto &i : vEntries)
      if (!i.accept(_vis))
        return _vis->visitLeave(this);

    for (auto &i : vSubSections)
      if (!i.accept(_vis))
        return _vis->visitLeave(this);
  }

  return _vis->visitLeave(this);
}

bool ConfigSection::validate() const {
  for (auto const &i : vSubSections)
    if (!i.validate())
      return false;

  for (auto const &i : vEntries)
    if (!i.validate())
      return false;

  return true;
}

ConfigEntry &ConfigSection::addEntry(std::string           _name,
                                     ConfigEntry::VAL_TYPE _devVal,
                                     ConfigEntry::FUNCTION _validate) {
  auto lFindRes = find_if(begin(vEntries), end(vEntries), [=](auto const &t) { return _name == t.getName(); });

  if (lFindRes == end(vEntries)) {
    vEntries.emplace_back(this, _name, _devVal, _validate);
    return vEntries.back();
  }

  return *lFindRes;
}

ConfigSection &ConfigSection::addSection(std::string _name) {
  auto lFindRes = find_if(begin(vSubSections), end(vSubSections), [=](auto const &t) { return _name == t.getName(); });

  if (lFindRes == end(vSubSections)) {
    vSubSections.push_back(ConfigSection(this, _name));
    return vSubSections.back();
  }

  return *lFindRes;
}
