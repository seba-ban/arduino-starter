# Project 11 Redesign — Spinning Fan Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Replace the transistor-based motor circuit with an L293D motor driver, external 9V battery, L7805 regulator, direction toggle button, and two LED direction indicators.

**Architecture:** Archive the original transistor version, then rewrite the `.ino` and `README.md` in-place. No new folders beyond the archive. The `.ino` contains all logic (speed via PWM on EN1, direction via IN1/IN2, debounced button, LED state).

**Tech Stack:** Arduino C++ (`analogWrite`, `digitalRead`, `millis`-based debounce), no libraries required.

---

## File Map

| Action | Path | Responsibility |
|--------|------|----------------|
| Create | `projects/archive/11-spinning-fan-transistor/11-spinning-fan.ino` | Original transistor version — preserved for reference |
| Create | `projects/archive/11-spinning-fan-transistor/README.md` | Original README — preserved for reference |
| Rewrite | `projects/11-spinning-fan/11-spinning-fan.ino` | New L293D + direction control code |
| Rewrite | `projects/11-spinning-fan/README.md` | New wiring guide and explanation |

---

### Task 1: Archive the original project 11

**Files:**
- Create: `projects/archive/11-spinning-fan-transistor/11-spinning-fan.ino`
- Create: `projects/archive/11-spinning-fan-transistor/README.md`

- [ ] **Step 1: Create archive folder and copy files**

```bash
mkdir -p projects/archive/11-spinning-fan-transistor
cp projects/11-spinning-fan/11-spinning-fan.ino projects/archive/11-spinning-fan-transistor/11-spinning-fan.ino
cp projects/11-spinning-fan/README.md projects/archive/11-spinning-fan-transistor/README.md
```

- [ ] **Step 2: Verify copies exist and match originals**

```bash
diff projects/11-spinning-fan/11-spinning-fan.ino projects/archive/11-spinning-fan-transistor/11-spinning-fan.ino
diff projects/11-spinning-fan/README.md projects/archive/11-spinning-fan-transistor/README.md
```

Expected: no output (files are identical).

- [ ] **Step 3: Commit the archive**

```bash
git add projects/archive/11-spinning-fan-transistor/
git commit -m "chore: archive original project 11 transistor version for future reference"
```

---

### Task 2: Rewrite the .ino file

**Files:**
- Rewrite: `projects/11-spinning-fan/11-spinning-fan.ino`

- [ ] **Step 1: Write the new .ino file**

Replace the entire contents of `projects/11-spinning-fan/11-spinning-fan.ino` with:

