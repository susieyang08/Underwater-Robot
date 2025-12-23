#include "DownServo_function.h"
#include "AroundServo_function.h"
#include <Servo.h>
// #include <MPU6050_tockn.h>
// #include <Wire.h>

Servo myServo;//定义涵道电机
// MPU6050 mpu6050(Wire);//定义MPU6050的I2C通信
int run_state = 0;

void setup()
{
  // put your setup code here, to run once:
  DownServoPins_init();//初始化底盘轮子的所有引脚
  AroundServoPins_init();//初始化周围螺旋桨电机的引脚
  myServo.attach(17, 1000, 2000);//初始化涵道电机
  myServo.writeMicroseconds(1500);//设置涵道电机处于停止状态
  Serial1.begin(9600);//蓝牙模块HC-12的通讯引脚
  Serial.begin(9600);//电脑串口监控器
  // Wire.begin();//初始化i2c总线
  // mpu6050.begin();//初始化MPU6050
  // mpu6050.calcGyroOffsets(true);//开机校准MPU6050
}

void loop()
{
  // put your main code here, to run repeatedly:
  controlByHC_12();//通过HC-12对机器人进行控制
  
  
  // testAngle();
  // 下面代码是打印MPU6050传回来的数据值
  // mpu6050.update();
  // Serial.print("angleX : ");
  // Serial.print(mpu6050.getAngleX());
  // Serial.print("\tangleY : ");
  // Serial.println(mpu6050.getAngleY());
  // delay(200);
}

void controlByHC_12()
{
  if(Serial1.available())
  {
    String data_receive = Serial1.readStringUntil('\n');
    // Serial.println(data_receive);//电脑接受数据


    //控制轮子的左右移动
    if(data_receive.substring(0,data_receive.indexOf(':')) == "lx"){ //如果蓝牙传来的数据值是控制底盘的轮子d
      int down_speedX = (data_receive.substring(data_receive.indexOf(':') + 1, data_receive.indexOf('y'))).toInt();
      int down_speedY = (data_receive.substring(data_receive.indexOf('y') + 1, data_receive.indexOf('e'))).toInt();

      if(down_speedX > 200){//当拨杆返回数值大于200，视为向前推拨杆，小车前进
        down_forward(150);
      }else if(down_speedX < -200){//反之，后退
        down_back(150);
      }else if(down_speedY > 200){//左转
        down_left(150);
      }else if(down_speedY < -200){//右转
        down_right(150);
      }else if(down_speedX > -180 && down_speedX < 180 && down_speedY > -180 && down_speedY < 180){
        down_FB_stop(0);
      }
    }

    //控制螺旋桨
    //控制前后左右的翻转
    if(data_receive.substring(0,data_receive.indexOf(':')) == "rx")
    {
      int around_speedX = (data_receive.substring(data_receive.indexOf(':') + 1, data_receive.indexOf('y'))).toInt();
      int around_speedY = (data_receive.substring(data_receive.indexOf('y') + 1, data_receive.indexOf('e'))).toInt();
 
      if(around_speedX > 200){ //向前推
        around_forward(255);
      }else if(around_speedX < -200){//向后拉
        around_back(255);
      }else if(around_speedY > 200){//向右推
        around_right(255);
      }else if(around_speedY < -200){//向左推
        around_left(255);
      }else if(around_speedX > -180 && around_speedX < 180 && around_speedY > -180 && around_speedY < 180){
        around_stop(0);
      }
    }

    

    //控制rov推进器
    if(data_receive.substring(0,data_receive.indexOf(':')) == "q"){
      myServo.writeMicroseconds(1000);//反向推进
    }
    else if(data_receive.substring(0, data_receive.indexOf(':')) == "w")
    {
      myServo.writeMicroseconds(2000);//正向推进
    }
    else if(data_receive.substring(0, data_receive.indexOf(':')) == "s")
    {
      myServo.writeMicroseconds(1500);//停止
    }
  }
}

// void testAngle()//通过MPU6050传回来的数值进行姿态调整
// {
//   mpu6050.update();
//   int AngleX = mpu6050.getAngleX();
//   int AngleY = mpu6050.getAngleY();
//   while(AngleX < -40 || AngleX > 40 || AngleY < -40 || AngleY > 40)
//   {
//     if(AngleX > 40)
//     {
//       around_left(150);
//       delay(30);
//       around_left(0);
//       // Serial.print("1: ");
//       // Serial.println(AngleX);
//     }
//     if(AngleX < -40)
//     {
//       around_right(150);
//       delay(30);
//       around_right(0);
//       // Serial.print("2: ");
//       // Serial.println(AngleX);
//     }
//     if(AngleY > 40)
//     {
//       around_back(150);
//       delay(30);
//       around_back(0);
//       // Serial.print("3: ");
//       // Serial.println(AngleX);
//     }
//     if(AngleY < -40)
//     {
//       around_forward(150);
//       delay(30);
//       around_forward(0);
//       // Serial.print("4: ");
//       // Serial.println(AngleX);
//     }
//     mpu6050.update();
//     AngleX = mpu6050.getAngleX();
//     AngleY = mpu6050.getAngleY();
//   }
// }