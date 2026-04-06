# Arduino Kids Curriculum — Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Build 13 standalone Arduino projects for children (~8 years old), each with a heavily-commented `.ino` sketch and a child-friendly README with step-by-step wiring instructions.

**Architecture:** Each project is a self-contained folder under `projects/`. The folder name matches the `.ino` filename (Arduino IDE requirement). READMEs use simple English, numbered wiring steps, and connection tables. Code uses descriptive names and comments explaining every line.

**Tech Stack:** Arduino Uno R4 WiFi (`arduino:renesas_uno:unor4wifi`), `arduino-cli` at `./bin/arduino-cli`, libraries: DHT sensor library, Adafruit Unified Sensor, LiquidCrystal (built-in), NewPing, Servo (built-in), MFRC522, Arduino_LED_Matrix (bundled with core), ArduinoGraphics.

---

## Reference: Pin Assignments

| Project | Component | Pin |
|---------|-----------|-----|
| 01 | LED | D9 |
| 02 | Red LED | D2 |
| 02 | Yellow LED | D3 |
| 02 | Green LED | D4 |
| 03 | Button | D2 |
| 03 | LED | D9 |
| 04 | Button | D2 |
| 04 | Buzzer | D8 |
| 05 | RGB Red | D9 (PWM) |
| 05 | RGB Green | D10 (PWM) |
| 05 | RGB Blue | D11 (PWM) |
| 05 | Potentiometer | A0 |
| 06 | Photoresistor | A0 |
| 06 | LED | D9 |
| 07 | DHT11 data | D2 |
| 07 | LCD RS | D7 |
| 07 | LCD E | D8 |
| 07 | LCD D4 | D9 |
| 07 | LCD D5 | D10 |
| 07 | LCD D6 | D11 |
| 07 | LCD D7 | D12 |
| 08 | PIR OUT | D2 |
| 08 | Buzzer | D8 |
| 09 | HC-SR04 TRIG | D9 |
| 09 | HC-SR04 ECHO | D10 |
| 09 | Buzzer | D8 |
| 10 | Servo signal | D9 |
| 11 | BC547 base | D9 (PWM) |
| 11 | Potentiometer | A0 |
| 12 | RC522 SDA/SS | D10 |
| 12 | RC522 SCK | D13 |
| 12 | RC522 MOSI | D11 |
| 12 | RC522 MISO | D12 |
| 12 | RC522 RST | D9 |
| 12 | Green LED | D3 |
| 12 | Red LED | D4 |
| 12 | Buzzer | D8 |
| 13 | (built-in 12×8 matrix) | — |

---

## Reference: README Template

Every README must follow this exact structure:

```
# Project NN: [Name] [stars]

> [One fun sentence describing what it does.]

## What you will build
[2–3 sentences describing the result in concrete, exciting terms.]

## What you need
- N × [Component name]
- ...

## Difficulty
[stars] — [one-line difficulty description]

## Wiring

### Step-by-step

1. [Plain-English wiring instruction]
2. ...

### Connection table

| Wire from | Wire to |
|-----------|---------|
| Arduino GND | Breadboard − rail |
| ... | ... |

## How to upload the code

1. Open the file `NN-name/NN-name.ino` in Arduino IDE.
2. Make sure the board is set to **Arduino UNO R4 WiFi**.
3. Click the big **→ Upload** arrow at the top.
4. Wait for "Done uploading" at the bottom.

## What should happen
[Concrete description of expected behavior.]

## How does it work?
[2–4 child-friendly sentences. No jargon.]

## Want to learn more? (optional)
[One fun challenge or science question. Skipping this is fine.]
```

---

## Reference: .ino Comment Style

Every `.ino` file must open with a block comment:

```cpp
/*
 * Project NN: [Name]
 *
 * What this does: [one sentence]
 *
 * Parts needed:
 *   - [list]
 *
 * Written for children — every line is explained!
 */
```

Then use inline comments on every non-obvious line:

```cpp
// This sets up the Arduino — it runs once when you plug in the power
void setup() {
  pinMode(LED_PIN, OUTPUT);  // tell Arduino that pin 9 is an OUTPUT (it will send electricity out)
}

// This runs over and over, forever — like a heartbeat
void loop() {
  digitalWrite(LED_PIN, HIGH);  // turn the LED ON (HIGH = electricity flowing)
  delay(1000);                  // wait 1000 milliseconds = 1 second
  digitalWrite(LED_PIN, LOW);   // turn the LED OFF
  delay(1000);                  // wait 1 second again
}
```

---

## Task 0: Setup

**Files:** none created yet

- [ ] **Step 1: Create project directory structure**

```bash
mkdir -p /workspaces/arduino/projects
```

- [ ] **Step 2: Verify the Arduino core is installed**

```bash
./bin/arduino-cli core list
```

Expected output includes: `arduino:renesas_uno   1.5.3   Arduino UNO R4 Boards`

If missing, run:
```bash
./bin/arduino-cli core install arduino:renesas_uno
```

- [ ] **Step 3: Install all required libraries**

```bash
./bin/arduino-cli lib install "DHT sensor library"
./bin/arduino-cli lib install "Adafruit Unified Sensor"
./bin/arduino-cli lib install "NewPing"
./bin/arduino-cli lib install "MFRC522"
./bin/arduino-cli lib install "ArduinoGraphics"
```

LiquidCrystal and Servo are built into the core — no install needed.
Arduino_LED_Matrix is bundled with the `arduino:renesas_uno` core — no install needed.

- [ ] **Step 4: Verify libraries installed**

```bash
./bin/arduino-cli lib list
```

Expected: DHT sensor library, Adafruit Unified Sensor, NewPing, MFRC522, ArduinoGraphics all listed.

- [ ] **Step 5: Commit**

```bash
git init  # only if not already a git repo
git add .
git commit -m "chore: initial setup, install libraries and core"
```

---

## Task 1: Project 01 — Blink

**Files:**
- Create: `projects/01-blink/01-blink.ino`
- Create: `projects/01-blink/README.md`

- [ ] **Step 1: Create the project folder and .ino file**

```bash
mkdir -p /workspaces/arduino/projects/01-blink
```

Write `projects/01-blink/01-blink.ino`:

```cpp
/*
 * Project 01: Blink
 *
 * What this does: makes an LED flash on and off, over and over.
 *
 * Parts needed:
 *   - 1 × LED (any color)
 *   - 1 × Resistor (220 ohm — red-red-brown stripes)
 *   - 2 × jumper wires
 *
 * Written for children — every line is explained!
 */

// This gives the number 9 a friendly name: LED_PIN
// It means "the LED is connected to pin number 9"
#define LED_PIN 9

// setup() runs once when the Arduino turns on
void setup() {
  // Tell the Arduino that pin 9 will send electricity OUT (OUTPUT)
  pinMode(LED_PIN, OUTPUT);
}

// loop() runs over and over, forever — like a heartbeat
void loop() {
  digitalWrite(LED_PIN, HIGH);  // HIGH = turn the LED ON
  delay(1000);                  // wait 1 second (1000 milliseconds)
  digitalWrite(LED_PIN, LOW);   // LOW = turn the LED OFF
  delay(1000);                  // wait 1 second
  // now loop() starts again from the top!
}
```

- [ ] **Step 2: Write `projects/01-blink/README.md`**

Follow the README template. Key content:

- **What you will build:** An LED that flashes on and off by itself — like the heartbeat of your Arduino!
- **What you need:** 1× LED, 1× 220 ohm resistor (red-red-brown stripes), 2× jumper wires, Arduino + breadboard
- **Difficulty:** ⭐ — great first project, only 2 wires!
- **Wiring steps:**
  1. Push the LED into the breadboard. The LONGER leg is + (positive). The SHORTER leg is − (negative).
  2. Connect one end of the resistor to the LONGER leg (+ side) of the LED.
  3. Connect a jumper wire from the other end of the resistor to **pin 9** on the Arduino.
  4. Connect a jumper wire from the SHORTER leg (− side) of the LED to any **GND** pin on the Arduino.
