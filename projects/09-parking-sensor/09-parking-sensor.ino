/*
 * Project 09: Parking Sensor
 *
 * What this does: beeps faster and faster as your hand gets closer —
 *                 just like the parking sensor in a car!
 *
 * Parts needed:
 *   - 1 × HC-SR04 ultrasonic distance sensor (looks like two big eyes)
 *   - 1 × active buzzer
 *   - jumper wires
 *
 * Library used:
 *   - NewPing — makes using the HC-SR04 easy
 *
 * Written for children — every line is explained!
 */

#include <NewPing.h>   // include the NewPing library for the distance sensor

#define TRIG_PIN     9    // TRIG pin — sends out the sound pulse
#define ECHO_PIN     10   // ECHO pin — listens for the pulse to bounce back
#define BUZZER_PIN   8    // buzzer is on pin 8
#define MAX_DISTANCE 100  // we only care about objects within 100 cm

// Create a sonar object — this is our "remote control" for the HC-SR04
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

// setup() runs once when the Arduino turns on
void setup() {
  pinMode(BUZZER_PIN, OUTPUT);  // pin 8 sends electricity to the buzzer
  Serial.begin(9600);           // start communication with the computer
}

// loop() runs over and over, forever
void loop() {
  // Measure the distance to the nearest object in centimeters
  // (NewPing sends a pulse and measures how long it takes to bounce back)
  int distance = sonar.ping_cm();

  // Print the distance to the computer
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance == 0) {
    // 0 means nothing was detected within 100 cm — stay quiet
    digitalWrite(BUZZER_PIN, LOW);  // buzzer off
    delay(200);                     // short pause before checking again
  } else if (distance > 50) {
    // Far away (more than 50 cm) — slow beep
    digitalWrite(BUZZER_PIN, HIGH); // BEEP...
    delay(50);                      // beep for 50 ms
    digitalWrite(BUZZER_PIN, LOW);  // silence
    delay(500);                     // long gap — slow beeping
  } else if (distance > 20) {
    // Getting closer (20–50 cm) — medium beep
    digitalWrite(BUZZER_PIN, HIGH); // BEEP
    delay(50);                      // beep for 50 ms
    digitalWrite(BUZZER_PIN, LOW);  // silence
    delay(200);                     // medium gap
  } else if (distance > 5) {
    // Very close! (5–20 cm) — fast beep
    digitalWrite(BUZZER_PIN, HIGH); // BEEP
    delay(50);                      // beep for 50 ms
    digitalWrite(BUZZER_PIN, LOW);  // silence
    delay(50);                      // very short gap — fast beeping!
  } else {
    // TOO CLOSE! (less than 5 cm) — continuous beep
    digitalWrite(BUZZER_PIN, HIGH); // continuous BEEEEEP!
    delay(100);                     // stay on
  }
}
