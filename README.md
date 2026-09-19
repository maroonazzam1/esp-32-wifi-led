# ESP32 LED Blink

First ESP32 project: turning an LED on and off with a GPIO pin.

## Hardware

- ESP32-WROOM-32 dev board
- 1x LED
- 1x resistor (220Ω – 330Ω)
- Breadboard + jumper wires
- USB-C cable

## Wiring

| LED pin | Connects to |
|---|---|
| Long leg (anode, +) | Resistor → **GPIO 13** |
| Short leg (cathode, −) | **GND** on the ESP32 |

The resistor goes in series between the LED's long leg and GPIO 13. Either
orientation of the resistor is fine — resistors aren't polarised.

**Always unplug the USB-C cable before changing any wiring.**

## Code

The LED pin is defined at the top of the sketch:

```cpp
const int led = 13;
```

Change that number if you move the LED to a different GPIO.

## Notes

- GPIO 13 is a safe general-purpose pin on the ESP32.
- If the LED doesn't light, check the legs aren't reversed — the long leg
  must be the one going to GPIO 13.
