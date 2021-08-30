/*
liquidcrystal.C
Autor: RecursiveError

biblioteca para display lcd 16x2 compativel com HD44780
Adaptada para o Shift-Register 74HC595
*/
#include <util/delay.h>
#include <stdint.h> 
#include <stdlib.h>
#include "IO.h"
#include "liquidcrystal_expander_595.h"

//gera clock no pino EN do display
static void lcd_595_push(liquidcrystal_595 *const self, uint8_t data, uint8_t mode){
    digitalWrite(self->register_select, mode);
    switch(self->mode){
        case _4BITS_:
            self->controler->write(self->controler, data >> 4);
            self->pulse(self);
            self->controler->write(self->controler, data & 0x0F);
            self->pulse(self);
            break;
        case _8BITS_:
            self->controler->write(self->controler, data);
            self->pulse(self);
            break;
        case FULL:
            //ainda não implemtentado
            break;
        default:
            return;
        break;
    }
}

//pulsa o LCD fora SOMENTE PARA O MODO DE BITS (4BITS/8BITS)
static void lcd_595_pulse_bits(liquidcrystal_595 *const self){
    if(self->mode == FULL){
        //AINDA NÃO IMPLEMENTADO
    }else{
        digitalWrite(self->enable, HIGH);
        _delay_us(5);
        digitalWrite(self->enable, LOW);
        _delay_us(5);
    }
}

liquidcrystal_595* _liquidcrystal_595_C(operating_mode mode, uint8_t data, uint8_t clock,uint8_t enable,\
                                      uint8_t register_select, uint8_t lcd_enable){
                                          
    liquidcrystal_595 *temp = (liquidcrystal_595*)malloc(sizeof(liquidcrystal_595));
    temp->controler = serial_output_C(data, clock, enable);
    temp->register_select = register_select;
    temp->enable = lcd_enable;
    temp->mode = mode;
    temp->push_data = lcd_595_push;
    temp->pulse = lcd_595_pulse_bits;
    return temp;
}