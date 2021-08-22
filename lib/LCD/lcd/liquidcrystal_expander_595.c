/*
LCD.C
Autor: RecursiveError

biblioteca para display lcd 16x2 compativel com HD44780
Adaptada para o Shift-Register 74HC595
*/
#include <util/delay.h>
#include <stdint.h> 
#include "IO.h"
#include "liquidcrystal_expander_595.h"

//gera clock no pino EN do display
void lcd_pulse(LCD *const self){
    digitalWrite(self->enable, HIGH);
    _delay_us(5);
    digitalWrite(self->enable, LOW);
    _delay_us(5);
}

//envia 4 bits para o display
void push_nibble(LCD *const self, char value, char select){
    so_write(&self->controler, value);
    digitalWrite(self->resister_select, select);
    lcd_pulse(self);    
}

//envia 8 bits em 2 pacotes de 4 bits
void push_byte(LCD *const self, char value, char register_select){
    push_nibble(self, value >> 4, register_select);
    push_nibble(self, value & 0x0F, register_select);
}


void lcd_send_char(LCD *const self, char value){
    push_byte(self, value, HIGH);
    _delay_us(80);
}

void lcd_command(LCD *const self, char value){
    push_byte(self, value, LOW);
    _delay_ms(2);
}

void lcd_send_string(LCD *const self, char string[]){
    int i = 0;
    while(string[i] != '\0'){
        lcd_send_char(self, string[i]);
        i++;
    }
}

void lcd_send_number(LCD *const self, int value){
    unsigned long int i = 10000;
    while(i>0){
        lcd_send_char(self, (value/i) % 10 + 48);
        i /= 10;
    }
}


//define a posição do cursor
void lcd_set_position(LCD *const self, int line, int col){
    if(line == 0){
        lcd_command(self, 0x80+col);
    }
    if(line == 1){
        lcd_command(self, 0xC0+col);
    }    
}

//inicia o display
void lcd_init(LCD *const self, uint8_t register_select, uint8_t enable){
    pinMode(register_select, OUTPUT);
    pinMode(enable, OUTPUT);
    self->resister_select = register_select;
    self->enable = enable;
    so_init(&self->controler, DATA, CLOCK, ENABLE);

     
    _delay_ms(15);
    //ESTADO DA COMUNICAÇÃO É INCERTO
    push_nibble(self, 0X3, LOW);
    _delay_ms(5);
    push_nibble(self, 0X3, LOW);
    _delay_us(160);
    push_nibble(self, 0X3, LOW);//ESTADO DA COMUNICAÇÃO É 8BITS

    //MUDANDO PARA 4BITS
    _delay_us(160);
    push_nibble(self, 0x2, LOW);
    _delay_ms(10);
    //confg do display
    lcd_command(self,0x28);
    lcd_command(self, 0x08+0x04);
    lcd_command(self, 0x01);
    _delay_us(15);
}



