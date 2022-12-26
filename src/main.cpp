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

#include <Arduino.h>
#include <setmicro.h>
#include <joy.h>
#include <bt.h>
#include <mux.h>

Joy j(DCS);
Mux mux1(j.getJoy(), S0_M1, S1_M1, S2_M1, S3_M1);
Mux mux2(j.getJoy(), S0_M2, S1_M2, S2_M2, S3_M2);
PushButton PushJoy(j.getJoy());
Button bArrayM1[TOT_BUTTONS_MUX];
Button bArrayM2[TOT_BUTTONS_MUX];

int names1[TOT_BUTTONS_MUX] = {
        0, 1, 2, 3,
        4, 5, 6, 7,
        8, 9, 10, 11,
        12, 13, 14, 15
};

int names2[TOT_BUTTONS_MUX] = {
        16, 17, 18, 19,
        20, 21, 22, 23,
        24, 25, 26, 27,
        28, 29, 30, FORBIDDEN_BUTTON
};

int* reversedArr2 = reverseArray(names2, TOT_BUTTONS_MUX);

Button JoyButton;
int joyPinBtName = 31;

void setup() {
    setLed();
    j.setAxesRange(X, OUT_MIN, OUT_MAX);
    j.setAxesRange(Y, OUT_MIN, OUT_MAX);
    j.setAxesRange(Z, OUT_MIN, OUT_MAX);
    setPinMux();
    setCursor();
    setPot();
    JoyButton.setInputPin(BT_JOY);
    JoyButton.setPinName(joyPinBtName);
    setButtonsInput(bArrayM1, bArrayM2, SIG_M1, SIG_M2);
    setPinNames(bArrayM1, bArrayM2, reversedArr2, names1);
}

void loop() {
    j.setAxis(X, H_JOY, NORM);
    j.setAxis(Y, V_JOY, REV);
    j.setAxis(Z, POT, NORM);
    mux1.readMux(bArrayM1);
    mux2.readMux(bArrayM2);
    PushJoy.push(JoyButton);
}

