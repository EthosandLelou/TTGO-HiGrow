// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2018
// MIT License

#pragma once

#include "../Configuration.hpp"

namespace ARDUINOJSON_NAMESPACE {

struct NestingLimit {
  NestingLimit() : value(ARDUINOJSON_DEFAULT_NESTING_LIMIT) {}
  explicit NestingLimit(uint8_t n) : value(n) {}

  uint8_t value;
};
}  // namespace ARDUINOJSON_NAMESPACE