```cpp
/*
 * Project 11: Spinning Fan
 *
 * What this does: turn the knob to make a motor spin faster or slower,
 *                 and press the button to flip the direction — like reversing a fan!
 *
 * Parts needed:
 *   - 1 × DC motor (small, 3–5V, with 2 wires)
 *   - 1 × L293D motor driver chip (16-pin DIP)
 *   - 1 × L7805ABV 5V regulator (TO-220, 3 legs)
 *   - 1 × 9V battery + clip
 *   - 1 × potentiometer (round knob)
 *   - 1 × tact-switch button
 *   - 1 × green LED + 220Ω resistor  (forward indicator)
 *   - 1 × red LED   + 220Ω resistor  (reverse indicator)
 *   - jumper wires
 *
 * WHY CAN'T WE PLUG THE MOTOR STRAIGHT INTO ARDUINO?
 *   Motors are hungry — they need more electricity than an Arduino pin can give.
 *   They also make electrical noise that can confuse or even damage Arduino.
 *   The L293D chip acts like a helper: it takes instructions from Arduino
 *   and passes them to the motor, while keeping the motor's stronger electricity
 *   safely away from Arduino.
 *   The 9V battery powers the motor. The L7805 regulator steps that 9V down
 *   to a safe 5V so the motor doesn't get too much power.
 *
 * DIRECTION CONTROL:
 *   The L293D controls direction using two pins (IN1 and IN2):
 *     IN1=HIGH, IN2=LOW  → motor spins forward
 *     IN1=LOW,  IN2=HIGH → motor spins in reverse
 *   We flip these two pins every time the button is pressed.
 *
 * Written for children — every line is explained!
 */

// --- Pin assignments ---
#define EN1_PIN  9   // L293D enable pin — controls speed via PWM
#define IN1_PIN  7   // L293D input 1 — direction signal A
#define IN2_PIN  8   // L293D input 2 — direction signal B
#define POT_PIN  A0  // potentiometer middle leg — reads knob position
#define BTN_PIN  2   // direction toggle button (other leg to GND)
#define LED_FWD  4   // green LED — lights up when going forward
#define LED_REV  5   // red LED   — lights up when going in reverse

// --- State variables ---
bool goingForward = true;   // true = forward, false = reverse

// Button debounce — we use millis() so the motor doesn't pause when pressed
bool lastButtonState = HIGH;          // button unpressed reads HIGH (INPUT_PULLUP)
unsigned long lastDebounceTime = 0;   // when the button last changed
const unsigned long DEBOUNCE_MS = 50; // ignore changes shorter than 50 milliseconds

// setup() runs once when the Arduino turns on
void setup() {
  pinMode(EN1_PIN, OUTPUT);  // speed control — PWM output to L293D enable
  pinMode(IN1_PIN, OUTPUT);  // direction signal A
  pinMode(IN2_PIN, OUTPUT);  // direction signal B
  pinMode(LED_FWD, OUTPUT);  // green LED
  pinMode(LED_REV, OUTPUT);  // red LED

  // INPUT_PULLUP means the pin reads HIGH when the button is not pressed.
  // When the button is pressed it connects the pin to GND, so it reads LOW.
  // This way we don't need an external resistor on the button!
  pinMode(BTN_PIN, INPUT_PULLUP);

  // Start in forward direction
  setDirection(goingForward);

  Serial.begin(9600);  // start communication with the computer
}

// loop() runs over and over, forever
void loop() {
  // --- Read and apply motor speed ---
  // Read the knob: gives 0 (all the way left) to 1023 (all the way right)
  int knobValue = analogRead(POT_PIN);

  // Convert 0–1023 to 0–255 (the range analogWrite understands)
  int motorSpeed = map(knobValue, 0, 1023, 0, 255);

  // Send the speed to the L293D enable pin
  // 0 = motor stopped, 255 = full speed
  analogWrite(EN1_PIN, motorSpeed);

  // --- Check button for direction toggle ---
  bool currentButtonState = digitalRead(BTN_PIN);

  // Only act when the button state actually changes
  if (currentButtonState != lastButtonState) {
    lastDebounceTime = millis();  // record when the change happened
  }

  // Wait until the button has been stable for DEBOUNCE_MS milliseconds
  if ((millis() - lastDebounceTime) > DEBOUNCE_MS) {
    // Button just pressed (HIGH → LOW means finger pressed down)
    if (currentButtonState == LOW && lastButtonState == HIGH) {
      goingForward = !goingForward;  // flip direction
      setDirection(goingForward);
    }
  }

  lastButtonState = currentButtonState;  // remember for next loop

  // --- Show info in Serial Monitor ---
  Serial.print("Speed: ");
  Serial.print(motorSpeed);
  Serial.print("  Direction: ");
  Serial.println(goingForward ? "FORWARD" : "REVERSE");
}

// setDirection() updates the L293D inputs and the indicator LEDs
// Call it with true for forward, false for reverse
void setDirection(bool forward) {
  if (forward) {
    digitalWrite(IN1_PIN, HIGH);  // IN1=HIGH, IN2=LOW → forward
    digitalWrite(IN2_PIN, LOW);
    digitalWrite(LED_FWD, HIGH);  // green LED on
    digitalWrite(LED_REV, LOW);   // red LED off
  } else {
    digitalWrite(IN1_PIN, LOW);   // IN1=LOW, IN2=HIGH → reverse
    digitalWrite(IN2_PIN, HIGH);
    digitalWrite(LED_FWD, LOW);   // green LED off
    digitalWrite(LED_REV, HIGH);  // red LED on
  }
}
```

- [ ] **Step 2: Verify the file compiles (no Arduino board needed)**

```bash
arduino-cli compile --fqbn arduino:renesas_uno:unor4wifi projects/11-spinning-fan/
```

Expected output ends with: `Used platform Version` and no errors. If `arduino-cli` is not available, skip this step and note it for manual verification.

- [ ] **Step 3: Commit**

