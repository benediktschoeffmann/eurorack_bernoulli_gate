#define KNOB_PIN  A0
#define IN_PIN    2
#define OUT_A_PIN 3
#define OUT_B_PIN 4

#define RESOLUTION 1024
#define DEBOUNCE 35
bool pressed;
int p, r;


void setup() {
  pressed = false;
  randomSeed(analogRead(A4));
  pinMode(IN_PIN, INPUT_PULLUP);
  pinMode(OUT_A_PIN, OUTPUT);
  pinMode(OUT_B_PIN, OUTPUT);
}

void loop() {

  if (LOW == digitalRead(IN_PIN)) {

    if (pressed == false) {
      pressed = true;
      p = analogRead(KNOB_PIN);
      r = random(RESOLUTION);  
      
      if (r <= p) {
        digitalWrite(OUT_A_PIN, HIGH);
      } else {
        digitalWrite(OUT_B_PIN, HIGH);
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
    delay(DEBOUNCE);
  }
  
}