- **Connection table:**

| Wire from | Wire to |
|-----------|---------|
| LED long leg (+) → resistor → | Arduino pin 9 |
| LED short leg (−) | Arduino GND |

- **What should happen:** The LED flashes: ON for 1 second, OFF for 1 second, forever.
- **How does it work?** The Arduino sends electricity to pin 9 for 1 second, then stops for 1 second. The LED lights up when electricity flows through it.
- **Want to learn more?** Change `delay(1000)` to `delay(200)` and upload again. Can you make it blink as fast as your heartbeat?

- [ ] **Step 3: Compile to verify no errors**

```bash
./bin/arduino-cli compile --fqbn arduino:renesas_uno:unor4wifi projects/01-blink/
```

Expected: `Compilation successful`

- [ ] **Step 4: Commit**

```bash
git add projects/01-blink/
git commit -m "feat: project 01 - blink"
```

---

## Task 2: Project 02 — Traffic Light

**Files:**
- Create: `projects/02-traffic-light/02-traffic-light.ino`
- Create: `projects/02-traffic-light/README.md`

- [ ] **Step 1: Create folder and .ino file**

```bash
mkdir -p /workspaces/arduino/projects/02-traffic-light
```

Write `projects/02-traffic-light/02-traffic-light.ino`:

```cpp
/*
 * Project 02: Traffic Light
 *
 * What this does: cycles through red, yellow, and green LEDs
 *                 just like a real traffic light.
 *
 * Parts needed:
 *   - 1 × red LED
 *   - 1 × yellow LED
 *   - 1 × green LED
 *   - 3 × resistor (220 ohm — red-red-brown stripes)
 *   - jumper wires
 *
 * Written for children — every line is explained!
 */

#define RED_PIN    2   // red LED is connected to pin 2
#define YELLOW_PIN 3   // yellow LED is connected to pin 3
#define GREEN_PIN  4   // green LED is connected to pin 4

void setup() {
  // Tell Arduino that all three pins will send electricity OUT
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
}

// A helper function to make all lights turn off at once
// We call this before turning on each new light
void allOff() {
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
}

void loop() {
  // --- RED: stop! ---
  allOff();                       // make sure everything is off first
  digitalWrite(RED_PIN, HIGH);    // turn red ON
  delay(3000);                    // stay red for 3 seconds

  // --- YELLOW: get ready to go ---
  allOff();
  digitalWrite(YELLOW_PIN, HIGH); // turn yellow ON
  delay(1000);                    // stay yellow for 1 second

  // --- GREEN: go! ---
  allOff();
  digitalWrite(GREEN_PIN, HIGH);  // turn green ON
  delay(3000);                    // stay green for 3 seconds

  // --- YELLOW again: get ready to stop ---
  allOff();
  digitalWrite(YELLOW_PIN, HIGH);
  delay(1000);

  // now loop() starts again — red, yellow, green, yellow, red...
}
```

- [ ] **Step 2: Write `projects/02-traffic-light/README.md`**

Key content:
- **What you will build:** Three LEDs that cycle like a real traffic light — red, yellow, green!
- **What you need:** 1× red LED, 1× yellow LED, 1× green LED, 3× 220 ohm resistors, jumper wires, Arduino + breadboard
- **Difficulty:** ⭐ — three LEDs, six wires
- **Wiring steps:** Wire all three LEDs the same way as project 01, using pins 2, 3, and 4 respectively. Each LED gets its own resistor.
- **Connection table:**

| Wire from | Wire to |
|-----------|---------|
| Red LED long leg (+) → resistor | Arduino pin 2 |
| Red LED short leg (−) | Arduino GND |
| Yellow LED long leg (+) → resistor | Arduino pin 3 |
| Yellow LED short leg (−) | Arduino GND |
| Green LED long leg (+) → resistor | Arduino pin 4 |
| Green LED short leg (−) | Arduino GND |

- **What should happen:** Red for 3 seconds → yellow for 1 second → green for 3 seconds → yellow for 1 second → repeat.
- **How does it work?** The Arduino turns one LED on at a time, waits, then switches to the next — just like a real traffic light controller.
- **Want to learn more?** Real traffic lights in Poland stay red for about 60 seconds. Try changing `3000` to `60000`. What happens?

- [ ] **Step 3: Compile**

```bash
./bin/arduino-cli compile --fqbn arduino:renesas_uno:unor4wifi projects/02-traffic-light/
```

- [ ] **Step 4: Commit**

```bash
git add projects/02-traffic-light/
git commit -m "feat: project 02 - traffic light"
```

---

## Task 3: Project 03 — Button Light

**Files:**
- Create: `projects/03-button-light/03-button-light.ino`
- Create: `projects/03-button-light/README.md`

- [ ] **Step 1: Create folder and .ino file**

```bash
mkdir -p /workspaces/arduino/projects/03-button-light
```

Write `projects/03-button-light/03-button-light.ino`:

```cpp
/*
 * Project 03: Button Light
 *
 * What this does: the LED turns ON when you press the button,
 *                 and turns OFF when you let go.
 *
 * Parts needed:
 *   - 1 × LED (any color)
 *   - 1 × resistor (220 ohm — red-red-brown stripes)
 *   - 1 × tact-switch button
 *   - jumper wires
 *
 * Written for children — every line is explained!
 */

#define BUTTON_PIN 2   // the button is connected to pin 2
#define LED_PIN    9   // the LED is connected to pin 9

void setup() {
  pinMode(LED_PIN, OUTPUT);           // pin 9 sends electricity OUT to the LED
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // pin 2 reads the button
                                      // INPUT_PULLUP means: when button is NOT pressed,
                                      // the pin reads HIGH. When pressed, it reads LOW.
                                      // (This is why we check for LOW below!)
}

void loop() {
  // Read the button: is it being pressed right now?
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW) {
    // LOW means the button IS pressed — turn the LED on!
    digitalWrite(LED_PIN, HIGH);
  } else {
    // HIGH means the button is NOT pressed — turn the LED off
    digitalWrite(LED_PIN, LOW);
  }
}
```

- [ ] **Step 2: Write `projects/03-button-light/README.md`**

Key content:
- **What you will build:** A light switch you control with a button — press it to light up!
- **What you need:** 1× LED, 1× 220 ohm resistor, 1× tact-switch button, jumper wires, Arduino + breadboard
- **Difficulty:** ⭐ — your first interactive project!
- **Wiring steps:**
  1. Push the button into the breadboard so it straddles the center gap.
  2. Connect one leg of the button to pin 2 on the Arduino.
  3. Connect the opposite leg of the button to GND on the Arduino.
  4. Wire the LED and resistor to pin 9 and GND (same as project 01).
- **Connection table:**

| Wire from | Wire to |
|-----------|---------|
| Button leg 1 | Arduino pin 2 |
| Button leg 2 | Arduino GND |
| LED long leg (+) → resistor | Arduino pin 9 |
| LED short leg (−) | Arduino GND |

- **What should happen:** LED is OFF. Press button → LED turns ON. Let go → LED turns OFF.
- **How does it work?** The button connects the pin to GND when pressed. The Arduino reads this as LOW and turns the LED on. When you let go, the built-in pull-up resistor brings the pin back to HIGH, and the LED turns off.
- **Want to learn more?** Can you change the code so the LED stays ON until you press the button again (a toggle)?

- [ ] **Step 3: Compile**

```bash
./bin/arduino-cli compile --fqbn arduino:renesas_uno:unor4wifi projects/03-button-light/
```