```bash
git add projects/11-spinning-fan/11-spinning-fan.ino
git commit -m "feat: project 11 — rewrite with L293D motor driver and direction control"
```

---

### Task 3: Rewrite the README

**Files:**
- Rewrite: `projects/11-spinning-fan/README.md`

- [ ] **Step 1: Write the new README**

Replace the entire contents of `projects/11-spinning-fan/README.md` with:

```markdown
# Project 11: Spinning Fan ⭐⭐⭐

> Control a motor with a knob and flip its direction with a button!

## What you will build

A motor you can control like a real fan:
turn the knob to set the speed, and press a button to flip the direction.
A green light shows the motor is going forward.
A red light shows the motor is going in reverse.

## Why can't we plug the motor straight into Arduino?

Motors are hungry — they need more electricity than an Arduino pin can give.
They also make electrical noise that can confuse or damage Arduino.

That is why we use two special helpers:

- The **L293D chip** takes instructions from Arduino and passes them to the motor.
  It keeps the motor's stronger electricity safely away from Arduino.
- The **9V battery** powers the motor from its own supply — not from Arduino.
- The **L7805 regulator** sits between the battery and the chip.
  It steps the 9V down to a safe 5V so the motor doesn't get too much power.

## What you need

- 1 × DC motor (small, with 2 short wires)
- 1 × L293D motor driver chip (16 legs — place it across the middle of the breadboard)
- 1 × L7805ABV 5V voltage regulator (looks like a small transistor with a metal tab)
- 1 × 9V battery + battery clip
- 1 × Potentiometer (round knob)
- 1 × Tact-switch button
- 1 × Green LED
- 1 × Red LED
- 2 × Resistor 220Ω (**red, red, brown, gold** stripes)
- Several jumper wires
- 1 × Arduino Uno R4 WiFi
- 1 × Breadboard

## Difficulty

⭐⭐⭐ — more parts than earlier projects, but each part has one clear job!

## Wiring

### Step 1 — Place the L293D chip

Push the L293D chip into the breadboard so its legs straddle the centre gap.
The small notch or dot on the chip marks **pin 1** (top-left when the notch faces left).

```
        notch
         ▽
  16 |‾‾‾‾‾‾‾‾| 1
  15 |        | 2
  14 |        | 3
  13 |        | 4
  12 |        | 5
  11 |        | 6
  10 |        | 7
   9 |________| 8
```

### Step 2 — Wire the L7805 regulator (9V → 5V)

Hold the L7805 with the **metal tab facing away** from you and legs pointing down:

```
  [ metal tab ]
  |    |    |
  IN  GND  OUT
