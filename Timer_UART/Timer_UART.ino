int timerOverflowCount = 0;
char *p = "Nguyen Van Tiem";
uint8_t cnt = 0;
char mess[10];
bool volatile  flag = false; // danh dau bat dau gui

void encode(char c) {
  mess[0] =0;
  mess[9] = 1;
  for (int i = 1; i <= 8; i++) {
    mess[i] = (c >> (i - 1)) & 0x01;
  }
}

void initTimer() {
  // che do compare A
  TCCR0A = 0x80;
  // pre scale f/64
  TCCR0B = 0x03;
  DDRB = 0xff;       //configure PORTD as output
  TCNT0 = 0x00;
  //gia tri compare
  /*
     16.000.000 clk = 1s => 9600 b/s can 16.000.000/9600 clk
     ta su dung f/64 cho do le ocra = 16.000.000/(9600*64) = 28
  */
  OCR0A = 28;
  // thiet lap ngat timer
  TIMSK0 = 0x02;
  // ngat tong
  sei();
}

void initPinRx() {
  DDRD |= (1 << DDD0);
  DDRB |= (1 << DDD5);
}



void set(int i) {
  //    PORTB |= (1 << PB3);     // set pin 3 of Port B high
  //    PORTB &= ~(1 << PB3);
  PORTD &= (i << PD0);
}

ISR( TIMER0_COMPA_vect) {
  if (flag) {
    PORTD &= (mess[cnt++] << PD0); // gan trang thai
    if (cnt >= 10) {
      cnt = 0;
      flag  = false;
    }
  }

}

void setup() {
  // put your setup code here, to run once:
  initTimer();
  encode('T');
  flag = true;
}

void loop() {

}
