#ifndef _SOUND_DIORAMA_MASTER_H
#define _SOUND_DIORAMA_MASTER_H

#include <DioramaMaster.h>
#include <SoundMaster.h>

class SoundDioramaMaster: public DioramaMaster, public SoundMaster {
public:
    SoundDioramaMaster(DFRobotDFPlayerMini* player);

    void begin();
};

#endif