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
#pragma once

#include <cmath>

#include "base.h"

namespace mps {

// NOTE: Approximate result.
// Returns sin(2*pi*x). CAUTION: Assume 0 <= x <= 1.
#pragma omp declare simd
double SinTwoPiApprox(double x);

// NOTE: Approximate result.
// Returns sin(2*pi*x). CAUTION: Assume 0 <= x <= 1.
#pragma omp declare simd
double CosTwoPiApprox(double x);

// Optimize later. Not much impact on running time.
// Returns sin(x)/x.
double SincPi(double x);

// Slow form. Mainly for tests.
inline Cplex Sinusoid(double freq) {
  freq *= (2.0 * M_PI);
  return Cplex(::cos(freq), ::sin(freq));
}

} // namespace mps