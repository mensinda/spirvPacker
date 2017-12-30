#!/bin/bash

REGISTRY="https://www.khronos.org/registry/spir-v/api/spir-v.xml"
FILE_NAME="spirv.xml"
HPP_FILE="ToolMagicNumber.hpp"
CPP_FILE="ToolMagicNumber.cpp"

cd "`dirname "$0"`"

wget "$REGISTRY" -O "$FILE_NAME"

cat <<EOF > "$HPP_FILE"
//! \note This is an automatically generated file
#pragma once

#include "spvCfg.hpp"
#include <string>
#include <vector>

namespace spirvPacker {

struct SPIRVToolDesc {
  uint32_t value;
  std::string vendor;
  std::string comment;
  std::string tool;
};

SPIRVToolDesc getToolDeskFromMagicNumber(uint32_t _val);

}
EOF

cat <<EOF > "$CPP_FILE"
//! \note This is an automatically generated file

#include "spvCfg.hpp"
#include "$HPP_FILE"

using namespace spirvPacker;

SPIRVToolDesc spirvPacker::getToolDeskFromMagicNumber(uint32_t _val) {
  switch(_val) {
EOF

while read -r line; do
  L="`echo "$line" | sed 's/^[ \t]*<id[ \t]*//g'`"
  L="`echo "$L"    | sed 's/[ \t]*\/>//g'`"

  value="0"
  vendor="<N/A>"
  comment="No comment"
  tool="<N/A>"

  while [[ ! -z "$L" ]]; do
    TYPE=""
    VAL=""

    TYPE="`echo "$L"    | sed 's/^[ \t]*\([a-z]*\)=.*/\1/g' `"
    L="`echo "$L"       | sed 's/^[ \t]*[a-z]*=//g' `"
    VAL="`echo "$L"     | sed 's/^"\([^"]*\)".*/\1/g'`"
    L="`echo "$L"       | sed 's/^"[^"]*"[ \t]*//g' `"
    eval "${TYPE}=\"$VAL\""
  done

  cat <<EOF >> "$CPP_FILE"
    case $value: return {
      $value, // value
      "$vendor", // vendor
      "$comment", // comment
      "$tool" // tool
    };

EOF

done < <(grep '^[ \t]*<id .\+/>[ \t]*$' "$FILE_NAME")

cat <<EOF >> "$CPP_FILE"
    default: return {
      _val, // value
      "<UNKNOWN>", // vendor
      "<UNKNOWN>", // comment
      "<UNKNOWN>" // tool
    };
  }
}
EOF

clang-format -i "$HPP_FILE"
clang-format -i "$CPP_FILE"

rm "$FILE_NAME"
