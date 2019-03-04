//
// Created by dimitrisgan on 27/2/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_WALLET_H
#define TRANSACTIONBITCOINSYSTEM_WALLET_H


#include "myString.h"
#include "mylinkedList.h"

//struct bitcoinInfo{
//    myString id; //btcId
//    btc_tree * transactionTree_ptr;
//
//};


struct wallet{
    myString id ; // aka userName
    int balance;
    linkedList<myString> btcIdsOwned_list;
    linkedList<int> amountOnEachBtc;

};



#endif //TRANSACTIONBITCOINSYSTEM_WALLET_H
