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
#include <logger.h>
#include <bt.h>
#include <mux.h>

Joystick_ newJoy(
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
CD74HC4067 mux1(S0_M1, S0_M1, S2_M1, S3_M1);
CD74HC4067 mux2(S0_M2, S1_M2, S2_M2, S3_M2);
Button bArrayM1[TOT_BUTTONS_MUX];
Button bArrayM2[TOT_BUTTONS_MUX];

long axes_values[AXES_NUMBER];
bool log_active = true;

void setup() {
    setLed();
    setAxesRange(newJoy, AXES_NUMBER);
    setPinMux();
    setButtonSIG(bArrayM1, bArrayM2, SIG_M1, SIG_M2);
    setCursor();
    setPot();
}

void loop() {
    axes_values[0] = setAxis(newJoy, X, H_JOY, NORM, ZERO_AT_CENTER);
    axes_values[1] = setAxis(newJoy, Y, V_JOY, NORM, ZERO_AT_CENTER);
    axes_values[2] = setAxis(newJoy, Z, POT, NORM, ZERO_AT_START);

    int * btStateArray1 = readMux(newJoy, mux1, bArrayM1);
    int * btStateArray2 = readMux(newJoy, mux2, bArrayM2);

    if(log_active){
        logAxes(axes_values, AXES_NUMBER);
        logActiveButtons(btStateArray1, FIRST_ARRAY);
        logActiveButtons(btStateArray2, SECOND_ARRAY);
    }
}

