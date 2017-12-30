#!/bin/bash

GRAMAR_FILE="../../../external/spirv/spirv.core.grammar.json"
HPP_FILE="BinaryOpParser.hpp"
CPP_FILE="BinaryOpParser.cpp"

cd "`dirname "$0"`"

SPIRV_VERSION="`jq .major_version $GRAMAR_FILE`.`jq .minor_version $GRAMAR_FILE`.`jq .revision $GRAMAR_FILE`"

cat <<EOF > "$HPP_FILE"
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
 *
 * SPIRV version: $SPIRV_VERSION
 */

#pragma once

#include "spvCfg.hpp"
#include "SPIRVDisassembly.hpp"

namespace spirvPacker {
namespace dis {

typedef std::vector<uint32_t>::iterator ITER;


bool parseInstruction(dis::Instruction &_inst);

// Instructions
`for i in $(jq -r '.instructions  | .[] | .opname' "$GRAMAR_FILE"); do echo "bool parse_$i(dis::Instruction &_inst);"; done`

// Operands
`for i in $(jq -r '.operand_kinds | .[] | .kind'   "$GRAMAR_FILE"); do echo "ITER parse_$i($i &_val, ITER _begin, ITER _end);";  done`

}
}
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
 *
 * SPIRV version: $SPIRV_VERSION
 */

#include "spvCfg.hpp"
#include "$HPP_FILE"

using namespace spirvPacker;
using namespace spirvPacker::dis;
using namespace std;

#define PARSE_PARAM(CURR, END, ARR, KIND, NAME)                                                                        \
  if (CURR >= END)                                                                                                     \
    return END + 1;                                                                                                    \
  ARR.push_back(make_shared<KIND>(NAME, ""));                                                                          \
  CURR = parse_##KIND(static_cast<KIND &>(*ARR.back()), CURR, END);

#define PARSE_NORMAL(CURR, END, ARR, KIND, NAME)                                                                       \
  if (CURR >= END)                                                                                                     \
    return false;                                                                                                      \
  ARR.push_back(make_shared<KIND>(NAME, ""));                                                                          \
  CURR = parse_##KIND(static_cast<KIND &>(*ARR.back()), CURR, END);

#define PARSE_ONE(CURR, END, ARR, KIND, NAME)                                                                          \
  if (CURR >= END)                                                                                                     \
    return true;                                                                                                       \
  ARR.push_back(make_shared<KIND>(NAME, "?"));                                                                         \
  CURR = parse_##KIND(static_cast<KIND &>(*ARR.back()), CURR, END);

#define PARSE_MULT(CURR, END, ARR, KIND, NAME)                                                                         \
  while (CURR < END) {                                                                                                 \
    ARR.push_back(make_shared<KIND>(NAME, "*"));                                                                       \
    CURR = parse_##KIND(static_cast<KIND &>(*ARR.back()), CURR, END);                                                  \
  }

bool spirvPacker::dis::parseInstruction(Instruction &_inst) {
  switch(_inst.op) {
`for i in $(jq -r '.instructions | .[] | .opname' "$GRAMAR_FILE"); do echo "case spv::Op::$i: return parse_$i(_inst);"; done`
default: return false;
  }
}

EOF

# | jq -r '.operand_kinds | .[] | select(.kind == "ImageOperands")'

NUM_INST=`jq -r '.instructions  | .[] | .opname' "$GRAMAR_FILE" | wc -l`
NUM_OPER=`jq -r '.operand_kinds | .[] | .kind'   "$GRAMAR_FILE" | wc -l`
NUM_ALL=$(( NUM_INST + NUM_OPER ))

getValue() {
  if [[ "${1/$2/}" == "$1" ]]; then
    declare -g $3=""
  else
    TEMP="${1#*$2\":}"
    TEMP="${TEMP#*\"}"
    TEMP="${TEMP%%\"*}"
    declare -g $3="$TEMP"
  fi
}

echo ""

#################################
#### Generate operand parser ####
#################################

declare -A OPERANDS

