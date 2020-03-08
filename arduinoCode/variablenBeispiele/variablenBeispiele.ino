// Voreinstellungen
void setup() {
  Serial.begin(9600); // Adresse setzen
}

// Eigentliche Arbeit
void loop()
{
  Serial.println("------Durchlauf-------");
  
  String ichBinEinText = "Hallo Welt";
  
  Serial.println(ichBinEinText);
  ichBinEinText = "Anderer Text";
  Serial.println(ichBinEinText);

  int zahl = 10;
  Serial.println(zahl);
  delay(1000);

}
