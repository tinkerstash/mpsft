/*
 * Copyright (c) 2017 Jiawei Chiu
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 *
 */
#include "catch.hpp"

#include "base.h"
#include "integer.h"

namespace mps {

TEST_CASE("MulMod", "") {
  const int64_t divisor = kPrimes[15];
  for (int i = 0; i < 1000; ++i) {
    const int64_t a = RandomInt32();
    const int64_t b = RandomInt32();
    REQUIRE(MulMod(a, b, divisor) == (a * b) % divisor);
  }
}

// Check if we have overflow issues.
TEST_CASE("Transform", "") {
  constexpr int32_t n = 536870909; // Prime.
  Transform tf(n, 10000000, 10000001, 10000002);
  REQUIRE(tf.a == 10000000);
  REQUIRE(tf.b == 10000001);
  REQUIRE(tf.c == 10000002);
  REQUIRE(MulPosMod(tf.a_inv, tf.a, n) == 1);
}

TEST_CASE("TransformMore", "") {
  constexpr int32_t n = 536870909; // Prime.
  for (int i = 0; i < 10000; ++i) {
    Transform tf(n);
    REQUIRE(MulPosMod(tf.a_inv, tf.a, n) == 1);
  }
}

} // namespace mps