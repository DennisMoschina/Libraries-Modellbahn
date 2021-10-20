#include <SoundSlave.h>

int soundToPlay;

SoundSlave *ptrToClassSoundSlave;

static void outsideSendSound() {
    ptrToClassSoundSlave->sendSound();
}

SoundSlave::SoundSlave(int address): address(address) { }

void SoundSlave::begin() {
    Wire.begin(this->address);
    this->noSound();
    Wire.onRequest(outsideSendSound);
}

void SoundSlave::playSoundWithID(int sound) {
    soundToPlay = sound;
}

void SoundSlave::noSound() {
    this->playSoundWithID(0);
}

void SoundSlave::sendSound() {
    Wire.write(soundToPlay);
    this->noSound();
}