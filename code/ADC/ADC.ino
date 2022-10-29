#define F_CPU 16000000UL
#define USART_BAUDRATE 9600 // Desired Baud Rate
#define BAUD_PRESCALER (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

#define ASYNCHRONOUS (0<<UMSEL00) // USART Mode Selection

#define DISABLED    (0<<UPM00)
#define EVEN_PARITY (2<<UPM00)
#define ODD_PARITY  (3<<UPM00)
#define PARITY_MODE  DISABLED // USART Parity Bit Selection

#define ONE_BIT (0<<USBS0)
#define TWO_BIT (1<<USBS0)
#define STOP_BIT ONE_BIT      // USART Stop Bit Selection

#define FIVE_BIT  (0<<UCSZ00)
#define SIX_BIT   (1<<UCSZ00)
#define SEVEN_BIT (2<<UCSZ00)
#define EIGHT_BIT (3<<UCSZ00)
#define DATA_BIT   EIGHT_BIT

void initADC(unsigned int input_channel) {
 
//  ADCSRA |= (1 << ADEN);
//  ADMUX |= (1 << REFS0) | (1 << REFS1);
//  ADMUX |= (0 << ADLAR);
//
//  // Select input channel for AD_Converter: AD0 - AD7
//  ADMUX |= input_channel;
//  // 16MHz / 128 ~ 125kHz
//  ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

// Select Vref=AVcc
 ADMUX |= (1<<REFS0);
 //set prescaller to 128 and enable ADC 
 ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADEN);    
  ADMUX = (ADMUX & 0xF0) | (input_channel & 0x0F);
 
}

int readADC() {
 
  ADCSRA |= (1 << ADSC) ;
  while (ADCSRA & (1 << ADSC));

  return ADC;
}

void initUART() {
  UBRR0H = BAUD_PRESCALER >> 8;
  UBRR0L = BAUD_PRESCALER;

  // Set Frame Format
  UCSR0C = ASYNCHRONOUS | PARITY_MODE | STOP_BIT | DATA_BIT;
  UCSR0B = (0 << RXEN0) | (1 << TXEN0);
}

void send_char(char  a){
   while (( UCSR0A & (1 << UDRE0)) == 0) {}; // Do nothing until UDR is ready
  UDR0 = 'a';
}

void sendUART(int a) {
  if(a==0){
    while (( UCSR0A & (1 << UDRE0)) == 0) {}; // Do nothing until UDR is ready
     UDR0 = '0';
    while (( UCSR0A & (1 << UDRE0)) == 0) {}; // Do nothing until UDR is ready
     UDR0 = '\n';
    return ; 
  }
  char t[5]; 
  int l =0; 
  while (a > 0) {
    t[l++] = a % 10;
    a /= 10;
  } 
  
  if(l==0){
    return ; 
  }
  
  for(int i = l-1;i>=0;i-- ){ 
    t[i] += 48;
    while (( UCSR0A & (1 << UDRE0)) == 0) {}; // Do nothing until UDR is ready
    UDR0 = t[i];
    }
   
  while (( UCSR0A & (1 << UDRE0)) == 0) {}; // Do nothing until UDR is ready
  UDR0 = '\n';
}

void setup() {
  int t = 0;
  int i, j;
  initUART();
  initADC(0);
}
int tem = 0;
void loop() {
  tem  = readADC();
  sendUART(tem);
  delay(1000);
}
