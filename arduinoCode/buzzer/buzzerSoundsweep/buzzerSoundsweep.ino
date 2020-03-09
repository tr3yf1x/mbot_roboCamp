
#include <string.h>
#include <MeMCore.h>

#include <MeLEDMatrix.h>

// Richtige Port-Nummer angeben!
MeUltrasonicSensor ultraSensor(3);
MeLEDMatrix Matrix_1(1);
MeBuzzer buzzer;

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
      Serial.print("Messwert:");
			Serial.println(aktuellesMessergebnis);
			zeigeWertAufDisplay(aktuellesMessergebnis);  
			vorherigesMessergebnis = aktuellesMessergebnis;      
		}
parkGeraeusch(aktuellesMessergebnis);
	}
}

boolean werteWeichenAb(double _aktuellerMesswert, double _vorherigerMesswert)
{
	return  abs(_aktuellerMesswert - _vorherigerMesswert) > 0.5;
}

void zeigeWertAufDisplay(double _input)
{
	String ausgabe = String( _input);

	// Längenbeschränkung auf 4 - LED-Matrix kann eh nicht mehr anzeigen.
	char ausgabeZeichenkette[4];
	ausgabe.toCharArray(ausgabeZeichenkette, 4);

	// Helligkeit des Displays setzen
	setzteHelligkeit(_input);

	Matrix_1.drawStr(1,7, ausgabeZeichenkette);
}

void setzteHelligkeit(double _aktuellerMesswert)
{
	if(_aktuellerMesswert < 5)
	{
		Matrix_1.setBrightness(5);
	}
	else if(_aktuellerMesswert < 7)
	{
		Matrix_1.setBrightness(4);
	}
	else if(_aktuellerMesswert < 10)
	{
		Matrix_1.setBrightness(3);
	}
	else if(_aktuellerMesswert < 15)
	{
		Matrix_1.setBrightness(2);
	}
	else if(_aktuellerMesswert < 20)
	{
		Matrix_1.setBrightness(1);
	}
	else
	{
		Matrix_1.setBrightness(0);
	}
}

void parkGeraeusch(double _aktuellerMesswert)
{
	if(_aktuellerMesswert > 10)
	{
		return;
	}

// Messwert wird kleiner, Frequenz muss aber höher werden
double frequenzFaktor = 10.0 / _aktuellerMesswert;
frequenzFaktor *= frequenzFaktor;
Serial.print("Frequenzfaktor:");
Serial.println(frequenzFaktor);
Serial.print("Frequenz:");
Serial.println(262 * frequenzFaktor);
    buzzer.tone(262 * frequenzFaktor, 0.25 * 1000);

}
