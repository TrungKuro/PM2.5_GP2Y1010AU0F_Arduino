# PM2.5 GP2Y1010AU0F Dust Sensor Library
Library sensor PM2.5 GP2Y1010AU0F for **boards Arduino**
<p align="center"><img src="/assets/GP2Y1010AU0F.jpg"/></p>

## Constructors
```
GP2Y1010AU0F(uint8_t pinLed, uint8_t pinVo);
```
+ pinLed: Output pin to control sensor (note: use pin Digital)
+ pinVo : Input pin to the sensor receives data (note: use pin Analog)

## Methods

### Take value Dust Density, unit (mg/m3). Use Formula follow Datasheet: D = 0,2*Vo – 0,18
```
float getDustDensityDefault();
```

### Take value Dust Density, unit (mg/m3). Use Formula has Calibrate: D = 0,172*Vo – 0,0999
```
float getDustDensityCalibrate();
```

### .Take value Dust Density, unit (mg/m3). Use custom Formula
```
float getDustDensityCustom(float A, float B);
```
+ Formula: D = A*Vo + B
