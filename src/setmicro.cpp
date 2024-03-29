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

// Arduino general settings

#include "Arduino.h"
#include "setmicro.h"

void setLed(){
    // disable TXLED and RXLED (TXLED is always on if the USB is tranmitting data)
    DDRD &= ~(1<<5);
}

void setPinMux(){
    // first multiplexer
    pinMode(S0_M1, OUTPUT);
    pinMode(S1_M1,OUTPUT);
    pinMode(S2_M1,OUTPUT);
    pinMode(S3_M1,OUTPUT);
    pinMode(SIG_M1,INPUT_PULLUP);

    // second multiplexer
    pinMode(S0_M2, OUTPUT);
    pinMode(S1_M2,OUTPUT);
    pinMode(S2_M2,OUTPUT);
    pinMode(S3_M2,OUTPUT);
    pinMode(SIG_M2,INPUT_PULLUP);
}

void setCursor(){
    pinMode(BT_JOY, INPUT_PULLUP);
    pinMode(H_JOY, INPUT);
    pinMode(V_JOY, INPUT);
}

void setPot(){
    pinMode(POT, INPUT);
}