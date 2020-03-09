#include <string.h>
#include <MeMCore.h>

#include <MeLEDMatrix.h>

// Richtige Port-Nummer angeben!
MeUltrasonicSensor ultraSensor(3);
MeLEDMatrix Matrix_1(1);

void setup() {

	Serial.begin(9600);
	// zur Sicherheit die Displayhelligkeit setzen
	Matrix_1.setBrightness(5);
}

void loop() {
  String ausgabe = String( ultraSensor.distanceCm(), HEX);
  Serial.println(ausgabe);

  // Längenbeschränkung auf 4 - LED-Matrix kann eh nicht mehr anzeigen.
  char ausgabeZeichenkette[4];
  ausgabe.toCharArray(ausgabeZeichenkette, 4);
	
  Matrix_1.drawStr(1,7, ausgabeZeichenkette);
  delay(1000);
}
