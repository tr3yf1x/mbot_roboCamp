/***********************************************************************
   Program:     Turn_On_All_Onboard_LEDs

   Author:      Charles McKnight

   Description:
    This program sets the color of the onboard LEDs to a shade of red,
    waits 2 seconds and then turns the onboard LEDs to black (off).
 ************************************************************************/

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
