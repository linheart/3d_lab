#!/bin/bash

set -e
BUILD_DIR="build"

if [ ! -d "$BUILD_DIR" ]; then
    mkdir $BUILD_DIR
fi
cd $BUILD_DIR

cmake -DENABLE_COVERAGE=ON ..

make -j$(nproc)
ctest
make coverage

./tests

cd coverage_html
explorer.exe $(wslpath -w $(realpath index.html))

cd ../../