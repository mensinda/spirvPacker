#!/bin/bash

cd "`dirname "$0"`"

which jq &> /dev/null
if (( $? != 0 )); then
  echo "command line tool jq (https://stedolan.github.io/jq/) not found"
  echo "Download it here: https://stedolan.github.io/jq/download/"
  exit 1
fi

./lib/compiler/glslang/genResourcesFile.sh
./lib/disassembler/default/generateMagicNumberLookup.sh
./lib/generateOperands.sh
./lib/disassembler/default/generateParsers.sh
