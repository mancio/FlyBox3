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
#include <Arduino.h>

Logger::Logger(int axes_number) {
    axes_number = axes;
}

void Logger::logAxes() {
    for (int i = 0; i < sizeof(axes_array) ; ++i) {
        String line = " Axis " + axes_array[i] + ":"
        Serial.print(x_p);
    }
    Serial.print("Axis X: ");
    Serial.print(x_p);
    Serial.print("    Axis Y: ");
    Serial.print(y_p);
    Serial.print("    Axis Z: ");
    Serial.print(z_p);
    Serial.println("");
}