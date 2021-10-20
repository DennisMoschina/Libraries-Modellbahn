#include <DioramaSlave.h>

bool perform = false;

DioramaSlave *ptrToClassDioramaSlave;

static void outsideReceived(int howMany) {
    ptrToClassDioramaSlave->received(howMany);
}

DioramaSlave::DioramaSlave(int address): address(address) {
}

void DioramaSlave::begin() {
    Wire.begin(address);
    Wire.onReceive(outsideReceived);
}

bool DioramaSlave::shouldPerform() {
    Serial.print("Should perform in getter: ");
    Serial.println(perform);
    return perform;
}
void DioramaSlave::performed() {
    perform = false;
}

void DioramaSlave::received(int howMany) {
    int result = Wire.read();
    Serial.print("message: ");
    Serial.println(result);
    perform = (result == PERFORM_MESSAGE);
    Serial.print("shouldPerform in received: ");
    Serial.println(perform);
}