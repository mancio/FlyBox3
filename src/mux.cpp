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

#include <mux.h>

Mux::Mux(Joystick_ * J, int s0, int s1, int s2, int s3){
    newMux = new CD74HC4067(s0 ,s1 ,s2 ,s3);
    newJoy = J;
}

int *Mux::readMux(Button * btArray) {
    static int stateArray[TOT_BUTTONS_MUX];
    for (int i = 0; i < TOT_BUTTONS_MUX; i++) {
        if(newMux != nullptr) newMux->channel(i);
        int bt_in = btArray[i].debounce(BUTTONS_DEBOUNCE_DELAY);
        if(newJoy != nullptr) newJoy->setButton(i, bt_in);
        stateArray[i] = bt_in;
    }
    return stateArray;
}
