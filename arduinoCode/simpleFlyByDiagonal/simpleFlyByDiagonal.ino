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
//MeBoard myBoard(MakeblockOrion); MeBoard myBoard(mBot);
MeLEDMatrix Matrix_1(1);
// char string_data[] = "1234567890abcdefghijklmnop";
char string_data[] = "x-x";

int move_times = strlen(string_data) * 12;

void setup() {
  Matrix_1.setBrightness(5);//
}

void loop()
{

/*
  for (int32_t i = 0; i < move_times; i++) {
    if (i > move_times)i = 0; 
    Matrix_1.drawStr(strlen(string_data) - i, 7, string_data);
    delay(60);
  }
  */
while(true)
{
  int32_t xAxis = -5;
  int32_t brightness = 1;
  for(int32_t yAxis = 0; yAxis < 15; yAxis++)
  {
    Matrix_1.drawStr(xAxis, yAxis, string_data);
   xAxis ++;
   brightness = (brightness > 4) ? 0 : brightness++;
  // Matrix_1.setBrightness(brightness);//
   
    delay(60);
  }
  
}
}
