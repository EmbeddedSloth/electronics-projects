# 02 - Automated Parking Gate - In Work

An automated parking barrier controlled by an ultrasonic distance sensor (HC-SR04) on an Arduino Uno, complete with red/green traffic LEDs, an audio alert on opening, and hysteresis/timing logic to prevent jitter. The gate remains closed (horizontal) by default with the red LED active. When a vehicle approaches within the opening threshold, the servo motor lifts the barrier to the vertical position, switches to the green LED, and triggers a short tone.

![Photo 1](images/02-car-ramp1.jpeg)
![Photo 2](images/02-car-ramp2.jpeg)

## How it works

| State / Phase | Condition / Timing | Barrier position | Servo angle | Traffic LEDs | Piezo |
|---|---|---|---|---|---|
| Idle (Closed) | No vehicle detected (`> 70 mm` when closed) | Closed (horizontal) | 0° | Red ON, Green OFF | Silent |
| Opening | Vehicle detected (`> 0` and `<= 50 mm`) while ramp is down | Opens to vertical | 90° | Red OFF, Green ON | Short tone (`1000 Hz`, `200 ms`) |
| Holding Open | Vehicle remains within `<= 50 mm` | Stays open | 90° | Red OFF, Green ON | Silent |
| Closing Sequence | Vehicle moves past `> 70 mm`: `3000 ms` green hold -> switch to red -> `1500 ms` red warning hold -> close -> `5000 ms` post-close pause | Closes to horizontal | 0° | Green ON (3s), then Red ON (1.5s + 5s) | Silent |

A deadband (`<= 50 mm` to open, `> 70 mm` to trigger closing) and state tracking (`isRampUp`) prevent rapid re-triggering or jitter when an object is stationary or moving near the threshold. A `5000 ms` pause after closing gives the barrier time to settle before accepting the next vehicle.

## Parts

- Arduino Uno R3
- Breadboard and jumper wires
- 1 x Servo motor
- 1 x HC-SR04 ultrasonic distance sensor
- 1 x 100 uF electrolytic capacitor (decoupling)
- 1 x Red LED and 1 x Green LED (with appropriate current-limiting resistors)
- 1 x Piezo buzzer
- 1 x Pushbutton / switch (wired on `D3`, logic pending)

## Pin map

| Pin | Connected to |
|---|---|
| D6 | Servo motor signal wire |
| D3 | Switch / button input (logic in progress) |
| D4 | Piezo buzzer |
| D7 | Green LED |
| D8 | Red LED |
| D9 | HC-SR04 `Echo` pin |
| D10 | HC-SR04 `Trig` pin |

Both the servo motor and the HC-SR04 ultrasonic sensor are powered directly from 5V and GND, with a 100 uF capacitor connected across the power rails near the servo to stabilize voltage drops. Full schematic: [schematic/02-car-ramp.pdf](schematic/02-car-ramp.pdf)
![Schematic](schematic/02-car-ramp.png)

## Build and upload

Requires VS Code with the PlatformIO extension. Make sure `arduino-libraries/Servo` is included in `platformio.ini` under `lib_deps`.
```
pio run               # build
pio run -t upload     # upload to the board
```
## Try it in a simulator

![Tinkercad circuit](images/car-ramp.png)

You can rebuild this circuit in [Tinkercad Circuits](https://www.tinkercad.com/circuits)
and run the code there without any hardware:

1. Build the circuit as shown above (see the pin map for connections).
2. Open the code editor and switch it to **Text** mode.
3. Paste the contents of `src/main.cpp`.
4. **Delete the first line** (`#include <Arduino.h>`). Tinkercad includes it
   automatically, and keeping it causes a compile error.
5. Click **Start Simulation**.

## Next steps

- Add an LCD display once a larger breadboard is available.
- Integrate a Raspberry Pi with a camera to read license plates, track entering vehicles, and open the gate automatically on exit like a real-world parking system.