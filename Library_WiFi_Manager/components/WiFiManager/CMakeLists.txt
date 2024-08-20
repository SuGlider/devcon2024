cmake_minimum_required(VERSION 3.5)

idf_component_register(SRCS "WiFiManager.cpp"
                       INCLUDE_DIRS "."
                       REQUIRES espressif__arduino-esp32
                       )

project(WiFiManager)
