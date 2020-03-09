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
  double vorherigesMessergebnis = 0;
  double aktuellesMessergebnis = 0;


  while(true)
  {
    aktuellesMessergebnis = ultraSensor.distanceCm();
    if(werteWeichenAb(aktuellesMessergebnis, vorherigesMessergebnis))
    {
      String ausgabe = String( aktuellesMessergebnis, HEX);
      Serial.println(ausgabe);
      zeigeWertAufDisplay(ausgabe);  
      vorherigesMessergebnis = aktuellesMessergebnis;
    }
    delay(1000);
  }

}

boolean werteWeichenAb(double _aktuell, double _vorher)
{
  return  abs(_aktuell - _vorher) > 0.5;

}

void zeigeWertAufDisplay(String _input)
{
  // Längenbeschränkung auf 4 - LED-Matrix kann eh nicht mehr anzeigen.
  char ausgabeZeichenkette[4];
  _input.toCharArray(ausgabeZeichenkette, 4);

  Matrix_1.drawStr(1,7, ausgabeZeichenkette);
}
