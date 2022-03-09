
#include <SoftwareSerial.h>         //inkludere bibliotek til serial avlesing for porter som ikke er TX/RX
SoftwareSerial mySerial(11, 10);     //definere port 10 og 9 til serial avlesing RX/TX
#include <Wire.h>


char val;                           //variabel for tekst
char seriell_tekst;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);               //start seriell avlesning
  mySerial.begin(9600);             //start bluetooth seriell avlesning
  Wire.begin();                     //start I2C kommuniserings prosess
}

void loop() {
  // put your main code here, to run repeatedly:

  if (mySerial.available()) {                           //hvis tekst blir detektert på myserial portene
    val = mySerial.read();                              //variabel for tekst leser av myserial
    Serial.print(val);                                  //variabel for tekst printer innholdet i lokalt seriell vindu.
<<<<<<< Updated upstream
  }
=======
  }                                                     
>>>>>>> Stashed changes

if  (Serial.available()) {   
  seriell_tekst = Serial.read();
  mySerial.write(seriell_tekst);
}


//Serial.print (1);
//delay(500);
}
