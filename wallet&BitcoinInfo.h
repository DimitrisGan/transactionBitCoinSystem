//
// Created by dimitrisgan on 27/2/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_WALLET_H
#define TRANSACTIONBITCOINSYSTEM_WALLET_H


#include "myString.h"
#include "mylinkedList.h"

struct bitcoinInfo{
    myString id;

};


struct wallet{
    myString id ;
    int remainder;
    linkedList<bitcoinInfo> bitcoinOwned_list;
};

#endif //TRANSACTIONBITCOINSYSTEM_WALLET_H
