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

#ifndef FLYBOX3_JOY_H
#define FLYBOX3_JOY_H

/**
 * class to control all joystick HID operation
 */
class Joy {
    public:
        /**
         * function to initialize the HID joystick
         *
         * @param type zero for a left hand pad with axis X,Y,Z,
         * throttle axis and 33 buttons
         *
         */
        void init(int type);
};

#endif //FLYBOX3_JOY_H
