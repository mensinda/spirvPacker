#!/bin/bash

GRAMAR_FILE="../external/spirv/spirv.core.grammar.json"
OUT_FILE="SPIRVOperands.hpp"
CPP_FILE="SPIRVOperands.cpp"

cd "`dirname "$0"`"

cat <<EOF > "$OUT_FILE"
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
/*!
 * \note This is an automatically generated file
 * \warning All changes to this file will be lost
 * Generated with $0
 */

#pragma once

#include "spvCfg.hpp"
#include <string>
#include <vector>
#include <spirv.hpp>

namespace spirvPacker {
namespace dis {

typedef std::vector<uint32_t>::iterator ITER;

enum class Category {
`for i in $(cat "$GRAMAR_FILE" | jq -r '.operand_kinds | .[] | .category' | sort | uniq); do echo "$i,"; done`
};

enum class Kind {
`for i in $(cat "$GRAMAR_FILE" | jq -r '.operand_kinds | .[] | .kind'); do echo "$i,"; done`
};

struct Operand {
  std::string name = "";
  std::string quantifier = "";

  std::vector<std::shared_ptr<Operand>> parameters;

  virtual Category category() const = 0;
  virtual Kind kind() const = 0;
  virtual std::string doc() const = 0;

  virtual uint32_t valInt() const {return UINT32_MAX;}
  virtual std::string valStr() const {return "";}

  Operand(std::string _name, std::string _quan) : name(_name), quantifier(_quan) {}
  virtual ~Operand() {}
};

EOF

cat <<EOF > "$CPP_FILE"
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
/*!
 * \note This is an automatically generated file
 * \warning All changes to this file will be lost
 * Generated with $0
 */

#include "spvCfg.hpp"
#include "$OUT_FILE"
#include "Enum2Str.hpp"

using namespace spirvPacker::dis;

EOF

NUM_INST=`cat "$GRAMAR_FILE" | jq -r '.operand_kinds | .[] | .kind' | wc -l`

I=0
echo ""
while true; do
  CATE=`cat "$GRAMAR_FILE" | jq -r ".operand_kinds | .[$I] | .category"`
  KIND=`cat "$GRAMAR_FILE" | jq -r ".operand_kinds | .[$I] | .kind"`
  DOCS=`cat "$GRAMAR_FILE" | jq -r ".operand_kinds | .[$I] | .doc"`

  if [[ "$CATE" == null || "$KIND" == null ]]; then
    break;
  fi

  [[ "$DOCS" == null ]] && DOCS=""

  cat <<EOF >> "$OUT_FILE"

struct $KIND final : Operand {
EOF

  case $CATE in
    BitEnum)
      echo "uint32_t value;" >> "$OUT_FILE"
      echo "inline uint32_t valInt() const override {return value;}" >> "$OUT_FILE"
      echo "std::string valStr() const override;" >> "$OUT_FILE"
      echo "std::string $KIND::valStr() const {return Enum2Str::spv_${KIND}Mask_toStr(value);}" >> "$CPP_FILE"
      ;;

    ValueEnum)
      echo "spv::${KIND} value;" >> "$OUT_FILE"
      echo "inline uint32_t valInt() const override {return static_cast<uint32_t>(value);}" >> "$OUT_FILE"
      echo "std::string valStr() const override;" >> "$OUT_FILE"
      echo "std::string $KIND::valStr() const {return Enum2Str::toStr(value);}" >> "$CPP_FILE"
      ;;

    Literal)
      echo "std::vector<uint32_t> value;" >> "$OUT_FILE"
      echo "inline uint32_t valInt() const override {return value[0];}" >> "$OUT_FILE"
      echo "std::string valStr() const override;" >> "$OUT_FILE"
      if [[ "$KIND" == "LiteralString" ]]; then
        echo "std::string $KIND::valStr() const {return reinterpret_cast<char const *>(value.data());}" >> "$CPP_FILE"
      else
        echo "std::string $KIND::valStr() const {return std::to_string(value[0]);}" >> "$CPP_FILE"
      fi
      ;;

    Id)
      echo "uint32_t value;" >> "$OUT_FILE"
      echo "inline uint32_t valInt() const override {return value;}" >> "$OUT_FILE"
      echo "std::string valStr() const override;" >> "$OUT_FILE"
      echo "std::string $KIND::valStr() const {return std::to_string(value);}" >> "$CPP_FILE"
      ;;

    Composite)
      c=0
      for i in `cat "$GRAMAR_FILE" | jq -r ".operand_kinds | .[$I] | .bases | .[]"`; do
        echo "$i value$c = {\"\", \"\"};" >> "$OUT_FILE"
        (( c++ ))
      done
      ;;
  esac

  cat <<EOF >> "$OUT_FILE"

  inline Category category() const override {return Category::$CATE;}
  inline Kind kind() const override {return Kind::$KIND;}
  inline std::string doc() const override {return "$DOCS";}
  $KIND(std::string _name, std::string _quan) : Operand(_name, _quan) {}
};

EOF

  (( I++ ))
  echo -e "\x1b[1F\x1b[2KGenerating operands... `echo "(($I * 100) / $NUM_INST)" | bc`%" 1>&2
done

echo "}}" >> "$OUT_FILE"

clang-format -i "$OUT_FILE"
clang-format -i "$CPP_FILE"
