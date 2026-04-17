/*
 * Project 11: Spinning Fan
 *
 * What this does: turn the knob to make a motor spin faster or slower,
 *                 and press the button to flip the direction — like reversing a fan!
 *
 * Parts needed:
 *   - 1 × DC motor (small, 3–5V, with 2 wires)
 *   - 1 × L293D motor driver chip (16-pin DIP)
 *   - 1 × L7805ABV 5V regulator (TO-220, 3 legs)
 *   - 1 × 9V battery + clip
 *   - 1 × potentiometer (round knob)
 *   - 1 × tact-switch button
 *   - 1 × green LED + 220Ω resistor  (forward indicator)
 *   - 1 × red LED   + 220Ω resistor  (reverse indicator)
 *   - jumper wires
 *
 * WHY CAN'T WE PLUG THE MOTOR STRAIGHT INTO ARDUINO?
 *   Motors are hungry — they need more electricity than an Arduino pin can give.
 *   They also make electrical noise that can confuse or even damage Arduino.
 *   The L293D chip acts like a helper: it takes instructions from Arduino
 *   and passes them to the motor, while keeping the motor's stronger electricity
 *   safely away from Arduino.
 *   The 9V battery powers the motor. The L7805 regulator steps that 9V down
 *   to a safe 5V so the motor doesn't get too much power.
 *
 * DIRECTION CONTROL:
 *   The L293D controls direction using two pins (IN1 and IN2):
 *     IN1=HIGH, IN2=LOW  → motor spins forward
 *     IN1=LOW,  IN2=HIGH → motor spins in reverse
 *   We flip these two pins every time the button is pressed.
 *
 * Written for children — every line is explained!
 */

// --- Pin assignments ---
#define EN1_PIN  9   // L293D enable pin — controls speed via PWM
#define IN1_PIN  7   // L293D input 1 — direction signal A
#define IN2_PIN  8   // L293D input 2 — direction signal B
#define POT_PIN  A0  // potentiometer middle leg — reads knob position
#define BTN_PIN  2   // direction toggle button (other leg to GND)
#define LED_FWD  4   // green LED — lights up when going forward
#define LED_REV  5   // red LED   — lights up when going in reverse

// --- State variables ---
bool goingForward = true;   // true = forward, false = reverse

// Button debounce — we use millis() so the motor doesn't pause when pressed
bool lastButtonState = HIGH;          // raw reading from last loop
bool lastStableButtonState = HIGH;    // confirmed stable state after debounce
unsigned long lastDebounceTime = 0;   // when the button last changed
const unsigned long DEBOUNCE_MS = 50UL; // ignore changes shorter than 50 milliseconds

// setup() runs once when the Arduino turns on
void setup() {
  Serial.begin(9600);  // start communication with the computer (first, so it is ready before anything else)

  pinMode(EN1_PIN, OUTPUT);  // speed control — PWM output to L293D enable
  pinMode(IN1_PIN, OUTPUT);  // direction signal A
  pinMode(IN2_PIN, OUTPUT);  // direction signal B
  pinMode(LED_FWD, OUTPUT);  // green LED
  pinMode(LED_REV, OUTPUT);  // red LED

  // INPUT_PULLUP means the pin reads HIGH when the button is not pressed.
  // When the button is pressed it connects the pin to GND, so it reads LOW.
  // This way we don't need an external resistor on the button!
  pinMode(BTN_PIN, INPUT_PULLUP);

  // Start in forward direction
  setDirection(goingForward);
}

// loop() runs over and over, forever
void loop() {
  // --- Read and apply motor speed ---
  // Read the knob: gives 0 (all the way left) to 1023 (all the way right)
  int knobValue = analogRead(POT_PIN);

  // Convert 0–1023 to 0–255 (the range analogWrite understands)
  int motorSpeed = map(knobValue, 0, 1023, 0, 255);

  // Send the speed to the L293D enable pin
  // 0 = motor stopped, 255 = full speed
  analogWrite(EN1_PIN, motorSpeed);

  // --- Check button for direction toggle ---
  bool currentButtonState = digitalRead(BTN_PIN);

  // Record when the button state changes (start debounce window)
  if (currentButtonState != lastButtonState) {
    lastDebounceTime = millis();
  }
  lastButtonState = currentButtonState;  // always update raw state

  // After the button has been stable for DEBOUNCE_MS, check for a press
  if ((millis() - lastDebounceTime) >= DEBOUNCE_MS) {
    // Falling edge: button just pressed (HIGH → LOW)
    if (currentButtonState == LOW && lastStableButtonState == HIGH) {
      goingForward = !goingForward;  // flip direction
      setDirection(goingForward);
    }
    lastStableButtonState = currentButtonState;  // update stable state only after window
  }

  // --- Show info in Serial Monitor (at most every 200 ms) ---
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint >= 200UL) {
    lastPrint = millis();
    Serial.print("Speed: ");
    Serial.print(motorSpeed);
    Serial.print("  Direction: ");
    Serial.println(goingForward ? "FORWARD" : "REVERSE");
  }
}

// setDirection() updates the L293D inputs and the indicator LEDs
// Call it with true for forward, false for reverse
void setDirection(bool forward) {
  if (forward) {
    digitalWrite(IN1_PIN, HIGH);  // IN1=HIGH, IN2=LOW → forward
    digitalWrite(IN2_PIN, LOW);
    digitalWrite(LED_FWD, HIGH);  // green LED on
    digitalWrite(LED_REV, LOW);   // red LED off
  } else {
    digitalWrite(IN1_PIN, LOW);   // IN1=LOW, IN2=HIGH → reverse
    digitalWrite(IN2_PIN, HIGH);
    digitalWrite(LED_FWD, LOW);   // green LED off
    digitalWrite(LED_REV, HIGH);  // red LED on
  }
}
