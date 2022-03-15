#include <Servo.h>

Servo myservo;                             //Lager servo objekt for å kontrollere servo


int pos = 0;                               // Variabel for å lagre servo posisjon

void setup() {
  myservo.attach(3);                       // Setter servo på pin 5 til servo objekt
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) {    // Går fra 0 grader til 180 grader, med en økning på 1 grad 
                                       
    myservo.write(pos);                    // Forteller servo å gå til posisjon i forhold til variabel "pos"
    delay(15);                             // Venter 15 ms for servo til å nå posisjon
  }
  for (pos = 180; pos >= 0; pos -= 1) {    // Går fra 180 grader til 0 grader, med en nedøkning på 1
    myservo.write(pos);                    // Forteller servo å gå til posisjon i forhold til variabel "pos"
    delay(15);                             // Venter 15 ms for servo til å nå posisjon
  }
}
