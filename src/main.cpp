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

Joy Joy;
Logger logger(3);

long axes_values[] = {};
bool log_active = true;

void setup() {
    setLed();
    Joy.startJoy();
    setMux();
    setCursor();
    setPot();
}

void loop() {
    long x_pos = Joy.setAxis(X, H_JOY, NORM, ZERO_AT_CENTER);
    long y_pos = Joy.setAxis(Y, V_JOY, NORM, ZERO_AT_CENTER);
    long z_pos = Joy.setAxis(Z, POT, NORM, ZERO_AT_START);

    if(log_active){
    // print axes pos to monitor
        logger.logAxes(x_pos, y_pos, z_pos);
    }
}

