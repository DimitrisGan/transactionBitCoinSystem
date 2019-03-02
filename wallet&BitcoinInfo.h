//
// Created by dimitrisgan on 27/2/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_WALLET_H
#define TRANSACTIONBITCOINSYSTEM_WALLET_H


#include "myString.h"
#include "mylinkedList.h"
#include "bitcoinTree.h"

struct bitcoinInfo{
    myString id;
    //todo pointer to a tree
    btree * transactionTree_ptr;

};


struct wallet{
    myString id ; // aka userName
    int remainder;
    linkedList<bitcoinInfo> bitcoinOwned_list;
    //todo prepei na krataw kai ta percentages tou kathe bitcoin
};


//todo
struct bitCoin_amountOwnership_relation{
    bitcoinInfo btc;
    double amountOwned;
};


#endif //TRANSACTIONBITCOINSYSTEM_WALLET_H
