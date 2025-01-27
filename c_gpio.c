#include <stdint.h>
#include <avr/io.h>
#include <stdio.h>

bool c_setpin_output(uint8_t pin){
  if (pin < 8){
    uint8_t bit_val = (1 << pin);
    DDRD |= bit_val;
  }
  else if (pin < 14){
    pin -= 8;
    uint8_t bit_val = (1 << pin); 
    DDRB |= bit_val;
  }

  else
    return false;

  return true;
}

bool c_digital_write(int pin, bool setOn){

  if (pin < 8){
    uint8_t bit_val = (1 << pin);
    if (setOn) {
      PORTD |= bit_val;
    }
    else {
      bit_val = ~bit_val;
      PORTD &= bit_val;
    }
  } 
  else if (pin < 14){
    pin -= 8;
    uint8_t bit_val = (1 << pin); 
    if (setOn) {
      PORTB |= bit_val;
    }
    else {
      bit_val = ~bit_val;
      PORTB &= bit_val;
    } 
  }

  else
    return false;

  return true;

}
