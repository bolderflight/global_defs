# global_defs
This library defines items that are typically used across multiple libraries.
   * [License](LICENSE.md)
   * [Changelog](CHANGELOG.md)
   * [Contributing guide](CONTRIBUTING.md)

# Description

## Installation
CMake is used to build this library, which is exported as a library target called *global_defs*. The header is added as:

```
#include "global_defs/global_defs.h"
```

The library can be also be compiled stand-alone using the CMake idiom of creating a *build* directory and then, from within that directory issuing:

```
cmake ..
make
```

This will build the library and an example executable called *global_defs_ex*. The example executable source files are located at *examples/global_defs_ex.cc*.

## Definitions

**std::size_t MAX_POLY_COEF_SIZE** Defines a standard maximum size of polynomial coefficients. This enables defining a statically allocated array for storing polynomial coefficients and tracking the actual number of coefficients with a separate variable.

**enum AircraftType** This enum defines the type of aircraft being operated.

| Enum               | Value (int8_t) | Description         |
| ------------------ | ----- | ------------------- |
| FIXED_WING         | 0     | Fixed-wing aircraft |
| HELICOPTER         | 1     | Helicopter          |
| MULTIROTOR         | 2     | Multirotor          |
| VTOL               | 3     | VTOL aircraft       |


**enum AircraftState** This enum defines the aircraft state.

| Enum      | Value (int8_t) | Description                                  |
| --------- | ----- | -------------------------------------------- |
| INIT      | 0     | System is initializing                       |
| STANDBY   | 1     | Ready to fly, motors are not enabled         |
| ACTIVE    | 2     | Flying, motors are enabled                   |
| CAUTION   | 3     | Off-nominal condition, still able to operate |
| EMERGENCY | 4     | Emergency condition, not able to operate     |
| FTS       | 5     | Flight Termination System has been activated |

**enum AircraftMode** This enum defines the aircraft mode of operation.

| Enum       | Value (int8_t) | Description                     |
| ---------- | ----- | ------------------------------- |
| MANUAL     | 0     | Manual flight mode              |
| STABALIZED | 1     | Stability augmented flight mode |
| ATTITUDE   | 2     | Attitude feedback flight mode   |
| AUTO       | 3     | Autonomous flight mode          | 
| TEST       | 4     | Test point                      |

* Manual flight mode: pilot is directly controlling the aircraft effectors
* Stability augmented flight mode: pilot-in-the-loop with the flight computer providing additional aircraft stability
* Attitude feedback flight mode: pilot-in-the-loop with inceptor / stick commands providing attitude commands to the control system
* Autonomous flight mode: autonomously flying without pilot inputs, typically navigating between waypoints
* Test: flight test points

**MissionItem** This struct defines a Mission Item, which can be a waypoint in a flight plan, a fence vertex, or a rally point. The struct is defined as:

| Name | Description |
| --- | --- |
| bool autocontinue | Whether to automatically continue to the next MissionItem |
| uint8_t frame | The [coordinate frame](https://mavlink.io/en/messages/common.html#MAV_FRAME) of the MissionItem |
| uint16_t cmd | The [command](https://mavlink.io/en/messages/common.html#mav_commands) associated with the MissionItem |
| float param1 | Command dependent parameter |
| float param2 | Command dependent parameter |
| float param3 | Command dependent parameter |
| float param4 | Command dependent parameter |
| int32_t x | Typically latitude represented as 1e7 degrees |
| int32_t y |  Typically longitude represented as 1e7 degrees  |
| float z | Typically altitude, but can be dependent on the command and frame |
