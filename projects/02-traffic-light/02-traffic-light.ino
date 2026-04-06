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
 *   - 3 × resistor (220 ohm — red, red, brown, gold stripes)
 *   - jumper wires
 *
 * Written for children — every line is explained!
 */

#define RED_PIN    2   // red LED is connected to pin 2
#define YELLOW_PIN 3   // yellow LED is connected to pin 3
#define GREEN_PIN  4   // green LED is connected to pin 4

// setup() runs once when the Arduino turns on
void setup() {
  // Tell Arduino that all three pins will send electricity OUT
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
}

// A helper function to turn ALL lights off at once
// We call this before turning on each new light
void allOff() {
  digitalWrite(RED_PIN, LOW);    // turn red OFF
  digitalWrite(YELLOW_PIN, LOW); // turn yellow OFF
  digitalWrite(GREEN_PIN, LOW);  // turn green OFF
}

// loop() runs over and over, forever
void loop() {
  // --- RED: stop! ---
  allOff();                       // make sure everything is off first
  digitalWrite(RED_PIN, HIGH);    // turn red ON
  delay(3000);                    // stay red for 3 seconds

  // --- YELLOW: get ready to go ---
  allOff();                       // turn everything off before switching
  digitalWrite(YELLOW_PIN, HIGH); // turn yellow ON
  delay(1000);                    // stay yellow for 1 second

  // --- GREEN: go! ---
  allOff();                       // turn everything off before switching
  digitalWrite(GREEN_PIN, HIGH);  // turn green ON
  delay(3000);                    // stay green for 3 seconds

  // --- YELLOW again: get ready to stop ---
  allOff();                       // turn everything off before switching
  digitalWrite(YELLOW_PIN, HIGH);
  delay(1000);                    // stay yellow for 1 second

  // now loop() starts again — red, yellow, green, yellow, red...
}
