#ifndef _SOUND_Master_H
#define _SOUND_Master_H

#include <Arduino.h>
#include <Wire.h>
#include <DFRobotDFPlayerMini.h>

class SoundMaster {
    struct SoundSlaveAddress {
        int address;
        SoundSlaveAddress* next = nullptr;

        bool contains(int address);
        void remove(int address);
        void add(int address);
    };

public:
    SoundMaster(DFRobotDFPlayerMini* player);

    void begin();

    void addSlave(int address);
    void removeSlave(int addres);
 
    void handleSound();

private:
    static const int SOUND_SIZE = sizeof(int);
    static const int DATA_SIZE = SOUND_SIZE;

    DFRobotDFPlayerMini* player;

    SoundSlaveAddress* slaveAddressList = nullptr;

    void requestSound(int address);
    void playSound(int sound);
    void readSound();
};

#endif