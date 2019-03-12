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

    bitcoin(btc_tree *transactionTree_ptr);

    bitcoin( myString id, btc_tree *transactionTree_ptr);

    bitcoin( bitcoin &right);

    virtual ~bitcoin();

    const myString &getId() const;

    btc_tree *getTransactionTree_ptr() ;

    bool operator==( bitcoin &rhs) ;

    bool operator!=( bitcoin &rhs) ;

    bool operator==(const myString &id) const;

    bool operator!=(const myString &id) const;

    friend ostream &operator<<(ostream &os, const bitcoin &bitcoin1);
};



#endif //TRANSACTIONBITCOINSYSTEM_BITCOIN_H
