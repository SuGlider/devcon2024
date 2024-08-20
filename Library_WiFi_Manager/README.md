| Supported Targets | ESP32 | ESP32-C3 | ESP32-C6 | ESP32-S2 | ESP32-S3 |
| ----------------- | ----- | -------- | -------- | -------- | -------- |

# _WiFi Manager Library example_

This is the simplest buildable example made to be used as a template for new projects running Arduino-esp32 as an ESP-IDF component that need to add external Arduino Libraries.
See [Arduino-esp32](https://components.espressif.com/components/espressif/arduino-esp32) in ESP Registry.

The Arduino Library used in this example is the WiFi Manager that allows users to select a WiFi SSID from a list created within a Web Page served by the ESP32.
For more information, please read https://github.com/tzapu/WiFiManager
Arduino Libraries Information: https://www.arduinolibraries.info/libraries/wi-fi-manager
This library figures among the top starred llibraries based on https://www.arduinolibraries.info/

Any other library can be used as well.

## How to use example

After cloning this repository, go to the `Library_WiFi_Manager` folder and select the target by executing `idf.py set-target <SoC_target>`. 
`<SoC_target>` can be one of the installed IDF version supported targets. 
For IDF 5.1.4, possible target that support WiFi are: esp32, esp32s2, esp32s3, esp32c3 and esp32c6.
Then just run command: `idf.py build` or `idf.py -p PORT flash monitor`.

## Example folder contents

The project **wifi_manager** contains one source file in C++ language [main.cpp](main/main.cpp). The file is located in folder [main](main).
The source code of this example was based on one of the examples from `WiFiManager` Library, the [Basic.ino](https://github.com/tzapu/WiFiManager/blob/master/examples/Basic/Basic.ino).

ESP-IDF projects are built using CMake. The project build configuration is contained in `CMakeLists.txt`
files that provide set of directives and instructions describing the project's source files and targets
(executable, library, or both).

Any Arduino Library can be manually added to the local components folder of the project.
It is possible to add any number of libraries.
For each library it is necessary to create or adjust the `CMakeLists.txt` content of the Library.

The `WiFiManager` Library can be added to the `components` folder by just cloning it.
`git clone https://github.com/tzapu/WiFiManager.git components/WiFiManager`
After that, just create/adjust the [CMakeLists.txt](components/WiFiManager/CMakeLists.txt) file.

```
idf_component_register(SRCS "WiFiManager.cpp"
                       INCLUDE_DIRS "."
                       REQUIRES espressif__arduino-esp32    <<< HERE
                      )
``` 

Below is short explanation of remaining files in the project folder.

```
├── CMakeLists.txt             Global project CMake configuration file
├── sdkconfig.defaults         sdkconfig setting for an Arduino project
├── components
│   ├── WiFiManager
│   │   ├── CMakeLists.txt     This needs to be modified to relefect the name of the Arduino Managed Component
│   │   ├── ...                Original Library files
├── main                       
│   ├── CMakeLists.txt         Arduino sketch CMake configuration file
│   ├── idf_component.yml      List of IDF components necessary to build the project (ESP32 Arduino is an IDF component)
│   └── main.cpp               Arduino Sketch code - don't forget to add "#include <Arduino.h>" on it
└── README.md                  This is the file you are currently reading
```

## How to add Arduino libraries

In the project create folder `components/` and clone the library there.
In the library folder create new CMakeLists.txt file, add lines shown below to the file and edit the SRCS to match the library source files.

```
idf_component_register(SRCS "user_library.cpp" "another_source.c"
                       INCLUDE_DIRS "."
                       REQUIRES espressif__arduino-esp32
                      )
```

Below is structure of the project folder with the Arduino libraries.

```
├── CMakeLists.txt
├── components
│   ├── user_library
│   │   ├── CMakeLists.txt     This needs to be added
│   │   ├── ...
├── main
│   ├── CMakeLists.txt
│   ├── idf_component.yml
│   └── main.cpp
└── README.md                  This is the file you are currently reading
```
