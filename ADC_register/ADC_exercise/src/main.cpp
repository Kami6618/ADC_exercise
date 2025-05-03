#include <Arduino.h>

#define ADC_CHANNEL 0

volatile int poti_value = 0;
volatile bool int_flag = false;

void setup() {
  Serial.begin(115200);

  // ADC aktivieren und Prescaler auf 128 setzen (125 kHz @ 16 MHz)
  ADCSRA |= (1 << ADEN) | (1 << ADIE) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

  // Interne 5V Referenzspannung aktivieren und Kanal setzen
  ADMUX = (ADMUX & 0b11110000) | (ADC_CHANNEL & 0x0F);
  
  ADMUX |= (1 << REFS0);

  sei(); // globale Interrupts aktivieren

  // Erste Wandlung starten
  ADCSRA |= (1 << ADSC);
}

void loop() {
  if (int_flag) {
    int_flag = false;

    float voltage = (poti_value * 5.0) / 1023.0;

    Serial.print("Potentiometer analog value = ");
    Serial.print(voltage, 2);
    Serial.println(" V");

    delay(500);

    // Nächste Messung starten
    ADCSRA |= (1 << ADSC);
  }
}

ISR(ADC_vect) {
  poti_value = ADC;
  int_flag = true;
}
