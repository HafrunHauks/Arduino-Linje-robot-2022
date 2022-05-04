
#include <Servo.h>
int pinLB = 6; // define pin6 as left back connect with IN1
int pinLF = 9; // define pin9 as left forward connect with IN2
int pinRB = 10; // define pin10 as right back connect with IN3
int pinRF = 11; // define pin11 as right back connect with IN4

int sensor_hoy = 2;
int sensor_hoyhoy = 3;
int sensor_ven = 4;
int sensor_venven = 5;

int sensor_kollisjon_echo = 7;
int sensor_kollisjon_trigger = 8;
int duration =0;
int distance = 0;


bool hoy = 0;
bool hoyhoy = 0;
bool ven = 0;
bool venven = 0;


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
  Serial.begin(9600);
  pinMode(pinLB, OUTPUT);
  pinMode(pinLF, OUTPUT);
  pinMode(pinRB, OUTPUT);
  pinMode(pinRF, OUTPUT);

  pinMode(sensor_hoy, INPUT);
  pinMode(sensor_hoyhoy, INPUT);
  pinMode(sensor_ven, INPUT);
  pinMode(sensor_venven, INPUT);



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

void sensor()
{
  hoy = digitalRead(sensor_hoy);
  hoyhoy = digitalRead(sensor_hoyhoy);
  ven = digitalRead(sensor_ven);
  venven = digitalRead(sensor_venven);
}

void kollisjon()
{
  digitalWrite(sensor_kollisjon_trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(sensor_kollisjon_trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensor_kollisjon_trigger, LOW);
  duration = pulseIn(sensor_kollisjon_echo, HIGH);
  distance = (duration  * 0.0343) / 2;
  distance = constrain (sensor_kollisjon_echo, 0.0, 60.0);
  delay(1);
}

void loop() {
  // put your main code here, to run repeatedly:



  kollisjon();

  sensor();
  Serial.print(hoy);
  Serial.print(hoyhoy);
  Serial.print(ven);
  Serial.print(venven);
  Serial.println("");

  //Kjøre fram
  if ((hoy == LOW) and (hoyhoy == LOW) and (ven == LOW) and (venven == LOW))
  {
    advance(50);
  }

  //
  if ((hoy == HIGH) and (hoyhoy == LOW) and (ven == LOW) and (venven == LOW))
  {
    turnL(4);
  }


  if ((hoy == HIGH) and (hoyhoy == HIGH) and (ven == LOW) and (venven == LOW))
  {
    turnL(6);

  }


  if ((hoy == LOW) and (hoyhoy == LOW) and (ven == HIGH) and (venven == LOW))
  {
    turnR(4);
  }


  if ((hoy == LOW) and (hoyhoy == LOW) and (ven == HIGH) and (venven == HIGH))
  {
    turnR(6);
  }


}
