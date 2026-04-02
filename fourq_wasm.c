#include <emscripten.h>
#include <stdio.h>
#include <string.h>
#include "FourQ_api.h"

EM_JS(void, js_random_bytes, (unsigned char* buf, int len), {
  const array = new Uint8Array(len);
  crypto.getRandomValues(array);
  HEAPU8.set(array, buf);
});

void random_bytes(unsigned char* buf, unsigned int len) {
  js_random_bytes(buf, len);
}

EMSCRIPTEN_KEEPALIVE
int wasm_FullKeyGeneration(unsigned char* sk, unsigned char* pk) {
  return SchnorrQ_FullKeyGeneration(sk, pk);
}

EMSCRIPTEN_KEEPALIVE
int wasm_Sign(const unsigned char* sk, const unsigned char* pk,
              const unsigned char* msg, unsigned int msg_len,
              unsigned char* signature) {
  return SchnorrQ_Sign(sk, pk, msg, msg_len, signature);
}

EMSCRIPTEN_KEEPALIVE
int wasm_Verify(const unsigned char* pk, const unsigned char* msg,
                unsigned int msg_len, const unsigned char* signature,
                unsigned int* valid) {
  return SchnorrQ_Verify(pk, msg, msg_len, signature, valid);
}
