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

#ifndef FLYBOX3_BTCONF_H
#define FLYBOX3_BTCONF_H

#include <timers.h>

class Button {
    private:
        // pin to debounce
        int _pin;
        // previous reading state
        int last_state;
        // current reading state
        int state;
        // timer for button debounce
        Timer T;
    public:
        /**
         * to initialize the button handler component
         */
        Button();

        /**
         * debounce the pin
         *
         * @param long delay time in milliseconds
         *
         * @return int 0 pressed and 1 released (using pullup configuration)
         */
        int debounce(long delay);

        /**
         * set the newpin to be debounced
         *
         * @param int newpin number
         */
        void setPin(int pin);
};

Button btArrayM1[16];
Button btArrayM2[16];

void fillButtonArray(Button bt, int array);

#endif //FLYBOX3_BTCONF_H
