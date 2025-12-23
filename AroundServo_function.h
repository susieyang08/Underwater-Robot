#define Around1_1 6 
#define Around1_2 7
#define Around2_1 8
#define Around2_2 9
#define Around3_1 24
#define Around3_2 25
#define Around4_1 26
#define Around4_2 27

void AroundServoPins_init(){
  pinMode(Around1_1,OUTPUT);
  pinMode(Around1_2,OUTPUT);
  pinMode(Around2_1,OUTPUT);
  pinMode(Around2_2,OUTPUT);
  pinMode(Around3_1,OUTPUT);
  pinMode(Around3_2,OUTPUT);
  pinMode(Around4_1,OUTPUT);
  pinMode(Around4_2,OUTPUT);
}

void around_forward(int speed){
  analogWrite(Around1_1,0);
  analogWrite(Around1_2,speed);
  analogWrite(Around2_1,0);
  analogWrite(Around2_2,speed);
  analogWrite(Around3_1,0);
  analogWrite(Around3_2,speed);
  analogWrite(Around4_1,0);
  analogWrite(Around4_2,speed);
}

void around_back(int speed){
  analogWrite(Around1_1,speed);
  analogWrite(Around1_2,0);
  analogWrite(Around2_1,speed);
  analogWrite(Around2_2,0);
  analogWrite(Around3_1,speed);
  analogWrite(Around3_2,0);
  analogWrite(Around4_1,speed);
  analogWrite(Around4_2,0);
}

void around_left(int speed){
  analogWrite(Around1_1,speed);
  analogWrite(Around1_2,0);
  analogWrite(Around2_1,0);
  analogWrite(Around2_2,speed);
  analogWrite(Around3_1,speed);
  analogWrite(Around3_2,0);
  analogWrite(Around4_1,0);
  analogWrite(Around4_2,speed);
}

void around_right(int speed){
  analogWrite(Around1_1,0);
  analogWrite(Around1_2,speed);
  analogWrite(Around2_1,speed);
  analogWrite(Around2_2,0);
  analogWrite(Around3_1,0);
  analogWrite(Around3_2,speed);
  analogWrite(Around4_1,speed);
  analogWrite(Around4_2,0);
}

void around_stop(int speed)
{
  analogWrite(Around1_1,0);
  analogWrite(Around1_2,0);
  analogWrite(Around2_1,0);
  analogWrite(Around2_2,0);
  analogWrite(Around3_1,0);
  analogWrite(Around3_2,0);
  analogWrite(Around4_1,0);
  analogWrite(Around4_2,0);
}

void around_RL_stop(int speed)
{
  analogWrite(Around2_1,0);
  analogWrite(Around2_2,0);
  analogWrite(Around4_1,0);
  analogWrite(Around4_2,0);
}

void around_FB_stop(int speed)
{
  analogWrite(Around1_1,0);
  analogWrite(Around1_2,0);
  analogWrite(Around3_1,0);
  analogWrite(Around3_2,0);

}