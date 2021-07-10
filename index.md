# Project Description
The goal of this project is to create a physical device that functions like photoshop's (or any image editor's) eyedropper too. In other words, the device will take a color sample and return the color's hex value (ie #ffffff) to the user. While this project could more conveniently be created in the form of a smartphone app, the goal is to demonstrate how this can be done with more fundamental hardware components and microcontrollers. In other words, the goal of this project is practice, not practicality.

# Theory
The project uses a Raspberry Pi and Camera Modules in order to sample colors and process the color information. The Pi is connected via serial connection to an Arduino, which is responsible for interfacing with the push button controls and the 7segment displays. Below is a brief diagram of the project's program flow.

Color sampling occurs by averaging the squares of the color values of each pixel in the sample space, and then taking the root of the sum. This method produces more accurate results than merely taking an average. 

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

# Required Software
- python (included with Raspberry Pi OS)
- picamera (included with Raspberry Pi OS)
- Pillow PIL Fork

### Markdown

Markdown is a lightweight and easy-to-use syntax for styling your writing. It includes conventions for

```markdown
Syntax highlighted code block

# Header 1
## Header 2
### Header 3

- Bulleted
- List

1. Numbered
2. List

**Bold** and _Italic_ and `Code` text

[Link](url) and ![Image](src)
```

For more details see [GitHub Flavored Markdown](https://guides.github.com/features/mastering-markdown/).

### Jekyll Themes

Your Pages site will use the layout and styles from the Jekyll theme you have selected in your [repository settings](https://github.com/khanhptruong/real_eyedropper/settings/pages). The name of this theme is saved in the Jekyll `_config.yml` configuration file.

### Support or Contact

Having trouble with Pages? Check out our [documentation](https://docs.github.com/categories/github-pages-basics/) or [contact support](https://support.github.com/contact) and we’ll help you sort it out.



