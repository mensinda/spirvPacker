/* Copyright (c) 2017, EPL-Vizards
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the EPL-Vizards nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL EPL-Vizards BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include "spvCfg.hpp"
#include <stdint.h>

#define JENKINS_HASH_ID 0
#define MURMUR_HASH_ID 1
#define FNV1A_HASH_ID 2
#define HASH_FUNC_TO_USE FNV1A_HASH_ID

namespace spirvPacker {

inline size_t jenkinsHash(char const *data) {
  size_t hash = 0;
  while (*data != 0) {
    hash += static_cast<size_t>(*data);
    hash += hash << 10;
    hash ^= hash >> 6;
    ++data;
  }
  hash += hash << 3;
  hash ^= hash >> 11;
  hash += hash << 15;
  return hash;
}

constexpr size_t jenkinsHash(char const *data, size_t n) {
  size_t hash = 0;
  for (size_t i = 0; i < n; ++i) {
    hash += static_cast<size_t>(data[i]);
    hash += hash << 10;
    hash ^= hash >> 6;
  }
  hash += hash << 3;
  hash ^= hash >> 11;
  hash += hash << 15;
  return hash;
}

const size_t FNV1A_BASE  = 2166136261;
const size_t FNV1A_PRIME = 16777619;

inline size_t fnv1aHash(const char *data) {
  size_t hash = FNV1A_BASE;
  while (*data != 0) {
    hash ^= static_cast<size_t>(*(data++));
    hash *= FNV1A_PRIME;
  }
  return hash;
}

constexpr size_t fnv1aHash(const char *data, size_t n) {
  size_t hash = FNV1A_BASE;
  for (size_t i = 0; i < n; ++i) {
    hash ^= static_cast<size_t>(data[i]);
    hash *= FNV1A_PRIME;
  }
  return hash;
}

  // inline constexpr uint64_t MurmurHash64A(const void *key, int len, unsigned int seed = 0x346AF759) {
  //   const uint64_t m = 0xc6a4a7935bd1e995;
  //   const int      r = 47;
  //
  //   uint64_t h = seed ^ (len * m);
  //
  //   const uint64_t *data = (const uint64_t *)key;
  //   const uint64_t *end  = data + (len / 8);
  //
  //   while (data != end) {
  //     uint64_t k = *data++;
  //
  //     k *= m;
  //     k ^= k >> r;
  //     k *= m;
  //
  //     h ^= k;
  //     h *= m;
  //   }
  //
  //   const unsigned char *data2 = (const unsigned char *)data;
  //
  //   switch (len & 7) {
  //     case 7: h ^= uint64_t(data2[6]) << 48;
  //     case 6: h ^= uint64_t(data2[5]) << 40;
  //     case 5: h ^= uint64_t(data2[4]) << 32;
  //     case 4: h ^= uint64_t(data2[3]) << 24;
  //     case 3: h ^= uint64_t(data2[2]) << 16;
  //     case 2: h ^= uint64_t(data2[1]) << 8;
  //     case 1: h ^= uint64_t(data2[0]); h *= m;
  //   };
  //
  //   h ^= h >> r;
  //   h *= m;
  //   h ^= h >> r;
  //
  //   return h;
  // }


#if HASH_FUNC_TO_USE == JENKINS_HASH_ID
inline constexpr size_t hashFunc(char const *data, size_t n) { return jenkinsHash(data, n); }
inline size_t           hashFunc(char const *data) { return jenkinsHash(data); }
#elif HASH_FUNC_TO_USE == MURMUR_HASH_ID
inline constexpr size_t hashFunc(char const *data, size_t n) { return MurmurHash64A(data, n); }
inline size_t           hashFunc(char const *data) { return MurmurHash64A(data, strlen(data)); }
#elif HASH_FUNC_TO_USE == FNV1A_HASH_ID
inline constexpr size_t hashFunc(char const *data, size_t n) { return fnv1aHash(data, n); }
inline size_t           hashFunc(char const *data) { return fnv1aHash(data); }
#else
#error "Invalid hash function set"
#endif

constexpr size_t operator"" _h(char const *data, size_t n) { return hashFunc(data, n); }
} // namespace spirvPacker
