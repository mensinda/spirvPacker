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
#include <memory>
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

  ConfigNode(ConfigNode const &) = delete;
  ConfigNode &operator=(const ConfigNode &) = delete;

  ConfigNode(ConfigNode &&) = default;
  ConfigNode &operator=(ConfigNode &&) = default;

  virtual bool       validate() const        = 0;
  virtual bool       accept(ConfigVisitor *) = 0;
  inline std::string getName() const noexcept { return vName; }
  inline ConfigNode *getParent() const noexcept { return vParent; }
  std::string        genPath() const noexcept;
};



/*!
 * \brief A config entry. Leave of a config tree
 *
 * The config data is stored in a variant and supports strings, integers, doubles, booleans and arrays
 */
class ConfigEntry final : public ConfigNode {
 public:
  typedef std::variant<std::string, long int, double, bool> ARRAY_VAL_TYPE; //!< Variant type for array elements

  //! \brief Structure for striring array elements
  struct ArrayType {
    size_t                      index; //!< The variant index all array elements must have
    std::vector<ARRAY_VAL_TYPE> array; //!< The elemets
  };

  static const size_t STR_TYPE    = 0; //!< Variant index for std::string
  static const size_t INT_TYPE    = 1; //!< Variant index for long int
  static const size_t DOUBLE_TYPE = 2; //!< Variant index for double
  static const size_t BOOL_TYPE   = 3; //!< Variant index for bool
  static const size_t ARRAY_TYPE  = 4; //!< Variant index for ArrayType

  typedef std::function<bool(ConfigEntry const *)>                     FUNCTION; //!< Custom validation function type
  typedef std::variant<std::string, long int, double, bool, ArrayType> VAL_TYPE; //!< Entry variant type

 private:
  VAL_TYPE vDefaultValue;
  VAL_TYPE vValue;
  FUNCTION vValidata;

 public:
  ConfigEntry(ConfigNode *_parent, std::string _name, VAL_TYPE _devVal, FUNCTION _validate)
      : ConfigNode(_parent, _name), vDefaultValue(_devVal), vValue(vDefaultValue), vValidata(_validate) {}

  ConfigEntry(ConfigEntry const &) = delete;
  ConfigEntry &operator=(const ConfigEntry &) = delete;

  ConfigEntry(ConfigEntry &&) = default;
  ConfigEntry &operator=(ConfigEntry &&) = default;

  inline ConfigEntry &operator=(const VAL_TYPE &_val) {
    vValue = _val;
    return *this;
  }

  inline ConfigEntry &operator+=(const ARRAY_VAL_TYPE &_val) {
    emplace_back(_val);
    return *this;
  }

  inline VAL_TYPE defaultValue() const noexcept { return vDefaultValue; }
  inline VAL_TYPE value() const noexcept { return vValue; }
  inline VAL_TYPE operator*() const noexcept { return vValue; }

  inline std::string valStr() const { return std::get<std::string>(vValue); } //!< Get the value as a string. \throws
  inline long int    valInt() const { return std::get<long int>(vValue); }    //!< Get the value as a int. \throws
  inline double      valDouble() const { return std::get<double>(vValue); }   //!< Get the value as a double. \throws
  inline bool        valBool() const { return std::get<bool>(vValue); }       //!< Get the value as a bool. \throws

  // Array operations only
  inline ARRAY_VAL_TYPE valArray(size_t _i) { return std::get<ArrayType>(vValue).array[_i]; }
  inline size_t         size() const { return std::get<ArrayType>(vValue).array.size(); }
  inline void           clear() { std::get<ArrayType>(vValue).array.clear(); }
  inline bool           empty() const { return size() == 0; }
  inline ARRAY_VAL_TYPE operator[](size_t _i) { return valArray(_i); }

  inline ARRAY_VAL_TYPE emplace_back(ARRAY_VAL_TYPE _value) {
    std::get<ArrayType>(vValue).array.emplace_back(_value);
    return std::get<ArrayType>(vValue).array.back();
  }

  inline bool accept(ConfigVisitor *_vis) override { return _vis->visit(this); }
  bool        validate() const override;
};



class ConfigSection final : public ConfigNode {
 private:
  std::vector<std::unique_ptr<ConfigSection>> vSubSections;
  std::vector<std::unique_ptr<ConfigEntry>>   vEntries;

 public:
  ConfigSection(ConfigNode *_parent, std::string _name);
  ConfigSection(std::string _name = "config");

  ConfigSection(ConfigSection const &) = delete;
  ConfigSection &operator=(const ConfigSection &) = delete;

  ConfigSection(ConfigSection &&) = default;
  ConfigSection &operator=(ConfigSection &&) = default;

  ConfigSection &operator[](std::string _name);
  ConfigEntry &  operator()(std::string _name);

  inline ConfigEntry &addArrayEntry(std::string            _name,
                                    ConfigEntry::ArrayType _devVal,
                                    ConfigEntry::FUNCTION  _validate = [](ConfigEntry const *) { return true; }) {
    return addEntry(_name, _devVal, _validate);
  }

  ConfigEntry &addEntry(std::string           _name,
                        ConfigEntry::VAL_TYPE _devVal,
                        ConfigEntry::FUNCTION _validate = [](ConfigEntry const *) { return true; });

  ConfigSection &addSection(std::string _name);

  bool accept(ConfigVisitor *_vis) override;
  bool validate() const override;
};

} // namespace spirvPacker