- [ ] **Step 4: Commit**

```bash
git add projects/03-button-light/
git commit -m "feat: project 03 - button light"
```

---

## Task 4: Project 04 — Buzzer Doorbell

**Files:**
- Create: `projects/04-buzzer-doorbell/04-buzzer-doorbell.ino`
- Create: `projects/04-buzzer-doorbell/README.md`

- [ ] **Step 1: Create folder and .ino file**

```bash
mkdir -p /workspaces/arduino/projects/04-buzzer-doorbell
```

Write `projects/04-buzzer-doorbell/04-buzzer-doorbell.ino`:

```cpp
/*
 * Project 04: Buzzer Doorbell
 *
 * What this does: makes a BEEP sound when you press the button —
 *                 just like a doorbell!
 *
 * Parts needed:
 *   - 1 × buzzer (the black round one)
 *   - 1 × tact-switch button
 *   - jumper wires
 *
 * Note: this buzzer has a generator built in — it makes sound
 *       whenever electricity flows through it. No code for sound needed!
 *
 * Written for children — every line is explained!
 */

#define BUTTON_PIN 2   // button is on pin 2
#define BUZZER_PIN 8   // buzzer is on pin 8

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);        // pin 8 will send electricity to the buzzer
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // read the button (LOW = pressed)
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);  // read the button

  if (buttonState == LOW) {
    // Button is pressed — send electricity to the buzzer to make it BEEP
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    // Button is not pressed — stop the buzzer
    digitalWrite(BUZZER_PIN, LOW);
  }
}
```

- [ ] **Step 2: Write `projects/04-buzzer-doorbell/README.md`**

Key content:
- **What you will build:** A real doorbell — press the button, hear the BEEP!
- **What you need:** 1× active buzzer, 1× tact-switch button, jumper wires, Arduino + breadboard
- **Difficulty:** ⭐ — two wires for the buzzer, two for the button
- **Wiring steps:**
  1. The buzzer has two legs. The LONGER leg is + (positive). Note: some buzzers are labeled with a + on top.
  2. Connect the buzzer's long leg (+) to pin 8 on the Arduino.
  3. Connect the buzzer's short leg (−) to GND on the Arduino.
  4. Wire the button the same way as project 03: one leg to pin 2, other leg to GND.
- **Connection table:**

| Wire from | Wire to |
|-----------|---------|
| Buzzer long leg (+) | Arduino pin 8 |
| Buzzer short leg (−) | Arduino GND |
| Button leg 1 | Arduino pin 2 |
| Button leg 2 | Arduino GND |

- **What should happen:** Silence. Press button → BEEEEEP. Let go → silence.
- **How does it work?** The buzzer has a tiny vibrating disc inside. When electricity flows in, the disc vibrates and makes sound — just like a speaker!
- **Want to learn more?** Can you wire both an LED AND the buzzer so pressing the button makes both light AND sound?

- [ ] **Step 3: Compile**

```bash
./bin/arduino-cli compile --fqbn arduino:renesas_uno:unor4wifi projects/04-buzzer-doorbell/
```

- [ ] **Step 4: Commit**

```bash
git add projects/04-buzzer-doorbell/
git commit -m "feat: project 04 - buzzer doorbell"
```

---

## Task 5: Project 05 — Rainbow RGB

**Files:**
- Create: `projects/05-rainbow-rgb/05-rainbow-rgb.ino`
- Create: `projects/05-rainbow-rgb/README.md`

- [ ] **Step 1: Create folder and .ino file**

```bash
mkdir -p /workspaces/arduino/projects/05-rainbow-rgb
```

Write `projects/05-rainbow-rgb/05-rainbow-rgb.ino`:

```cpp
/*
 * Project 05: Rainbow RGB
 *
 * What this does: turns the knob (potentiometer) to cycle through
 *                 all the colors of the rainbow using ONE special LED!
 *
 * Parts needed:
 *   - 1 × RGB LED (the one with 4 legs — COMMON ANODE type)
 *   - 3 × resistor (220 ohm — red-red-brown stripes)
 *   - 1 × potentiometer (the round knob)
 *   - jumper wires
 *
 * IMPORTANT: This RGB LED is "common anode" — that means:
 *   - The LONGEST leg connects to 5V (power)
 *   - To turn a color ON, we send LOW (0), not HIGH!
 *   - To turn a color OFF, we send HIGH (255)
 *   - This is the OPPOSITE of a normal LED — don't worry, it's normal!
 *
 * Written for children — every line is explained!
 */

#define RED_PIN   9    // red color inside the LED — pin 9 (can do PWM)
#define GREEN_PIN 10   // green color — pin 10 (can do PWM)
#define BLUE_PIN  11   // blue color — pin 11 (can do PWM)
#define POT_PIN   A0   // the potentiometer knob is on analog pin A0

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  // A0 is analog — no pinMode needed for analog reading
}

void loop() {
  // Read the knob — gives a number from 0 to 1023
  int knobValue = analogRead(POT_PIN);

  // Map the knob (0–1023) to a color position (0–767)
  // 768 = 256 × 3 (three color sections in our rainbow)
  int colorPosition = map(knobValue, 0, 1023, 0, 767);

  // Figure out how much red, green, and blue to show
  int red, green, blue;

  if (colorPosition < 256) {
    // Section 1: red fades out, green fades in (red → yellow → green)
    red   = 255 - colorPosition;  // red goes from bright to zero
    green = colorPosition;        // green goes from zero to bright
    blue  = 0;
  } else if (colorPosition < 512) {
    // Section 2: green fades out, blue fades in (green → cyan → blue)
    red   = 0;
    green = 255 - (colorPosition - 256);
    blue  = colorPosition - 256;
  } else {
    // Section 3: blue fades out, red fades in (blue → purple → red)
    red   = colorPosition - 512;
    green = 0;
    blue  = 255 - (colorPosition - 512);
  }

  // For common-anode RGB: we SUBTRACT from 255 because LOW = ON
  // (255 - 255 = 0 = full brightness; 255 - 0 = 255 = off)
  analogWrite(RED_PIN,   255 - red);
  analogWrite(GREEN_PIN, 255 - green);
  analogWrite(BLUE_PIN,  255 - blue);

  delay(10);  // tiny pause to keep things smooth
}
```

- [ ] **Step 2: Write `projects/05-rainbow-rgb/README.md`**

Key content:
- **What you will build:** One tiny LED that can glow in ANY color — turn the knob to travel through the rainbow!
- **What you need:** 1× RGB LED (4 legs), 3× 220 ohm resistors, 1× potentiometer, jumper wires, Arduino + breadboard
- **Difficulty:** ⭐⭐ — slightly tricky wiring, but the result is magical!
- **Important note:** The RGB LED has 4 legs. The LONGEST one goes to **5V** (not GND — this is different from normal LEDs!).

Wiring the RGB LED — identify legs by length and position:
```
  [R] [longest=5V] [G] [B]
  pin9   5V        pin10  pin11
```
Each shorter leg goes through its own 220 ohm resistor to the pin.

- **Connection table:**

| Wire from | Wire to |
|-----------|---------|
| RGB longest leg | Arduino 5V |
| RGB Red leg → resistor | Arduino pin 9 |
| RGB Green leg → resistor | Arduino pin 10 |
| RGB Blue leg → resistor | Arduino pin 11 |
| Potentiometer left leg | Arduino GND |
| Potentiometer middle leg | Arduino A0 |
| Potentiometer right leg | Arduino 5V |

- **What should happen:** Turn the knob slowly — the LED glides through red, yellow, green, cyan, blue, purple, and back to red.
- **How does it work?** Inside the LED are three tiny colored lights (red, green, blue). By mixing them at different brightnesses — just like mixing paint — you can make any color!
- **Want to learn more?** Can you figure out which knob position makes orange? Or pink?

