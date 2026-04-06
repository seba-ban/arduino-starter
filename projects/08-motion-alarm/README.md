# Project 08: Motion Alarm ⭐⭐

> A sensor that spots when someone moves and sounds an alarm — guard your room!

## What you will build

A motion-detecting alarm!
Set it up by your door or on a shelf, and it will beep whenever someone walks past.
It is like having your own burglar alarm — perfect for keeping siblings out of your room!

## What you need

- 1 × PIR sensor (white dome on a small circuit board, usually labeled HC-SR501)
- 1 × Active buzzer
- Several jumper wires
- 1 × Arduino Uno R4 WiFi
- 1 × Breadboard

## Difficulty

⭐⭐ — very few wires! But you need to wait 5 seconds after powering on.

## Wiring

The PIR sensor has 3 pins. Look at the bottom of the board — they are labeled **VCC**, **OUT**, and **GND**.

### Step-by-step

1. Connect the PIR sensor's **VCC** pin to **5V** on the Arduino.
2. Connect the PIR sensor's **OUT** pin to **pin 2** on the Arduino.
3. Connect the PIR sensor's **GND** pin to **GND** on the Arduino.
4. Connect the **long leg (+)** of the buzzer to **pin 8** on the Arduino.
5. Connect the **short leg (−)** of the buzzer to **GND** on the Arduino.

> 💡 **Tip:** If the alarm goes off immediately (without any movement), the sensor may still be warming up. Power off, wait 30 seconds, then power on again and wait 5 seconds before testing.

> 💡 **Buzzer tip:** If the buzzer makes no sound, try flipping it around — buzzers only work one way!

### Connection table

| Wire from | Wire to |
|-----------|---------|
| PIR VCC | Arduino 5V |
| PIR OUT | Arduino pin 2 |
| PIR GND | Arduino GND |
| Buzzer long leg (+) | Arduino pin 8 |
| Buzzer short leg (−) | Arduino GND |

## How to upload the code

1. Open the file `08-motion-alarm/08-motion-alarm.ino` in Arduino IDE.
2. Go to **Tools → Board → Arduino UNO R4 Boards** and select **Arduino UNO R4 WiFi**.
3. Click the big **→ Upload** arrow at the top.
4. Wait for "Done uploading" at the bottom of the screen.

## What should happen

1. After uploading, the Serial Monitor (if open) shows "Warming up... please wait 5 seconds".
2. After 5 seconds, the alarm is armed and ready.
3. Walk in front of the sensor → the buzzer beeps!
4. Stand completely still → the buzzer goes quiet.

## How does it work?

The PIR sensor detects invisible heat (infrared light) coming from people and animals.
When you walk past, your body's warmth moves across the sensor and it sends a HIGH signal to the Arduino.
The Arduino then turns on the buzzer until nothing is moving anymore.
PIR stands for **Passive Infrared** — passive because it does not send out anything, it only listens!

## Want to learn more? (optional)

Can you add a red LED to the circuit so it flashes at the same time as the buzzer beeps?
(Hint: connect the LED and resistor to pin 4, and add `digitalWrite(4, HIGH/LOW)` to the alarm section of the code!)
