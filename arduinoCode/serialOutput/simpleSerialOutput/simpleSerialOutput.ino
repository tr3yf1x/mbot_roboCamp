int durchgaenge;

// Voreinstellungen
void setup() {
  Serial.begin(9600); // Adresse setzen
  durchgaenge = 0;
}


// Eigentliche Arbeit
void loop()
{
  Serial.println(durchgaenge);
  durchgaenge = durchgaenge +1;
  delay(1000); // Einmal jede Sekunde;
}