- [ ] **Step 3: Compile**

```bash
./bin/arduino-cli compile --fqbn arduino:renesas_uno:unor4wifi projects/05-rainbow-rgb/
```

- [ ] **Step 4: Commit**

```bash
git add projects/05-rainbow-rgb/
git commit -m "feat: project 05 - rainbow RGB"
```

---

## Task 6: Project 06 — Night Light

**Files:**
- Create: `projects/06-night-light/06-night-light.ino`
- Create: `projects/06-night-light/README.md`

- [ ] **Step 1: Create folder and .ino file**

```bash
mkdir -p /workspaces/arduino/projects/06-night-light
```

Write `projects/06-night-light/06-night-light.ino`:

```cpp
/*
 * Project 06: Night Light
 *
 * What this does: the LED turns ON automatically when it gets dark,
 *                 and turns OFF when there is enough light.
 *                 Just like a real night light!
 *
 * Parts needed:
 *   - 1 × photoresistor (light sensor — looks like a tiny snail)
 *   - 1 × resistor (10k ohm — brown-black-orange stripes)
 *   - 1 × LED (any color)
 *   - 1 × resistor (220 ohm — red-red-brown stripes) for the LED
 *   - jumper wires
 *
 * Written for children — every line is explained!
 */

#define LIGHT_PIN A0   // the photoresistor is connected to analog pin A0
#define LED_PIN   9    // the LED is connected to pin 9

// This is the brightness level where we decide it's "dark"
// 0 = completely dark, 1023 = super bright light
// Try different numbers if your room is very bright or very dark!
#define DARK_THRESHOLD 400

void setup() {
  pinMode(LED_PIN, OUTPUT);
  // A0 reads analog values — no pinMode needed

  // Serial lets us see numbers in the computer — helpful for testing!
  Serial.begin(9600);
}

void loop() {
  // Read how much light the sensor sees (0 = dark, 1023 = bright)
  int lightLevel = analogRead(LIGHT_PIN);

  // Print the number to the computer so we can see it
  Serial.print("Light level: ");
  Serial.println(lightLevel);

  if (lightLevel < DARK_THRESHOLD) {
    // It's dark! Turn the LED on
    digitalWrite(LED_PIN, HIGH);
  } else {
    // There is light — turn the LED off
    digitalWrite(LED_PIN, LOW);
  }

  delay(200);  // check the light 5 times per second
}
```

- [ ] **Step 2: Write `projects/06-night-light/README.md`**

Key content:
- **What you will build:** A smart night light that knows when it's dark and turns itself on!
- **What you need:** 1× photoresistor, 1× 10k ohm resistor (brown-black-orange), 1× LED, 1× 220 ohm resistor, jumper wires, Arduino + breadboard
- **Difficulty:** ⭐⭐ — two separate circuits to build, but each is simple
- **Wiring steps for the photoresistor** (voltage divider — two parts in a row):
  1. Connect a wire from Arduino **5V** to one leg of the photoresistor.
  2. Connect the other leg of the photoresistor to **A0** on the Arduino (and to one end of the 10k resistor).
  3. Connect the other end of the 10k resistor to **GND**.
  4. Wire the LED and 220 ohm resistor to pin 9 and GND as usual.
- **Connection table:**

| Wire from | Wire to |
|-----------|---------|
| Arduino 5V | Photoresistor leg 1 |
| Photoresistor leg 2 | Arduino A0 AND 10k resistor end 1 |
| 10k resistor end 2 | Arduino GND |
| LED long leg (+) → 220 ohm resistor | Arduino pin 9 |
| LED short leg (−) | Arduino GND |

- **Tip:** Open the Serial Monitor in Arduino IDE (the magnifying glass icon) to see the light level numbers while you cover the sensor with your hand!
- **What should happen:** Cover the photoresistor with your hand → LED turns ON. Uncover it → LED turns OFF.
- **How does it work?** The photoresistor changes how much electricity it lets through depending on the light. More light = more resistance = less voltage reaching A0. The Arduino reads this and decides if it's dark.
- **Want to learn more?** Try using Serial Monitor (the magnifying glass in Arduino IDE) to see the numbers change as you cover and uncover the sensor!

- [ ] **Step 3: Compile**

```bash
./bin/arduino-cli compile --fqbn arduino:renesas_uno:unor4wifi projects/06-night-light/
```

- [ ] **Step 4: Commit**

```bash
git add projects/06-night-light/
git commit -m "feat: project 06 - night light"
```

---

## Task 7: Project 07 — Weather Station

**Files:**
- Create: `projects/07-weather-station/07-weather-station.ino`
- Create: `projects/07-weather-station/README.md`

- [ ] **Step 1: Create folder and .ino file**

```bash
mkdir -p /workspaces/arduino/projects/07-weather-station
```

Write `projects/07-weather-station/07-weather-station.ino`:

```cpp
/*
 * Project 07: Weather Station
 *
 * What this does: shows the temperature and humidity on a small screen,
 *                 like a mini weather station!
 *
 * Parts needed:
 *   - 1 × DHT11 sensor (blue, 3 or 4 legs)
 *   - 1 × LCD screen 16x2 (the long blue/green display)
 *   - 1 × resistor (10k ohm — brown-black-orange) for DHT11
 *   - 1 × potentiometer (to adjust screen brightness)
 *   - jumper wires
 *
 * Libraries needed (already installed):
 *   - DHT sensor library by Adafruit
 *   - LiquidCrystal (built-in)
 *
 * Written for children — every line is explained!
 */

#include <DHT.h>          // the library that reads the DHT11 sensor
#include <LiquidCrystal.h> // the library that controls the LCD screen

#define DHT_PIN  2         // DHT11 data wire is on pin 2
#define DHT_TYPE DHT11     // tell the library we have a DHT11 (not DHT22)

// Create a DHT sensor object — think of it as a remote control for the sensor
DHT dht(DHT_PIN, DHT_TYPE);

// Create an LCD object — tell it which Arduino pins control the screen
// Pins: RS=7, E=8, D4=9, D5=10, D6=11, D7=12
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  dht.begin();        // start the DHT11 sensor
  lcd.begin(16, 2);   // start the LCD — 16 columns, 2 rows
  lcd.print("Weather Station!"); // show a welcome message
  delay(2000);        // keep it on screen for 2 seconds
  lcd.clear();        // clear the screen
}

void loop() {
  // Read the temperature in Celsius
  float temperature = dht.readTemperature();

  // Read the humidity (0–100 percent)
  float humidity = dht.readHumidity();

  // Check if the sensor gave us a valid reading
  // (sometimes sensors fail — isnan() checks for "Not a Number")
  if (isnan(temperature) || isnan(humidity)) {
    lcd.clear();
    lcd.print("Sensor error!");
    delay(2000);
    return;  // skip the rest of loop() and try again
  }

  // --- Show temperature on the first row of the screen ---
  lcd.setCursor(0, 0);          // move to column 0, row 0 (top row)
  lcd.print("Temp: ");
  lcd.print(temperature, 1);   // show temperature with 1 decimal place
  lcd.print(" C");

  // --- Show humidity on the second row ---
  lcd.setCursor(0, 1);          // move to column 0, row 1 (bottom row)
  lcd.print("Humidity: ");
  lcd.print(humidity, 0);       // show humidity as a whole number
  lcd.print("%");

  delay(2000);  // update every 2 seconds
}
```

- [ ] **Step 2: Write `projects/07-weather-station/README.md`**

