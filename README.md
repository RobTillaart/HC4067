
[![Arduino CI](https://github.com/RobTillaart/HC4067/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/HC4067/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/HC4067/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/HC4067/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/HC4067/actions/workflows/jsoncheck.yml)
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/HC4067/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/HC4067.svg?maxAge=3600)](https://github.com/RobTillaart/HC4067/releases)


# HC4067

HC4067 is an Arduino library for a HC4067 16 channel multiplexer.


## Description

A HC4067 class is a simple library to control the CD74HC4067 16 channel
multiplexer and compatible devices.

The channel selection is done with 4 select lines **S0..S3**

The device can be enables/disabled by the Enable line **E**


#### Compatibles

Not tested these but considered compatible
- CD74HC4067, 74HC4067, 74HCT4067


## Hardware connection

Typical connection is to connect the 4 **select pins** to 4 IO Pins of your board.

The optional **enablePin** must be connected to GND is not used.
This way the device is continuous enabled.


## Interface

```cpp
#include "HC4067.h"
```

#### Core

- **HC4067(uint8_t s0, uint8_t s1, uint8_t s2, uint8_t s3, uint8_t enablePin = 255)** constructor.
Set the 4 select pins and optional the enable pin.
If the enablePin == 255 it is considered not used.
- **void  setChannel(uint8_t channel)** set the current channel.
Valid values 0..15, the value are not checked.
- **uint8_t getChannel()** get current channel.


#### Enable

These functions work only if enablePin is set in the constructor.

- **void enable()** idem.
- **void disable()** idem.
- **bool isEnabled()** idem.
Also returns true if enablePin is not set.


## Future

#### Must

- elaborate documentation
  - links etc.


#### Should

- optimizations
  - ?
- investigate how to use with only 3 lines or 2 lines.
  - set s3 / s2 to LOW always or so


#### Could

- next() and prev() as channel selector.
  - internal channel var. needed.
- code to .cpp file
- example
  - scan all 16 channels into a uint16_t - IO not analog.
- investigate
  - can it be used as 16 channel OUTPUT
  - is it buffered?


#### Won't (unless requested)

- optimizations
  - only DW when changed? gain is minimal.

