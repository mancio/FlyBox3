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

#ifndef FLYBOX3_MUX_H
#define FLYBOX3_MUX_H

#include "../.pio/libdeps/leonardo/CD74HC4067/src/CD74HC4067.h"
#include "bt.h"
#include "joy.h"

int * readMux(Joystick_ newJoy, CD74HC4067 mux, Button *btArray);

#endif //FLYBOX3_MUX_H
