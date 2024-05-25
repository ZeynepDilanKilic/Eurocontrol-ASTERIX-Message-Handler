# Eurocontrol-ASTERIX-Message-Handler
C++ library for parsing and serializing Eurocontrol ASTERIX messages. Supports multiple categories and ensures efficient message handling for air traffic control and surveillance applications.
# Eurocontrol ASTERIX Message Handler

This project provides a C++ implementation for handling Eurocontrol ASTERIX messages, including parsing and serializing functionalities. It supports multiple ASTERIX categories and ensures efficient handling of message data for air traffic control and surveillance applications.

## Features

- **Multi-category support:** Parse and serialize various ASTERIX message categories.
- **High performance:** Efficiently processes large volumes of message data.
- **Extensible:** Easily add support for additional ASTERIX categories.

## Installation

To use the Eurocontrol ASTERIX Message Handler, clone the repository and build the project using CMake.

```bash
git clone https://github.com/ZeynepDilanKilic/Eurocontrol-ASTERIX-Message-Handler.git
cd Eurocontrol-ASTERIX-Message-Handler
mkdir build
cd build
cmake ..
make
