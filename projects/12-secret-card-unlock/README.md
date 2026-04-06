# Project 12: Secret Card Unlock ⭐⭐⭐

> Tap your magic card to unlock the green light — wrong card triggers the alarm!

## What you will build

A secret access system!
Only YOUR card makes the green LED light up and plays a happy beep — welcome!
Any other card triggers the red LED and a loud alarm — access denied!
It is like having a keycard for a secret room!

## What you need

- 1 × RC522 RFID reader module (with antenna)
- 1 × RFID card (white card)
- 1 × RFID key fob (the small key-shaped tag)
- 1 × Green LED + 1 × Resistor (220 ohm — **red, red, brown, gold** stripes)
- 1 × Red LED + 1 × Resistor (220 ohm — **red, red, brown, gold** stripes)
- 1 × Active buzzer
- Many jumper wires
- 1 × Arduino Uno R4 WiFi
- 1 × Breadboard

## Difficulty

⭐⭐⭐ — the most wires of any project, but follow the table carefully and you will get it!

## ⚠️ VERY IMPORTANT — Power Warning

The RC522 RFID reader **must connect to the 3.3V pin**, NOT the 5V pin!
**Using 5V will permanently damage the RC522 module!**

## Wiring

The RC522 module uses **SPI communication** — a special way for the Arduino and sensor to talk.
The SPI pins on the Arduino Uno R4 WiFi are fixed (they cannot be changed).

### RC522 connection table

| RC522 pin | Wire to |
|-----------|---------|
| VCC (or 3.3V) | Arduino **3.3V** (⚠️ NOT 5V!) |
| GND | Arduino GND |
| RST | Arduino pin 9 |
| IRQ | Not connected |
| MISO | Arduino pin 12 |
| MOSI | Arduino pin 11 |
| SCK | Arduino pin 13 |
| SDA (or NSS) | Arduino pin 10 |

### LEDs and buzzer

| Component | Wire from | Wire to |
|-----------|-----------|---------|
| Green LED | long leg (+) → 220 ohm resistor | Arduino pin 3 |
| Green LED | short leg (−) | Arduino GND |
| Red LED | long leg (+) → 220 ohm resistor | Arduino pin 4 |
| Red LED | short leg (−) | Arduino GND |
| Buzzer | long leg (+) | Arduino pin 8 |
| Buzzer | short leg (−) | Arduino GND |

> 💡 **Tip:** If any LED does not respond, try flipping it around — LEDs only work one way!

### Step-by-step summary

1. Wire the RC522 module using the table above — start with GND and 3.3V.
2. Wire the 6 SPI data pins (RST, MISO, MOSI, SCK, SDA).
3. Wire the green LED and resistor to pin 3 and GND.
4. Wire the red LED and resistor to pin 4 and GND.
5. Wire the buzzer to pin 8 and GND.

## First-time setup: find your card's ID

Before the system knows which card is yours, you need to tell it!

1. Upload the code **as it is** (do not change anything yet).
2. Open **Serial Monitor** in Arduino IDE (click the magnifying glass icon).
3. Tap your RFID card near the reader.
4. You will see something like: `Card UID: A1 B2 C3 D4`
5. Open the code and find this line:
   ```cpp
   byte AUTHORIZED_UID[4] = { 0xDE, 0xAD, 0xBE, 0xEF };  // REPLACE THESE!
   ```
6. Replace the 4 numbers with your card's UID. Add `0x` before each number:
   ```cpp
   byte AUTHORIZED_UID[4] = { 0xA1, 0xB2, 0xC3, 0xD4 };
   ```
7. Upload the code again. Now YOUR card is the key!

## How to upload the code

1. Open the file `12-secret-card-unlock/12-secret-card-unlock.ino` in Arduino IDE.
2. Go to **Tools → Board → Arduino UNO R4 Boards** and select **Arduino UNO R4 WiFi**.
3. Click the big **→ Upload** arrow at the top.
4. Wait for "Done uploading" at the bottom of the screen.

## What should happen

- **Your registered card** → green LED lights up + double happy beep ✅
- **Any other card or fob** → red LED lights up + double alarm beep ❌
- **No card** → nothing happens, waiting silently

## How does it work?

Every RFID card and fob has a unique ID number stored inside it — like a fingerprint.
When you hold a card near the reader, the reader sends out a radio wave that powers the card and asks for its ID.
The Arduino checks if that ID matches the one you programmed in, then decides: welcome or alarm!

## Want to learn more? (optional)

Can you add a second authorized card? (Hint: you need to check if the UID matches EITHER of two stored UIDs.)
Try using the key fob as the authorized device and setting the card as "unauthorized" — then swap them!
