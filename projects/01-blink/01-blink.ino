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
