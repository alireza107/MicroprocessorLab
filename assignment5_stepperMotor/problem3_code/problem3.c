/*******************************************************
This program was created by the
CodeWizardAVR V3.14 Advanced
Automatic Program Generator
� Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : Stepper motor part 3 
Version : 1.0.0
Date    : 1/23/2021
Author  : Alireza Dizaji
Company : 
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 12.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/
#include <mega16.h>
#include <delay.h>

const unsigned char motorSteps[4] = {0b00001001 , 0b00000101 , 0b00000110 , 0b00001010};

int myTime;

interrupt [TIM0_OVF] void timer0_ovf_isr(void)
{

TCNT0=0x0C;

if(myTime < 20){
    if(PINC.2== 0) {
            PORTB = motorSteps[3];   
            delay_ms(10);

            PORTB = motorSteps[2];
            delay_ms(10); 

            PORTB = motorSteps[1];
            delay_ms(10); 

            PORTB = motorSteps[0];
            delay_ms(10); 
        }    
    ++myTime;
    } 
myTime = 0; //  set timer to zero
}

void main(void)
{

TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (1<<CS02) | (0<<CS01) | (1<<CS00);
TCNT0=0x0C;
OCR0=0x00;

TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (0<<CS11) | (0<<CS10);
TCNT1H=0x00;
TCNT1L=0x00;


TCCR2=(0<<PWM2) | (0<<COM21) | (0<<COM20) | (0<<CTC2) | (0<<CS22) | (0<<CS21) | (0<<CS20);
TCNT2=0x00;


TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (1<<TOIE0);

#asm("sei")

myTime = 0;  
DDRC = 0x00;   
PINC = 0x00;  
DDRB = 0xff;  
PORTB = 0x00;

while (1)
      {

      }
} 