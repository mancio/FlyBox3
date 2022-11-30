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

#include <btconf.h>
#include <Arduino.h>

Button::Button() {
    last_state = HIGH;
    state = HIGH;
    _pin = 0;
}

int Button::debounce(long delay){
    state = digitalRead(_pin);
    last_state = state;
    if(T.TimerIsExpired(delay)){
        T.updateTimer();
        if (!state) return 0;
        else return 1;
    }
    return last_state;
}

void Button::setPin(int pin){
    _pin = pin;
}

void fillButtonArray(Button bt, int array){
    for (int i = 0; i < 16; ++i) {
        if(array == 1) btArrayM1[i] = bt;
        if(array == 2) btArrayM2[i] = bt;
    }
}