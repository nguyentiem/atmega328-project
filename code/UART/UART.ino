char *p = "Nguyen Van Tiem ";
char *q = "Tran Thi Diu ";
char dem =0; 

void initUART() {
   int i = 0;
    unsigned int ubrr = (16000000 / 8 / 9600 - 1) / 2; 
  
  UCSR0A = (0 << RXC0) | (0 << TXC0) | (0 << UDRE0) | (0 << FE0) | (0 << DOR0) | (0 << UPE0) | (0 << U2X0) | (0 << MPCM0);
  UCSR0B = (1 << RXCIE0) | (0 << TXCIE0) | (0 << UDRIE0) | (1 << RXEN0) | (1 << TXEN0) | (0 << UCSZ02) | (0 << RXB80) | (0 << TXB80);
  UCSR0C = (0 << UMSEL01) | (0 << UMSEL00) | (0 << UPM01) | (0 << UPM00) | (0 << USBS0) | (1 << UCSZ01) | (1 << UCSZ00) | (0 << UCPOL0);
  UBRR0H = (ubrr>>8);
  UBRR0L = (ubrr);
  sei();
}

void tx(char c) {
   while (!( UCSR0A & (1<<UDRE0))); /* Wait for empty transmit buffer*/
          UDR0 =c;            /* Put data into buffer, sends the data */

}

void tx_string(char *p) {
  char c;
  while ((c = *p++)!=NULL) {
    tx(c);
  }
}
//
ISR(USART_RX_vect)
{
  
  char data = UDR0;
  if (data == 't') {
    tx_string(p);
  } else {
    tx_string(q);
  }
  
  
}

void setup() {


        initUART();
//        tx_string(p);
//        char i;
//        while((i=*p++) != NULL) /* print the String  "Hello from ATmega328p" */
//        {
//          while (!( UCSR0A & (1<<UDRE0))); /* Wait for empty transmit buffer*/
//          UDR0 =i;            /* Put data into buffer, sends the data */
//                                    /* increment counter           */
//        }
      
}

void loop() {
  // put your main code here, to run repeatedly:

}
