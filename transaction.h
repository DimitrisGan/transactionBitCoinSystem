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


//todo to transaction list tha pairnei se template to sender receiverWalletId opote de xreiazetai sthn insert
//todo apo to walletID tha pairnw ta btcIds pou tha peiraksw mazi me to poso
//todo kai tha phgainw sto tree pou tha epistrefei deiktes pou tha tous xwnw
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
//         t_nodePtrList.clear(); OXI DE THELW NA GINEI FREE TO DENTRO MOY APO TO TRANSACTION NODE LIST

    }




    transaction& operator=( transaction rhs)  {
        transacId = rhs.transacId;
        senderWalletId =rhs.senderWalletId;
        receiverWalletId = rhs.receiverWalletId ;
//        bitcoinSentList = rhs.bitcoinSentList ;
        t_nodePtrList = rhs.t_nodePtrList; //todo EDW LATHOS //todo EDW LATHOS //todo EDW LATHOS //todo EDW LATHOS //todo EDW LATHOS //todo EDW LATHOS //todo EDW LATHOS //todo EDW LATHOS
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


//    void setBitcoinSentList( linkedList<myString> bitcoinSentList) {
//        transaction::bitcoinSentList = bitcoinSentList;
//    }

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
