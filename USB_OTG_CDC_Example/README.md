| Supported Targets | ESP32-S2 | ESP32-S3 |
| ----------------- | -------- | -------- |

# _USB OTG CDC example_

This is the simplest buildable example made to be used as a template for new projects running Arduino-esp32 as an ESP-IDF component that will redefine the `Serial` interface to be attached to the USB OTG / CDC port.
See [Arduino-esp32](https://components.espressif.com/components/espressif/arduino-esp32) in ESP Registry.

## How to use example

After cloning this repository, go to the `USB_OTG_CDC_Example` folder and select the target by executing `idf.py set-target <SoC_target>`. 
`<SoC_target>` can be one of the installed IDF version supported targets. For IDF 5.1.4, possible target that support Hardware USB CDC  are: esp32s3 and esp32s2.
Then just run command: `idf.py build` or `idf.py -p USB_PORT flash`. After flashing it will be necessary to open some other Serial Terminal using the USB port.

Usually, it is necessary to make the SoC to enter in Download Mode before uploading the firmware. After that, just press RESET/EN to start the new firmware.

## Example folder contents

The project **usb_otg_example** contains one source file in C++ language [main.cpp](main/main.cpp). The file is located in folder [main](main).

ESP-IDF projects are built using CMake. The project build configuration is contained in `CMakeLists.txt`
files that provide set of directives and instructions describing the project's source files and targets
(executable, library, or both).

Below is short explanation of remaining files in the project folder.

```
├── CMakeLists.txt             Global project CMake configuration file
├── sdkconfig.defaults         sdkconfig setting for an Arduino project
├── esp32-arduino-lib-builder  Clone it here. Instructions below.                       
├── main                       
│   ├── CMakeLists.txt         Arduino sketch CMake configuration file
│   ├── idf_component.yml      List of IDF components necessary to build the project (ESP32 Arduino is an IDF component)
│   └── main.cpp               Arduino Sketch code - don't forget to add "#include <Arduino.h>" on it
└── README.md                  This is the file you are currently reading
```

## Configuring the Hardware USB CDC Serial

ESP32 Arduino has two macro defined symbols that control what `Serial` symbol will represent.
Default `Serial` is the UART0 from `HardwareSerial` class.

`Serial` can be changed to be attached to the USB OTG / CDC port fro the SoC.
In order to make it work, it is necessary to define 2 symbols: `ARDUINO_USB_CDC_ON_BOOT` to `1` and `ARDUINO_USB_MODE` to `0`.

This is achieved by adding a couple lines to the [Project Folder CMakeLists.txt](CMakeLists.txt) file.


```
# Adds necessary definitions for compiling it using Serial symbol attached to the HW USB CDC port
list(APPEND compile_definitions "ARDUINO_USB_CDC_ON_BOOT=1")
list(APPEND compile_definitions "ARDUINO_USB_MODE=0")

set(EXTRA_COMPONENT_DIRS esp32-arduino-lib-builder/components/arduino_tinyusb)

```

It is also neessary to clone `esp32-arduino-lib-builder` and `arduino_tinyusb`.
Execute those two lines from the Project Folder:

`git clone https://github.com/espressif/esp32-arduino-lib-builder.git esp32-arduino-lib-builder`\
`git clone https://github.com/hathach/tinyusb.git esp32-arduino-lib-builder/components/arduino_tinyusb/tinyusb`

After that just run `idf.py set-target esp32s2` or `esp32s3` and then `idf.py -p PORT flash`. 
Open a Serial Monitor using the USB Port and watch the results.

In order to make sure that it is actually working correctly, the [sketch](main/main.cpp) will execute `Serial.begin();` with no baudrate, which only works for USB CDC. 
