
[![Arduino CI](https://github.com/RobTillaart/SIMON/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/SIMON/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/SIMON/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/SIMON/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/SIMON/actions/workflows/jsoncheck.yml)
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/SIMON/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/SIMON.svg?maxAge=3600)](https://github.com/RobTillaart/SIMON/releases)


# SIMON

Arduino library to build the "Simon says" game or a digital lock.


## Description

SIMON is a simple library to make a "Simon says" game. 
This same class can also be used for e.g. a digital lock.


## Interface

#### Base

- **SIMON()** constructor.

- **bool setSequence(uint8_t \* array, uint8_t length)** set the 
returns false if count > max size or array == NULL
- **void clear()** clears the current answer.
- **void add(uint8_t value)** add next element to answer.
if length becomes too large it is automatically reset.
- **bool verify()** check if answer matches the sequence.
- **uint8_t length()** returns the length of the answer so far.
- **uint8_t size()** returns the size of the "hidden" sequence.


## Operation

A SIMON 

- see examples (TODO).



## Future

- improve documentation
- add use of EEPROM to store a sequence over reboots
  - **SIMON(uint16_t EEPROM_ADDR)** constructor with EEPROM address
- add **bool getSequence(uint8_t \* array, uint8_t length)** ?
- add **bool generateSequence(min, max, length)** = random generator for sequences.
- add example
  - simon says game
  - digital lock
  - **bool mastermind(uint8_t \* array, uint8_t &black, uint8_t &white)** compare? (good-wronglocation + good-goodlocation)
- encrypted sequence (one way hash)
  - derived class.
- add **verify(uint8_t \* array, uint8_t length)**