```

| L7805 leg | Connect to |
|-----------|-----------|
| IN | 9V battery **red** wire |
| GND | 9V battery **black** wire AND Arduino GND |
| OUT | L293D **pin 8** |

### Step 3 — Wire the L293D chip

| L293D pin | Connect to | What it does |
|-----------|-----------|--------------|
| Pin 1 (EN1) | Arduino **pin 9** | Speed — PWM signal |
| Pin 2 (IN1) | Arduino **pin 7** | Direction signal A |
| Pin 3 (OUT1) | Motor wire 1 | Motor output A |
| Pin 4 (GND) | Arduino **GND** | Ground |
| Pin 5 (GND) | Arduino **GND** | Ground |
| Pin 6 (OUT2) | Motor wire 2 | Motor output B |
| Pin 7 (IN2) | Arduino **pin 8** | Direction signal B |
| Pin 8 (Vmotor) | L7805 **OUT** | Motor power (5V regulated) |
| Pin 16 (Vcc) | Arduino **5V** | Logic power for chip |
| Pins 9–15 | leave unconnected | (second channel, not used) |

### Step 4 — Wire the motor

| Motor wire | Connect to |
|-----------|-----------|
| Wire 1 | L293D **pin 3** (OUT1) |
| Wire 2 | L293D **pin 6** (OUT2) |

Don't worry which wire goes where — if the motor spins backwards, just swap the two motor wires.

### Step 5 — Wire the direction button

| Button leg | Connect to |
|-----------|-----------|
| Leg 1 | Arduino **pin 2** |
| Leg 2 | Arduino **GND** |

No resistor needed — the Arduino has a built-in pull-up resistor for this pin.

### Step 6 — Wire the green LED (forward indicator)

| Component | Connect to |
|-----------|-----------|
| Green LED long leg (+) | Arduino **pin 4** |
| Green LED short leg (−) | 220Ω resistor → Arduino **GND** |

### Step 7 — Wire the red LED (reverse indicator)

| Component | Connect to |
|-----------|-----------|
| Red LED long leg (+) | Arduino **pin 5** |
| Red LED short leg (−) | 220Ω resistor → Arduino **GND** |

### Step 8 — Wire the potentiometer

| Potentiometer leg | Connect to |
|-------------------|-----------|
| Left leg | Arduino **GND** |
| Middle leg | Arduino **A0** |
| Right leg | Arduino **5V** |

### Step 9 — Connect the 9V battery

Clip the battery clip onto the battery. The red wire goes to the L7805 IN leg and the black wire goes to GND. **Connect the battery last, after all other wires are in place.**

## How to upload the code

1. Open `11-spinning-fan/11-spinning-fan.ino` in Arduino IDE.
2. Go to **Tools → Board → Arduino UNO R4 Boards** and select **Arduino UNO R4 WiFi**.
3. Click the big **→ Upload** arrow at the top.
4. Wait for "Done uploading" at the bottom of the screen.

## What should happen

- Knob all the way **left** → motor **stopped**
- Turn knob **right** → motor starts spinning and speeds up
- **Green LED on** → motor spinning forward
- **Red LED on** → motor spinning in reverse
- **Press the button** → direction flips, LEDs swap

> 💡 **Tip:** If the motor does not move at low knob positions, turn the knob further right — some motors need a push to get started!

> 💡 **Tip:** If the motor spins the wrong way when you expect forward, swap the two motor wires on the breadboard.

## How does it work?

The potentiometer sends a number to the Arduino.
Arduino converts that number into a PWM signal (rapid on/off pulses) and sends it to the L293D's enable pin — more pulses means more speed.
When you press the button, Arduino swaps the two direction signals (IN1 and IN2), which makes the L293D reverse the electricity flow through the motor — and the motor spins the other way!

## Want to learn more? (optional)

**Challenge: add a stop zone.**
Right now, if the knob is all the way left, the motor slows to a stop — but the direction is still selected.
Can you change the code so that the motor is completely stopped when the speed is 0,
no matter which direction is selected?

*Hint: check if `motorSpeed == 0` before sending the direction signals.*
```

- [ ] **Step 2: Verify the README looks correct**

Open `projects/11-spinning-fan/README.md` and read through it. Check:
- L293D pin table has pins 1–16 all accounted for
- L7805 leg names match (IN, GND, OUT)
- Arduino pin numbers match the `.ino` file (EN1=9, IN1=7, IN2=8, BTN=2, LED_FWD=4, LED_REV=5, POT=A0)

- [ ] **Step 3: Commit**

```bash
git add projects/11-spinning-fan/README.md
git commit -m "docs: project 11 — rewrite README for L293D motor driver and direction control"
```

---

### Task 4: Final check

- [ ] **Step 1: Confirm all four files exist**

```bash
ls projects/archive/11-spinning-fan-transistor/
ls projects/11-spinning-fan/
```

Expected:
```
projects/archive/11-spinning-fan-transistor/: 11-spinning-fan.ino  README.md
projects/11-spinning-fan/:                    11-spinning-fan.ino  README.md
```

- [ ] **Step 2: Confirm git log shows three clean commits**

```bash
git log --oneline -5
```

Expected (most recent first):
```
docs: project 11 — rewrite README for L293D motor driver and direction control
feat: project 11 — rewrite with L293D motor driver and direction control
chore: archive original project 11 transistor version for future reference
```

- [ ] **Step 3: Spot-check pin consistency between .ino and README**

```bash
grep -n "pin" projects/11-spinning-fan/11-spinning-fan.ino | grep define
grep -n "pin [0-9]" projects/11-spinning-fan/README.md
```

Verify:
- EN1 = pin 9 in both files
- IN1 = pin 7 in both files
- IN2 = pin 8 in both files
- BTN = pin 2 in both files
- LED_FWD = pin 4 in both files
- LED_REV = pin 5 in both files
- POT = A0 in both files
