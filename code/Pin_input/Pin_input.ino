void initPin() {
  //////////////// write
//  DDRB |= (1 << DDB3);     // set pin 3 of Port B as output
//  PORTB |= (1 << PB3);     // set pin 3 of Port B high
//  PORTB &= ~(1 << PB3);    // set pin 3 of Port B low
//  PORTB |= (1 << PORTB3);  // set pin 3 high again
  /////////// read ////////
  DDRB &= ~(1 << PINB4);
//  uint8_t pinValue = PINB & (1 << PINB4);
}

uint8_t readPin() {
  uint8_t pinValue = PINB & (1 << PINB4);
  return pinValue;
}

void setup() {
  // put your setup code here, to run once:
initPin(); 
Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(readPin());
delay(1000);
}
