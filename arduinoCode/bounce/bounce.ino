#include <string.h>
#include <MeMCore.h>


#include <MeLEDMatrix.h>
#include <MePort.h>

//MeBoard myBoard(MakeblockOrion); MeBoard myBoard(mBot);
MeLEDMatrix Matrix_1(1);

char string_data[] = ".";

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
  
  while (true)
  {
     // 8 yAxis 16 xAxis
      int32_t xAxis = 1;

      for (int32_t yAxis = 0; yAxis < 15; yAxis++)
      {
        Matrix_1.drawStr(xAxis, yAxis, string_data);
       // xAxis ++;

        delay(300);
      }
    }
}
