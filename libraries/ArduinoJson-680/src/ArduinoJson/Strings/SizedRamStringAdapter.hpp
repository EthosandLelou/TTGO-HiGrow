// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2018
// MIT License

#pragma once

#include <string.h>  // strcmp

namespace ARDUINOJSON_NAMESPACE {

class SizedRamStringAdapter {
 public:
  SizedRamStringAdapter(const char* str, size_t n) : _str(str), _size(n) {}

  bool equals(const char* expected) const {
    const char* actual = reinterpret_cast<const char*>(_str);
    if (!actual || !expected) return actual == expected;
    return strcmp(actual, expected) == 0;
  }

  bool isNull() const {
    return !_str;
  }

  char* save(MemoryPool* pool) const {
    if (!_str) return NULL;
    char* dup = pool->allocFrozenString(_size);
    if (dup) memcpy(dup, _str, _size);
    return dup;
  }

  size_t size() const {
    return strlen(reinterpret_cast<const char*>(_str));
  }

  bool isStatic() const {
    return false;
  }

 private:
  const char* _str;
  size_t _size;
};

template <typename TChar>
inline SizedRamStringAdapter adaptString(const TChar* str, size_t size) {
  return SizedRamStringAdapter(reinterpret_cast<const char*>(str), size);
}

}  // namespace ARDUINOJSON_NAMESPACE
