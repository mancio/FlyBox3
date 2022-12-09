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

#include <logger.h>
#include <bt.h>
#include <Arduino.h>

void logAxes(long *values, int axes) {
    String axes_names_array[3] = {"X","Y", "Z (POT)"};
    for (int i = 0; i < axes; ++i) {
        String line = " Axis " + axes_names_array[i] + ": " + values[i] + " ";
        Serial.print(line);
        Serial.println(" ");
    }
}

void logActiveButtons(int *btArray, int arrayNumber) {
    for (int i = 1; i <= TOT_BUTTONS_MUX; ++i) {
        if(btArray[i] == HIGH) {
            String line;
            if(arrayNumber == FIRST_ARRAY) line = "Button " + String(i) + ": ON";
            if(arrayNumber == SECOND_ARRAY) line = "Button " + String(i + TOT_BUTTONS_MUX) + ": ON";
            Serial.print(line);
            Serial.println(" ");
        }
    }
}