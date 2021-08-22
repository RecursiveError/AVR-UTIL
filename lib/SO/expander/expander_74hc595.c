/*
Programa: expander_74hc595
Autor: RecursiveError

biblioteca para expansão de portas OUTPUT usando o shift-Register 74hc595
*/
#include <stdint.h>
#include "IO.h"
#include "expander_74hc595.h"


//inicia o 74hc595
uint8_t so_init(serial_output *const self, uint8_t data, uint8_t clock, uint8_t enable){
    self->data = data;
    self->clock = clock;
    self->enable = enable;
    pinMode(data, OUTPUT);
    pinMode(clock, OUTPUT);
    pinMode(enable, OUTPUT);
    return 0;
}

//gera clock no pino de data
uint8_t pulse_data(serial_output *const self){
    digitalWrite(self->clock, HIGH);
    digitalWrite(self->clock, LOW);
    return 0;
}

//gera clock no pino EN
uint8_t pulse_en(serial_output *const self){
    digitalWrite(self->enable, HIGH);
    digitalWrite(self->enable, LOW);
    return 0;
}


//envias as informaçãos bit a bit para o 74hc595
uint8_t so_write(serial_output *const self, char value){
    for(char i = 0; i < 8; i++){
        digitalWrite(self->data, value & 0x80);
        pulse_data(self);
        value <<= 1;
    }
    pulse_en(self);
    return 0;
}