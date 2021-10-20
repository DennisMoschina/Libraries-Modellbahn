#include <SoundDioramaMaster.h>

SoundDioramaMaster::SoundDioramaMaster(DFRobotDFPlayerMini* player): SoundMaster(player) {}

void SoundDioramaMaster::begin() {
    SoundMaster::begin();
    DioramaMaster::begin();
}