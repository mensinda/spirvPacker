#!/bin/bash

cd "$(dirname "$0")"

FILE="GLSLangRes.cpp"

SETUP=""
RETR=""

while IFS= read -r i; do
  NAME="${i%% *}"
  NAME="${NAME,}"
  VAL="${i##* }"

  if [[ "${NAME:0:3}" == "min" || "${NAME:0:3}" == "max" ]]; then
    SETUP+="_sec.addEntry(\"${NAME}\", ${VAL}l);"
    RETR+="lRes.${NAME} = CAST(_sec(\"${NAME}\").valInt());"
  else
    CUR_BOOL="true"
    [[ "$VAL" == "0" ]] && CUR_BOOL="false"
    SETUP+="_sec.addEntry(\"${NAME}\", ${CUR_BOOL});"
    RETR+="lRes.limits.${NAME} = _sec(\"${NAME}\").valBool();"
  fi
done < <(glslangValidator -c)

cat <<EOF > ${FILE}
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

// This file was automatically generated by $0

#include "spvCfg.hpp"
#include "GLSLangCompiler.hpp"

using namespace spirvPacker;
using namespace glslang;

#define CAST(x) static_cast<int>(x)

void GLSLangCompiler::initResources(ConfigSection& _sec)
{
$SETUP
}


TBuiltInResource GLSLangCompiler::getResources(ConfigSection& _sec)
{
TBuiltInResource lRes;

$RETR

return lRes;
}

EOF

clang-format -i ${FILE}
