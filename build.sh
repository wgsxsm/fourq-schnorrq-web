#!/bin/bash
emcc -O3 -s WASM=1 -s EXPORTED_RUNTIME_METHODS='["cwrap","ccall"]' \
     -s MODULARIZE=1 -s EXPORT_NAME='createFourQModule' \
     -s ALLOW_MEMORY_GROWTH=1 -s SINGLE_FILE=0 \
     -I. -I../sha512 -I../random \
     fourq_wasm.c schnorrq.c kex.c eccp2.c eccp2_core.c crypto_util.c hash_to_curve.c \
     ../sha512/sha512.c \
     -o fourq.js \
     -D _GENERIC_ -D _AMD64_ -D __LINUX__ -D USE_ENDO
echo "✅ 编译完成！生成 fourq.js 和 fourq.wasm"
