#include <string.h>
#include <MeMCore.h>

#include <MeLEDMatrix.h>

// Richtige Port-Nummer angeben!
MeUltrasonicSensor ultraSensor(3);
MeLEDMatrix Matrix_1(1);

const int messwerteSpeicherGroesse = 10;
double messwerteSpeicher[messwerteSpeicherGroesse];

void setup() {

  Serial.begin(9600);
  // zur Sicherheit die Displayhelligkeit setzen
  Matrix_1.setBrightness(5);
}


void loop() {
  double aktuellerMesswert =  ultraSensor.distanceCm();

  if(abstandVeraendert(aktuellerMesswert))
  {
    Serial.println(aktuellerMesswert);
  }
  // zeigeMesswerteSpeicher();


}


// Ab und zu hat der Sensor Messfehler
boolean abstandVeraendert(double _aktuellerMesswert)
{
  
  fuegeZuMesswerteSpeicher(_aktuellerMesswert);

// erst nach zweitem Vorkommen des Messwertes -> damit werden sporadische Messfehler nicht so drastisch angezeigt
if(haeufigkeitInMesswertSpeicher(_aktuellerMesswert) > messwerteSpeicherGroesse / 2 )
{
    return true;
}
  
  return false;
}

int haeufigkeitInMesswertSpeicher(double _messwert)
{
  int retVal = 0;
  for(int positionImSpeicher = 0;positionImSpeicher < messwerteSpeicherGroesse;positionImSpeicher++)
  {
    retVal = (messwerteSpeicher[positionImSpeicher] == _messwert) ? retVal +1 : retVal;   
  }

  return retVal;
}

void fuegeZuMesswerteSpeicher(double _aktuellerMesswert)
{
  double neuerMesswerteSpeicher[messwerteSpeicherGroesse];

  for(int positionImBisherigenSpeicher=0; positionImBisherigenSpeicher + 1<messwerteSpeicherGroesse;positionImBisherigenSpeicher++)
  {
    int positionImNeuenSpeicher = positionImBisherigenSpeicher +1;
    neuerMesswerteSpeicher[positionImNeuenSpeicher] = messwerteSpeicher[positionImBisherigenSpeicher];
  }

  // neuen Wert an erste Stelle
  neuerMesswerteSpeicher[0] = _aktuellerMesswert;


for(int positionImNeuenSpeicher=0; positionImNeuenSpeicher<messwerteSpeicherGroesse;positionImNeuenSpeicher++)
  {
messwerteSpeicher[positionImNeuenSpeicher] = neuerMesswerteSpeicher[positionImNeuenSpeicher];

  }

}

void zeigeMesswerteSpeicher()
{

// Serial.print("Messwertespeicher:");


Serial.print("[");
  for(int positionImMesswerteSpeicher=0;positionImMesswerteSpeicher < messwerteSpeicherGroesse; positionImMesswerteSpeicher++)
{
Serial.print(messwerteSpeicher[positionImMesswerteSpeicher]);
Serial.print(";");
}
Serial.println("]");

}
