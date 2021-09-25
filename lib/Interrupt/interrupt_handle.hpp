#ifndef _INT_HANDLER_HPP
#define _INT_HANDLER_HPP

#define int_vec 26 //quantidade de interrupções

typedef void (*handler_func)(void);
#include <stdint.h>

namespace  interrupt{
    class Interrupt{
        public: 
            void set_handle(uint8_t interrupt_num, handler_func callback);
            friend void exec(Interrupt &handler, uint8_t interrupt_num);
        private:
            handler_func Handler_func[int_vec]{nullptr};
    };
}
#endif