Key content:
- **What you will build:** Your own weather station that shows temperature and humidity on a real screen!
- **What you need:** 1× DHT11 sensor, 1× LCD 16×2 screen, 1× 10k ohm resistor, 1× potentiometer, many jumper wires, Arduino + breadboard
- **Difficulty:** ⭐⭐ — lots of wires for the screen, but each one is simple
- **Important:** The LCD screen needs a potentiometer to adjust contrast. Without it, the screen may be blank or all black.
- **Wiring steps:**
  1. **DHT11 sensor** (flat side facing you, left to right: VCC, DATA, GND):
     - VCC leg → Arduino 5V
     - DATA leg → Arduino pin 2 (also connect a 10k resistor from DATA to 5V)
     - GND leg → Arduino GND
  2. **LCD screen** (uses 6 Arduino pins + power):
     - LCD pin 1 (VSS) → Arduino GND
     - LCD pin 2 (VDD) → Arduino 5V
     - LCD pin 3 (V0, contrast) → potentiometer middle leg
     - LCD pin 4 (RS) → Arduino pin 7
     - LCD pin 5 (R/W) → Arduino GND
     - LCD pin 6 (E) → Arduino pin 8
     - LCD pins 7–10 (D0–D3) → not connected
     - LCD pin 11 (D4) → Arduino pin 9
     - LCD pin 12 (D5) → Arduino pin 10
     - LCD pin 13 (D6) → Arduino pin 11
     - LCD pin 14 (D7) → Arduino pin 12
     - LCD pin 15 (LED+) → Arduino 5V
     - LCD pin 16 (LED−) → Arduino GND
  3. **Potentiometer** (for screen contrast): left leg → GND, middle leg → LCD pin 3, right leg → 5V
- **Tip:** If the screen is blank after uploading, slowly turn the potentiometer knob until text appears.
- **What should happen:** Screen shows temperature and humidity, updating every 2 seconds.

- [ ] **Step 3: Compile**

```bash
./bin/arduino-cli compile --fqbn arduino:renesas_uno:unor4wifi projects/07-weather-station/
```

- [ ] **Step 4: Commit**

```bash
git add projects/07-weather-station/
git commit -m "feat: project 07 - weather station"
```

---

## Task 8: Project 08 — Motion Alarm

**Files:**
- Create: `projects/08-motion-alarm/08-motion-alarm.ino`
- Create: `projects/08-motion-alarm/README.md`

- [ ] **Step 1: Create folder and .ino file**

```bash
mkdir -p /workspaces/arduino/projects/08-motion-alarm
```

Write `projects/08-motion-alarm/08-motion-alarm.ino`:

```cpp
/*
 * Project 08: Motion Alarm
 *
 * What this does: sounds an alarm when it detects movement —
 *                 like a burglar alarm or a surprise trap for your sibling!
 *
 * Parts needed:
 *   - 1 × PIR sensor (the white dome on a small board)
 *   - 1 × buzzer
 *   - jumper wires
 *
 * Written for children — every line is explained!
 */

#define PIR_PIN    2   // PIR sensor output goes to pin 2
#define BUZZER_PIN 8   // buzzer is on pin 8

void setup() {
  pinMode(PIR_PIN, INPUT);     // pin 2 reads the PIR sensor (INPUT = receive electricity)
  pinMode(BUZZER_PIN, OUTPUT); // pin 8 sends electricity to the buzzer

  Serial.begin(9600);

  // The PIR sensor needs a few seconds to "warm up" and learn the room
  Serial.println("Getting ready... wait 5 seconds!");
  delay(5000);  // wait 5 seconds for the sensor to settle
  Serial.println("Ready! I will detect movement now.");
}

void loop() {
  // Read the PIR sensor: HIGH = motion detected, LOW = no motion
  int motionDetected = digitalRead(PIR_PIN);

  if (motionDetected == HIGH) {
    // Something moved! Sound the alarm!
    Serial.println("MOTION DETECTED!");
    digitalWrite(BUZZER_PIN, HIGH);  // turn buzzer ON
    delay(1000);                     // beep for 1 second
    digitalWrite(BUZZER_PIN, LOW);   // turn buzzer OFF
    delay(200);                      // short pause between beeps
  } else {
    // Nothing is moving — stay quiet
    digitalWrite(BUZZER_PIN, LOW);
  }
}
```

- [ ] **Step 2: Write `projects/08-motion-alarm/README.md`**

Key content:
- **What you will build:** A motion alarm! It goes off whenever someone walks past — perfect for guarding your room!
- **What you need:** 1× PIR sensor (white dome), 1× buzzer, jumper wires, Arduino + breadboard
- **Difficulty:** ⭐⭐ — very few wires, but wait 5 seconds before testing!
- **About the PIR sensor:** It has 3 pins. Look at the bottom — they are labeled VCC, OUT, GND.
- **Wiring steps:**
  1. PIR VCC → Arduino 5V
  2. PIR OUT → Arduino pin 2
  3. PIR GND → Arduino GND
  4. Buzzer long leg (+) → Arduino pin 8
  5. Buzzer short leg (−) → Arduino GND
- **Connection table:**

| Wire from | Wire to |
|-----------|---------|
| PIR VCC | Arduino 5V |
| PIR OUT | Arduino pin 2 |
| PIR GND | Arduino GND |
| Buzzer long leg (+) | Arduino pin 8 |
| Buzzer short leg (−) | Arduino GND |

- **What should happen:** After 5 seconds of setup, the alarm beeps whenever it detects movement. Stay very still — it will go quiet!
- **How does it work?** The PIR sensor detects heat from bodies (infrared light). When someone moves nearby, their body heat changes, and the sensor says "someone's there!"
- **Want to learn more?** Can you add an LED that flashes red when motion is detected?

- [ ] **Step 3: Compile**

```bash
./bin/arduino-cli compile --fqbn arduino:renesas_uno:unor4wifi projects/08-motion-alarm/
```

- [ ] **Step 4: Commit**

```bash
git add projects/08-motion-alarm/
git commit -m "feat: project 08 - motion alarm"
```

---

## Task 9: Project 09 — Parking Sensor

**Files:**
- Create: `projects/09-parking-sensor/09-parking-sensor.ino`
- Create: `projects/09-parking-sensor/README.md`

- [ ] **Step 1: Create folder and .ino file**

```bash
mkdir -p /workspaces/arduino/projects/09-parking-sensor
```

Write `projects/09-parking-sensor/09-parking-sensor.ino`:

```cpp
/*
 * Project 09: Parking Sensor
 *
 * What this does: beeps faster and faster as your hand gets closer —
 *                 just like the parking sensor in a car!
 *
 * Parts needed:
 *   - 1 × HC-SR04 ultrasonic distance sensor (looks like two eyes)
 *   - 1 × buzzer
 *   - jumper wires
 *
 * Library needed: NewPing (already installed)
 *
 * Written for children — every line is explained!
 */

#include <NewPing.h>   // the library that makes the distance sensor easy to use

#define TRIG_PIN   9   // TRIG pin sends out the sound wave
#define ECHO_PIN   10  // ECHO pin listens for the bounce back
#define BUZZER_PIN 8   // buzzer is on pin 8

// Maximum distance we care about (in centimeters)
#define MAX_DISTANCE 100

// Create a sonar object — it controls the HC-SR04 sensor
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Measure the distance in centimeters
  // (NewPing sends a ping and measures how long the echo takes)
  int distance = sonar.ping_cm();

  // Print the distance to the computer
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance == 0) {
    // 0 means nothing was detected within MAX_DISTANCE — stay quiet
    digitalWrite(BUZZER_PIN, LOW);
    delay(200);
  } else if (distance > 50) {
    // Far away — slow beeping
    digitalWrite(BUZZER_PIN, HIGH);
    delay(50);
    digitalWrite(BUZZER_PIN, LOW);
    delay(500);
  } else if (distance > 20) {
    // Getting closer — medium beeping
    digitalWrite(BUZZER_PIN, HIGH);
    delay(50);
    digitalWrite(BUZZER_PIN, LOW);
    delay(200);
  } else if (distance > 5) {
    // Very close! Fast beeping
    digitalWrite(BUZZER_PIN, HIGH);
    delay(50);
    digitalWrite(BUZZER_PIN, LOW);
    delay(50);
  } else {
    // TOO CLOSE! Continuous beep
    digitalWrite(BUZZER_PIN, HIGH);
    delay(100);
  }
}
```

