/*
FlyBox3 is a flight simulator game pad for games like X-plane, DCS and Flight Simulator used together
with a joystick

Copyright (C) 2022  Andrea Mancini

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "joy.h"

Joy::Joy(int type) {
    if(type == DCS){
        newJoy = new Joystick_(
                JOYSTICK_DEFAULT_REPORT_ID, // joystick ID
                JOYSTICK_TYPE_JOYSTICK, // device type
                32,
                0, // hotswitch count
                true, // X axis
                true, // Y axis
                true, // Z axis
                false, // X rotation?
                false, // Y rotation?
                false, // Z rotation?
                false, // rudder
                false, // throttle
                false, // accelerator
                false, // brake
                false // steering
        );
    } else newJoy = new Joystick_();
}

Joystick_ * Joy::getJoy(){
    return newJoy;
}

void Joy::setAxesRange(int axis, int out_min, int out_max) {
    _out_min = out_min;
    _out_max = out_max;
    if(newJoy != nullptr) {
        newJoy->begin();
        if(axis == X) newJoy->setXAxisRange(_out_min, _out_max);
        if(axis == Y) newJoy->setYAxisRange(_out_min, _out_max);
        if(axis == Z) newJoy->setZAxisRange(_out_min, _out_max);
    }
}

void Joy::setAxis(int name, int pin, bool direction) {
    long val = analogRead(pin);
    long mapped = mapValue(val, direction);
    if(newJoy != nullptr){
        if(name == X) {
            long a = antiNoise(mapped, X);
//            Serial.println(a);
            newJoy->setXAxis(a);
        }
        if(name == Y) {
            long a = antiNoise(mapped, Y);
//            Serial.println(a);
            newJoy->setYAxis(a);
        }
        if(name == Z) {
            long a = antiNoise(mapped, Z);
//            Serial.println(a);
            newJoy->setZAxis(a);
        }
    }
}

long Joy::mapValue(long value, bool direction){
    if(direction) return map(value, 0, IN_MAX, _out_min, _out_max);
    else return map(value, 0, IN_MAX, _out_max, _out_min);
}

long Joy::antiNoise(long value, int axis){
    if(axis == 0){
        if(value >= -HIGH_NOISE_THRESHOLD && value < HIGH_NOISE_THRESHOLD) return 0;
        if(value >= _out_max - LOW_NOISE_THRESHOLD) return _out_max;
        if(value <= _out_min + LOW_NOISE_THRESHOLD) return _out_min;
        if (abs(value-xVal) <= LOW_NOISE_THRESHOLD){
            return xVal;
        } else {
            xVal = value;
        }
    }
    if(axis == 1){
        if(value >= -HIGH_NOISE_THRESHOLD && value < HIGH_NOISE_THRESHOLD) return 0;
        if(value >= _out_max - LOW_NOISE_THRESHOLD) return _out_max;
        if(value <= _out_min + LOW_NOISE_THRESHOLD) return _out_min;
        if (abs(value-yVal) <= LOW_NOISE_THRESHOLD){
            return yVal;
        } else {
            yVal = value;
        }
    }
    if(axis == 2){
        if(value >= -LOW_NOISE_THRESHOLD && value < LOW_NOISE_THRESHOLD) return 0;
        if(value >= _out_max - LOW_NOISE_THRESHOLD) return _out_max;
        if(value <= _out_min + LOW_NOISE_THRESHOLD) return _out_min;
        if (abs(value-zVal) <= LOW_NOISE_THRESHOLD){
//            Serial.println(String(abs(value-zVal)) + "<=" + HIGH_NOISE_THRESHOLD);
            return zVal;
        } else {
//            Serial.println(String(abs(value-zVal)) + ">=" + HIGH_NOISE_THRESHOLD);
//            Serial.println("value " + String(value) + " and zVal " + String(zVal));
            zVal = value;
        }
    }
    return value;
}
