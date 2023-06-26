In this exercise, you will be sending text over LoRa using the ClusterDuck Protocol's API. By the end, you should be able to send data either as text or raw bytes. While there is a deliverable, this is meant to be exploratory in nature and you're encouraged to toy with parameters at your leisure.
## Getting Started
The first thing to do is open the file `main.cpp` where a sample program has been written that can be compiled and flashed to the board you've chosen. Do this with a terminal command as in the form below:
```
 pio run -t upload -e <ENV> --upload-port <PORT>
```
Where `<ENV>` is the environment in the `platformio.ini` that is included in this project and `<PORT>` is the serial port the board is connected on. You can find this port by the command `pio device list`. Note that port numbers in Windows an Linux are named very differently:
```PowerShell
pio run -t upload -e ttgo-lora32-v21 --upload-port COM3
```
Example for Linux:
```sh
pio run -t upload -e ttgo-lora32-v21 --upload-port /dev/ttyUSB0
```
When the process finishes, you should see the logo of Project OWL on the screen. 
## The API
The API is a set of functions that are used to send data through a LoRa network. It is defined in a class named `Duck`.
The API is defined in the file `Duck.h` and implemented in `Duck.cpp`. You are encouraged to look at the implementation to see how it works, but you should not need to modify it.
Below are the functions currently defined in the API:
```cpp
  int sendData(byte topic, const String data,
    const std::vector<byte> targetDevice = ZERO_DUID, std::vector<byte> * outgoingMuid = NULL);
  int sendData(byte topic, std::vector<byte> bytes,
    const std::vector<byte> targetDevice = ZERO_DUID, std::vector<byte> * outgoingMuid = NULL);
  int sendData(byte topic, const std::string data,
    const std::vector<byte> targetDevice = ZERO_DUID, std::vector<byte> * outgoingMuid = NULL);
  int sendData(byte topic, const byte* data, int length,
    const std::vector<byte> targetDevice = ZERO_DUID, std::vector<byte> * outgoingMuid = NULL);
```
There are multiple "duck" types that can be instantiated, but for now, `Ducklink` will suffice.
```cpp
DuckLink duck;
```
In the `setup()` function, setup the duck with a device ID, then the serial speed, and then setup the radio:
```cpp
duck.setDeviceId(devId);
duck.setupSerial(115200);
duck.setupRadio();
```
The pins and frequency should not need to be set manually, but if you're having trouble, this is what you should use:
```cpp
#define LORA_FREQ 915.0 // Frequency Range. Set for US Region 915.0Mhz
#define LORA_TXPOWER 20 // Transmit Power
// LORA PIN CONFIG
#define LORA_CS_PIN 18
#define LORA_DIO0_PIN 26
#define LORA_DIO1_PIN -1 // unused
#define LORA_RST_PIN 23
duck.setupRadio(LORA_FREQ, LORA_CS_PIN, LORA_RST_PIN, LORA_DIO0_PIN, LORA_DIO1_PIN, LORA_TXPOWER);
```
Notice that you are manipulating the display through a pointer to an object. This is done to minimize memory usage From here, the API can be used by calling the functions on the `display` pointer.
## Deliverable
The deliverable will be sending your name, UMID and course number using the `sendData()` variants above:
* Your name, UMID and course number will be printed in that order
* There must be some blank space between each item
* The transmissions should be separated by a 1 second interval
You may print this information to the display or over serial for debugging
## Challenge
If you have completed the deliverable, you are encouraged to play around with the API and see what you can do.
In this spirit, you are challenged to print information from either the AXP192 chip that governs the battery or the NE0-6M.
The libraries used to accomplish this are XPowersLib and TinyGPSPlus.