- [ ] **Step 2: Write `projects/09-parking-sensor/README.md`**

Key content:
- **What you will build:** A parking sensor that beeps faster and faster as your hand gets closer — exactly like in a real car!
- **What you need:** 1× HC-SR04 sensor (two round "eyes"), 1× buzzer, jumper wires, Arduino + breadboard
- **Difficulty:** ⭐⭐ — the sensor has 4 pins, but each is labeled
- **About the HC-SR04:** It has 4 pins labeled on the back: VCC, TRIG, ECHO, GND.
- **Wiring steps:**
  1. HC-SR04 VCC → Arduino 5V
  2. HC-SR04 TRIG → Arduino pin 9
  3. HC-SR04 ECHO → Arduino pin 10
  4. HC-SR04 GND → Arduino GND
  5. Buzzer long leg (+) → Arduino pin 8
  6. Buzzer short leg (−) → Arduino GND
- **Connection table:**

| Wire from | Wire to |
|-----------|---------|
| HC-SR04 VCC | Arduino 5V |
| HC-SR04 TRIG | Arduino pin 9 |
| HC-SR04 ECHO | Arduino pin 10 |
| HC-SR04 GND | Arduino GND |
| Buzzer long leg (+) | Arduino pin 8 |
| Buzzer short leg (−) | Arduino GND |

- **What should happen:** Slowly bring your hand toward the sensor. Far away = slow beep. Close = fast beep. Very close = continuous tone!
- **How does it work?** The sensor sends out a sound wave (too high for humans to hear) and listens for it to bounce back. The longer it takes to bounce, the farther the object is — exactly like a bat using echolocation!

- [ ] **Step 3: Compile**

```bash
./bin/arduino-cli compile --fqbn arduino:renesas_uno:unor4wifi projects/09-parking-sensor/
```

- [ ] **Step 4: Commit**

```bash
git add projects/09-parking-sensor/
git commit -m "feat: project 09 - parking sensor"
```

---

## Task 10: Project 10 — Servo Wave

**Files:**
- Create: `projects/10-servo-wave/10-servo-wave.ino`
- Create: `projects/10-servo-wave/README.md`

- [ ] **Step 1: Create folder and .ino file**

```bash
mkdir -p /workspaces/arduino/projects/10-servo-wave
```

Write `projects/10-servo-wave/10-servo-wave.ino`:

```cpp
/*
 * Project 10: Servo Wave
 *
 * What this does: makes a servo motor arm sweep back and forth —
 *                 like a robot waving hello!
 *
 * Parts needed:
 *   - 1 × servo motor MG-90S (with 3-wire cable)
 *   - jumper wires
 *
 * The servo has 3 wires (usually):
 *   - Brown or Black = GND
 *   - Red            = 5V power
 *   - Orange or Yellow = signal (control wire)
 *
 * Written for children — every line is explained!
 */

#include <Servo.h>   // the library that controls servo motors

#define SERVO_PIN 9   // the servo signal wire connects to pin 9

Servo myServo;  // create a servo object named "myServo"

void setup() {
  // Tell the servo object which pin it is connected to
  myServo.attach(SERVO_PIN);
}

void loop() {
  // Sweep from 0 degrees to 180 degrees, one degree at a time
  for (int angle = 0; angle <= 180; angle++) {
    myServo.write(angle);  // move the arm to this angle
    delay(15);             // wait 15 milliseconds between each step
                           // (gives the motor time to move)
  }

  // Sweep back from 180 degrees to 0 degrees
  for (int angle = 180; angle >= 0; angle--) {
    myServo.write(angle);
    delay(15);
  }

  // Now loop() starts again — the arm keeps waving!
}
```

- [ ] **Step 2: Write `projects/10-servo-wave/README.md`**

