//
// Created by dimitrisgan on 27/2/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_WALLET_H
#define TRANSACTIONBITCOINSYSTEM_WALLET_H


#include <ostream>
#include "myString.h"
#include "mylinkedList.h"
#include "bitcoinTree.h"



class wallet{
private:
    myString id ; // aka userName
    int balance;
    linkedList<myString> btcIdsOwned_list;
    linkedList<int> amountOnEachBtc;
public:
    wallet() = default;

    wallet( myString id, int balance,  linkedList<myString> btcIdsOwned_list,
            linkedList<int> amountOnEachBtc);



    virtual ~wallet() = default;

    wallet( wallet &right);


    myString getId() ;

    int getBalance() const;

    linkedList<myString> getBtcIdsOwned_list() ;

    linkedList<int> getAmountOnEachBtc() ;


    linkedList<myString>& getBtcIdsOwned_listByRef() ;

    linkedList<int>& getAmountOnEachBtcByRef() ;


    void setId(const myString &id);

    void setBalance(int balance);

    void setBtcIdsOwned_list( linkedList<myString> &btcIdsOwned_list);

    void setAmountOnEachBtc( linkedList<int> &amountOnEachBtc);

    bool operator==(const wallet &rhs) const;

    bool operator!=(const wallet &rhs) const;

    bool operator==(const myString &id) const;

    bool operator!=(const myString &id) const;

    friend ostream &operator<<(ostream &os, const wallet &wallet1);

};



#endif //TRANSACTIONBITCOINSYSTEM_WALLET_H
