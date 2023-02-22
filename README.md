# FlyBox3

<div align="center">

<img src="https://github.com/mancio/FlyBox3/blob/main/Schematics/f18.JPG" width="397" height="344" />

Pad with additional controls to play fly sims. Made with Arduino Pro Micro.

[![License: LGPL v3](https://img.shields.io/badge/License-LGPL_v3-blue.svg)](https://www.gnu.org/licenses/lgpl-3.0)

</div>

## Introduction 

This is the improvement of the [FlyBox2](https://github.com/mancio/FlyBox2) project.
In this version there are:
* additional momentary up/down switches for better control of 
flap, speedbrake, heading and course (ex. set up of a f18 in DCS).
* mini gamepad analog joystick for head control (for people without VR or neck pain).

## Code Documentation 

Documentation generated using [Doxygen](https://doxygen.nl).

[Here](https://github.com/mancio/FlyBox3/blob/main/doc/html/index.html) you can find the FlyBox3 doc in html.

## How to import libraries

If you are using CLion:
* go to ``Tools -> PlatformIO -> Home`` 
* add library to project 
* in the code click the class name to add ``#include`` automatically
  For people who like Intellj CLion IDE

## How to run project in Clion

* install PlatformIO plug in
* search ``Cmake`` in ``Settings`` and click ``+`` button to add ``Debug``, ``leonardo`` and ``Default``
* install python3
* autogenerate ``CmakeList.txt`` if not present
* add PlatformIO configuration on the top dropdown list (build/play section)
* remove build execution from the configuration list of this new configuration
* play the configuration with leonardo selected ``PlatformIO Upload|leonardo``

some links:
* [tutorial](https://docs.platformio.org/en/latest/integration/ide/clion.html)
* [python trick](https://community.platformio.org/t/could-not-find-the-package-with-requirements-for-your-system-windows-amd64/18416)