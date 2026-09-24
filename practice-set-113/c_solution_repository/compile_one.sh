#!/usr/bin/env sh
set -eu
if [ "$#" -ne 1 ]; then
  echo "Usage: ./compile_one.sh path/to/file.c"
  exit 1
fi
src="$1"
out="./program"
gcc "$src" -std=c11 -Wall -Wextra -pedantic -lm -o "$out"
echo "Built $out"
