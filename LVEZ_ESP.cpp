//
// Created by Hatobus on 18/02/13.
//

/*
The MIT License (MIT)

Copyright (c) 2015 bpyamasinn.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/


#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "LVEZ_ESP.h"

#include <string>

using namespace std;

LVEZ_8266::LVEZ_ESP8266::LVEZ_ESP8266() {
    string pin_num_analog = "A0";
}

LVEZ_8266::LVEZ_ESP8266::LVEZ_ESP8266(short pin_number) {
    short pin_num_digital = pin_number;
    pinMode(pin_number, INPUT);
}

long LVEZ_8266:: LVEZ_ESP8266::get_raw_data_analog() {
    long raw_data = 0;
    raw_data = analogRead(pin_num_analog);
    raw_data = raw_data >> 2;
    return raw_data;
}

long LVEZ_8266::LVEZ_ESP8266::analog_dist_mm() {
    long distance_mm = 0, raw_data = 0;
    raw_data = get_raw_data_analog();
    distance_mm = raw_data * 5;
    return distance_mm;
}

long LVEZ_8266::LVEZ_ESP8266::analog_dist_inch() {
    long distance_inch = 0, raw_data = 0;
    raw_data = get_raw_data_analog();
    distance_inch = (raw_data * 5) / 25.4;
    return distance_inch;
}

double LVEZ_8266::LVEZ_ESP8266::pulse_dist_mm() {
    double distance_mm = 0;
    distance_mm = pulseIn(pin_num_digital, HIGH);
    return distance_mm;
}

double LVEZ_8266::LVEZ_ESP8266::pulse_dist_inch() {
    double distance_inch = 0;
    distance_inch = pulseIn(pin_num_digital, HIGH);
    distance_inch = distance_inch / 25.4;
    return distance_inch;
}


LVEZ_ESP32::LVEZ_ESP32(short pin_number) {
    pin_num = pin_number;
    pinMode(pin_num, INPUT);
}

long LVEZ_ESP32::analog_dist_mm() {
    long distance_mm = 0, raw_data = 0;
    raw_data = get_raw_data_analog();
    distance_mm = raw_data * 5;
    return distance_mm;
}

long LVEZ_ESP32::analog_dist_inch() {
    long distance_inch = 0, raw_data = 0;
    raw_data = get_raw_data_analog();
    distance_inch = (raw_data * 5) / 25.4;
    return distance_inch;
}

long LVEZ_ESP32::get_raw_data_analog() {
    long raw_data = 0;
    raw_data = analogRead(pin_num);
    raw_data = raw_data >> 2;
    return raw_data;
}

double LVEZ_ESP32::pulse_dist_mm() {
    double distance_mm = 0;
    distance_mm = pulseIn(pin_num, HIGH);
    return distance_mm;
}

double LVEZ_ESP32::pulse_dist_inch() {
    double distance_inch = 0;
    distance_inch = pulseIn(pin_num, HIGH);
    distance_inch /= 25.4;
    return distance_inch;
}

LVEZ_Arduino::LVEZ_Arduino(short pin_number) {
    pin_num = pin_number;
    pinMode(pin_num, OUTPUT);
}

long LVEZ_Arduino::get_raw_data_analog(string analog_pin) {
    long raw_data;
    raw_data = analogRead(analog_pin);
    return raw_data;
}

long LVEZ_Arduino::analog_dist_mm(string analog_pin) {
    long distance_mm;
    distance_mm = get_raw_data_analog(analog_pin);
    distance_mm *= 5;
    return distance_mm;
}

long LVEZ_Arduino::analog_dist_inch(string analog_pin) {
    long distance_inch;
    distance_inch = get_raw_data_analog(analog_pin);
    distance_inch = distance_inch * 5 / 25.4;
    return distance_inch;
}

double LVEZ_Arduino::pulse_dist_mm() {
    double distance_mm;
    distance_mm = get_raw_data_pulse();
    return distance_mm;
}

double LVEZ_Arduino::pulse_dist_inch() {
    double distance_inch;
    distance_inch = get_raw_data_pulse();
    distance_inch /= 25.4;
    return distance_inch;
}

long LVEZ_Arduino::get_raw_data_pulse() {
    double raw_data;
    raw_data = pulseIn(pin_num, HIGH);
    return raw_data;
}


