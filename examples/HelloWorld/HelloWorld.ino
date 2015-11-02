

#include <SPI.h>
#include "Ucglib.h"

Ucglib_ILI9163_18x128x128_HWSPI ucg(/*dc=*/ 10 , /*cs=*/ 8, /*reset=*/ 9);

byte displayUpdate = 0;
int rad;

void setup(void)
{
  delay(1000);
  ucg.begin(UCG_FONT_MODE_TRANSPARENT);
  //ucg.begin(UCG_FONT_MODE_SOLID);
  ucg.clearScreen();
  ucg.setRotate180();
}

void loop(void)
{
  
  ucg.setColor(236, 240, 241);
  ucg.drawBox(0,0,128,128);
  ucg.setColor(52, 73, 94);
  ucg.drawDisc(0,0,rad,UCG_DRAW_LOWER_RIGHT);
  ucg.setColor(236, 240, 241);
  ucg.drawBox(16,0,112,128);
  ucg.drawBox(0,40,28,88);
  drawPause6_8(3, 15);
  rad+= 6;
  if(rad > 45) rad = 0;
  
  delay(500);  
}

void drawPause6_8(int x, int y) {
  ucg.drawLine(x, y, (x+1), (y+8));
  ucg.drawLine((x+3), y, (x+4), (y+8));
}
  
