#!/bin/bash
emcc -O3 -s WASM=1 -s ASSERTIONS=1 \
     -s EXPORTED_RUNTIME_METHODS='["cwrap","ccall","HEAPU8","HEAP8","getValue","setValue"]' \
     -s EXPORTED_FUNCTIONS='["_malloc","_free","_wasm_FullKeyGeneration","_wasm_Sign","_wasm_Verify","_set_hash_algo"]' \
     -s MODULARIZE=1 -s EXPORT_NAME='createFourQModule' \
     -s ALLOW_MEMORY_GROWTH=1 -s SINGLE_FILE=0 \
     -I. -I../sha512 -I../random -I./blake2b \
     fourq_wasm.c schnorrq.c kex.c eccp2.c eccp2_core.c crypto_util.c hash_to_curve.c \
     ../sha512/sha512.c blake2b/blake.c \
     -o fourq.js \
     -D _GENERIC_ -D _AMD64_ -D __LINUX__ -D USE_ENDO
echo "✅ 编译完成！生成 fourq.js 和 fourq.wasm"
