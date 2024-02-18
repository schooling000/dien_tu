#ifndef LED_H
#define LED_H

#include "Arduino.h"
#include "..\Type\Type.h"

class Led{
    private: 
        EStatus _status;
        int _pin;
    public:
        Led(int PinConnect);
        void debug(void *moniter);
        void on();
        void off();
};

#endif