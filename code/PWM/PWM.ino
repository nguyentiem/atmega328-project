/*
amtgega 328 có 6 pin PWM tương ứng với 
 TCCRxB TCCRxA OCxA OCxB : x -0,1,2
TCCRxB: cau hinh clock 
TCCRxA: cau hinh che do compare cho a và b 
như vay A va B dùng  chung che độ clock 
OCxA là giá trị compare để thực hiện pwm 
*/
void initPWM(){
//
//   // 0A 
//  DDRD |= (1<<PD6);    //Fast PWM output at OC0A pin
//  OCR0A = 50; // Duty cycle of 75%
//  TCCR0A |= (1<<COM0A1) | (1<<WGM01) | (1<<WGM00);  //Non-Inverting Fast PWM mode 3 using OCR A unit
//  TCCR0B |= (1<<CS00);  //No-Prescalar
//  // 0B 
//  DDRD |= (1<<PD5);    //Fast PWM output at OC0B pin
//  OCR0B = 191;  // Duty cycle of 75%
//  TCCR0A |= (1<<COM0B1) | (1<<WGM01) | (1<<WGM00);  //Non-Inverting Fast PWM mode 3 using OCR B unit
//  TCCR0B |= (1<<CS00);  //No-Prescalar

  DDRD |= (1<<PD6);    //Fast PWM output at OC0B pin
  OCR0A = 0;  // Duty cycle of 75%
  TCCR0A |= (1<<COM0A0)& (~(1<<COM0A1))| (1<<WGM01) | (1<<WGM00);  //Non-Inverting Fast PWM mode 3 using OCR B unit
  TCCR0B |= (1<<CS00)| (1<<WGM02);  //No-Prescalar
  }

void setup() {
  // put your setup code here, to run once:
    initPWM();
}

void loop() {
  // put your main code here, to run repeatedly:

}