Key content:
- **What you will build:** A robot arm that waves back and forth all by itself!
- **What you need:** 1× servo motor MG-90S, jumper wires (or the servo's own 3-wire cable), Arduino + breadboard
- **Difficulty:** ⭐⭐ — only 3 wires! Easy to set up, satisfying to watch.
- **About the servo wires:** The servo has 3 colored wires. The colors may vary but the order (from the connector tab) is usually GND, 5V, Signal.
  - Brown/Black wire → Arduino GND
  - Red wire → Arduino 5V
  - Orange/Yellow wire → Arduino pin 9
- **Connection table:**

| Servo wire | Wire to |
|------------|---------|
| Brown / Black (GND) | Arduino GND |
| Red (5V) | Arduino 5V |
| Orange / Yellow (signal) | Arduino pin 9 |

- **Tip:** Use female-to-male jumper wires to connect to the servo's 3-pin connector.
- **What should happen:** The servo arm sweeps slowly from one side to the other and back, like waving.
- **How does it work?** The servo has a tiny motor and gears inside. The Arduino sends special signals that tell it exactly what angle to move to.
- **Want to learn more?** Try attaching the little white plastic arm that came with the servo. Add a paper flag to it!

- [ ] **Step 3: Compile**

```bash
./bin/arduino-cli compile --fqbn arduino:renesas_uno:unor4wifi projects/10-servo-wave/
```

- [ ] **Step 4: Commit**

```bash
git add projects/10-servo-wave/
git commit -m "feat: project 10 - servo wave"
```

---

## Task 11: Project 11 — Spinning Fan

**Files:**
- Create: `projects/11-spinning-fan/11-spinning-fan.ino`
- Create: `projects/11-spinning-fan/README.md`

- [ ] **Step 1: Create folder and .ino file**

```bash
mkdir -p /workspaces/arduino/projects/11-spinning-fan
```

Write `projects/11-spinning-fan/11-spinning-fan.ino`:

```cpp
/*
 * Project 11: Spinning Fan
 *
 * What this does: turns the knob to make a motor spin faster or slower —
 *                 like controlling the speed of a fan!
 *
 * Parts needed:
 *   - 1 × DC motor (small, with 2 wires)
 *   - 1 × NPN transistor BC547 (looks like a tiny black D-shape with 3 legs)
 *   - 1 × resistor (1k ohm — brown-black-red stripes)
 *   - 1 × ceramic capacitor 100nF (small yellow/orange disc) — protects Arduino from motor spikes
 *   - 1 × potentiometer (knob)
 *   - jumper wires
 *
 * WHY DO WE NEED A TRANSISTOR?
 *   The motor needs more electricity than the Arduino pin can give.
 *   The transistor is like an amplifier — a tiny signal from the pin
 *   controls a bigger flow of electricity to the motor.
 *
 * Written for children — every line is explained!
 */

#define MOTOR_PIN 9    // transistor base is connected through resistor to pin 9
#define POT_PIN   A0   // potentiometer knob is on analog pin A0

void setup() {
  pinMode(MOTOR_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read the knob position (0 = all the way left, 1023 = all the way right)
  int knobValue = analogRead(POT_PIN);

  // Convert the knob value (0–1023) to a motor speed (0–255)
  // analogWrite needs 0–255, but analogRead gives 0–1023
  // map() converts from one range to another
  int motorSpeed = map(knobValue, 0, 1023, 0, 255);

  // Send the speed to the motor through the transistor
  // 0 = stopped, 255 = full speed
  analogWrite(MOTOR_PIN, motorSpeed);

  // Show the speed in Serial Monitor
  Serial.print("Motor speed: ");
  Serial.println(motorSpeed);

  delay(50);
}
```

- [ ] **Step 2: Write `projects/11-spinning-fan/README.md`**

Key content:
- **What you will build:** A motor you can control with a knob — turn it up for full speed, down to stop!
- **What you need:** 1× DC motor, 1× BC547 transistor, 1× 1k ohm resistor (brown-black-red), 1× ceramic capacitor 100nF (small yellow/orange disc), 1× potentiometer, jumper wires, Arduino + breadboard
- **Difficulty:** ⭐⭐⭐ — the transistor circuit is new, but the wiring table makes it clear
- **About the BC547 transistor:** It has 3 legs. With the flat side facing you: left leg = Collector (C), middle = Base (B), right = Emitter (E).
- **About the capacitor:** Place it across the two motor wires (legs don't have a direction for ceramic caps). It absorbs voltage spikes when the motor stops, protecting the Arduino.
- **Wiring steps:**
  1. Transistor Emitter (E, right leg) → Arduino GND
  2. Transistor Base (B, middle leg) → through 1k resistor → Arduino pin 9
  3. Transistor Collector (C, left leg) → Motor wire 1
  4. Motor wire 2 → Arduino 5V
  5. 100nF capacitor across the motor terminals (one leg on each motor wire) — no polarity for ceramic caps
  6. Potentiometer: left → GND, middle → A0, right → 5V
- **Connection table:**

| Wire from | Wire to |
|-----------|---------|
| Arduino pin 9 | 1k resistor end 1 |
| 1k resistor end 2 | BC547 Base (middle leg) |
| BC547 Emitter (right leg) | Arduino GND |
| BC547 Collector (left leg) | Motor wire 1 |
| Motor wire 2 | Arduino 5V |
| 100nF capacitor | across Motor wire 1 and Motor wire 2 |
| Potentiometer left | Arduino GND |
| Potentiometer middle | Arduino A0 |
| Potentiometer right | Arduino 5V |

- **What should happen:** Knob all the way left = motor stopped. Turn it right = motor speeds up. All the way right = full speed!
- **How does it work?** The Arduino sends a PWM signal to the transistor's base. PWM (Pulse Width Modulation) switches electricity on and off very fast. More on-time = more average power = faster motor.

- [ ] **Step 3: Compile**

```bash
./bin/arduino-cli compile --fqbn arduino:renesas_uno:unor4wifi projects/11-spinning-fan/
```

- [ ] **Step 4: Commit**

```bash
git add projects/11-spinning-fan/
git commit -m "feat: project 11 - spinning fan"
```

---

## Task 12: Project 12 — Secret Card Unlock

**Files:**
- Create: `projects/12-secret-card-unlock/12-secret-card-unlock.ino`
- Create: `projects/12-secret-card-unlock/README.md`

- [ ] **Step 1: Create folder and .ino file**

```bash
mkdir -p /workspaces/arduino/projects/12-secret-card-unlock
```

Write `projects/12-secret-card-unlock/12-secret-card-unlock.ino`:

```cpp
/*
 * Project 12: Secret Card Unlock
 *
 * What this does: tap your special RFID card → green light + happy beep!
 *                 tap a WRONG card → red light + alarm beep!
 *
 * Parts needed:
 *   - 1 × RFID reader RC522 (with SPI connector)
 *   - 1 × RFID card AND/OR 1 × RFID key fob
 *   - 1 × green LED + 220 ohm resistor
 *   - 1 × red LED + 220 ohm resistor
 *   - 1 × buzzer
 *   - jumper wires
 *
 * Library needed: MFRC522 (already installed)
 *
 * HOW TO FIND YOUR CARD'S ID:
 *   1. Upload this sketch
 *   2. Open Serial Monitor (baud 9600)
 *   3. Tap your card — it will print "Card UID: XX XX XX XX"
 *   4. Copy those numbers into AUTHORIZED_UID below
 *
 * Written for children — every line is explained!
 */

#include <SPI.h>      // SPI communication (how the RFID reader talks to Arduino)
#include <MFRC522.h>  // the library for the RC522 RFID reader

#define SS_PIN    10   // SDA/SS pin of RC522
#define RST_PIN   9    // RST (reset) pin of RC522
#define GREEN_LED 3    // green LED (access granted)
#define RED_LED   4    // red LED (access denied)
#define BUZZER    8    // buzzer

// YOUR CARD'S ID GOES HERE (4 bytes, in hexadecimal)
// First, upload with any values, then read your card's UID from Serial Monitor
// and replace these numbers with your card's actual UID
byte AUTHORIZED_UID[4] = { 0xDE, 0xAD, 0xBE, 0xEF }; // REPLACE THESE!

// Create the RFID reader object
MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();         // start SPI communication
  rfid.PCD_Init();     // start the RFID reader

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  // Start with both LEDs off
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BUZZER, LOW);

  Serial.println("Ready! Tap your card.");
}

void loop() {
  // Wait for a card to appear near the reader
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;  // no card detected — skip and try again
  }

  // Print the card's UID (unique ID) to Serial Monitor
  Serial.print("Card UID:");
  for (int i = 0; i < rfid.uid.size; i++) {
    Serial.print(" ");
    Serial.print(rfid.uid.uidByte[i], HEX);  // HEX = print as hexadecimal number
  }
  Serial.println();

  // Check if this card matches our authorized card
  bool isAuthorized = true;
  for (int i = 0; i < 4; i++) {
    if (rfid.uid.uidByte[i] != AUTHORIZED_UID[i]) {
      isAuthorized = false;  // one byte doesn't match — not our card!
      break;
    }
  }

  if (isAuthorized) {
    // --- ACCESS GRANTED ---
    Serial.println("Access granted! Welcome!");
    digitalWrite(GREEN_LED, HIGH);  // green light on
    // Happy beep: short high beep
    digitalWrite(BUZZER, HIGH);
    delay(100);
    digitalWrite(BUZZER, LOW);
    delay(100);
    digitalWrite(BUZZER, HIGH);
    delay(100);
    digitalWrite(BUZZER, LOW);
    delay(1000);
    digitalWrite(GREEN_LED, LOW);   // green light off
  } else {
    // --- ACCESS DENIED ---
    Serial.println("Access denied!");
    digitalWrite(RED_LED, HIGH);   // red light on
    // Alarm beep: long low beep
    digitalWrite(BUZZER, HIGH);
    delay(500);
    digitalWrite(BUZZER, LOW);
    delay(200);
    digitalWrite(BUZZER, HIGH);
    delay(500);
    digitalWrite(BUZZER, LOW);
    delay(500);
    digitalWrite(RED_LED, LOW);    // red light off
  }

  rfid.PICC_HaltA();  // stop reading this card (so we don't read it 100 times)
}
```

- [ ] **Step 2: Write `projects/12-secret-card-unlock/README.md`**

Key content:
- **What you will build:** A secret access system — only YOUR card unlocks the green light. Wrong card = red alarm!
- **What you need:** 1× RC522 RFID reader, 1× RFID card, 1× RFID key fob, 1× green LED, 1× red LED, 2× 220 ohm resistors, 1× buzzer, jumper wires, Arduino + breadboard
- **Difficulty:** ⭐⭐⭐ — most wires of any project, but very cool result!
- **About the RC522 module:** It has 8 pins. Look at the labels printed on the board.
- **Connection table (RFID reader uses SPI — fixed pins on the Arduino):**

| RC522 pin | Wire to |
|-----------|---------|
| VCC (3.3V) | Arduino **3.3V** (NOT 5V!) |
| GND | Arduino GND |
| RST | Arduino pin 9 |
| IRQ | not connected |
| MISO | Arduino pin 12 |
| MOSI | Arduino pin 11 |
| SCK | Arduino pin 13 |
| SDA | Arduino pin 10 |

| Other | Wire to |
|-------|---------|
| Green LED long (+) → resistor | Arduino pin 3 |
| Green LED short (−) | Arduino GND |
| Red LED long (+) → resistor | Arduino pin 4 |
| Red LED short (−) | Arduino GND |
| Buzzer long (+) | Arduino pin 8 |
| Buzzer short (−) | Arduino GND |

- **IMPORTANT: RC522 uses 3.3V, NOT 5V! Using 5V will damage the module.**
- **First-time setup:** After uploading, open Serial Monitor, tap your card. Copy the UID printed there into the `AUTHORIZED_UID` line in the code, then upload again.
- **What should happen:** Tap your registered card → green LED + happy double-beep. Tap the other card/fob → red LED + alarm.

- [ ] **Step 3: Compile**

```bash
./bin/arduino-cli compile --fqbn arduino:renesas_uno:unor4wifi projects/12-secret-card-unlock/
```

- [ ] **Step 4: Commit**

```bash
git add projects/12-secret-card-unlock/
git commit -m "feat: project 12 - secret card unlock"
```

---

## Task 13: Project 13 — LED Matrix Art

**Files:**
- Create: `projects/13-led-matrix-art/13-led-matrix-art.ino`
- Create: `projects/13-led-matrix-art/README.md`

- [ ] **Step 1: Create folder and .ino file**

```bash
mkdir -p /workspaces/arduino/projects/13-led-matrix-art
```

Write `projects/13-led-matrix-art/13-led-matrix-art.ino`:

```cpp
/*
 * Project 13: LED Matrix Art
 *
 * What this does: plays animations on the 12x8 LED dot display
 *                 built INTO the Arduino Uno R4 WiFi!
 *                 No extra parts needed — it's already there!
 *
 * Parts needed:
 *   - just the Arduino Uno R4 WiFi (the display is built in!)
 *   - USB cable to your computer
 *
 * The LED matrix has 12 columns and 8 rows = 96 tiny LEDs.
 *
 * Written for children — every line is explained!
 */

#include "Arduino_LED_Matrix.h"  // the library for the built-in LED matrix

// Create a matrix object to control the display
ArduinoLEDMatrix matrix;

// --- DRAW YOUR OWN PICTURES ---
// Each picture is an 8x12 grid of 1s (LED on) and 0s (LED off)
// Row 0 is the TOP row, row 7 is the BOTTOM row
// Column 0 is the LEFT, column 11 is the RIGHT

// A happy face :)
byte happyFace[8][12] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },   // row 0 (top) — empty
  { 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0 },   // row 1 — eyes
  { 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0 },   // row 2 — eyes
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },   // row 3 — empty
  { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },   // row 4 — smile corners
  { 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0 },   // row 5 — smile sides
  { 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0 },   // row 6 — smile bottom
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },   // row 7 (bottom) — empty
};

// A sad face :(
byte sadFace[8][12] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0 },   // eyes
  { 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0 },   // eyes
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0 },   // frown bottom
  { 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0 },   // frown sides
  { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },   // frown corners
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

// A heart <3
byte heart[8][12] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
  { 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0 },
  { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0 },
  { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
  { 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0 },
};

void setup() {
  matrix.begin();  // start the LED matrix display
}

void loop() {
  // Show the happy face
  matrix.renderBitmap(happyFace, 8, 12);
  delay(1500);  // show it for 1.5 seconds

  // Show the sad face
  matrix.renderBitmap(sadFace, 8, 12);
  delay(1500);

  // Show the heart
  matrix.renderBitmap(heart, 8, 12);
  delay(1500);

  // Show a built-in animation from the gallery!
  // The Arduino R4 comes with some pre-made animations.
  matrix.loadSequence(LEDMATRIX_ANIMATION_STARTUP);
  matrix.play(true);  // true = loop the animation
  delay(3000);        // play for 3 seconds

  // Stop the animation before we go back to our drawings
  matrix.loadFrame(LEDMATRIX_EMOJI_HAPPY);
  delay(1500);
}
```

- [ ] **Step 2: Write `projects/13-led-matrix-art/README.md`**

Key content:
- **What you will build:** Animations and art on the 96 tiny LEDs built right into your Arduino!
- **What you need:** Just the Arduino Uno R4 WiFi and a USB cable — no extra parts!
- **Difficulty:** ⭐⭐⭐ — no wiring at all, but designing pictures with 1s and 0s is creative fun
- **What should happen:** The display cycles through a happy face, sad face, heart, and a built-in startup animation.
- **How does it work?** The Arduino R4 WiFi has 96 LEDs built in, arranged in 8 rows and 12 columns. We draw pictures by putting `1` where we want a light on and `0` where we want it off.
- **Want to learn more?** Design your own picture! Draw an 8×12 grid on paper, fill in squares with a pencil for LEDs you want on, then type the 1s and 0s into a new entry in the code. What picture can you make?
- **Tip:** Use graph paper to design your pixel art first — it's much easier than counting on screen!

- [ ] **Step 3: Compile**

```bash
./bin/arduino-cli compile --fqbn arduino:renesas_uno:unor4wifi projects/13-led-matrix-art/
```

- [ ] **Step 4: Commit**

```bash
git add projects/13-led-matrix-art/
git commit -m "feat: project 13 - LED matrix art"
```

---

## Task 14: Final — Write TODO.md and verify all projects compile

- [ ] **Step 1: Verify all 13 projects compile cleanly**

Run this script to compile all projects in sequence:

```bash
for project in projects/*/; do
  echo "=== Compiling $project ==="
  ./bin/arduino-cli compile --fqbn arduino:renesas_uno:unor4wifi "$project"
done
```

Expected: `Compilation successful` for all 13 projects. Fix any errors before proceeding.

- [ ] **Step 2: Write `TODO.md` in the project root**

`TODO.md` is a human-readable overview. It should contain:

```markdown
# Arduino Kids Curriculum — TODO

13 standalone projects for children (~8 years old) using the Arduino Uno R4 WiFi.

## Projects

| # | Name | Difficulty | Status |
|---|------|------------|--------|
| 01 | [Blink](projects/01-blink/) | ⭐ | [ ] |
| 02 | [Traffic Light](projects/02-traffic-light/) | ⭐ | [ ] |
| 03 | [Button Light](projects/03-button-light/) | ⭐ | [ ] |
| 04 | [Buzzer Doorbell](projects/04-buzzer-doorbell/) | ⭐ | [ ] |
| 05 | [Rainbow RGB](projects/05-rainbow-rgb/) | ⭐⭐ | [ ] |
| 06 | [Night Light](projects/06-night-light/) | ⭐⭐ | [ ] |
| 07 | [Weather Station](projects/07-weather-station/) | ⭐⭐ | [ ] |
| 08 | [Motion Alarm](projects/08-motion-alarm/) | ⭐⭐ | [ ] |
| 09 | [Parking Sensor](projects/09-parking-sensor/) | ⭐⭐ | [ ] |
| 10 | [Servo Wave](projects/10-servo-wave/) | ⭐⭐ | [ ] |
| 11 | [Spinning Fan](projects/11-spinning-fan/) | ⭐⭐⭐ | [ ] |
| 12 | [Secret Card Unlock](projects/12-secret-card-unlock/) | ⭐⭐⭐ | [ ] |
| 13 | [LED Matrix Art](projects/13-led-matrix-art/) | ⭐⭐⭐ | [ ] |

## Suggested order for beginners
Start with 01 → 02 → 03 → 04, then pick any that looks fun!

## Setup before first project
See [implementation plan](docs/superpowers/plans/2026-04-06-arduino-curriculum.md) Task 0 for library installation.
```

- [ ] **Step 3: Final commit**

```bash
git add TODO.md
git commit -m "chore: add TODO.md project overview"
```
