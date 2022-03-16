
#include <Servo.h>
int pinLB = 6; // define pin6 as left back connect with IN1
int pinLF = 9; // define pin9 as left forward connect with IN2
int pinRB = 10; // define pin10 as right back connect with IN3
int pinRF = 11; // define pin11 as right back connect with IN4



/*
int Fspeedd = 0; // forward distance
int Rspeedd = 0; // right distance
int Lspeedd = 0; // left distance
int directionn = 0; //

Servo myservo; // new myservo
int delay_time = 250; // set stable time
int Fgo = 8;
int Rgo = 6;
int Lgo = 4;
int Bgo = 2;
// forward
// turn right
// turn left
// back
*/

int MotorSpeed = 200;
int TurningSpeed = 200;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLB, OUTPUT);
  pinMode(pinLF, OUTPUT);
  pinMode(pinRB, OUTPUT);
  pinMode(pinRF, OUTPUT);
}


void advance(int a) // forward
{
  analogWrite(pinRB, 0);
  analogWrite(pinRF, MotorSpeed);
  analogWrite(pinLB, 0);
  analogWrite(pinLF, MotorSpeed);
  delay(a * 15);
}


void turnR(int d) //turn right
{
  analogWrite(pinRB, 0);
  analogWrite(pinRF, TurningSpeed);
  analogWrite(pinLB, TurningSpeed);
  analogWrite(pinLF, 0);
  delay(d * 50);
}

void turnL(int e) //turn left
{
  analogWrite(pinRB, TurningSpeed);
  analogWrite(pinRF, 0);
  analogWrite(pinLB, 0);
  analogWrite(pinLF, TurningSpeed);
  delay(e * 50);
}


void stopp(int f) //stop
{
  analogWrite(pinRB, 0);
  analogWrite(pinRF, 0);
  analogWrite(pinLB, 0);
  analogWrite(pinLF, 0);
  delay(f * 100);
}

void back(int g) //back
{
  analogWrite(pinRB, MotorSpeed);
  analogWrite(pinRF, 0);
  analogWrite(pinLB, MotorSpeed);
  analogWrite(pinLF, 0);
  delay(g * 15);
}


void loop() {
  // put your main code here, to run repeatedly:

  advance(50);
  stopp(10);
  turnR(2);
  stopp(10);
  back(10);
  stopp(10);
  turnL(4);
  stopp(10);
  delay(5000);


}
