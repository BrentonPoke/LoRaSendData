![CIT banner](CIT.Stamp.png)
# LoRa Send Data Exercise
Companion to LoRaBoardDisplay Assignment

## Who this is for
This is the next exercise for in a sequence for ESP32 development boards. The level of proficiency required is in alignment with CSC121 at University of Michigan - Flint, which is Programming I in C++. While this exercise can be done inside of a first C++ programming course, one will need to be familiar with command line tools and a CLI environment, especiallly if using Linux.

## Pre-requisites
To get started, you will need the C++ compiler, cmake and [platformio](platformio.org) installed. There are a few ways to do this, but the [Platformio IDE](https://platformio.org/platformio-ide) is the easiest. It is simply a distribution of VSCode with Platformio's CLI tools integrated within. There are also many other IDEs supported by Platformio, which can be viewed [here](https://platformio.org/install/integration). This service is a dependency manager that makes it easy to work with embeded software projects.

## Compatible Boards
The CDP currently supports the following boards:
* [LILYGO® T-Beam ESP32 LoRa V1.1 SX1276](https://www.lilygo.cc/products/t-beam-v1-1-esp32-lora-module)

## Assignment
The assignment is to send either battery or GPS information using the LoRa transmitter. The instruction for the assignment can be found in the [Assignment.md](Assignment.md) file.
