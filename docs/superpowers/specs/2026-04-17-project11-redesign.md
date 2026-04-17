# Project 11 Redesign — Spinning Fan with L293D Motor Driver

Date: 2026-04-17

## Context

The original Project 11 controlled a DC motor via a BC547 NPN transistor, flyback diode, and capacitor, powered from Arduino's 5V pin. This approach was identified as problematic for beginners because:

- It powers the motor from Arduino's own 5V rail (current risk, electrical noise)
- It introduces three new concepts simultaneously (transistor, flyback diode, capacitor)
- It risks teaching the wrong mental model: beginners may not understand *why* the transistor is there

The redesign replaces the transistor circuit with an **L293D motor driver chip** and an **external 9V battery + L7805 5V regulator**, and adds **direction control** via a button and two indicator LEDs.

The original transistor version is archived at `projects/archive/11-spinning-fan-transistor/` for future reference (e.g. a later lesson on transistors).

---

## Audience

Children ~8 years and younger, parents assisting. No prior electronics or coding experience. Simple English throughout.

---

## Components

| Part | Quantity | Purpose |
|------|----------|---------|
| DC motor (3–5V small) | 1 | The fan |
| L293D motor driver chip | 1 | Controls speed and direction safely; isolates motor from Arduino |
| 9V battery + clip | 1 | External power source for the motor |
| L7805ABV 5V regulator (TO-220) | 1 | Steps 9V down to clean 5V for motor supply |
| Potentiometer 10k or 20k | 1 | Speed control knob |
| Tact-switch button | 1 | Toggles motor direction |
| LED green | 1 | "Forward" direction indicator |
| LED red | 1 | "Reverse" direction indicator |
| Resistor 220Ω (or 330Ω) | 2 | Current limiting for LEDs |
| Arduino Uno R4 WiFi | 1 | Microcontroller |
| Breadboard (830 points) | 1 | Connections |
| Jumper wires | several | Connections |

No separate flyback diode or capacitor needed — the L293D has built-in flyback diodes.

---

## Wiring

### L7805 regulator (9V → 5V for motor)

The L7805 has 3 pins. Hold it with the metal tab facing away from you, legs pointing down:

```
  [ metal tab ]
  |    |    |
  IN  GND  OUT
```

- **IN** → 9V battery positive (red wire)
- **GND** → 9V battery negative (black wire) AND Arduino GND
- **OUT** → L293D pin 8 (Vmotor)

### L293D chip pin mapping

The L293D is a 16-pin DIP chip. Place it straddling the centre of the breadboard.

| L293D Pin | Connect to | Purpose |
|-----------|-----------|---------|
| Pin 1 (EN1) | Arduino pin 9 (PWM) | Speed control enable |
| Pin 2 (IN1) | Arduino pin 7 | Direction input A |
| Pin 3 (OUT1) | Motor wire 1 | Motor output A |
| Pin 4 (GND) | Arduino GND | Ground |
| Pin 5 (GND) | Arduino GND | Ground |
| Pin 6 (OUT2) | Motor wire 2 | Motor output B |
| Pin 7 (IN2) | Arduino pin 8 | Direction input B |
| Pin 8 (Vmotor) | L7805 OUT | Motor power (5V regulated) |
| Pin 9 (EN2) | leave unconnected | (second channel, unused) |
| Pins 10–15 | leave unconnected | (second channel, unused) |
| Pin 16 (Vcc) | Arduino 5V | Logic power for chip |

### Direction indicator LEDs

| Component | From | To |
|-----------|------|----|
| Green LED anode | Arduino pin 4 | — |
| Green LED cathode | — | 220Ω resistor → Arduino GND |
| Red LED anode | Arduino pin 5 | — |
| Red LED cathode | — | 220Ω resistor → Arduino GND |

Green LED on = forward. Red LED on = reverse.

### Direction button

| Component | From | To |
|-----------|------|----|
| Tact-switch | Arduino pin 2 | Arduino GND |

Use `INPUT_PULLUP` in code — no external resistor needed.

### Potentiometer

| Leg | Connect to |
|-----|-----------|
| Left | Arduino GND |
| Middle | Arduino A0 |
| Right | Arduino 5V |

---

## Code Behaviour

- **Startup state:** forward direction, green LED on, motor stopped (knob at zero)
- **Potentiometer:** maps 0–1023 → 0–255 PWM, sent to EN1 via `analogWrite`
- **Button press:** toggles a `boolean forward` flag; swaps IN1/IN2 logic; swaps green/red LED
- **Debounce:** `millis()`-based, 50ms threshold — no `delay()` blocking the speed loop
- **Direction change while spinning:** motor immediately reverses at current speed (no forced stop required; L293D handles it)

### Pin assignments

```cpp
#define EN1_PIN  9   // PWM speed — L293D enable
#define IN1_PIN  7   // direction A
#define IN2_PIN  8   // direction B
#define POT_PIN  A0  // potentiometer
#define BTN_PIN  2   // direction toggle button
#define LED_FWD  4   // green LED (forward)
#define LED_REV  5   // red LED (reverse)
```

---

## README Structure

Follows the existing curriculum template. Key additions:

1. **"Why can't I plug the motor straight into Arduino?"** — opening explanation before the parts list. Covers: motors draw more current than pins can give; motors create electrical noise that can confuse or damage Arduino; the L293D and separate battery solve both problems.

2. **"What does the L7805 do?"** — one short paragraph. Analogy: like a tap that limits how much water flows through, the regulator limits voltage to a safe level for the motor.

3. **"What does the L293D do?"** — one short paragraph. Analogy: a security guard that passes instructions (from Arduino) to the motor, while keeping the motor's stronger electricity away from Arduino.

4. **Wiring section** — step-by-step numbered instructions + connection table (FROM → TO).

5. **"What should happen"** — bullet list:
   - Knob left → motor stopped
   - Knob right → motor spins faster
   - Green LED on → motor spinning forward
   - Red LED on → motor spinning in reverse
   - Press button → direction flips, LEDs swap

6. **"Want to learn more?" challenge** — add a stop zone: if the knob is turned all the way left (speed = 0), the motor should stop completely regardless of which direction is selected. Hint: check `motorSpeed == 0` before calling `analogWrite`.

---

## Archive Plan

Before any files are changed:

```
projects/archive/11-spinning-fan-transistor/
├── 11-spinning-fan.ino   (copy of original)
└── README.md             (copy of original)
```

The archive folder is created first, originals copied, then `projects/11-spinning-fan/` is rewritten.

---

## Difficulty Rating

Stays ⭐⭐⭐. The L293D chip has more pins than the transistor circuit, but each connection has a clearer purpose. The direction + LED interaction adds engagement without adding confusion.
