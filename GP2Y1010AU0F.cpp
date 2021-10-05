/*!
 *  @file GP2Y1010AU0F.cpp
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

#include "GP2Y1010AU0F.h"

/*!
 *  @brief  Instantiates a new GP2Y1010AU0F class
 *  @param  pinLed
 *          Output pin to control sensor (note: use pin Digital)
 *  @param  pinVo
 *          Input pin to the sensor receives data (note: use pin Analog)
 */
GP2Y1010AU0F::GP2Y1010AU0F(uint8_t pinLed, uint8_t pinVo)
{
  _pinLed = pinLed;
  _pinVo = pinVo;

  pinMode(_pinVo, OUTPUT);
}

/////////////////////////////////////////////////////////////////////

/*!
 *  @brief  Take value Dust Density, unit (mg/m3)
 *          The formula default based on Datasheet is: D = 0,2*Vo – 0,18
 */
float GP2Y1010AU0F::getDustDensityDefault()
{
  return 0.2 * GP2Y1010AU0F::calculateVo() - 0.18;
}

/*!
 *  @brief  Take value Dust Density, unit (mg/m3)
 *          With some calibrate I follow here: http://www.howmuchsnow.com/arduino/airquality/
 *          Formula: D = 0,172*Vo – 0,0999
 */
float GP2Y1010AU0F::getDustDensityCalibrate()
{
  return 0.172 * GP2Y1010AU0F::calculateVo() - 0.0999;
}

/*!
 *  @brief  Take value Dust Density, unit (mg/m3)
 *          But we still can custom calibrate for Formula: D = A*Vo + B
 */
float GP2Y1010AU0F::getDustDensityCustom(float A, float B)
{
  return A * GP2Y1010AU0F::calculateVo() + B;
}

/////////////////////////////////////////////////////////////////////

/*!
 *  @brief  Calculate value voltage of pinVo, unit Voltage (V)
 */
float GP2Y1010AU0F::calculateVo()
{
  /* Turn on IRED and wait 0.28ms to Sampling */
  digitalWrite(_pinLed, IRED_ON);
  delayMicroseconds(LED_ON_WAIT_SAMPLING);

  /* Read value Analog to convert to value Voltage, do it in 0.04ms */
  float value = analogRead(_pinVo);
  value = value * 5.0 / 1024.0;
  // delayMicroseconds(LED_ON_TAKE_DATA);

  /* Turn off IRED and wait 9.68ms to finish a cycle read then return value Vo */
  digitalWrite(_pinLed, IRED_OFF);
  delayMicroseconds(LED_OFF_SLEEPING);
  return value;
}
