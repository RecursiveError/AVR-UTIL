/*
liquidcrystal.C
Autor: RecursiveError

biblioteca para display lcd 16x2 compativel com HD44780
Adaptada para o Shift-Register 74HC595
*/
#include <util/delay.h>
#include "IO.hpp"
#include "lcd_package.hpp"

using namespace digitalIO;

namespace liquidcrystal {
    // --------------- LCD595_4BITS  FUNCTIONS ---------------
    void Lcd595_4bits::send(uint8_t value, bool std){
        if(std) DigitalIO(this->register_select).set_high();
        else DigitalIO(this->register_select).set_low();
        this->controller.send(value >> 4);
        this->pulse();
        this->controller.send(value & 0X0F);
        this->pulse();
    }

    void Lcd595_4bits::pulse(){
        DigitalIO(this->enable).set_high();
        _delay_us(5);
        DigitalIO(this->enable).set_low();
        _delay_us(5);
    }
    void Lcd595_4bits::set_pins(){
        this->controller.init().send(0x00);
        DigitalIO(this->register_select).output().set_low();
        DigitalIO(this->enable).output().set_low();
    }
    void Lcd595_4bits::set_cursor(uint8_t line, uint8_t cols){
        uint8_t command = (0x80 | (line<<6)) + cols;
        this->send(command, false);
    }
    // --------------- LCD595_4BITS  FUNCTIONS ---------------

    //-----------------------------------------------------

    // --------------- LCD2EN_4BITS  FUNCTIONS ---------------
    void Lcd2EN_4bits::send(uint8_t value, bool std){
        if(std) this->register_select.set_high();
        else this->register_select.set_low();
        this->send4bits(value >> 4);
        this->pulse();
        this->send4bits(value & 0x0F);
        this->pulse();
    }
    
    void Lcd2EN_4bits::send4bits(uint8_t value){
        for(auto i : this->pins){
            if(value & 0x01){
                i.set_high();
            }else{
                i.set_low();
            }
            value >>= 1;
        }
    }

    void Lcd2EN_4bits::pulse(){
        this->enable.set_high();
        _delay_us(5);
        this->enable.set_low();
        _delay_us(5);
    }

    void Lcd2EN_4bits::set_pins(){
        this->enable.output().set_low();
        this->enable = enable1;
        this->enable.output().set_low();
        this->register_select.output();
        for(auto i: this->pins){
            i.output().set_low();
        }
    }

    void  Lcd2EN_4bits::set_cursor(uint8_t line, uint8_t cols){
        if(line < 2) this->enable = enable1;
        else this->enable = enable2;
        uint8_t command = (0x80 | (line<<6)) + cols;
        this->send(command, false);
    }

}
