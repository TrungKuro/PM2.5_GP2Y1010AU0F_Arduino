/*!
 *  @file GP2Y1010AU0F.h
 *
 *  Library Sensor PM2.5 GP2Y1010AU0F use with boards Arduino
 *  Function measure PM2.5 dust density
 *
 *  @section author Author
 *
 *  Written by TrungKuro
 *
 *  @section license License
 *
 *  Hshop license, all text above must be included in any redistribution
 */

#ifndef GP2Y1010AU0F_H
#define GP2Y1010AU0F_H

#include <Arduino.h>

/* Use for pinLed */
#define IRED_ON   LOW
#define IRED_OFF  HIGH

/* Use for pinVo, unit time Microseconds */
#define LED_ON_WAIT_SAMPLING  280
#define LED_ON_TAKE_DATA      40 // No need, because analogRead() takes about 100 microseconds to read an analog input
#define LED_OFF_SLEEPING      9680  

class GP2Y1010AU0F
{
public:
  GP2Y1010AU0F(uint8_t pinLed, uint8_t pinVo);
  float getDustDensityDefault();
  float getDustDensityCalibrate();
  float getDustDensityCustom(float A, float B);

private:
  uint8_t _pinLed, _pinVo;
  float calculateVo();
};

#endif
