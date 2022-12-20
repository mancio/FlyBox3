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

#ifndef FLYBOX3_SETMICRO_H
#define FLYBOX3_SETMICRO_H

#define POT A0 /*!< slide potentiometer pin */

#define BT_JOY A1 /*!< push button pin */
#define H_JOY A2 /*!< joystick horizontal movement */
#define V_JOY A3 /*!< joystick vertical movement */

#define S0_M1 1 /*!< first multiplexer S0 pin */
#define S1_M1 0 /*!< first multiplexer S1 pin */
#define S2_M1 2 /*!< first multiplexer S2 pin */
#define S3_M1 3 /*!< first multiplexer S8 pin */
#define SIG_M1 4 /*!< first multiplexer SIG pin */

#define S0_M2 5 /*!< second multiplexer S0 pin */
#define S1_M2 6 /*!< second multiplexer S1 pin */
#define S2_M2 7 /*!< second multiplexer S2 pin */
#define S3_M2 8 /*!< second multiplexer S3 pin */
#define SIG_M2 9 /*!< second multiplexer SIG pin */

#define AXES_NUMBER 3 /*!< total number of axes */

void setLed(); /*!< turn off Arduino build-in led */
void setPinMux(); /*!< set multiplexer pin mode */
void setCursor(); /*!< set the pins of the analog mini joystick */
void setPot(); /*!< set the analog pin of the potentiometer */

#endif //FLYBOX3_SETMICRO_H
