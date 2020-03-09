#include <string.h>
#include <MeMCore.h>

/*
#include <MeLEDMatrix.h>
#include <MePort.h>
*/

// Richtige Port-Nummer angeben!
MeUltrasonicSensor ultraSensor(3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(ultraSensor.distanceCm());
  delay(1000);
}
