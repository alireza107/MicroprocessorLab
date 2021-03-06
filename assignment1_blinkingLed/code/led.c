/*******************************************************
This program was created by the
CodeWizardAVR V3.14 Advanced
Automatic Program Generator
� Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : Blinking LED
Version : 
Date    : 12/13/2020
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

// Declare temp variable 
int temp;

void main(void)
{
    temp = 0x00;

    DDRA = 0x00;   
    PINA = 0x00;  
       
    DDRB = 0xff;  
    PORTB = 0x00;
    
    #asm("sei")

    while (1) {  
            if(PINA.0==1)  // click btn for start blinking 
            {   temp = 0x1;
                while(temp<=0xff) {  // forward blinking of LEDs
                     PORTB = temp; 
                     temp = temp*2; // going to next port by *2
                     delay_ms(50);
                }  
                temp = 0x80;
                while(temp>=0x1) {   // reverse blinking of LEDs
                     PORTB = temp; 
                     temp = temp/2;  // going to previous port by /2
                     delay_ms(50);
                } 
            } else {
                PORTB = 0x00; 
                temp = 0x00;
            }
    }
}