| Supported Targets | ESP32 | ESP32-C2 | ESP32-C3 | ESP32-C6 | ESP32-H2 | ESP32-S2 | ESP32-S3 |
| ----------------- | ----- | -------- | -------- | -------- | -------- | -------- | -------- |

# _Hello world example_

This is the simplest buildable example made to be used as a template for new projects running Arduino-esp32 as an ESP-IDF component.
See [Arduino-esp32](https://components.espressif.com/components/espressif/arduino-esp32) in ESP Registry.

## How to use example

After cloning this repository, go to the `hello_world` folder and select the target by executing `idf.py set-target <SoC_target>`. 
`<SoC_target>` can be one of the installed IDF version supported targets. For IDF 5.1.4, possible target are: esp32, esp32s2, esp32s3, esp32c3, esp32c6 and esp32h2.
Then just run command: `idf.py build` or `idf.py -p PORT flash monitor`.

## Example folder contents

The project **hello_world** contains one source file in C++ language [main.cpp](main/main.cpp). The file is located in folder [main](main).

ESP-IDF projects are built using CMake. The project build configuration is contained in `CMakeLists.txt`
files that provide set of directives and instructions describing the project's source files and targets
(executable, library, or both).

Below is short explanation of remaining files in the project folder.

```
├── CMakeLists.txt             Global project CMake configuration file
├── sdkconfig.defaults         sdkconfig setting for an Arduino project
├── main                       
│   ├── CMakeLists.txt         Arduino sketch CMake configuration file
│   ├── idf_component.yml      List of IDF components necessary to build the project (ESP32 Arduino is an IDF component)
│   └── main.cpp               Arduino Sketch code - don't forget to add "#include <Arduino.h>" on it
└── README.md                  This is the file you are currently reading
```

