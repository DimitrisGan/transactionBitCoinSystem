//
// Created by dimitrisgan on 4/3/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_SYNCHRONISEFUNCTIONS_H
#define TRANSACTIONBITCOINSYSTEM_SYNCHRONISEFUNCTIONS_H


#include "wallet&BitcoinInfo.h"
#include "myBucket.h"
#include "recordsBucket.h"
#include "myHashMap.h"

//myHashMap< myBucket_chain<wallet> , 100 , MyKeyHash > walletHT;
//myHashMap< myBucket_chain<bitcoin> , 100 , MyKeyHash > btcHT;
//
//
//myHashMap< recordsBucket_chain<1000> , 100 , MyKeyHash > senderHT;
//myHashMap< recordsBucket_chain<1000> , 100 , MyKeyHash > receiverHT;

    template < /*type of bucketChain*/unsigned tableSize, unsigned  bucketSize>
struct Synchroniser{

//    myHashMap< myBucket_chain<wallet> , tableSize , MyKeyHash > *walletHT;
//    myHashMap< myBucket_chain<bitcoin> , tableSize , MyKeyHash > *btcHT;
//

    //todo senderHT
    //todo receiverHT
    //todo walletHT
    //todo btcHT

    void insertTransaction(){};

};

//void insertTransaction (myHashMap< myBucket_chain<wallet> , int tableSize , MyKeyHash > walletHT)




//void readSender(); lathos einai edw


#endif //TRANSACTIONBITCOINSYSTEM_SYNCHRONISEFUNCTIONS_H
