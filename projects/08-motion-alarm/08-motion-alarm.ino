/*
 * Project 08: Motion Alarm
 *
 * What this does: sounds an alarm when it detects movement —
 *                 like a burglar alarm for your bedroom!
 *
 * Parts needed:
 *   - 1 × PIR sensor (white dome on a small circuit board)
 *   - 1 × active buzzer
 *   - jumper wires
 *
 * Written for children — every line is explained!
 */

#define PIR_PIN    2   // PIR sensor output wire connects to pin 2
#define BUZZER_PIN 8   // buzzer connects to pin 8

// setup() runs once when the Arduino turns on
void setup() {
  pinMode(PIR_PIN, INPUT);     // pin 2 reads the PIR sensor (INPUT = receive)
  pinMode(BUZZER_PIN, OUTPUT); // pin 8 sends electricity to the buzzer

  Serial.begin(9600);  // start communication with the computer

  // The PIR sensor needs a warm-up time when first powered on
  // It learns what "normal" looks like so it can spot movement
  Serial.println("Warming up... please wait 5 seconds and stay still!");
  delay(5000);         // wait 5 seconds for the sensor to settle
  Serial.println("Ready! I will now detect movement.");
}

// loop() runs over and over, forever
void loop() {
  // Read the PIR sensor: HIGH = motion detected, LOW = no motion
  int motionDetected = digitalRead(PIR_PIN);

  if (motionDetected == HIGH) {
    // Something moved! Sound the alarm!
    Serial.println("MOTION DETECTED! Alarm!");
    digitalWrite(BUZZER_PIN, HIGH);  // turn buzzer ON — BEEP!
    delay(500);                      // beep for half a second
    digitalWrite(BUZZER_PIN, LOW);   // turn buzzer OFF
    delay(200);                      // short gap between beeps
  } else {
    // Nothing is moving — stay quiet
    digitalWrite(BUZZER_PIN, LOW);   // make sure buzzer is off
  }
}
