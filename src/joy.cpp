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

#include <joy.h>

Joy::Joy(int type) {
    if(type == DCS){
        newJoy = new Joystick_(
                JOYSTICK_DEFAULT_REPORT_ID, // joystick ID
                JOYSTICK_TYPE_JOYSTICK, // device type
                32, // buttons number starting from zero
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

void Joy::setAxesRange(int axes) {
    for (int i = 1; i <= axes; ++i) {
        if(newJoy != nullptr){
            if(i == 1) newJoy->setXAxisRange(OUT_MIN, OUT_MAX);
            if(i == 2) newJoy->setYAxisRange(OUT_MIN, OUT_MAX);
            if(i == 3) newJoy->setZAxisRange(OUT_MIN, OUT_MAX);
        }
    }
}

long Joy::setAxis(int name, int pin, bool direction, bool type) {
    long val = analogRead(pin);
    long mapped = mapValue(val, direction, type);
    if(newJoy != nullptr){
        if(name == X) newJoy->setXAxis(mapped);
        if(name == Y) newJoy->setYAxis(mapped);
        if(name == Z) newJoy->setZAxis(mapped);
    }
    return mapped;
}

long mapValue(long value, bool direction, bool type) {
    if(type){
        if(direction) return map(value, 0, IN_MAX, OUT_MIN, OUT_MAX);
        else return map(value, 0, IN_MAX, OUT_MAX, OUT_MIN);
    } else {
        if(direction) return map(value, 0, IN_MAX, 0, OUT_MAX);
        else return map(value, 0, IN_MAX, OUT_MAX, 0);
    }
}
