int lt = 2;
int hw = 3;
int ledpin = 13;
int val_lt; 
int val_hw;

void setup() {
  // put your setup code here, to run once:
pinMode(ledpin, OUTPUT);
pinMode(lt, INPUT);
pinMode(hw, INPUT);
Serial.begin(9600);
}

void loop() {
val_lt = digitalRead(lt);
 if (val_lt == 0)
 {
 digitalWrite(ledpin, HIGH);
 
}
else
{
  digitalWrite(ledpin, LOW);

}
// val_hw = digitalRead(hw);
// if (val_hw == 0)
//
//{
// digitalWrite(ledpin, HIGH)
//}
//else
//{
// digitalWrite(ledpin, LOW);
//}
Serial.print("lt");
Serial.println(" ");  
Serial.println(val_lt);

//Serial.print(" ");  
//Serial.print("hw");
//Serial.print(hw);
//Serial.print(" ");     
// 
delay(1000);
}
