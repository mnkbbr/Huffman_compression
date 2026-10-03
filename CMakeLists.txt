cmake_minimum_required(VERSION 3.10)
project(Huff)

add_executable(Huff
    src/DataCompressPreparing/CompressData.cpp
    src/DataCompressPreparing/GetCompressedString.cpp
    src/DataCompressPreparing/GetTable.cpp
    src/DataCompressPreparing/WriteCodes.cpp

    src/Fileread/ConvertBTS.cpp
    src/Fileread/ReadTable.cpp
    src/Fileread/ReadWriteData.cpp

    src/FileWrite/WriteTableData.cpp
    src/FileWrite/WriteCompressedText.cpp

    src/FreeTree.cpp
    src/compress.cpp
    src/decompress.cpp
    src/main.cpp
    
)

target_include_directories(Huff PRIVATE include)
