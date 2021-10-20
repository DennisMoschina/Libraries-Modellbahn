#include "DioramaMaster.h"

DioramaMaster::DioramaMaster() {
}

void DioramaMaster::begin() {
    Wire.begin();
}

void DioramaMaster::sendStart(int address) {
    // Serial.println("sending start");
    Wire.beginTransmission(address);
    Wire.write(1);
    Wire.endTransmission();
}