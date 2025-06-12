// ---------------------------------------------------- //
// Arduino Nano: Start LED (D3) & Charge LED (D5) timing
// ---------------------------------------------------- //
// Sequence on power‐on:
//  1) STATE_INITIAL: Start LED ON for  5 seconds
//  2) STATE_CHARGE: Charge LED ON for  1 hour
//  3) STATE_START:  Start LED ON for 24 hours
//  4) Loop between STATE_CHARGE (1 h) ↔ STATE_START (24 h)
// ----------------------------------------------------

const uint8_t PIN_START = 3;   // “Start” LED on D3
const uint8_t PIN_CHARGE = 5;  // “Charge” LED on D5
const uint8_t PIN_RELAY = 7;   // “Relay”  on D7
const uint8_t PIN_PERM = 13;   // Permenantly OFF 13 LED

enum State { STATE_INITIAL,
             STATE_CHARGE,
             STATE_START };
State currentState = STATE_INITIAL;

// Durations in milliseconds:
const unsigned long D_INITIAL = 1UL * 60UL * 1000UL;        //  1 Minutes
const unsigned long D_CHARGE = 1UL * 60UL * 60UL * 1000UL;  //  1 hour
const unsigned long D_START = 24UL * 60UL * 60UL * 1000UL;  // 24 hours

//For Testing
// const unsigned long D_INITIAL = 30UL * 1000UL;       //  30 seconds
// const unsigned long D_CHARGE = 1UL * 60UL * 1000UL;  //  1 Mins
// const unsigned long D_START = 2UL * 60UL * 1000UL;   // 2 Mins

unsigned long stateStartMillis = 0;

void setup() {
  pinMode(PIN_START, OUTPUT);
  pinMode(PIN_CHARGE, OUTPUT);
  pinMode(PIN_PERM, OUTPUT);
  pinMode(PIN_RELAY, OUTPUT);
  // On power‐up, immediately turn ON the Start LED (STATE_INITIAL)
  digitalWrite(PIN_START, HIGH);

  digitalWrite(PIN_CHARGE, LOW);
  digitalWrite(PIN_RELAY, LOW);

  digitalWrite(PIN_PERM, LOW);
  stateStartMillis = millis();
}

void loop() {
  unsigned long now = millis();
  unsigned long elapsed = now - stateStartMillis;

  switch (currentState) {
    case STATE_INITIAL:
      // STATE_INITIAL: Start LED is ON for 5 seconds
      if (elapsed >= D_INITIAL) {
        // Transition → STATE_CHARGE: turn OFF Start, turn ON Charge
        currentState = STATE_CHARGE;
        stateStartMillis = now;
        digitalWrite(PIN_START, LOW);

        digitalWrite(PIN_CHARGE, HIGH);
        digitalWrite(PIN_RELAY, HIGH);

        digitalWrite(PIN_PERM, LOW);
      }
      break;

    case STATE_CHARGE:
      // STATE_CHARGE: Charge LED is ON for 1 hour
      if (elapsed >= D_CHARGE) {
        // Transition → STATE_START: switch LEDs
        currentState = STATE_START;
        stateStartMillis = now;
        digitalWrite(PIN_CHARGE, LOW);
        digitalWrite(PIN_RELAY, LOW);

        digitalWrite(PIN_START, HIGH);

        digitalWrite(PIN_PERM, LOW);
      }
      break;

    case STATE_START:
      // STATE_START: Start LED is ON for 24 hours
      if (elapsed >= D_START) {
        // Transition → STATE_CHARGE (1h), loop indefinitely
        currentState = STATE_CHARGE;
        stateStartMillis = now;
        digitalWrite(PIN_START, LOW);

        digitalWrite(PIN_CHARGE, HIGH);
        digitalWrite(PIN_RELAY, HIGH);
        
        digitalWrite(PIN_PERM, LOW);
      }
      break;
  }
}
