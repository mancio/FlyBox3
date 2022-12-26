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

#include "../.pio/libdeps/leonardo/Joystick/src/Joystick.h"
#include "bt.h"

#define IN_MAX 1024
#define OUT_MIN (-341)
#define OUT_MAX 341
#define X 0
#define Y 1
#define Z 2
#define NORM true
#define REV false
#define DCS 0

class Joy{
    private:
        Joystick_ *newJoy = nullptr; /*!< Pointer to new Joystick element */
        int _out_min = 0;
        int _out_max = IN_MAX;
        long mapValue(long value, bool direction) const;
    public:
        /**
         * Initialize the Joystick
         * @param type Use "DCS" for a 3 axis 32 buttons Joystick
         */
        explicit Joy(int type);
        void setAxesRange(int axis, int out_min, int out_max); /*!< Set the axes scale using the Arduino map function */
        /**
         *
         * @param name
         * @param pin
         * @param direction
         * @param type
         * @return
         */
        void setAxis(int name, int pin, bool direction);

        Joystick_ * getJoy();
};





#endif //FLYBOX3_JOY_H
