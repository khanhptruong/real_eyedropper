# Project Description
The goal of this project is to create a physical device that functions like photoshop's (or any image editor's) eyedropper too. In other words, the device will take a color sample and return the color's hex value (ie #ffffff) to the user. While this project could more conveniently be created in the form of a smartphone app, the goal is to demonstrate how this can be done with more fundamental hardware components and microcontrollers. In other words, the goal of this project is practice, not practicality.

# Theory
The project uses a Raspberry Pi and Camera Modules in order to sample colors and process the color information. The Pi is connected via serial connection to an Arduino, which is responsible for interfacing with the push button controls and the 7segment displays.

Color sampling occurs by averaging the squares of the color values of each pixel in the sample space, and then taking the root of the sum. This method produces more accurate results than merely taking an average. 

![color_avg](https://raw.githubusercontent.com/khanhptruong/real_eyedropper/gh-pages/docs/assets/color_avg_equation.jpg)

# Required Hardware
- Raspberry Pi 4 Model B
- Raspberry Pi High Resolution Camera Module
- Arduino Uno
- x2 4-Digit 7-Segment Displays (common cathode)
- SN74HC595 Shift Registers
- x7 1k Resistors
- 10k Resistor
- Push Button

*_Note that other Arduino and Rasberry Pi models will work as well, and the original Pi Camera Module will work as well._

*_Note the [datasheets](https://www.ti.com/lit/ds/symlink/sn74hc595.pdf) for the SN74HC595 Shift Registers often show incorrect pin order for the output. Below is the correct pin order, with Q0 being the least significant bit, and Q7 being the most significant bit. Magenta colored font indicates the corrections I've made to the [original datasheet](https://www.ti.com/lit/ds/symlink/sn74hc595.pdf)._

![595](https://raw.githubusercontent.com/khanhptruong/real_eyedropper/gh-pages/docs/assets/595-correction.jpg)

*_Note the [datasheets](https://cdn-shop.adafruit.com/datasheets/865datasheet.pdf) for the 4-Digit 7-Segment Displays show an incorrect number of pins. They show 12 pins when there in fact 14. Below is the correct pin order, with pin7 and pin8 controling the colon on the display. Magenta colored font indicates the corrections I've made to the [original datasheet](https://cdn-shop.adafruit.com/datasheets/865datasheet.pdf)._

![7seg](https://raw.githubusercontent.com/khanhptruong/real_eyedropper/gh-pages/docs/assets/7seg-correction.jpg)

# Required Software
- python (included with Raspberry Pi OS)
- picamera (included with Raspberry Pi OS)
- Pillow PIL Fork

# Design
The design of the project is relatively simple, below are diagrams of the program flow and the hardware schematics:

![pi_progflow](https://raw.githubusercontent.com/khanhptruong/real_eyedropper/gh-pages/docs/assets/pi_progflow.jpg)

![arduo_proflow](https://raw.githubusercontent.com/khanhptruong/real_eyedropper/gh-pages/docs/assets/arduino_progflow.jpg)

![schematic](https://raw.githubusercontent.com/khanhptruong/real_eyedropper/gh-pages/docs/assets/real_eyedropper_schematic.png)

A few things to note:
- in order to prevent bleeding in the 7 segment display, clear the 7 segments between moving to the next digit
- resistors are wired to the segment outputs, wiring to the digit outputs causes voltage drop that dims the display

# Notes for Future Improvement
- Color accuracy is heavily affected by exposure and lighting. Adding a controlled light source such as a ringlight can make color readings more consistent.
- The current version lacks portability, a shell, power source, and portable monitor can be implemented to make the device truely portable.
- The is a delay before the camera samples a color, delay can be minimized by not turning display on and off constantly.
