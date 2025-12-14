cmake_minimum_required(VERSION 3.16)  # CMake version check
project(wifi_emulator LANGUAGES CXX)               
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(wifi_emulator
               src/main.cpp
               src/ipc/socket_server.cpp
               src/ipc/Protocol.cpp
               src/ipc/wifi_device.cpp
                )
                


