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

#ifndef FLYBOX3_JOYCONF_H
#define FLYBOX3_JOYCONF_H

#include "../.pio/libdeps/leonardo/Joystick/src/Joystick.h"

#define IN_MAX 1024
#define OUT_MIN (-101)
#define OUT_MAX 101
#define ZERO_AT_START false
#define ZERO_AT_CENTER true
#define X 0
#define Y 1
#define Z 2
#define NORM true
#define REV false

class Joy {
    private:
        Joystick_ NewJoy;
    public:
        /**
         * call Arduino Joystick library to initialize the Joystick component.
         * It makes a new Joystick object
         * with the following configuration:
         * axes X,Y,Z,
         * throttle axis and 33 buttons.
         * Use in main before setup and loop.
         */
        Joy();

        /**
         * wrap of the begin function of the Joystick arduino library.
         * It goes inside setup();
         */
        void startJoy();

        /**
         * assign a value to the Axis after Analog Read
         * @param name of the axis (X,Y,Z,...)
         * @param pin number to read
         * @param direction NORM = normal or REV = reversed
         * @param type
         * @return the axis position
         */
        long setAxis(int name, int pin, bool direction, bool type);

        /**
         * map the value from analog value to different scale.
         * Mapping to a smaller scale reduce axis flickering.
         * @param value
         * @param direction
         * @param type
         * @return
         */
        static long mapValue(long value, bool direction, bool type);
};




#endif //FLYBOX3_JOYCONF_H
