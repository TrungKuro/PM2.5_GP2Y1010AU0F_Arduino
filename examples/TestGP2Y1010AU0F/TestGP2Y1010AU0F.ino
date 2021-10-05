#include <GP2Y1010AU0F.h>

#define LED_PIN 2
#define VO_PIN  A0

GP2Y1010AU0F dust(LED_PIN, VO_PIN);

void setup()
{
  Serial.begin(9600);
  Serial.print(F("PM2.5 GP2Y1010AU0F test!\n"));
}

void loop()
{
  float dustDensity = dust.getDustDensityDefault(); // Unit (mg/m3)
  Serial.print(F("Dust Density PM2.5: "));
  Serial.print(dustDensity, 2); Serial.print(F(" mg/m3\n"));

  delay(1000);
}
