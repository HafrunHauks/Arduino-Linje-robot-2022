

int sensor = 2;
int ledpin = 13;
int val;

void setup() {
Serial.begin(9600);
pinMode(sensor,INPUT);
pinMode(ledpin,OUTPUT);
}
 
void loop() {
bool value = digitalRead(sensor);
if(value == 0)
{
  digitalWrite(ledpin, HIGH);
 
}
else
{
    digitalWrite(ledpin, LOW);
  
  }
}

Vil denne funke?
