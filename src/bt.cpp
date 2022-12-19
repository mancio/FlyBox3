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

#include <bt.h>
#include <Arduino.h>

Button::Button() {
    last_state = HIGH;
    state = HIGH;
    inputPin = 0;
    pinName = 1;
}

int Button::debounce(long delay){
    state = digitalRead(inputPin);
    last_state = state;
    if(T.TimerIsExpired(delay)){
        T.updateTimer();
        if (state == LOW) return BUTTON_PRESSED;
        else return BUTTON_RELEASED;
    }
    return last_state;
}

void Button::setInputPin(int pin){
    inputPin = pin;
}

int Button::getPinName(){
    return pinName;
}

void Button::setPinName(int name){
    pinName = name;
}

void setButtonSIG(Button *btArray1, Button *btArray2, int sig1, int sig2){
    for (int i = 0; i < TOT_BUTTONS_MUX; ++i) {
        btArray1[i].setInputPin(sig1);
        btArray2[i].setInputPin(sig2);
    }
}

void setPinNames(Button *btArray1, Button *btArray2, int names1[], int names2[]){
    for (int i = 0; i < TOT_BUTTONS_MUX; ++i) {
        btArray1[i].setPinName(names1[i]);
        btArray2[i].setPinName(names2[i]);
    }
}

void setPinNames(Button button, int name){
    button.setPinName(name);
}