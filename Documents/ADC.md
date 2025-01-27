# ADC Documention
An Analog-to-Digital Converter (ADC) is a system that converts an analog signal (continuous values such as voltage) into a digital value (discrete binary representation) that can be processed by a microcontroller or computer.
For example, an Arduino Nano (ATmega328P) has a 10-bit ADC, meaning it converts an analog voltage (0–5V) into values between 0 - 1023.

`Related Registers:`
- ADMUX
- ADCSRA
- ADCSRB (not covered)
- ADC : ADCH and ADCL

# ADMUX bit map:
| Bit | Description | Name |
| --- | ----------- | ---- |
| 3-0	| Channel Selection Bits | MUX[3:0]	|
| 7-6 | Reference Selection Bits | REFS |
| 5 | ADC Left Adjust Result | ADLAR |
| 4 | not used | _ |

- `Channel Selection Bits`:
These four bits selects which of the 8 analog inputs are being used.

| 3 | 2 | 1 | 0 | pin |
| - | - | - | - | --- |
| 0 | 0 | 0 | 0 | A0 |
| 0 | 0 | 0 | 1 | A1 |
| 0 | 0 | 1 | 0 | A2 |
| 0 | 0 | 1 | 1 | A3 |
| 0 | 1 | 0 | 0 | A4 |
| 0 | 1 | 0 | 1 | A5 |
| 0 | 1 | 1 | 0 | A6 |
| 0 | 1 | 1 | 1 | A7 |

The last bit(`3`) is used for internal ADCs which are not covered here.

- `Reference Selection Bits`:
In order to perform an analog-to-digital conversion (ADC), the microcontroller needs a reference voltage to compare the input voltage on the selected analog pin to the reference voltage.

| 7 | 6 | reference |
| - | - | --------- |
| 0 | 1 | Uses the AVcc pin as the reference voltage. `5V` |
| 0 | 0 | Uses the external voltage at the `AREF` pin as the reference voltage |
| 1 | 1 | Uses the internal `1.1V` reference voltage as the reference for the ADC |
| 1 | 0 | not used |

- `ADC Left Adjust Result`:

The ADC on the ATmega328P produces a 10-bit result (values from 0 to 1023) after the conversion. Since each register can only hold 8 bits (one byte), the result is split across two registers: ADCL (low byte) and ADCH (high byte).

**If ADLAR = 0 (Right-Adjusted Result):**
- The 10-bit result is right-aligned in the ADCL and ADCH registers.
- The least significant 8 bits (LSB) go into ADCL, and the most significant 2 bits (MSB) go into the high byte of ADCL, while ADCH gets the remaining 2 most significant bits.
**If ADLAR = 1 (Left-Adjusted Result):**
- The 10-bit result is left-aligned in the ADCL and ADCH registers.
- The most significant 8 bits (MSB) go into ADCH, and the least significant 2 bits (LSB) go into ADCL.

# ADCSRA bit map:

| Bit | Description | name |
| --- | ----------- | ---- |
|  7  | ADC Enable: Enables the ADC (1 = enabled) | ADEN |
|  6  | ADC Start Conversion: Starts the conversion (1 = conversion started) | ADSC |
|  5  | ADC Auto Trigger Enable: Enables automatic triggering for conversions | ADATE |
|  4  | ADC Interrupt Flag: Indicates that the conversion is complete (1 = conversion complete) | ADIF |
|  3  | ADC Interrupt Enable: Enables the ADC conversion interrupt | ADIE |
|  2-0  | ADC Prescaler: ADC clock prescaler | 	ADPS |

