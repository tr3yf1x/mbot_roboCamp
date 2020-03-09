#include <string.h>
#include <MeMCore.h>

#include <MeLEDMatrix.h>
#include <MePort.h>

long runtime = 0;
const long runtimeConversionFactor = 800;

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
  while (true)
  {
    sendTimeToSerial();
    runtime++;
    delay(1);
  }
  delay(1000);
}


void sendTimeToSerial()
{
  if(runtime % runtimeConversionFactor == 0)
  {
    Serial.print(getMinutes());
    Serial.print(":");
    Serial.println(getSeconds()); 
  }
}

long getMinutes()
{
    return (convertRuntimeToSeconds() / 60) % 60;
}

long getSeconds()
{
  return convertRuntimeToSeconds() % 60;
}

long convertRuntimeToSeconds()
{
  return runtime / runtimeConversionFactor;
}
