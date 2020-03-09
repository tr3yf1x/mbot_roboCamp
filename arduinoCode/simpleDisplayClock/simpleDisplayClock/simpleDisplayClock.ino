#include <string.h>
#include <MeMCore.h>

#include <MeLEDMatrix.h>
#include <MePort.h>

// Voreinstellungen
void setup() {
 
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Test");
  Serial.println("-----------");
  
}

// Eigentliche Arbeit
void loop()
{
  int i = 0;
  Serial.print("Test");
  i++;
  delay(1000);
}
