#ifndef _DIORAMA_MASTER_H
#define _DIORAMA_MASTER_H

#include <Arduino.h>
#include <Wire.h>

class DioramaMaster {
public:
    DioramaMaster();

    void begin();

    void sendStart(int address);
};

#endif