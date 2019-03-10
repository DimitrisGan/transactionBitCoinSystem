//
// Created by dimitrisgan on 4/3/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_SYNCHRONISEFUNCTIONS_H
#define TRANSACTIONBITCOINSYSTEM_SYNCHRONISEFUNCTIONS_H


#include "wallet.h"
#include "myBucket.h"
#include "recordsBucket.h"
#include "myHashMap.h"
#include "transacHashMap.h"
#include "bitcoin.h"

//myHashMap< myBucket_chain<wallet> , 100 , MyKeyHash > walletHT;
//myHashMap< myBucket_chain<bitcoin> , 100 , MyKeyHash > btcHT;
//
//
//myHashMap< recordsBucket_chain<1000> , 100 , MyKeyHash > senderHT;
//myHashMap< recordsBucket_chain<1000> , 100 , MyKeyHash > receiverHT;

struct Synchroniser{

    myTransacHashMap senderHT_ptr;
    myTransacHashMap  receiverHT_ptr;
    myHashMap<wallet> walletHT_ptr;
    myHashMap< bitcoin> btcHT_ptr;
    myHashMap<transaction> transacHT_ptr;


    //todo ayrio !!!
    Synchroniser(const myTransacHashMap &senderHT_ptr, const myTransacHashMap &receiverHT_ptr,
                 const myHashMap<wallet> &walletHT_ptr, const myHashMap<bitcoin> &btcHT_ptr,
                 const myHashMap<transaction> &transacHT_ptr);

    void insertTransaction(transaction potentialTransaction);


    bool transactionIsValid(transaction potentialTransac, int sendersBalance);

    void decideWhichAndHowMuchInEach2extractFromSender(wallet *sendersWallet,
                                                       linkedList<myString> &btcId2extract_list,
                                                       linkedList<int> &amountInEachBtc2extract_list,
                                                       int amount2extract,
                                                       linkedList<myString> &indexesList2remove);


    void removeLostOwnershipBtcFromSender(wallet *sendersWallet, linkedList<myString> &btc2deleteInlist);

    void  addAmountAndBtc2receiver(wallet *receiversWallet , linkedList<myString> btcId2extract_list ,linkedList<int> amountInEachBtc2extract_list);

    void  addTheNewNodes2Tree(myString senderId ,myString receiverId , linkedList<myString> btcId2extract_list ,linkedList<int> amountInEachBtc2extract_list);

    void createTransactionNode(myString sender,myString receiver ,int amount);
    void updateWallet(); //will be called two times for sender and receiver

};






//void insertTransaction (myHashMap< myBucket_chain<wallet> , int tableSize , MyKeyHash > walletHT)




//void readSender(); lathos einai edw


#endif //TRANSACTIONBITCOINSYSTEM_SYNCHRONISEFUNCTIONS_H
