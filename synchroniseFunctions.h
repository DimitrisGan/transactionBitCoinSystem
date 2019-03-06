//
// Created by dimitrisgan on 4/3/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_SYNCHRONISEFUNCTIONS_H
#define TRANSACTIONBITCOINSYSTEM_SYNCHRONISEFUNCTIONS_H


#include "wallet&BitcoinInfo.h"
#include "myBucket.h"
#include "recordsBucket.h"
#include "myHashMap.h"
#include "transacHashMap.h"

//myHashMap< myBucket_chain<wallet> , 100 , MyKeyHash > walletHT;
//myHashMap< myBucket_chain<bitcoin> , 100 , MyKeyHash > btcHT;
//
//
//myHashMap< recordsBucket_chain<1000> , 100 , MyKeyHash > senderHT;
//myHashMap< recordsBucket_chain<1000> , 100 , MyKeyHash > receiverHT;

struct Synchroniser{

//    myHashMap< myBucket_chain<wallet> , tableSize , MyKeyHash > *walletHT;
//    myHashMap< myBucket_chain<bitcoin> , tableSize , MyKeyHash > *btcHT;
//

    //todo senderHT
    //todo receiverHT
    //todo walletHT
    //todo btcHT
    myTransacHashMap *senderHT_ptr;
    myTransacHashMap  *receiverHT_ptr;
    myHashMap< myBucket_chain<wallet>> *walletHT_ptr;
    myHashMap< myBucket_chain<bitcoin>> *btcHT_ptr;

    Synchroniser(myTransacHashMap *senderHT_ptr, myTransacHashMap *receiverHT_ptr,
                 myHashMap<myBucket_chain<wallet>> *walletHT_ptr, myHashMap<myBucket_chain<bitcoin>> *btcHT_ptr)
            : senderHT_ptr(senderHT_ptr), receiverHT_ptr(receiverHT_ptr), walletHT_ptr(walletHT_ptr),
              btcHT_ptr(btcHT_ptr) {}

    void insertTransaction( myString sender,myString receiver ,int amount );
    void checkIfTransactionIsPossible(myString sender,myString receiver ,int amount);
    void createTransactionNode(myString sender,myString receiver ,int amount);
    void updateWallet(); //will be called two times for sender and receiver

};






//void insertTransaction (myHashMap< myBucket_chain<wallet> , int tableSize , MyKeyHash > walletHT)




//void readSender(); lathos einai edw


#endif //TRANSACTIONBITCOINSYSTEM_SYNCHRONISEFUNCTIONS_H
