cmake_minimum_required(VERSION 3.10)
project(Huff)

add_executable(Huff
    src/main.cpp
    src/compress.cpp
    src/decode.cpp
    src/FreeTree.cpp
    src/GetCompressedString.cpp
    src/GetTable.cpp
    src/WriteCodes.cpp
    src/WriteData.cpp
)

target_include_directories(Huff PRIVATE include)
