cmake_minimum_required(VERSION 3.12)
project(transactionBitCoinSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(transactionBitCoinSystem
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/CMakeCache.txt
        cmake-build-debug/Makefile
        cmake-build-debug/transactionBitCoinSystem
        cmake-build-debug/transactionBitCoinSystem.cbp
        CMakeLists.txt
        main.cpp dataStructures.cpp dataStructures.h walletStructure.cpp walletStructure.h mylinkedList.cpp mylinkedList.h myString.cpp myString.h)
