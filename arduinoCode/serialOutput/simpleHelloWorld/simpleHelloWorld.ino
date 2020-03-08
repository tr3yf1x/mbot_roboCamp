
// Voreinstellungen
void setup() {
  Serial.begin(9600); // Adresse setzen
}


// Eigentliche Arbeit
void loop()
{
  Serial.println("Hello World!");
  delay(1000); // Einmal jede Sekunde;
}
