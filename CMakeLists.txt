cmake_minimum_required(VERSION 3.30)
project(FileCompressionSystem)

set(CMAKE_CXX_STANDARD 20)

add_executable(FileCompressionSystem
        src/main.cpp
        src/Reader.cpp
        src/Encoder.cpp
        src/Decoder.cpp
)
