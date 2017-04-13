// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <catch.hpp>

using namespace Catch::Matchers;

TEST_CASE("JsonArray::remove()") {
  DynamicJsonBuffer _jsonBuffer;
  JsonArray& _array = _jsonBuffer.createArray();
  _array.add("one");
  _array.add("two");
  _array.add("three");

  SECTION("RemoveFirstByIndex") {
    _array.remove(0);

    REQUIRE(2 == _array.size());
    REQUIRE_THAT(_array[0], Equals("two"));
    REQUIRE_THAT(_array[1], Equals("three"));
  }

  SECTION("RemoveMiddleByIndex") {
    _array.remove(1);

    REQUIRE(2 == _array.size());
    REQUIRE_THAT(_array[0], Equals("one"));
    REQUIRE_THAT(_array[1], Equals("three"));
  }

  SECTION("RemoveLastByIndex") {
    _array.remove(2);

    REQUIRE(2 == _array.size());
    REQUIRE_THAT(_array[0], Equals("one"));
    REQUIRE_THAT(_array[1], Equals("two"));
  }

  SECTION("RemoveFirstByIterator") {
    JsonArray::iterator it = _array.begin();
    _array.remove(it);

    REQUIRE(2 == _array.size());
    REQUIRE_THAT(_array[0], Equals("two"));
    REQUIRE_THAT(_array[1], Equals("three"));
  }

  SECTION("RemoveMiddleByIterator") {
    JsonArray::iterator it = _array.begin();
    ++it;
    _array.remove(it);

    REQUIRE(2 == _array.size());
    REQUIRE_THAT(_array[0], Equals("one"));
    REQUIRE_THAT(_array[1], Equals("three"));
  }

  SECTION("RemoveLastByIterator") {
    JsonArray::iterator it = _array.begin();
    ++it;
    ++it;
    _array.remove(it);

    REQUIRE(2 == _array.size());
    REQUIRE_THAT(_array[0], Equals("one"));
    REQUIRE_THAT(_array[1], Equals("two"));
  }
}
