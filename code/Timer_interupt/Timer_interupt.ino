/*
 compare OCRA interupt 
 */
int timerOverflowCount = 0;

void initTimer() {
  // che do compare A 
  TCCR0A =0x80; 
  // pre scale f/64 
  TCCR0B = 0x03;
  DDRB = 0xff;       //configure PORTD as output
  TCNT0 = 0x00;
  //gia tri compare 
  OCR0A=250;
  // thiet lap ngat timer  
   TIMSK0= 0x02; 
  // ngat tong 
  sei(); 
}

ISR( TIMER0_COMPA_vect) {
 timerOverflowCount++;
  if(timerOverflowCount>=1000){
       PORTB ^= (1 << PORTB5);
       timerOverflowCount = 0;
      }
} 

void setup() {
  // put your setup code here, to run once:
  initTimer();
}

void loop() {
  
}
