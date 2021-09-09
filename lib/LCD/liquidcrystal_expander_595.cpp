/*
liquidcrystal.C
Autor: RecursiveError

biblioteca para display lcd 16x2 compativel com HD44780
Adaptada para o Shift-Register 74HC595
*/
#include <util/delay.h>
#include "IO.hpp"
#include "liquidcrystal_expander_595.hpp"

namespace liquidcrystal {
    void Liquidcrystal595_4bits::send(uint8_t value, bool std){
        if(std) register_select.set_high();
        else register_select.set_low();
        this->controller.send(value >> 4);
        this->pulse();
        this->controller.send(value & 0X0F);
        this->pulse();
    }

    void Liquidcrystal595_4bits::pulse(){
        this->enable.set_high();
        _delay_us(5);
        this->enable.set_low();
        _delay_us(5);
    }
    void Liquidcrystal595_4bits::set_pins(){
        this->controller.init().send(0x00);
        this->register_select.output().set_low();
        this->enable.output().set_low();
    }
}


/*
static void _lcd_595_push_8bits_(liquidcrystal_595 *const self, uint8_t data, uint8_t mode){
    digitalWrite(self->register_select, mode);
    self->controler->write(self->controler, data);
    self->pulse(self);
}

//gera clock no pino EN do display
static void _lcd_595_push_4bits_(liquidcrystal_595 *const self, uint8_t data, uint8_t mode){
    digitalWrite(self->register_select, mode);
    self->controler->write(self->controler, data >> 4);
    self->pulse(self);
    self->controler->write(self->controler, data & 0x0F);
    self->pulse(self);
}

static void _lcd_595_push_FULL_(liquidcrystal_595 *const self, uint8_t data, uint8_t mode){
    //ainda não implementado
    return;
}

//pulsa o LCD fora SOMENTE PARA O MODO DE BITS (4BITS/8BITS)
static void _lcd_595_pulse_bits_(liquidcrystal_595 *const self){
        digitalWrite(self->enable, HIGH);
        _delay_us(5);
        digitalWrite(self->enable, LOW);
        _delay_us(5);
}

static void _lcd_595_pulse_FULL_(liquidcrystal_595 *const self){
    //ainda não implementado
    return;
}



liquidcrystal_595* _liquidcrystal_595_C(uint8_t mode, uint8_t data, uint8_t clock,uint8_t enable,\
                                      uint8_t register_select, uint8_t lcd_enable, uint8_t read_write){
                                          
    liquidcrystal_595 *temp = (liquidcrystal_595*)malloc(sizeof(liquidcrystal_595));
    temp->controler = serial_output_C(data, clock, enable);
    temp->register_select = register_select;
    temp->enable = lcd_enable;
    temp->read_write = read_write;
    switch(mode){
        case _4BITS_:
            temp->push_data = _lcd_595_push_4bits_;
            temp->pulse = _lcd_595_pulse_bits_;
            break;
        case _8BITS_:
            temp->push_data = _lcd_595_push_8bits_;
            temp->pulse = _lcd_595_pulse_bits_;
            break;
        case _FULL_:
            temp->push_data = _lcd_595_push_FULL_;
            temp->pulse = _lcd_595_pulse_FULL_;
            break;
        default:
            free(temp);
            return NULL;
        break;
    }
    return temp;
}
*/