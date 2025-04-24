# ADC_excercise

## Direkte Register (für ADC laut Datenblatt)

### Wichtige Register und Bits:

- **ADMUX** – ADC Multiplexer Selection Register (Siehe 23.9.1 im Datenblatt)
  - **MUX3:0** (Bits 3-0): Pinwahl, z.B. `0101` für ADC5 (Pin A5 Siehe Tabelle 23-4. Input Channel Selections)

- **ADCSRA** – ADC Control and Status Register A
  - **ADEN** (Bit 7): ADC aktivieren
  - **ADSC** (Bit 6): Start der Konvertierung
  - **ADIF** (Bit 4): ADC Interrupt Flag (zeigt Ende der Konvertierung an)
  - **ADIE** (Bit 3): Interruptenable (wenn ADC über Interrupts verwendet wird)
  - **ADPS2:0** (Bits 2-0): Prescaler zur Taktrate

### Prescaler

Der ADC benötigt eine Frequenz zwischen 50 kHz und 200 kHz (Siehe Datenblatt S.208 Z.1). Bei 16 MHz Systemtakt wird z. B. ein Prescaler von 128 gewählt:
- **16 MHz / 128 = 125 kHz**.
- ADPS2:0 = 111 (setzt Prescaler auf 128 siehe Tabelle auf S.219)
