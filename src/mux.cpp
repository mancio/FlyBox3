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

Multiplexer::Multiplexer(Joy joy, int s0, int s1, int s2, int s3) {
    CD74HC4067 Mux(s0, s1, s2, s3);
    newMux = Mux;
    newJoy = joy;
}

int* Multiplexer::readMux(Button *btArray) {
    int *stateArray = new int[TOT_BUTTONS_MUX];
    for (int i = 0; i < TOT_BUTTONS_MUX; i++) {
        newMux.channel(i);
        int bt_in = btArray[i].debounce(BUTTONS_DEBOUNCE_DELAY);
        newJoy.writeButton(i, !bt_in);
        stateArray[i] = !bt_in;
    }
    return stateArray;
}