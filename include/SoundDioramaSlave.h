#ifndef _SOUND_DIORAMA_SLAVE_H
#define _SOUND_DIORAMA_SLAVE_H

#include <SoundSlave.h>
#include <DioramaSlave.h>

class SoundDioramaSlave: public SoundSlave, public DioramaSlave {
public:
    SoundDioramaSlave(int address);
    void begin();
};

#endif