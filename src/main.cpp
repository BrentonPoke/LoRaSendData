/**
 * @file MamaDuck.ino
 * @brief Uses the built in Mama Duck.
 */
#include <string>
#include <arduino-timer.h>
#include <DuckLink.h>
#include <vector>
#include <Arduino.h>

#ifdef SERIAL_PORT_USBVIRTUAL
#define Serial SERIAL_PORT_USBVIRTUAL
#endif

// create a built-in mama duck
DuckLink duck;

DuckDisplay* display = NULL;

// LORA RF CONFIG
#define LORA_FREQ 915.0 // Frequency Range. Set for US Region 915.0Mhz
#define LORA_TXPOWER 20 // Transmit Power
// LORA HELTEC PIN CONFIG
#define LORA_CS_PIN 18
#define LORA_DIO0_PIN 26
#define LORA_DIO1_PIN -1 // unused
#define LORA_RST_PIN 14

bool sendData(const byte* buffer, int length);
// create a timer with default settings
auto timer = timer_create_default();

// for sending the counter message
const int INTERVAL_MS = 60000;
int counter = 1;

void setup() {
    // The Device ID must be unique and 8 bytes long. Typically the ID is stored
    // in a secure nvram, or provided to the duck during provisioning/registration
    std::string deviceId("RELAY001");
    std::vector<byte> devId;
    devId.insert(devId.end(), deviceId.begin(), deviceId.end());

    Serial.println("[DUCK] Setup OK!");

}

void loop() {
    timer.tick();
    // Use the default run(). The Mama duck is designed to also forward data it receives
    // from other ducks, across the network. It has a basic routing mechanism built-in
    // to prevent messages from hoping endlessly.
    duck.run();
}

bool runSensor(void *) {
    bool result;

    return result;
}
