#define down1 2 
#define down2 3 
#define down3 4 
#define down4 5

void DownServoPins_init(){
  pinMode(down1,OUTPUT);
  pinMode(down2,OUTPUT);
  pinMode(down3,OUTPUT);
  pinMode(down4,OUTPUT);
}

void down_forward(int speed){//前进
  analogWrite(down1,speed);
  analogWrite(down2,0);
  analogWrite(down3,speed);
  analogWrite(down4,0);
}

void down_back(int speed){//后退
  analogWrite(down1,0);
  analogWrite(down2,speed);
  analogWrite(down3,0);
  analogWrite(down4,speed);
}

void down_left(int speed){//前进
  analogWrite(down1,0);
  analogWrite(down2,speed);
  analogWrite(down3,speed);
  analogWrite(down4,0);
}

void down_right(int speed){//后退
  analogWrite(down1,speed);
  analogWrite(down2,0);
  analogWrite(down3,0);
  analogWrite(down4,speed);
}

void down_FB_stop(int speed)
{
  analogWrite(down1,0);
  analogWrite(down2,0);
  analogWrite(down3,0);
  analogWrite(down4,0);
}

void down_RL_stop(int speed)
{
  analogWrite(down1,0);
  analogWrite(down2,0);
  analogWrite(down3,0);
  analogWrite(down4,0);
}