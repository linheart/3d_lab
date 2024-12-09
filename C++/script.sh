#!/bin/bash

set -e
BUILD_DIR="build"
EXEC_DIR="exec"

mkdir -p $BUILD_DIR
cd $BUILD_DIR

cmake -DENABLE_COVERAGE=ON ..

make -j$(nproc)

mkdir -p $EXEC_DIR

for exe in *; do
    if [ -f "$exe" ] && [ -x "$exe" ] && [ "$exe" != "tests" ]; then
        mv "$exe" "$EXEC_DIR"
    fi
done

ctest
make coverage

./tests

cd coverage_html
explorer.exe $(wslpath -w $(realpath index.html))