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
