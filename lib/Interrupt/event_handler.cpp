#include "event_handler.hpp"

namespace interrupt{
    void Interrupt::set_handle(uint8_t interrupt_num, handler_func callback){
        if(callback == nullptr || interrupt_num > 26) return;
        this->Handler_func[interrupt_num] = callback;

    }
    void exec(Interrupt &handler,uint8_t interrupt_num){
        if(handler.Handler_func[interrupt_num] != nullptr){
            handler.Handler_func[interrupt_num]();
        }
    }
}