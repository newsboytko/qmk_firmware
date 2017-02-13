Satan (GH60 RevCHN) keyboard firmware
=====================================

## Supported Layouts

### ANSI
`TODO`

### ISO
`TODO`

### HHKB
`TODO`

### ISO with split right shift
`TODO`

### ANSI with Foot Switches

ANSI layout extra sockets (normally used for split right shift and split backspace) repurposed for foot switches, as seen in the build by GabePlaysDrums.

`TODO: link to build log`

## RGB Underglow

RGB underglow requires a WS2812[b] LED strip.  

Connect D-In on the LED strip to the PE2 pin on the microcontroller.

![RGB microcontroller wiring](controller.jpg)

Connect the Vcc and Ground pins to the breakout pins on the PCB.

![RGB power wiring](power.jpg)

The recommended number of LEDs is 8 due to power draw, though some users have used up to 16 with no issues.