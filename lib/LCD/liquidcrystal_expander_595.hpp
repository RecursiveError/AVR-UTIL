/*
Programa: liquidcrystal_expander_595.h
Autor: RecursiveError

biblioteca para o displays compativeis com o HD44780 usando o shift-register 74hc595

essa biblioteca também é compatível com controladores semelhantes ao shift-register 74hc595
*/

#ifndef _LCD_595_H
#define _LCD_595_H


#include <stdint.h>
#include "liquidcrystal.hpp"
#include "expander_74hc595.hpp"
#include "IO.hpp"
namespace liquidcrystal{
    class Liquidcrystal595_4bits : public Liquidcrystal{
        public:
            Liquidcrystal595_4bits() = default;
            Liquidcrystal595_4bits(uint8_t data, uint8_t clock, uint8_t enable, uint8_t RS, uint8_t EN):
            controller{data,clock,enable},
            register_select{RS},
            enable{EN}
            {
                this->_mode = _LCD_4BITS_;
            }
        private:
            serial_output::Expander_74hc595 controller;
            digitalIO::DigitalIO register_select, enable;
            void pulse() override;
            void set_pins() override;
            void send(uint8_t value, bool std) override;
    };
}

#endif