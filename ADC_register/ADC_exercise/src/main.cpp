#include <Arduino.h>

unsigned long lastmillis = 0;

void setup() {
  Serial.begin(9600);

  ADMUX = (0000);
  
  ADCSRA = (1 << ADEN ) | (1<< ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

void loop() {

  if(millis() - lastmillis >= 500) { // Benutzung von millis für die Aktualisierung alle 0.5 Sekunden
    
    ADCSRA |= (1 << ADSC);
    int analogwert = ADC;
    float spg = (analogwert * 5.0) /1023.0; // Umrechnung in Spannung
    Serial.print("Potentiometer analog value = ");
    Serial.print(spg, 2);
    Serial.println(" V");
    
    lastmillis = millis();
 }
}
