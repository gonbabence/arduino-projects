/*
 * Basic project which tests a piezo voltage and display the value on a 2-digit 7 segment display.
 * Library used for using the display: https://github.com/DeanIsMe/SevSeg
 */

#include <SevSeg.h>

SevSeg sevseg;

const int piezoPin = A0;

unsigned long previousMillis = 0;
const long interval = 50;

int sensorValue = 0;
float voltage = 0;

void setup() {
  byte numDigits = 2;
  byte digitPins[] = {11, 12};
  byte segmentPins[] = {3, 4, 5, 6, 7, 8, 9, 10};
  bool resistorsOnSegments = true;
  byte hardwareConfig = COMMON_ANODE;
  bool updateWithDelays = false;
  bool leadingZeros = false;
  bool disableDecPoint = false;

  sevseg.begin(
    hardwareConfig,
    numDigits,
    digitPins,
    segmentPins,
    resistorsOnSegments,
    updateWithDelays,
    leadingZeros,
    disableDecPoint
  );

  Serial.begin(9600);
}

void doLoop() {
  sensorValue = analogRead(piezoPin);

  // Convert the sensor value to voltage (assuming 5V reference voltage)
  voltage = sensorValue * (5.0 / 1023.0);

  Serial.print("sensor value: ");
  Serial.print(sensorValue);

  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");
}

void loop() {
  sevseg.refreshDisplay();
  sevseg.setNumber(min(99, sensorValue));

  // not using delays because that can mess up the 7 segment display
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    doLoop();
  }
}
