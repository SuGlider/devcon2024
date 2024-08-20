| Supported Targets | ESP32 | ESP32-C2 | ESP32-C3 | ESP32-C6 | ESP32-H2 | ESP32-S2 | ESP32-S3 |
| ----------------- | ----- | -------- | -------- | -------- | -------- | -------- | -------- |

# _Arduino Debug and Logging example_

This is the simplest buildable example made to be used as a template for new projects running Arduino-esp32 as an ESP-IDF component.
See [Arduino-esp32](https://components.espressif.com/components/espressif/arduino-esp32) in ESP Registry.

## How to use example

After cloning this repository, go to the `arduino_debug_example` folder and select the target by executing `idf.py set-target <SoC_target>`. 
`<SoC_target>` can be one of the installed IDF version supported targets. For IDF 5.1.4, possible target are: esp32, esp32s2, esp32s3, esp32c3, esp32c6 and esp32h2.
Then just run command: `idf.py build` or `idf.py -p PORT flash monitor`.

## Example folder contents

The project **arduino_debug_example** contains one source file in C++ language [main.cpp](main/main.cpp). The file is located in folder [main](main).

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

## Activating Arduino Debug Level and Messages

ESP32 Arduino has its own log API. It can display messages for the different debug levels, as selected with the MenuConfig.
Those are the possible log messages and levels:

``` cpp
  log_e("This is an Error Level Log message!");
  log_w("This is a Warning Level Log message!");
  log_i("This is an Info Level Log message!");
  log_d("This is a Debug Level Log message!");
  log_v("This is a Verbose Level Log message!");

```

In order to active it, it is necessary to select the proper Debug Level using `idf.py menuconfig` command.
Go to `(Top Menu) → Arduino Configuration → Debug Log Configuration → Default log level` and select the level.
ESP32 Arduino Default Level is just ERROR.

![Arduino options in Menuconfig](https://github.com/SuGlider/devcon2024/blob/main/images/arduino_log_level.png?raw=true)

## Changing the Bootloader Log level

Bootloader messages are printed when the device boots. It may contain information about the boot process and also about the SoC, such as Flash, Partition Table and so on.
It is possible to change the Log Level of these information.
Go to `(Top) → Bootloader config → Bootloader log verbosity` and select the level

![Arduino options in Menuconfig](https://github.com/SuGlider/devcon2024/blob/main/images/bootload_log_level.png?raw=true)

## Changing the IDF Components Log level

These messages are printed when by the various IDF components.
It may contain information about each IDF Component operation.
It is possible to change the Log Level of these information.
Go to `(Top) → Component config → Log output → Default log verbosity` and select the level

![Arduino options in Menuconfig](https://github.com/SuGlider/devcon2024/blob/main/images/idf_boot_level.png?raw=true)

