#pragma once
//
//    FILE: simon.h
//  AUTHOR: Rob Tillaart
//    DATE: 2022-05-26
// VERSION: 0.1.0
// PURPOSE: Arduino library for SIMON
//     URL: https://github.com/RobTillaart/SIMON


#include "Arduino.h"

#define SIMON_LIB_VERSION        (F("0.1.0"))


class SIMON
{
public:
  SIMON();

  //  returns false if count > max size or array == NULL
  bool    setSequence(uint8_t * array, uint8_t length);

  //  clears the current answer
  void    clear();
  //  add next element to answer
  void    add(uint8_t value);
  //  check if answer matches the sequence
  bool    verify();
  //  returns the length of the answer so far
  uint8_t length();
  //  returns the size of the "hidden" sequence
  uint8_t size();

private:
  uint8_t _sequence[10];   // TODO dynamic allocation ?
  uint8_t _answer[10];
  uint8_t _idx     = 0;
  uint8_t _size    = 0;    //  size of the sequence
  uint8_t _maxSize = 10;

};


// -- END OF FILE --

