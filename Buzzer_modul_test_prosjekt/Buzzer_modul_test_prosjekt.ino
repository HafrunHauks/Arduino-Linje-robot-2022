int buzzer = 4;                                      //Setter buzzer til pin 4

void setup() {
  // put your setup code here, to run once:
pinMode(buzzer, OUTPUT);                             //Buzzer blir til output signal

}

void loop() {
  // put your main code here, to run repeatedly:
tone(buzzer,1535,500);                               //Setter buzzeren på frekvens 1535 Hz for 500 millisekund    
delay(1000);                                         //500 milllisekund stillhet

}
