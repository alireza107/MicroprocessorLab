/*******************************************************
This program was created by the
CodeWizardAVR V3.14 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : simple counter
Version : 1.0.0
Date    : 12/31/2020
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

int timer;
int number = 0; // because we are using decoder we can pass decimal numbers

// Timer1 overflow interrupt service routine
interrupt [TIM1_OVF] void timer1_ovf_isr(void)
{
    ++timer;
    if(timer == 5){
        if(number < 10){
            PORTD =  number;
        } else {
            number = 0 ;
            PORTD = number;
        }
        number++;
    }

    TCNT1H=0xFF;
    TCNT1L=0xF0;
}

void main(void)
{
    TCCR1A=0x00;
    TCCR1B=0x01;
    TCNT1H=0xFF;
    TCNT1L=0xF0;

    MCUCR=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
    MCUCSR=(0<<ISC2);

    // Timer(s)/Counter(s) Interrupt(s) initialization
    TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (1<<TOIE1) | (0<<OCIE0) | (0<<TOIE0);

    #asm("sei")    

    DDRD=0xff;
    PORTD=0; // set default value for counter

    while (1) {

    }
}