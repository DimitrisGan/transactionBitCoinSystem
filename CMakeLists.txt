cmake_minimum_required(VERSION 3.12)
project(transactionBitCoinSystem)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(transactionBitCoinSystem
        assistantFunctions.cpp
        assistantFunctions.h
        dataStructures.cpp
        dataStructures.h
        main.cpp
        myHashTable.cpp
        myHashTable.h
        mylinkedList.cpp
        mylinkedList.h
        myString.cpp
        myString.h
        walletStructure.cpp
        walletStructure.h hashFunction.h bucket.cpp bucket.h wallet&BitcoinInfo.cpp wallet&BitcoinInfo.h ErrorsCodes.h)
