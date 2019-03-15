//
// Created by dimitrisgan on 8/3/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_TRANSACTION_H
#define TRANSACTIONBITCOINSYSTEM_TRANSACTION_H


//template <class U ,class B>

#include <ostream>
#include "myString.h"
#include "date.h"
#include "bitcoinTree.h"
//#include "bitcoinTree.h"


class transaction{
public: //private:
    myString transacId;
    myString senderWalletId;
    myString receiverWalletId; //in sender table is receiverWalletId
    date transacTime;

    //mporei na exoun dhmiourgithei parapanw apo ena nodes se diaforetika bitcoins trees
//    linkedList<myString> bitcoinSentList;
    int amount;
    linkedList<t_node *> t_nodePtrList;

public:

    transaction() = default;


    virtual ~transaction() {
//         t_nodePtrList.clear();

    }


    transaction& operator=( transaction rhs)  {
        transacId = rhs.transacId;
        senderWalletId =rhs.senderWalletId;
        receiverWalletId = rhs.receiverWalletId ;
        t_nodePtrList = rhs.t_nodePtrList;
        amount = rhs.amount;
        transacTime = rhs.transacTime;
        t_nodePtrList = rhs.t_nodePtrList;
        return *this;
    }


    bool operator==(const transaction &rhs) const;

    bool operator!=(const transaction &rhs) const;

    bool operator==(const myString &id) const;

    bool operator!=(const myString &id) const;

    friend ostream &operator<<(ostream &os, const transaction &transaction1);

    //getters
     myString &getSenderWalletId()  {
        return senderWalletId;
    }

     myString &getReceiverWalletId()  {
        return receiverWalletId;
    }

     date &getTransacTime()  {
        return transacTime;
    }

    int getAmount() const {
        return amount;
    }

    myString getTransacId() {
        return transacId;
    }


    //setters

    void setTransacId(myString transacId) {
        transaction::transacId = transacId;
    }

    void setSenderWalletId(const myString &senderWalletId) {
        transaction::senderWalletId = senderWalletId;
    }

    void setReceiverWalletId(const myString &receiverWalletId) {
        transaction::receiverWalletId = receiverWalletId;
    }

    void setAmount(int amount) {
        transaction::amount = amount;
    }

    void setTreeNodeList_ptrs( linkedList<t_node *> treeNodeList_ptrs) {
        transaction::t_nodePtrList = treeNodeList_ptrs;
    }

    void setTransacTime(const date &transacTime) {
        transaction::transacTime = transacTime;
    }

    void updateTransacionPtrIn_t_nodes();

};

#endif //TRANSACTIONBITCOINSYSTEM_TRANSACTION_H
