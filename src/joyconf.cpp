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

#include "../.pio/libdeps/leonardo/Joystick/src/Joystick.h"

/**
 * initialize controller for a left hand pad with axes X,Y,Z,
 * throttle axis and 33 buttons
 */
Joystick_ Joystick(
        JOYSTICK_DEFAULT_REPORT_ID, // joystick ID
        JOYSTICK_TYPE_JOYSTICK, // device type
        32, // buttons number starting from zero
        0, // hotswitch count
        true, // X axis
        true, // Y axis
        false, // Z axis
        false, // X rotation?
        false, // Y rotation?
        false, // Z rotation?
        false, // rudder
        true, // throttle
        false, // accelerator
        false, // brake
        false // steering
);