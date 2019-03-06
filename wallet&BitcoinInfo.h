//
// Created by dimitrisgan on 27/2/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_WALLET_H
#define TRANSACTIONBITCOINSYSTEM_WALLET_H


#include "myString.h"
#include "mylinkedList.h"
#include "bitcoinTree.h"

struct bitcoin{
    myString id; //btcId
    btc_tree * transactionTree_ptr;

    bitcoin( myString id, btc_tree *transactionTree_ptr);

    bool operator==( bitcoin &rhs) ;

    bool operator!=( bitcoin &rhs) ;
};


class wallet{
private:
    myString id ; // aka userName
    int balance;
    linkedList<myString> btcIdsOwned_list;
    linkedList<int> amountOnEachBtc;
public:
//    wallet() = default;

    wallet( myString id, int balance,  linkedList<myString> btcIdsOwned_list,
            linkedList<int> amountOnEachBtc);

    virtual ~wallet() = default;


    myString getId() ;

     linkedList<myString> getBtcIdsOwned_list() ;


    void setId(const myString &id);

    void setBalance(int balance);

    void setBtcIdsOwned_list( linkedList<myString> &btcIdsOwned_list);

    void setAmountOnEachBtc( linkedList<int> &amountOnEachBtc);

    bool operator==(const wallet &rhs) const;

    bool operator!=(const wallet &rhs) const;

};



#endif //TRANSACTIONBITCOINSYSTEM_WALLET_H
