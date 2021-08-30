#include <stdlib.h>
#include <stdint.h>
#include <util/delay.h>

#include "liquidcrystal.h"
#include "lcd/liquidcrystal_expander_595.h"
#include "IO.h"

static void lcd_send_char(liquidcrystal *const self, char value){
    self->super->push_data(self->super, value, HIGH);
    _delay_us(80);
}

static void lcd_command(liquidcrystal *const self, char value){
    self->super->push_data(self->super, value, LOW);
    _delay_ms(2);
}

static void lcd_send_string(liquidcrystal *const self, char *string){
    int i = 0;
    while(string[i] != '\0'){
        self->super->push_data(self->super, string[i], HIGH);
        i++;
    }
}

static void lcd_send_number(liquidcrystal *const self, int value){
    unsigned long int i = 10000;
    while(i>0){
        lcd_send_char(self, (value/i) % 10 + 48);
        i /= 10;
    }
}


//define a posição do cursor
static void lcd_set_position(liquidcrystal *const self, int line, int col){
    if(line == 0){
        lcd_command(self, 0x80+col);
    }
    if(line == 1){
        lcd_command(self, 0xC0+col);
    }    
}

static void lcd_init(liquidcrystal *const self){
    pinMode(self->super->register_select, OUTPUT);
    pinMode(self->super->enable, OUTPUT);
    //pinMode(read_write, OUTPUT);

    _delay_ms(15);
    lcd_command(self, 0x03);
    _delay_ms(5);
    lcd_command(self, 0x03);
    _delay_us(160);
    lcd_command(self, 0x03);                                
    _delay_us(160);
    if(self->super->mode != _8BITS_){
        //MUDANDO PARA 4BITS
        lcd_command(self, 0x02);
        _delay_ms(10);
    }
    //confg do display
    lcd_command(self, 0x28);
    lcd_command(self, 0x0C);
    lcd_command(self, 0x01);
    _delay_us(15);
    
}


//costrutor da classe principal
//recebe o tipo do lcd e recebe os mesmos argumentos  e em mesma ordem do seu costrutor
liquidcrystal* _liquidcrystal_C(lcd_type type, operating_mode mode, int pins[static 11]){
    liquidcrystal *lcd = (liquidcrystal*)malloc(sizeof(liquidcrystal));
    liquidcrystal_base *temp = (liquidcrystal_base*)malloc(sizeof(liquidcrystal_base));
    switch(type){
        case _NORMAL_:
            //Ainda não implementado
            break;
        case _SHIFT_74HC595_:
            temp = _liquidcrystal_595_C(mode,pins[0],pins[1],pins[2],pins[3],pins[4]);
            lcd->super = temp;
            break;
        default:
            free(temp);
            free(lcd);
            return NULL;
        break;
    }
    lcd->type = type;
    lcd->init = lcd_init;
    lcd->write = lcd_send_string;
    lcd->write_char = lcd_send_char;
    lcd->write_number = lcd_send_number;
    lcd->set_position = lcd_set_position;
    lcd->command = lcd_command;
    return lcd;
}