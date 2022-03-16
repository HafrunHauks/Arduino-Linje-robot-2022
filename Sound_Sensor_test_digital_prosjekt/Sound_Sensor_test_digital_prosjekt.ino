const int mic =  8;                                         // Setter mic til pin 8                           
int val = 0;                                                // Variabel for å aktivere sensor på høyere frekvens

void setup()
{
  
  Serial.begin(9600);                                       // Initialiserer seriell kommunikasjon på 9600 bits per sekund
 
  pinMode(mic, INPUT);                                      // Initialiserer micen som input

}

void loop()
{
   
  
  val=digitalRead(mic);                                     // Val settes til å digital lese på mic                       
  if (val == 1)                                             // Sjekker om val blir lik 1
  { 
    Serial.println("hearing something");                    // Seriell printer  til seriell overvåker
    delay(1000);                                            // Frekvens er på 1535hz i 1 sekund
  }
}
 
