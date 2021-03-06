# LVEZ_ESP

This is Maxbotix LV-EZ series's repository.

LV-EZ series is very accurate sonic wave distance sensor.

dataseat is [here](https://www.maxbotix.com/downloads.htm)

To measure distance using LV-EZ series, two method.

First, to read analog value with **TOUT** pin.

but this method is a complecated with connect.

## Analog Read

### Using ESP 8266 series

ESP8266's analog input volume is **0~1V's** and 10 bits (0~1023). We need to transfer 3.3V to 1.0V. 

like this.

![3.3to1v](./pic/to1V.jpg)

you have to connect like this circle.

If you connect directly, ESP8266 will brake.

![](./pic/ESP8266connect.jpg)


### Using ESP 32 series
ESP32's analog input volume is 0~3.3V. Enable to directly connect. 
But, ESP32's resolution is 12 bit.

So, to mapping value 12bit to 10bit(0~4096 to 0~1023).

```map.cpp
long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
```

or 12bit value date right shift 2bit.

```shift.cpp
long data_for_12bit = 3456;

long deta_for_10bit = data_for_12bit >> 2;
```

like this(exsample code with transfer)

```mapping.cpp
double val,inch, dist_mm;
val = analogRead(analogpin);

distance = map(val, 0, 4096, 0, 1024);
//or
// distance = val >> 2;

dist_mm = distance * 5;

inch = dist_mm / 25.4;

Serial.println(dist_mm + "mm");
Serial.println(inch + "inch");
```

this code is transfer 12bit to 10bit.

![](./pic/ESP32_LVEZ.png)

This is circle, to use LV-EZ1 with ESP32.

### Using Arduino
Arduino is very easy to use this one.

First, You attach Arduino's Analog pin(A0 ~ A5)

![](./pic/Arduino_LVEZ.png)

# pulse

LV-EZ series enable to use pulse in/out.

### ESP8266

You attach enable to use PWM pin.

PWM pin is IO12,13,14,15,16 pins.

![](./pic/ESP8266_pwm.png)

### ESP32

PWM enable to use all pins.

Using software PWM code.

![](./pic/ESP32_PWMLVEZ.png)

use pulse in/out

### Arduino

![](./pic/Arduino_PWMLVEZ.png)


## License
MIT
