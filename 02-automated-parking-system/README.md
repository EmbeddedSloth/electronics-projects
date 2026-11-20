# 02 - Automated Parking Gate - In Work

An automated parking barrier controlled by an ultrasonic distance sensor (HC-SR04) on an Arduino Uno. The gate remains closed (horizontal) by default. When a vehicle approaches within the threshold distance, the servo motor lifts the barrier to the vertical position.

![Photo 1](images/02-car-ramp1.jpeg)
![Photo 2](images/02-car-ramp2.jpeg)

## How it works

| State | Ultrasonic sensor (HC-SR04) | Barrier position | Servo angle |
|---|---|---|---|
| Idle | No vehicle detected (`> 50 mm`) | Closed (horizontal) | 0° |
| Active | Vehicle detected (`<= 50 mm`) | Open (vertical) | 90° |

Once the vehicle moves away from the sensor, the barrier returns to the closed position.

## Parts

- Arduino Uno R3
- Breadboard and jumper wires
- 1 x Servo motor
- 1 x HC-SR04 ultrasonic distance sensor
- 1 x 100 uF electrolytic capacitor (decoupling)

## Pin map

| Pin | Connected to |
|---|---|
| D2 | Servo motor signal wire |
| D10 | HC-SR04 `Trig` pin |
| D11 | HC-SR04 `Echo` pin |

Both the servo motor and the HC-SR04 ultrasonic sensor are powered directly from 5V and GND, with a 100 uF capacitor connected across the power rails near the servo to stabilize voltage drops. Full schematic: [schematic/02-car-ramp.pdf](schematic/02-car-ramp.pdf)
![Schematic](schematic/02-car-ramp.png)

## Build and upload

Requires VS Code with the PlatformIO extension. Make sure `arduino-libraries/Servo` is included in `platformio.ini` under `lib_deps`.

## Next steps

Adding Raspberry Pi that will remeber vehicle registrations that enter and opet the ramp when they exeit like a real world parking system
