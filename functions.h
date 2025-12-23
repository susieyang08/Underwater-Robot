#include <SoftwareSerial.h>

SoftwareSerial HC12(4, 5);

#define LEFT_X A0
#define LEFT_Y A1
#define RIGHT_X A2
#define RIGHT_Y A3
#define STOP 6
#define UP 2
#define DOWN 3


void ps2_pins_init()
{
  pinMode(LEFT_X, INPUT);
  pinMode(LEFT_Y, INPUT);
  pinMode(RIGHT_X, INPUT);
  pinMode(RIGHT_Y, INPUT);
}


void readKey(){
  if(digitalRead(STOP) == 0)
  {
    delay(40);
    if(digitalRead(STOP) == 0)
    {
      HC12.print("s:");
      HC12.println('e');
    }
  }

  if(digitalRead(UP) == 0)
  {
    delay(40);
    if(digitalRead(UP) == 0)
    {
      HC12.print("w:");
      HC12.println('e');
    }
  }

  if(digitalRead(DOWN) == 0)
  {
    delay(40);
    if(digitalRead(DOWN) == 0)
    {
      HC12.print("q:");
      HC12.println('e');
    }
  }
}