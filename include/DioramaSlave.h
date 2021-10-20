#ifndef _DIORAMA_SLAVE_H
#define _DIORAMA_SLAVE_H

#include <Arduino.h>
#include <Wire.h>

#define PERFORM_MESSAGE 1
    
class DioramaSlave {
public:
    DioramaSlave(int address);
    void begin();

    bool shouldPerform();
    void performed();

    void received(int howMany);
    void requestedSound();
    
private:

    const int address;

    void sendSound();
};

#endif