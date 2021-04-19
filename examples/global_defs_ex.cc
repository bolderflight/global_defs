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

#include <iostream>
#include "global_defs/global_defs.h"

int main() {
  /* Printing the size of the waypoint object */
  std::cout << sizeof(bfs::Waypoint) << std::endl << std::endl;
  /* Define a couple of waypoints */
  bfs::Waypoint point1 = {
    .frame = bfs::Waypoint::Frame::NED,
    .type = bfs::Waypoint::Type::LAUNCH,
    .radius_m = 500,
    .param = 1000,
    .x = 0,
    .y = 0,
    .z = -100
  };
  bfs::Waypoint point2 = {
    .frame = bfs::Waypoint::Frame::WGS84,
    .type = bfs::Waypoint::Type::LAND,
    .radius_m = 500,
    .param = 1000,
    .x = 0,
    .y = 0,
    .z = -100
  };
  /* Print the waypoint values */
  std::cout << static_cast<int>(point1.frame) << std::endl;
  std::cout << static_cast<int>(point1.type) << std::endl;
  std::cout << point1.radius_m << std::endl;
  std::cout << point1.param << std::endl;
  std::cout << point1.x << std::endl;
  std::cout << point1.y << std::endl;
  std::cout << point1.z << std::endl << std::endl;

  std::cout << static_cast<int>(point2.frame) << std::endl;
  std::cout << static_cast<int>(point2.type) << std::endl;
  std::cout << point2.radius_m << std::endl;
  std::cout << point2.param << std::endl;
  std::cout << point2.x << std::endl;
  std::cout << point2.y << std::endl;
  std::cout << point2.z << std::endl;

}
