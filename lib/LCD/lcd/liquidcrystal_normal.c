/*
Programa: liquidcrystal_normal.c
Autor: RecursiveError

biblioteca para o displays compativeis com o HD44780
*/
#include <stdlib.h>
/*
static void _lcd_normal_push_8bits_(liquidcrystal_normal *const self, uint8_t data, uint8_t mode){
    digitalWrite(self->register_select, mode);
    for(uint8_t i = 0; i<8; i++){
        digitalWrite(self->pins[i], data & (1<<i));
    }
    self->pulse(self);
}

static void _lcd_normal_push_4bits_(liquidcrystal_normal *const self, uint8_t data, uint8_t mode){
    digitalWrite(self->register_select, mode);
    uint8_t i;
    char high_nibble, low_nibble;

    high_nibble = (data>>4) & 0x0F;
    low_nibble = data;
    for(i = 0; i<4; i++){
        if((high_nibble & 1<<i)){
            digitalWrite(self->pins[i], HIGH);
        }else{
            digitalWrite(self->pins[i], LOW);
        }
    }
    digitalWrite(self->pins[0], HIGH);
    self->pulse(self);

    for(i = 0; i<4; i++){
        if((low_nibble & 1<<i)){
            digitalWrite(self->pins[i], HIGH);
        }else{
            digitalWrite(self->pins[i], LOW);
        }
    }
    self->pulse(self);
}


static void _lcd_normal_pulse_bits_(liquidcrystal_normal *const self){
    digitalWrite(self->enable, HIGH);
    _delay_us(5);
    digitalWrite(self->enable, LOW);
    _delay_us(5);

}


liquidcrystal_normal* _liquidcrystal_normal_C(uint8_t mode, uint8_t register_select, uint8_t enable, uint8_t read_write, uint8_t *pins){
    liquidcrystal_normal *temp = (liquidcrystal_normal*)malloc(sizeof(liquidcrystal_normal));
    temp->register_select = register_select;
    temp->enable = enable;
    temp->read_write = read_write;
    for(uint8_t i = 0; i<8; i++){
        temp->pins[i] = pins[i];
        pinMode(temp->pins[i], OUTPUT);
    }
    switch(mode){
        case _4BITS_:
            temp->push_data = _lcd_normal_push_4bits_;
            temp->pulse = _lcd_normal_pulse_bits_;
            break;
        case _8BITS_:
            temp->push_data = _lcd_normal_push_8bits_;
            temp->pulse = _lcd_normal_pulse_bits_;
            break;
        case _FULL_:
            break;
        default:
        free(temp);
        return NULL;
    }
    return temp;

}

*/