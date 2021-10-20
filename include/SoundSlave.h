#ifndef _SOUND_SLAVE_H
#define _SOUND_SLAVE_H

#include <Wire.h>

class SoundSlave {
public:
    SoundSlave(int address);

    void begin();

    void playSoundWithID(int sound);
    void sendSound();

private:
    const int address;
    
    // int soundToPlay = -1;

    void noSound();
};

#endif