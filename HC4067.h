#pragma once
//
//    FILE: HC4067.h
//  AUTHOR: Rob Tillaart
//    DATE: 2023-01-25
// VERSION: 0.1.2
// PURPOSE: Arduino library for CD74HC4067 1 x 16 channel multiplexer and compatibles.
//     URL: https://github.com/RobTillaart/HC4067



#include "Arduino.h"

#define HC4067_LIB_VERSION         (F("0.1.2"))


class HC4067
{
public:
  explicit HC4067(uint8_t s0, uint8_t s1, uint8_t s2, uint8_t s3, uint8_t enablePin = 255)
  {
    _pins[0] = s0;
    _pins[1] = s1;
    _pins[2] = s2;
    _pins[3] = s3;
    uint8_t i = 4;
    while (i--)
    {
      pinMode(_pins[i], OUTPUT);
      digitalWrite(_pins[i], LOW);
    }
    _channel = 0;

    if (enablePin != 255)
    {
      _enablePin = enablePin;
      pinMode(_enablePin, OUTPUT);
      digitalWrite(_enablePin, HIGH);
    }
  }


  void setChannel(uint8_t channel)
  {
    if ((channel & 0x0F) != _channel)
    {
      _channel = channel & 0x0F;
      uint8_t mask = 0x08;
      uint8_t i = 3;
      while (mask)
      {
        digitalWrite(_pins[i--], (mask & _channel));
        mask >>= 1;
      }
    }
  }


  uint8_t getChannel()
  {
    return _channel;
  }


  void enable()
  {
    if (_enablePin != 255)
    {
      digitalWrite(_enablePin, LOW);
    }
  }


  void disable()
  {
    if (_enablePin != 255)
    {
      digitalWrite(_enablePin, HIGH);
    }
  }


  bool isEnabled()
  {
    if (_enablePin != 255)
    {
      return (digitalRead(_enablePin) == LOW);
    }
    return true;
  }


private:
  uint8_t  _pins[4];
  uint8_t  _enablePin = 255;
  uint8_t  _channel   = 0;
};


//  -- END OF FILE --

