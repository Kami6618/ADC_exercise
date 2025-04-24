#include <Arduino.h>
#define Potipin  A5  // Der PotentiometerPin wird definiert

unsigned long lastmillis = 0;

void setup() {
  
  
  Serial.begin(9600);
}

void loop() {

  if(millis() - lastmillis >= 500) { // Benutzung von millis für die Aktualisierung alle 0.5 Sekunden
    
    int Analogwert = analogRead(Potipin);
    float Spg = Analogwert * (5.0/1023.0); // Umrechnung in Spannung
    Serial.print("Potentiometer analog value = ");
    Serial.print(Spg, 2);
    Serial.println(" V");
  }
}
