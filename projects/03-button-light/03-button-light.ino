/*
 * Project 03: Button Light
 *
 * What this does: the LED turns ON when you press the button,
 *                 and turns OFF when you let go.
 *
 * Parts needed:
 *   - 1 × LED (any color)
 *   - 1 × resistor (220 ohm — red, red, brown, gold stripes)
 *   - 1 × tact-switch button
 *   - jumper wires
 *
 * Written for children — every line is explained!
 */

#define BUTTON_PIN 2   // the button is connected to pin 2
#define LED_PIN    9   // the LED is connected to pin 9

// setup() runs once when the Arduino turns on
void setup() {
  pinMode(LED_PIN, OUTPUT);           // pin 9 sends electricity OUT to the LED

  // INPUT_PULLUP is a special mode for buttons
  // It means: when button is NOT pressed, pin reads HIGH
  //           when button IS pressed, pin reads LOW
  // (This is why we check for LOW below to detect a press)
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

// loop() runs over and over, forever
void loop() {
  // Read the button — is it being pressed right now?
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW) {
    // LOW means the button IS pressed — turn the LED on!
    digitalWrite(LED_PIN, HIGH);  // turn LED ON
  } else {
    // HIGH means the button is NOT pressed — turn the LED off
    digitalWrite(LED_PIN, LOW);   // turn LED OFF
  }
}
