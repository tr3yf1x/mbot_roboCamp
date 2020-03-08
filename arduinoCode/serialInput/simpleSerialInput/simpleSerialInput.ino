String eingabeBenutzer = ""; // for incoming serial data

// Voreinstellungen
void setup() {
  Serial.begin(9600); // Adresse setzen
}


// Eigentliche Arbeit
void loop()
{
  // Prüfen, ob es Nachrichten gibt
  if (Serial.available()) {
    // Eingabe zuweisen:
    eingabeBenutzer = Serial.readString();

    // Benutzereingabe ausgeben
    Serial.print("Sie sagten: ");
    Serial.println(eingabeBenutzer);
  }
}
