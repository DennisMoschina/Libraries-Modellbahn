#ifndef _DIORAMA_SLAVE_H
#define _DIORAMA_SLAVE_H

#include <Arduino.h>
#include <Wire.h>

#define PERFORM_MESSAGE 1

/**
 * @brief Diese Klasse wird genutzt, um die Kommunikation zwischen einem Arduino, welcher das Ausführen
 * in den einzelnen Modulen steuert.
 * 
 * @author Dennis Moschina
 */
class DioramaSlave {
public:
    DioramaSlave(int address);

    /**
     * @brief Diese Funktion startet die Kommunikation und konfiguriert alle restlichen Funktionen.
     */
    void begin();

    /**
     * @brief Prüfe, ob die Aktion ausgeführt werden soll.
     * 
     * @return ob die Aktion ausgeführt werden soll
     */
    bool shouldPerform();

    /**
     * @brief Signalisiere, dass die Aktion ausgeführt wurde.
     * 
     * @note Muss aufgerufen werden, da sonst {@link #shouldPerform} nicht richtig funktioniert
     */
    void performed();


protected:
    void received(int howMany);
    void requestedSound();
    
private:

    const int address;

    void sendSound();
};

#endif