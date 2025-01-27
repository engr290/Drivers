enum class c_ADC_ref {
  VCC,
  AREF,
  internal_1_1
};


bool c_init_adc(uint8_t pin, c_ADC_ref reference) {

  if (pin > 7)
    return false;

  ADMUX &= 0xF0;  // Clear the lower 4 bits

  // Selecting ADC Pin
  ADMUX |= pin;

  // Selecting ADC reference
  uint8_t temp = 0;
  switch (reference) {
    case c_ADC_ref::VCC:
        temp = 48; // 0110000
      break;
    case c_ADC_ref::AREF:
        temp = 16; // 0010000
      break;
    case c_ADC_ref::internal_1_1:
        temp = 112; // 1110000
      break;
    default:
      return false;
  }
  ADMUX |= temp;

  ADCSRA &= 0xF8; // Clear the previous prescaler setting
  ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Set prescaler to 128 

  ADCSRA |= (1 << ADEN);   // turning adc on


  return true;
}

int c_analog_read(){

  ADCSRA |= (1 << ADSC);   // start reading

  // i is there for timeout
  for(int i = 0; i < 10000 && (ADCSRA & (1 << ADSC)); i++);
  
  return ADC;

}
