#include <Servo.h>                                          // Inkluderer biblotek <Servo.h>
Servo myservo;                                              // Lager servo objekt for å kontrollere servo

const int mic =  8;                                         // Setter mic til pin 8
const int buzzer = 4;                                       // Setter buzzer til pin 4
int pos = 0;                                                // Variabel for å lagre servo posisjon
int val = 0;                                                // Variabel for å aktivere sensor på høyere frekvens


void setup()
{
  Serial.begin(9600);                                       // Initialiserer seriell kommunikasjon på 9600 bits per sekund

  pinMode(mic, INPUT);                                      // Initialiserer micen som input

  myservo.attach(3);                                        // Setter servo på pin 3 til servo objekt
                                 

}

void loop()
{
  val = digitalRead(mic);                                   // Val settes til å digital lese på mic
  if (val == 1)                                             // Sjekker om val blir lik 1
  {
    tone(buzzer, 1535, 500);                                // Setter buzzeren på frekvens 1535 Hz for 500 millisekund
    Serial.println("hearing something");                    // Seriell printer  til seriell overvåker
    servo();                                                // Sender servo() til egen void
  }

  else                                                      // Eller
  {
    tone(buzzer, 31);                                       // Frekvens er på 31 hz når mic er deaktivert (val == 0)

  }
}

void servo()
{
  for (pos = 0; pos <= 180; pos += 1) {                     // Går fra 0 grader til 180 grader, med en økning på 1 grad

    myservo.write(pos);                                     // Forteller servo å gå til posisjon i forhold til variabel "pos"
    delay(15);                                              // Venter 15 ms for servo til å nå posisjon
  }
  for (pos = 180; pos >= 0; pos -= 1) {                     // Går fra 180 grader til 0 grader, med en nedøkning på 1
    myservo.write(pos);                                     // Forteller servo å gå til posisjon i forhold til variabel "pos"
    delay(15);                                              // Venter 15 ms for servo til å nå posisjon
  }
}
