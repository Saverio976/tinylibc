#!/usr/bin/env bash

for FILE in $(find src/ -name '*.c' -print); do
  file_check=${FILE/src/tests}
  if [[ ! -f "$file_check" ]]; then
    mkdir -p $(dirname "$file_check")
    cp ./scripts/template_test.c "$file_check"
  fi
done
