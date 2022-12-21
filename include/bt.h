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

#ifndef FLYBOX3_BT_H
#define FLYBOX3_BT_H

#define TOT_BUTTONS_MUX 16
#define FORBIDDEN_BUTTON 99
#define BUTTONS_DEBOUNCE_DELAY 100
#define BUTTON_PRESSED 1
#define BUTTON_RELEASED 0
#include <timers.h>
#include <WString.h>

class Button {
    private:
        int inputPin; /*!< Pin to debounce */
        int pinName;
        int last_state; /*!< Previous reading state */
        int state; /*!< Current reading state */
        Timer T; /*!< Timer for button debounce */
    public:
        Button(); /*!< Initialize the button handler component */
        /**
         * Debounce the pin
         * @param long delay time in milliseconds
         * @return int 0 pressed and 1 released (using pullup configuration)
         */
        int debounce(long delay);
        /**
         * Set the SIG pin of Arduino
         * @param pin connected to SIG on the Multiplexer
         */
        void setInputPin(int pin);

        int getPinName();

        void setPinName(int name);

    int getInputPin();

    int getLastState();
};

void setButtonsInput(Button *btArray1, Button *btArray2, int sig1, int sig2);

void setPinNames(Button *btArray1, Button *btArray2, int names1[], int names2[]);

#endif //FLYBOX3_BT_H
