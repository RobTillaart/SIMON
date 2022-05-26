//
//    FILE: simon.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2022-05-26
// VERSION: 0.1.0
// PURPOSE: Arduino library for SIMON
//     URL: https://github.com/RobTillaart/SIMON
//
// HISTORY:
// 0.1.0    2022-05-26  initial version


#include "simon.h"


SIMON::SIMON()
{
  _idx = 0;
  _size = 10;
}


bool SIMON::setSequence(uint8_t * array, uint8_t length)
{
  if ((length > _maxSize) || (array == NULL))
  {
    _size = 0;
    return false;
  }
  for (int i = 0; i < length; i++)
  {
    _sequence[i] = array[i];
  }
  _size = length;
  return true;
}


void SIMON::clear()
{
  _idx = 0;
}


void SIMON::add(uint8_t value)
{
  if (_idx == _maxSize)
  {
    _idx = 0;
  }
  answer[_idx] = value;
  _idx++;
}


bool SIMON::verify()
{
  if (_idx != _size) return false;
  for (int i = 0; i < _size; i++)
  {
    if (_sequence[i] != _answer[i]) return false;
  }
  return true;
}


uint8_t SIMON::count()
{
  return _idx;
}


uint8_t SIMON::size()
{
  return _size;
}


// -- END OF FILE --

