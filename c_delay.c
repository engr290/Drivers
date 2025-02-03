volatile unsigned long timer_count = 0;  // Variable to hold the number of timer overflows

// Timer 0 Interrupt Service Routine (ISR)
ISR(TIMER0_COMPA_vect) {
  timer_count++;  // Increment the count every time Timer 0 matches OCR0A
}

// Custom delay function using Timer 0
void delayTimer0(unsigned long ms) {

 // Set Timer 0 to CTC mode
  TCCR0A = 0;               // Normal mode (no PWM, no special behavior)
  TCCR0B = (1 << WGM02) | (1 << CS01) | (1 << CS00);  // CTC mode, prescaler 64

  OCR0A = 249;  // Set OCR0A for a 1ms delay (with prescaler 64, the timer will overflow every 1ms)

  TIMSK0 |= (1 << OCIE0A);  // Enable interrupt on compare match A (when timer reaches OCR0A)


  unsigned long target_count = ms;  // Calculate when to stop (target count)
  
  // Wait until the timer_count reaches the target_count
  while (timer_count < target_count) {
    // You can place other code here that will run during the delay
  }

  timer_count = 0;
  TCCR0A = 0;   // Clear TCCR0A register
  TCCR0B = 0;   // Clear TCCR0B register
}
