#include <stdint.h>
#include <util/delay.h>

#include "liquidcrystal.hpp"
#include "IO.hpp"

namespace liquidcrystal{
    Liquidcrystal& Liquidcrystal::init(uint8_t cols, uint8_t line){
        this->set_pins();
        this->_line = line;
        this->_cols = cols;
        this->config(0X3);
        _delay_ms(5);
        this->config(0X3);
        _delay_us(160);
        this->config(0X3);//ESTADO DA COMUNICAÇÃO É 8BITS
        _delay_us(160);
        if(this->_mode == _LCD_4BITS_){
            this->config(0x2);
        }
        _delay_ms(10);

        //confg do display
        config(0x28);
        config(0x0C);
        config(0x01);
        _delay_us(15);

        return *this;
    }

    Liquidcrystal& Liquidcrystal::write(char value){
        this->send(value, true);
        _delay_us(80);
        return *this;
    }

    Liquidcrystal& Liquidcrystal::write(int value){
        unsigned long int i = 10000;
        while(i>0){
            this->write((char)(value/i) % 10 + 48);
            i /= 10;
        }
        return *this;
    }

    Liquidcrystal& Liquidcrystal::write(char* value){
        for(uint16_t i = 0; value[i] != '\0'; i++){
            this->write(value[i]);
        }
        return *this;
    }

    Liquidcrystal& Liquidcrystal::config(uint8_t flag){
        this->send(flag, false);
        _delay_ms(2);
        return *this;
    }

    Liquidcrystal& Liquidcrystal::set_curso(uint8_t line, uint8_t cols){
        if(line == 0){
            this->config(0x80+cols);
        }
        if(line == 1){
            this->config(0xC0+cols);
        }
        return *this;
    }

    void Liquidcrystal::send(uint8_t value, bool std){
        //override this
    }

    void Liquidcrystal::pulse(){
        //override this
    }

    void Liquidcrystal::set_pins(){
        //override this
    }

}