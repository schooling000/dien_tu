#include "Led.h"

Led::Led(int PinConnect){
    _status = OFF;
    _pin = PinConnect;
    pinMode(_pin, OUTPUT);
}

void Led::off(){
    _status = OFF;
    digitalWrite(_pin, _status);
}

void Led::on(){
    _status = ON;
    digitalWrite(_pin, _status);
}