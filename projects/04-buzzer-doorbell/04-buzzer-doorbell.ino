/*
 * Project 04: Buzzer Doorbell
 *
 * What this does: makes a BEEP sound when you press the button —
 *                 just like a doorbell!
 *
 * Parts needed:
 *   - 1 × active buzzer (the black round one with a sticker on top)
 *   - 1 × tact-switch button
 *   - jumper wires
 *
 * Note: this is an ACTIVE buzzer — it has a tiny generator inside.
 *       It makes sound whenever electricity flows through it.
 *       No special sound code needed!
 *
 * Written for children — every line is explained!
 */

#define BUTTON_PIN 2   // button is connected to pin 2
#define BUZZER_PIN 8   // buzzer is connected to pin 8

// setup() runs once when the Arduino turns on
void setup() {
  pinMode(BUZZER_PIN, OUTPUT);        // pin 8 will send electricity to the buzzer
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // read the button (LOW = pressed, just like project 03)
}

// loop() runs over and over, forever
void loop() {
  int buttonState = digitalRead(BUTTON_PIN);  // read the button: pressed or not?

  if (buttonState == LOW) {
    // Button is pressed — send electricity to the buzzer to make it BEEP!
    digitalWrite(BUZZER_PIN, HIGH);  // BEEP!
  } else {
    // Button is not pressed — stop the buzzer
    digitalWrite(BUZZER_PIN, LOW);   // silence
  }
}
