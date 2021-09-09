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
