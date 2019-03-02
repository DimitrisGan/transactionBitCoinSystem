cmake_minimum_required(VERSION 3.12)
project(transactionBitCoinSystem)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(transactionBitCoinSystem
        assistantFunctions.cpp
        assistantFunctions.h
        main.cpp
        myHashTable.tpp
        myHashTable.h
        mylinkedList.tpp
        mylinkedList.h
        myString.cpp
        myString.h
        walletStructure.cpp
        walletStructure.h hashFunction.h bucket.tpp bucket.h wallet&BitcoinInfo.cpp wallet&BitcoinInfo.h ErrorsCodes.h bitcoinTree.cpp bitcoinTree.h)
