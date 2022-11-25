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

//

#ifndef FLYBOX3_PINS_H
#define FLYBOX3_PINS_H

// slide potentiometer
#define POT A0 // OTB sl pot

// joystick
#define BT_JOY A1 // push button
#define H_JOY A2 // horizontal movement
#define V_JOY A3 // vertical movement

// multiplexer one
#define SO_M1 5
#define S1_M1 6
#define S2_M1 7
#define S3_M1 8
#define SIG_M1 9

// multiplexer two
#define SO_M2 0
#define S1_M2 1
#define S2_M2 2
#define S3_M2 3
#define SIG_M2 4


#endif //FLYBOX3_PINS_H
