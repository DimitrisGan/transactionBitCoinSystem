cmake_minimum_required(VERSION 3.12)
project(transactionBitCoinSystem)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(transactionBitCoinSystem
        assistantFunctions.cpp
        assistantFunctions.h
        main.cpp
        mylinkedList.tpp
        mylinkedList.h
        myString.cpp
        myString.h
        hashFunction.h recordsBucket.h wallet.cpp wallet.h ErrorsCodes.h bitcoinTree.cpp bitcoinTree.h myBucket.tpp transacHashMap.cpp transacHashMap.h myBucket.h synchroniseFunctions.cpp synchroniseFunctions.h myHashMap.h hashFunction.cpp date.cpp date.h transaction.cpp transaction.h bitcoin.cpp bitcoin.h APIfunctions.cpp APIfunctions.h)
