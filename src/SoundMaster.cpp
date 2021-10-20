#include <SoundMaster.h>

void SoundMaster::SoundSlaveAddress::add(int address) {
    SoundSlaveAddress* newElement = new SoundSlaveAddress();
    newElement->address = address;
    newElement->next = this->next;
    this->next = newElement;
}

bool SoundMaster::SoundSlaveAddress::contains(int address) {
    if (this == nullptr) return false;
    if (this->address == address) return true;
    return this->next->contains(address);
}

void SoundMaster::SoundSlaveAddress::remove(int address) {
    if (this->next == nullptr) return;
    if (this->next->address == address) {
        SoundSlaveAddress* newNext = this->next->next;
        delete this->next;
        this->next = newNext;
    }
}


SoundMaster::SoundMaster(DFRobotDFPlayerMini* player) {
    this->player = player;
}

void SoundMaster::begin() {
    Wire.begin();
}

void SoundMaster::addSlave(int address) {
    if (this->slaveAddressList == nullptr) {
        SoundSlaveAddress* newElement = new SoundSlaveAddress();
        newElement->address = address;
        this->slaveAddressList = newElement;
    } else if (!this->slaveAddressList->contains(address)) this->slaveAddressList->add(address);
}

void SoundMaster::removeSlave(int address) {
    while (this->slaveAddressList->contains(address)) this->slaveAddressList->remove(address);
}

void SoundMaster::handleSound() {
    SoundSlaveAddress* currentIndex = this->slaveAddressList;
    while (currentIndex != nullptr) {
        this->requestSound(currentIndex->address);
        currentIndex = currentIndex->next;
    }
    Serial.println();
}

void SoundMaster::requestSound(int address) {
    Serial.println(address);
    if (Wire.requestFrom(address, DATA_SIZE) != DATA_SIZE) {
        Serial.println("number of returned bytes not matched");
        return;
    }
    this->readSound();
}

void SoundMaster::playSound(int sound) {
    Serial.print("playing sound ");
    Serial.println(sound);
    if (this->player->readState() != 1) this->player->play(sound);
}

void SoundMaster::readSound() {
    int sound = Wire.read();
    if (sound <= 0) {
        Serial.println("no valid sound chosen");
        return;
    }
    this->playSound(sound);
}