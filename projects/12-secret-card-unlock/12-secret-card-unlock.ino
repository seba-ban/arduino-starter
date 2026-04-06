/*
 * Project 12: Secret Card Unlock
 *
 * What this does: tap your special RFID card → green light + happy beep!
 *                 tap a wrong card → red light + alarm beep!
 *
 * Parts needed:
 *   - 1 × RC522 RFID reader module
 *   - 1 × RFID card AND/OR 1 × RFID key fob
 *   - 1 × green LED + 220 ohm resistor (red, red, brown, gold)
 *   - 1 × red LED + 220 ohm resistor (red, red, brown, gold)
 *   - 1 × active buzzer
 *   - jumper wires
 *
 * IMPORTANT: The RC522 module uses 3.3V — NOT 5V!
 *            Connecting it to 5V will BREAK the module!
 *
 * Library used: MFRC522
 *
 * HOW TO FIND YOUR CARD'S ID (first-time setup):
 *   1. Upload this sketch as-is
 *   2. Open Serial Monitor (baud 9600)
 *   3. Tap your RFID card near the reader
 *   4. Copy the "Card UID: XX XX XX XX" numbers
 *   5. Replace the numbers in AUTHORIZED_UID below
 *   6. Upload again — now your card is the secret key!
 *
 * Written for children — every line is explained!
 */

#include <SPI.h>      // SPI library — controls how Arduino talks to the RC522
#include <MFRC522.h>  // MFRC522 library — controls the RFID reader

// SPI pins (these are fixed on the Arduino Uno R4 WiFi — do not change!)
#define SS_PIN  10  // SS/SDA pin of RC522 connects to pin 10
#define RST_PIN  9  // RST (reset) pin of RC522 connects to pin 9

// LED and buzzer pins
#define GREEN_LED 3  // green LED (access granted) — pin 3
#define RED_LED   4  // red LED (access denied) — pin 4
#define BUZZER    8  // buzzer — pin 8

// YOUR SECRET CARD'S ID — replace these 4 numbers with your card's UID
// (follow the HOW TO FIND YOUR CARD'S ID instructions above)
byte AUTHORIZED_UID[4] = { 0xDE, 0xAD, 0xBE, 0xEF };  // REPLACE THESE!

// Create the RFID reader object — our "remote control" for the RC522
MFRC522 rfid(SS_PIN, RST_PIN);

// setup() runs once when the Arduino turns on
void setup() {
  Serial.begin(9600);  // start communication with the computer
  SPI.begin();         // start the SPI communication bus (needed for RC522)
  rfid.PCD_Init();     // start the RFID reader

  // Set up the LED and buzzer pins
  pinMode(GREEN_LED, OUTPUT);  // green LED sends electricity OUT
  pinMode(RED_LED, OUTPUT);    // red LED sends electricity OUT
  pinMode(BUZZER, OUTPUT);     // buzzer sends electricity OUT

  // Start with everything off
  digitalWrite(GREEN_LED, LOW);  // green LED off
  digitalWrite(RED_LED, LOW);    // red LED off
  digitalWrite(BUZZER, LOW);     // buzzer off (silent)

  Serial.println("Ready! Tap your card.");
}

// loop() runs over and over, forever
void loop() {
  // Check if a card is near the reader
  // PICC_IsNewCardPresent() returns true if a new card is detected
  // PICC_ReadCardSerial() reads the card's unique ID
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;  // no card yet — go back to the start of loop() and try again
  }

  // A card was found! Print its UID to the Serial Monitor
  Serial.print("Card UID:");
  for (int i = 0; i < rfid.uid.size; i++) {
    Serial.print(" ");
    Serial.print(rfid.uid.uidByte[i], HEX);  // print each byte as a hex number
  }
  Serial.println();  // move to a new line

  // Check if this card's UID matches our authorized card
  bool cardIsAuthorized = true;  // assume it matches until we find a difference
  for (int i = 0; i < 4; i++) {
    if (rfid.uid.uidByte[i] != AUTHORIZED_UID[i]) {
      cardIsAuthorized = false;  // one byte does not match — not our card!
      break;                     // stop checking — it is already denied
    }
  }

  if (cardIsAuthorized) {
    // --- ACCESS GRANTED! ---
    Serial.println("Access GRANTED! Welcome!");
    digitalWrite(GREEN_LED, HIGH);  // turn green LED on
    // Happy beep: two short beeps
    digitalWrite(BUZZER, HIGH);     // BEEP
    delay(100);                     // for 100ms
    digitalWrite(BUZZER, LOW);      // pause
    delay(100);                     // for 100ms
    digitalWrite(BUZZER, HIGH);     // BEEP again
    delay(100);                     // for 100ms
    digitalWrite(BUZZER, LOW);      // done
    delay(1000);                    // keep green light on for 1 second
    digitalWrite(GREEN_LED, LOW);   // turn green LED off
  } else {
    // --- ACCESS DENIED! ---
    Serial.println("Access DENIED!");
    digitalWrite(RED_LED, HIGH);   // turn red LED on
    // Alarm beep: two long beeps
    digitalWrite(BUZZER, HIGH);    // BEEEEP
    delay(500);                    // for 500ms
    digitalWrite(BUZZER, LOW);     // short pause
    delay(200);                    // for 200ms
    digitalWrite(BUZZER, HIGH);    // BEEEEP
    delay(500);                    // for 500ms
    digitalWrite(BUZZER, LOW);     // done
    delay(500);                    // keep red light on briefly
    digitalWrite(RED_LED, LOW);    // turn red LED off
  }

  rfid.PICC_HaltA();  // tell the reader to stop reading this card
                      // (without this, it would read the same card dozens of times)
}
