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
#include <joyconf.h>
#include <logger.h>
#include <btconf.h>
#include <muxconf.h>

Joy myJoy;
Logger myLogger;
Multiplexer mux1(myJoy, S0_M1, S0_M1, S2_M1, S3_M1, SIG_M1);
Multiplexer mux2(myJoy, S0_M2, S0_M2, S2_M2, SIG_M2);
Button bArrayM1[TOT_BUTTONS_MUX];
Button bArrayM2[TOT_BUTTONS_MUX];

long axes_values[3];
bool log_active = true;

void setup() {
    setLed();
    myJoy.startJoy();
    setMux();
    setCursor();
    setPot();
}

void loop() {
    axes_values[0] = myJoy.setAxis(X, H_JOY, NORM, ZERO_AT_CENTER);
    axes_values[1] = myJoy.setAxis(Y, V_JOY, NORM, ZERO_AT_CENTER);
    axes_values[2] = myJoy.setAxis(Z, POT, NORM, ZERO_AT_START);

    mux1.readMux(bArrayM1);
    mux2.readMux(bArrayM2);


    if(log_active){
        myLogger.logAxes(axes_values);
    }
}

