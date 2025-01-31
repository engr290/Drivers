# Timers
There are three timers in ATmega328P.

- Timer0 (8 - bits)
- Timer1 (16 - bits)
- Timer2 (8 - bits)

Since Timer1 is 16-bit, it offers greater accuracy, and we will use it later for PWM.

# Timer1
Related Registers:
- TCCR1A
- TCCR1B
- TCNT1
- OCR1
- ICR1
- TIMSK1
- TIFR1

# TCCR1A – Timer/Counter1 Control Register A

| bit | Name |
| --- | ---- |
| 7 | COM1A1 |
| 6 | COM1A0 |
| 5 | COM1B1 |
| 4 | COM1B0 |
| 3 | - |
| 2 | - |
| 1 | WGM11 |
| 0 | WGM10 |

# TCCR1B – Timer/Counter1 Control Register B

| bit | Name |
| --- | ---- |
| 7 | ICNC1 |
| 6 | ICES1 |
| 5 | - |
| 4 | WGM13 |
| 3 | WGM12 |
| 2 | CS12 |
| 1 | CS11 |
| 0 | CS10 |

#### Compare Output Mode for Channel A, Pin 9
| COM1A1 | COM1A0 | Behavior |
| ------ | ------ | -------- |
| 0 | 0 | Normal (OC1A disconnected) |
| 0 | 1 | Toggle OC1A on compare match |
| 1 | 0 | Clear OC1A on compare match (Non-inverting PWM) |
| 1 | 1 | Set OC1A on compare match (Inverting PWM) |

#### Compare Output Mode for Channel B, Pin 10
| COM1B1 | COM1B0 | Behavior |
| ------ | ------ | -------- |
| 0 | 0 | Normal (OC1B disconnected) |
| 0 | 1 | Toggle OC1B on compare match |
| 1 | 0 | Clear OC1B on compare match (Non-inverting PWM) |
| 1 | 1 | Set OC1B on compare match (Inverting PWM) |


#### Waveform Generation Mode
| WGM13 | WGM12 | WGM11 | WGM10 | Mode |
| ----- | ----- | ----- | ----- | ---- |
| 0 | 0 | 0 | 0 | Normal Mode |
| 0 | 1 | 0 | 0 | CTC Mode (OCR1A) |
| 1 | 1 | 1 | 0 | Fast PWM (ICR1 as TOP) |
| 1 | 1 | 1 | 1 | Fast PWM (OCR1A as TOP) |


#### Clock Select – Prescaler
| CS12 | CS11 | CS10 | Clock Source |
| ---- | ---- | ---- | ------------ |
| 0 | 0 | 0 | No clock (Timer stopped) |
| 0 | 0 | 1 | No prescaler (16 MHz) |
| 0 | 1 | 0 | Prescaler 8 (2 MHz) |
| 0 | 1 | 1 | Prescaler 64 (250 kHz) |
| 1 | 0 | 0 | Prescaler 256 (62.5 kHz) |
| 1 | 0 | 1 | Prescaler 1024 (15.625 kHz) |


