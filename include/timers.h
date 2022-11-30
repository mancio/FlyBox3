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

#ifndef FLYBOX3_TIMERS_H
#define FLYBOX3_TIMERS_H

/**
 * define all timers activity
 */
class Timer {
    private:
        unsigned long last = 0; /*!< last timestamp stored */
    public:
        /**
         * update time by calculating the difference
         * between the current time and the Arduino boot
         */
        void updateTimer();
        /**
         * check if the time expire
         * @param t time limit
         * @return true if time TimerIsExpired otherwise false
         */
        bool TimerIsExpired(unsigned long t) const;
};

#endif //FLYBOX3_TIMERS_H
