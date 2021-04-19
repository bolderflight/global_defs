/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2021 Bolder Flight Systems Inc
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the “Software”), to
* deal in the Software without restriction, including without limitation the
* rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
* sell copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
* IN THE SOFTWARE.
*/

#ifndef INCLUDE_GLOBAL_DEFS_GLOBAL_DEFS_H_
#define INCLUDE_GLOBAL_DEFS_GLOBAL_DEFS_H_

#include <cstdint>

namespace bfs {

enum class GnssFix : uint8_t {
  FIX_NONE = 0,
  FIX_2D = 2,
  FIX_3D = 3,
  FIX_DGNSS = 4,
  FIX_RTK_FLOAT = 5,
  FIX_RTK_FIXED = 6,
  FIX_STATIC = 7,
  FIX_PPP = 8
};

enum class AircraftType : uint8_t {
  FIXED_WING = 0,
  TRICOPTER = 1,
  QUADROTOR = 2,
  HEXAROTOR = 3,
  OCTOROTOR = 4,
  DECAROTOR = 5,
  DODECAROTOR = 6,
  HELICOPTER = 7,
  COAXIAL_HELICOPTER = 8,
  VTOL = 9
};

enum class AircraftState : uint8_t {
  INIT = 0,
  CAL = 1,
  STANDBY = 2,
  ACTIVE = 3,
  CAUTION = 4,
  EMERGENCY = 5,
  POWEROFF = 6,
  FTS = 7
};

enum class AircraftMode : uint8_t {
  MANUAL = 0,
  STABALIZED = 1,
  ATTITUDE = 2,
  AUTO = 3,
  TEST = 4
};

struct Waypoint {
  enum class Frame : unsigned int {
    NED = 0,
    WGS84 = 1
  };
  enum class Type : unsigned int {
    LAUNCH = 0,
    WAYPOINT = 1,
    LOITER_UNLIM = 2,
    LOITER_TURNS = 3,
    LOITER_TIME = 4,
    LOITER_ALT = 5,
    LAND = 6
  };
  Frame frame : 1;
  Type type : 5;
  int radius_m : 10;
  int param : 15;
  int32_t x;
  int32_t y;
  int32_t z;
};

}  // namespace bfs

#endif  // INCLUDE_GLOBAL_DEFS_GLOBAL_DEFS_H_
