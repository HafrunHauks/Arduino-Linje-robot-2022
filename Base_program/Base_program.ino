
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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinLB, OUTPUT);
  pinMode(pinLF, OUTPUT);
  pinMode(pinRB, OUTPUT);
  pinMode(pinRF, OUTPUT);
}


void advance(int a) // forward
{
  digitalWrite(pinRB, LOW);
  digitalWrite(pinRF, HIGH);
  digitalWrite(pinLB, LOW);
  digitalWrite(pinLF, HIGH);
  delay(a * 15);
}


void turnR(int d) //turn right
{
  digitalWrite(pinRB, LOW);
  digitalWrite(pinRF, HIGH);
  digitalWrite(pinLB, HIGH);
  digitalWrite(pinLF, LOW);
  delay(d * 50);
}

void turnL(int e) //turn left
{
  digitalWrite(pinRB, HIGH);
  digitalWrite(pinRF, LOW);
  digitalWrite(pinLB, LOW);
  digitalWrite(pinLF, HIGH);
  delay(e * 50);
}


void stopp(int f) //stop
{
  digitalWrite(pinRB, HIGH);
  digitalWrite(pinRF, HIGH);
  digitalWrite(pinLB, HIGH);
  digitalWrite(pinLF, HIGH);
  delay(f * 100);
}

void back(int g) //back
{
  digitalWrite(pinRB, HIGH);
  digitalWrite(pinRF, LOW);
  digitalWrite(pinLB, HIGH);
  digitalWrite(pinLF, LOW);
  delay(g * 300);
}


void loop() {
  // put your main code here, to run repeatedly:

  advance(50);
  stopp(20);
  turnR(2);
  stopp(10);
  /*
      back(10);
    delay(1000);
    turnL(10);
    delay(1000);
    stopp(5);
    delay(1000);
    advance(5);
    delay(5000);
  */

}
