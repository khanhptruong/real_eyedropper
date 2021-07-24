Khanh Truong
github id: khanhptruong

Real Eyedropper Project
July 7, 2021

For more detailed info, visit github page: https://khanhptruong.github.io/real_eyedropper/

-----------
Description
-----------
This project attempts to create a physical version of the photoshop eyedroper tool. The Real Eyedropper uses a camera in order to capture color data and display the color in hex format (ie #ffffff) on a 7 segment display.

--------------
Included Files
--------------
real_eyedropper.py	-code to run on raspberry pi
real_eyedropper.ino	-code to run on arduino
README.txt		-this file

-------------------
Required Components
-------------------
Raspberry Pi 4 Model B (or similar)
Raspberry Pi High Resolution Camera Module
Arduino Uno (or similar)
x2 4-Digit 7-Segment Displays (common cathode)
SN74HC595N Shift Registers
x7 1k Resistors
10k Resistor
Push Button

-----------------
Required Software
-----------------
picamera library
Pillow (PIL Fork)

-----
Notes
-----
-Most SN74HC595 datasheets are incorrect, the output data pins are often shown in the wrong order. Hence the arrangement of pins in this project does not reflect datasheets. See project page for more info.
-Most 4-Digit 7-Segment Display datasheets are incorrect, the actual component has 2 more pins than shown in the datasheets. See project page for more info.
