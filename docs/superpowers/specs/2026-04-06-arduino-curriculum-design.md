# Arduino Kids Curriculum — Design Spec
Date: 2026-04-06

## Context

Two families learning Arduino together:
- One Polish-speaking family
- One Polish-American family (father speaks English, aids his son)

Target age: ~8 years and younger. Parents assist. No prior electronics or coding experience.
Language: Simple English (accessible to non-native speakers).

Board: **Arduino Uno R4 WiFi** (`arduino:renesas_uno`)

---

## Curriculum Approach

**Option C: Standalone projects with a suggested order.**

- Each project is fully self-contained — no dependencies on other projects
- Projects have a difficulty rating (⭐ / ⭐⭐ / ⭐⭐⭐)
- A suggested play order is provided, but families can follow their interests
- Pure hands-on fun; optional "Want to learn more?" sections for math/science (never required)

---

## Project List (13 projects)

| # | Name | Key Components | Difficulty |
|---|------|---------------|------------|
| 01 | Blink | LED, resistor | ⭐ |
| 02 | Traffic Light | 3 LEDs, resistors | ⭐ |
| 03 | Button Light | LED, button, resistor | ⭐ |
| 04 | Buzzer Doorbell | buzzer, button | ⭐ |
| 05 | Rainbow RGB | RGB LED, potentiometer | ⭐⭐ |
| 06 | Night Light | photoresistor, LED, resistor | ⭐⭐ |
| 07 | Weather Station | DHT11, LCD 16x2 | ⭐⭐ |
| 08 | Motion Alarm | PIR sensor, buzzer | ⭐⭐ |
| 09 | Parking Sensor | HC-SR04, buzzer | ⭐⭐ |
| 10 | Servo Wave | Servo MG-90S | ⭐⭐ |
| 11 | Spinning Fan | DC motor, BC547 transistor, potentiometer | ⭐⭐⭐ |
| 12 | Secret Card Unlock | RFID RC522, LEDs, buzzer | ⭐⭐⭐ |
| 13 | LED Matrix Art | Arduino R4 built-in 12×8 LED matrix | ⭐⭐⭐ |

---

## Folder Structure

```
arduino/
├── TODO.md
├── elements.txt
├── bin/
├── docs/
└── projects/
    ├── 01-blink/
    │   ├── 01-blink.ino
    │   └── README.md
    ├── 02-traffic-light/
    │   ├── 02-traffic-light.ino
    │   └── README.md
    └── ... (same pattern for all 13 projects)
```

The `.ino` file and its containing folder share the same name — required by Arduino IDE.

---

## README Template (per project)

Each README contains these sections, scaled to the project's complexity:

1. **Title + difficulty + one-line description**
2. **What you will build** — a fun, concrete description of the outcome
3. **What you need** — exact component list with quantities
4. **Wiring** — numbered step-by-step instructions; for multi-component projects, a connection table (FROM → TO) is included
5. **How to upload** — fixed steps: open `.ino` → click Upload → wait
6. **What should happen** — concrete description of expected behavior
7. **How does it work?** — simple 2–4 sentence explanation a child can understand
8. **Want to learn more?** *(optional)* — a fun challenge or science/math question; skipping this never blocks the project

No circuit diagram images. Wiring is described in plain text and tables only.

---

## Code Style

- Every `.ino` file is heavily commented
- Comments explain **what** AND **why** in simple English
- No assumed programming knowledge — even `void setup()` is explained on first use
- Variable names are descriptive (e.g., `ledPin`, `buttonPin`, `distance`)
- Magic numbers are named constants (e.g., `#define TRIGGER_PIN 9`)

---

## Libraries Needed (to be installed via arduino-cli)

| Project | Library |
|---------|---------|
| 07 Weather Station | `DHT sensor library` (Adafruit) |
| 07 Weather Station | `LiquidCrystal` (built-in) |
| 09 Parking Sensor | `NewPing` |
| 10 Servo Wave | `Servo` (built-in) |
| 11 Spinning Fan | none (analogWrite + transistor) |
| 12 Secret Card Unlock | `MFRC522` |
| 13 LED Matrix Art | `Arduino_LED_Matrix` (built-in for R4) |

---

## Implementation Notes

- LCD 16x2 is connected in 4-bit parallel mode (standard LiquidCrystal library, no I2C adapter needed since it has goldpin connectors already soldered)
- RGB LED is common-anode type — logic is inverted (LOW = on, HIGH = off)
- DHT11 is used for the weather station (temp + humidity); LM35 is not used (DHT11 covers temperature)
- DC motor controlled via BC547 NPN transistor (no L293D needed for simple on/off or PWM speed control without direction change)
- HC-SR04 uses the `NewPing` library — cleaner code that is easier for kids to read than raw pulseIn timing
- PIR sensor output is a simple digital HIGH/LOW — no library needed
- RFID RC522 uses SPI, needs MFRC522 library
- Arduino Uno R4 WiFi has a built-in 12×8 LED matrix accessible via `Arduino_LED_Matrix` library
