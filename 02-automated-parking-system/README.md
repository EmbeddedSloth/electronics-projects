# 02 - Automated Parking Gate - In Work

An automated parking barrier controlled by a push button on an Arduino Uno. The gate remains closed (horizontal) by default. When the button is pressed, the servo motor lifts the barrier to the vertical position.

![Photo 1](images/02-car-ramp1.jpeg)
![Photo 2](images/02-car-ramp2.jpeg)

## How it works

| State | Button | Barrier position | Servo angle |
|---|---|---|---|
| Idle | Not pressed (`LOW`) | Closed (horizontal) | 0° |
| Active | Pressed (`HIGH`) | Open (vertical) | 90° |

When the button is released, the barrier immediately returns to the closed position.

## Parts

- Arduino Uno R3
- Breadboard and jumper wires
- 1 x Servo motor
- 1 x 100 uF electrolytic capacitor (decoupling)
- 1 x 10 kohm resistor (button pull-down)
- 1 push button

## Pin map

| Pin | Connected to |
|---|---|
| D2 | Push button (with 10 kohm pull-down to GND) |
| D9 | Servo motor signal wire |

The button connects 5V to D2. The servo motor is powered directly from 5V and GND, with a 100 uF capacitor connected across the power rails near the servo to stabilize voltage drops. Full schematic: [schematic/02-car-ramp.pdf](schematic/02-car-ramp.pdf)
![Schematic](schematic/02-car-ramp.png)

## Build and upload

Requires VS Code with the PlatformIO extension. Make sure `arduino-libraries/Servo` is included in `platformio.ini` under `lib_deps`.

## Next steps

Adding a ultrasonic sensor that will replace the pushbutton and recognize when a car is close to the ramp.
