/*
 * lcd.c
 *
 * Created: 12/31/2020 7:30:14 PM
 * Author: alireza
 */

#include <stdio.h>
#include <mega16.h>
#include <delay.h>

#asm
    .equ __lcd_port=0x18;
#endasm
#include <lcd.h>


void main(void){
    PORTB = 0x00;
    DDRB = 0x00;
    
    lcd_init(16);
    lcd_clear();
    lcd_gotoxy(0,0);
    lcd_putsf("Hello World!");
}
