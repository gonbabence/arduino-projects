int buttonPin = 12;
int buttonPin2 = 11;
int ledPin = 2;
int ledPin2 = 3;
bool ledOn = false;
bool ledOn2 = false;
int buttonPrevState = LOW;
int buttonPrevState2 = LOW;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.println('Started...');
}

void toggleButton(int pin, int &prevState, bool &state) {
  int buttonState = digitalRead(pin);
  if (buttonState != prevState) {
    if (buttonState == LOW) {
      state = !state;
    }

    prevState = buttonState;

    delay(10);
  }
}

void loop() {
  toggleButton(buttonPin, buttonPrevState, ledOn);
  toggleButton(buttonPin2, buttonPrevState2, ledOn2);
  digitalWrite(ledPin, ledOn ? HIGH : LOW);
  digitalWrite(ledPin2, ledOn2 ? HIGH : LOW);
}
