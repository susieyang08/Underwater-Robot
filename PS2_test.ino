#include "functions.h"

void setup()
{
  // put your setup code here, to run once:
  pinMode(STOP, INPUT);
  ps2_pins_init();
  pinMode(UP, INPUT);
  pinMode(DOWN,INPUT);
  HC12.begin(9600);
  Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:
  readKey();
  delay(100);

  HC12.print("lx:");
  HC12.print(map(analogRead(A0),0,1024,-255,255));
  HC12.print("y");
  HC12.print(map(analogRead(A1),0,1024,-255,255));
  HC12.print('e');
  HC12.print('\n'); 
  delay(100);

  HC12.print("rx:");
  HC12.print(map(analogRead(A2),0,1024,-255,255));
  HC12.print("y");
  HC12.print(map(analogRead(A3),0,1024,-255,255));
  HC12.print('e');
  HC12.print('\n');
  delay(100);
}