I=0
while true; do
  OP=`jq -c ".operand_kinds | .[$I]" "$GRAMAR_FILE"`
  (( I++ ))
  [[ "$OP" == null ]] && break

  getValue "$OP" category CATE
  getValue "$OP" kind     KIND
  OPERANDS[$KIND]="$OP"

  echo "ITER spirvPacker::dis::parse_$KIND($KIND &_val, ITER _pos, ITER _end) {"
  echo "(void)_end;"

  case $CATE in
    BitEnum)
      echo -e "_val.value = *(_pos++);"
      J=0
      while true; do
        ENUM=`echo "$OP" | jq -c ".enumerants | .[$J]"`
        (( J++ ))
        [[ "$ENUM"                   == null    ]] && break
        [[ "${ENUM/\"parameters\"/}" == "$ENUM" ]] && continue # Check if the enum has parameters

        PARAM_KINDS=(`echo "$ENUM" | jq -r ".parameters | .[] | .kind"`)
        PARAM_NAMES=(`echo "$ENUM" | jq -r ".parameters | .[] | .name"`)

        getValue "$ENUM" enumerant EN
        echo "if(_val.value & static_cast<uint32_t>(spv::${KIND}Mask::$EN)) {"

        for (( K=0; K < ${#PARAM_KINDS[@]}; K++ )); do
          NAME="${PARAM_NAMES[$K]}"
          [[ "$NAME" == null ]] && NAME=""
          NAME="${NAME//\'/}"
          echo "PARSE_PARAM(_pos, _end, _val.parameters, ${PARAM_KINDS[$K]}, \"$NAME\")"
        done

        echo "}"
      done
      ;;

    ValueEnum)
      echo -e "_val.value = static_cast<spv::${KIND}>(*(_pos++));\n"
      if [[ "${OP/\"parameters\"/}" != "$OP" ]]; then # Check that the entire enum has at least one parameter

        echo -e "switch(_val.value) {"
        J=0
        while true; do
          ENUM=`echo "$OP" | jq -c ".enumerants | .[$J]"`
          (( J++ ))
          [[ "$ENUM"                   == null    ]] && break
          [[ "${ENUM/\"parameters\"/}" == "$ENUM" ]] && continue # Check if the enum has parameters

          PARAM_KINDS=(`echo "$ENUM" | jq -r ".parameters | .[] | .kind"`)
          PARAM_NAMES=(`echo "$ENUM" | jq -r ".parameters | .[] | .name"`)

          getValue "$ENUM" enumerant EN
          echo "case spv::${KIND}::$EN:"
          for (( K=0; K < ${#PARAM_KINDS[@]}; K++ )); do
            NAME="${PARAM_NAMES[$K]}"
            [[ "$NAME" == null ]] && NAME=""
            NAME="${NAME//\'/}"
            echo "PARSE_PARAM(_pos, _end, _val.parameters, ${PARAM_KINDS[$K]}, \"$NAME\")"
          done
          echo "break;"

        done
        echo -e "default: break;\n}"
      fi
      ;;

    Literal)
      if [[ "$KIND" == "LiteralString" ]]; then
        cat <<EOF
  _val.value.clear();
  while(_pos != _end) {
    uint32_t lDat = *_pos;
    _pos++;
    _val.value.push_back(lDat);

    // Break when at least one byte is 0
    if((lDat & 0xFF000000) == 0 || (lDat & 0x00FF0000) == 0 || (lDat & 0x0000FF00) == 0 || (lDat & 0x000000FF) == 0)
      break;
  }
EOF
      else
        cat <<EOF >> "$CPP_FILE"
  _val.value.clear();
  _val.value.push_back(*(_pos++));
EOF
      fi
      ;;

    Id)
      echo "_val.value = *(_pos++);"
      ;;

    Composite)
      c=0
      for i in `echo "$OP" | jq -r ".bases | .[]"`; do
        cat <<EOF
  if(_pos >= _end)
    return _end + 1;

  _pos = parse_$i(_val.value$c, _pos, _end);
EOF
        (( c++ ))
      done
      ;;
  esac

  echo -e "return _pos;\n}\n"

  echo -e "\x1b[1F\x1b[2KGenerating parser... `echo "(($I * 100) / $NUM_ALL)" | bc`%" 1>&2
done >> "$CPP_FILE"

######################################
#### Generate instructions parser ####
######################################

I=0
while true; do
  INST=`jq -c ".instructions | .[$I]" "$GRAMAR_FILE"`
  (( I++ ))
  [[ "$INST" == "null" ]] && break

  #OP=`echo "$INST" | jq -r ".opname"`
  getValue "$INST" opname OP

  if [[ "${INST/\"operands\"/}" == "$INST" ]]; then
    echo "bool spirvPacker::dis::parse_$OP(Instruction &) {"
    echo "// No operands"
  else
    echo "bool spirvPacker::dis::parse_$OP(Instruction &_inst) {"
    echo "auto lCurr = begin(_inst.rawBinary) + 1;"
    echo "auto lEnd  = end(_inst.rawBinary);"
  fi

  J=0
  while true; do
    OPERAND="`echo "$INST" | jq -c ".operands | .[$J]"`"
    [[ "$OPERAND" == "null" ]] && break;

    getValue "$OPERAND" kind       KIND
    getValue "$OPERAND" name       NAME
    getValue "$OPERAND" quantifier QUAN

    NAME="${NAME//\\n/}"
    NAME="${NAME//\'/}"

    getValue "${OPERANDS[$KIND]}" category CATE

    MACRO=""
    case "$QUAN" in
      "?") MACRO="PARSE_ONE" ;;
      "*") MACRO="PARSE_MULT" ;;
      *)   MACRO="PARSE_NORMAL" ;;
    esac
    echo "${MACRO}(lCurr, lEnd, _inst.operands, $KIND, \"$NAME\")"

    (( J++ ))
  done

  echo -e "return true;\n}\n"

  echo -e "\x1b[1F\x1b[2KGenerating parser... `echo "((($I + $NUM_OPER) * 100) / $NUM_ALL)" | bc`%" 1>&2
done >> "$CPP_FILE"

clang-format -i "$HPP_FILE"
clang-format -i "$CPP_FILE"
