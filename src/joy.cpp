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

void setAxesRange(Joystick_ NewJoy,  int axes) {
    for (int i = 1; i <= axes; ++i) {
        if(i == 1) NewJoy.setXAxisRange(OUT_MIN, OUT_MAX);
        if(i == 2) NewJoy.setYAxisRange(OUT_MIN, OUT_MAX);
        if(i == 3) NewJoy.setZAxisRange(OUT_MIN, OUT_MAX);
    }
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

long setAxis(Joystick_ NewJoy, int name, int pin, bool direction, bool type) {
    long val = analogRead(pin);
    long mapped = mapValue(val, direction, type);
    if(name == X) NewJoy.setXAxis(mapped);
    if(name == Y) NewJoy.setYAxis(mapped);
    if(name == Z) NewJoy.setZAxis(mapped);
    return mapped;
}