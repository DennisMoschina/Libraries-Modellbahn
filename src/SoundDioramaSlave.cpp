#include <SoundDioramaSlave.h>

SoundDioramaSlave::SoundDioramaSlave(int address): SoundSlave(address), DioramaSlave(address) {
}

void SoundDioramaSlave::begin() {
    SoundSlave::begin();
    DioramaSlave::begin();
}