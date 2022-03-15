void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);                               //initialiserer sereill kommunikasjon på 9600bits per sekund

}

void loop() {
 {
int sensorValue = analogRead (A0);                // Leser input signalet på analog pin 0 

Serial.println (sensorValue);                     // Printer ut verdien loddrett i seriell monitor
 }
 

}
