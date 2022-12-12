#! /bin/bash

mkdir -p dist

cd ../../../deps/emsdk
./emsdk install latest
./emsdk activate latest
source ./emsdk_env.sh

cd ../../js/browser/wa-sqlite
make

cp dist/wa-sqlite-async.wasm ../wa-crsqlite/dist
# cp dist/wa-sqlite-async.mjs  ../../pkg/browser/wa-crsqlite/src/wa-sqlite-async.js