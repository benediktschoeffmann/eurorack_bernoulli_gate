#define KNOB_PIN  A0  // potentionmeter
#define IN_AN_PIN A1  // trigger-in jack
#define IN_PIN    2   // trigger-in button

#define LED_A_PIN 3   // left led
#define LED_B_PIN 4   // right led

#define OUT_A_PIN 5   // left out-jack
#define OUT_B_PIN 6   // right out-jack


#define RESOLUTION 1024 // ADC-Resolution
#define TRESHOLD 768    // for High State
#define DEBOUNCE 50     // in ms

bool pressed;
uint8_t p, r;

void setup() {
  pressed = false;
  randomSeed(analogRead(A4));
  pinMode(IN_PIN, INPUT_PULLUP);
  pinMode(IN_AN_PIN, INPUT_PULLUP);
  pinMode(LED_A_PIN, OUTPUT);
  pinMode(LED_B_PIN, OUTPUT);
  pinMode(OUT_A_PIN, OUTPUT);
  pinMode(OUT_B_PIN, OUTPUT);
}

void loop() {

  if (LOW == digitalRead(IN_PIN) || TRESHOLD < analogRead(IN_AN_PIN)) {

    if (pressed == false) {
      pressed = true;
      p = analogRead(KNOB_PIN);
      r = random(RESOLUTION);  
      
      if (r <= p) {
        digitalWrite(OUT_A_PIN, HIGH);
        digitalWrite(LED_A_PIN, HIGH);

      } else {
        digitalWrite(OUT_B_PIN, HIGH);
        digitalWrite(LED_B_PIN, HIGH);
      }
      delay(DEBOUNCE);
    } else {
      // signal is continuing
      // do nothing 
    }
  } else {
    pressed = false;
    digitalWrite(OUT_A_PIN, LOW);
    digitalWrite(OUT_B_PIN, LOW);
    digitalWrite(LED_A_PIN, LOW);
    digitalWrite(LED_B_PIN, LOW);
    
    delay(DEBOUNCE);
  }
  
}
