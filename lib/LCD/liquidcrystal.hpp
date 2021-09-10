/*
Programa: liquidcrystal.h
Autor: RecursiveError

header para gerenciar LCDs
*/
#ifndef _LIQUIDCRYSTAL_HPP
#define _LIQUIDCRYSTAL_HPP

#include <stdint.h>

#define _LCD_8BITS_ 1
#define _LCD_4BITS_ 2

namespace liquidcrystal{
    class Liquidcrystal{
        public:
            virtual Liquidcrystal& init(uint8_t line, uint8_t cols);
            virtual Liquidcrystal& write(char value);
            virtual Liquidcrystal& write(int value);
            virtual Liquidcrystal& write(char* value);
            virtual Liquidcrystal& config(uint8_t flag);
            virtual Liquidcrystal& set_curso(uint8_t line, uint8_t cols);
        protected:
            uint8_t _line{0}, _cols{0}, _mode{0};
        private:
            virtual void pulse() = 0;
            virtual void set_pins() = 0;
            virtual void send(uint8_t value, bool std) = 0;
    };
}


#endif
