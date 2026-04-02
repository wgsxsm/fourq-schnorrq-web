#include <emscripten.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "FourQ_api.h"
#include "../sha512/sha512.h"
#include "blake2b/blake.h"

int (*current_hash_fn)(const unsigned char *, unsigned long long, unsigned char *) = crypto_sha512;

EMSCRIPTEN_KEEPALIVE
void set_hash_algo(int algo) {
    current_hash_fn = (algo == 1) ? crypto_blake2b : crypto_sha512;
}

int random_bytes(unsigned char* buf, unsigned int len) {
  unsigned int i;
  for (i = 0; i < len; i++) {
    buf[i] = (unsigned char)(rand() & 0xFF);
  }
  return 1;
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
