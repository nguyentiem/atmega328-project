
int timerOverflowCount = 0;

void initTimer() {
  TCCR0B = 0x03;
  DDRB = 0xff;       //configure PORTD as output
  TCNT0 = 0x00;
}


void setup() {
  // put your setup code here, to run once:
  initTimer();
}

void loop() {
  
     while ( TCNT0 < 250);
     TCNT0 =0x00;
     timerOverflowCount++;
     if(timerOverflowCount>=1000){
       PORTB ^= (1 << PORTB5);
       timerOverflowCount = 0;
      }
}
