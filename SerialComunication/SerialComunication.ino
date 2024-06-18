// Incluye las bibliotecas necesarias
#include "BluetoothSerial.h"

// Crea un objeto BluetoothSerial
BluetoothSerial SerialBT;

void setup() {
    // Inicializa el puerto serie para la comunicación con el monitor serie
    Serial.begin(9600);

    // Inicializa el Bluetooth Serial con el nombre "ESP32test"
    SerialBT.begin("ESP32test");

    // Mensaje de inicio
    Serial.println("El dispositivo está listo para emparejarse.");
}

void loop() {
    // Si hay datos disponibles para leer desde Bluetooth
    if (SerialBT.available()) {
        // Lee los datos y envíalos al monitor serie
        char incomingChar = SerialBT.read();
        Serial.print(incomingChar);
    }

    // Si hay datos disponibles para leer desde el monitor serie
    if (Serial.available()) {
        // Lee los datos y envíalos por Bluetooth
        char outgoingChar = Serial.read();
        SerialBT.write(outgoingChar);
    }
}
