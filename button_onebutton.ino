#include <OneButton.h>

#define BUTTON_PIN_1 12
#define BUTTON_PIN_2 11

#define LED_PIN_1 2
#define LED_PIN_2 3

OneButton button1(
  BUTTON_PIN_1,
  true,
  true
);

OneButton button2(
  BUTTON_PIN_2,
  true,
  true
);

int ledState1 = LOW;
int ledState2 = LOW;

void setup() {
  Serial.begin(115200);
  Serial.println("One Button Example with polling.");
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  digitalWrite(LED_PIN_1, ledState1);
  digitalWrite(LED_PIN_2, ledState2);
  button1.attachClick(click);
}

void loop() {
  // put your main code here, to run repeatedly:
  button1.tick();
}

void click() {
  Serial.println("x1");
  ledState1 = !ledState1; // reverse the LED
  digitalWrite(LED_PIN_1, ledState1);
}
