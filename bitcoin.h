//
// Created by dimitrisgan on 8/3/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_BITCOIN_H
#define TRANSACTIONBITCOINSYSTEM_BITCOIN_H


#include "myString.h"
#include "bitcoinTree.h"

struct bitcoin{
    myString id; //btcId
    btc_tree * transactionTree_ptr;

    bitcoin( myString id, btc_tree *transactionTree_ptr);

    bool operator==( bitcoin &rhs) ;

    bool operator!=( bitcoin &rhs) ;

    friend ostream &operator<<(ostream &os, const bitcoin &bitcoin1);
};



#endif //TRANSACTIONBITCOINSYSTEM_BITCOIN_H
