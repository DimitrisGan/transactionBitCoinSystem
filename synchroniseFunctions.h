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



class Synchroniser{
private:
    myTransacHashMap    *senderHT_ptr;
    myTransacHashMap    *receiverHT_ptr;
    myHashMap<wallet>   *walletHT_ptr;
    myHashMap< bitcoin> *btcHT_ptr;
    myHashMap<transaction> *transacHT_ptr;

    date latestTransacDate;

    int max_t_id;



    bool transactionIsValid(transaction potentialTransac, int sendersBalance);

    void decideWhichAndHowMuchInEach2extractFromSender(wallet *sendersWallet,
                                                       linkedList<myString> &btcId2extract_list,
                                                       linkedList<int> &amountInEachBtc2extract_list,
                                                       int amount2extract,
                                                       linkedList<myString> &indexesList2remove);


    void removeLostOwnershipBtcFromSender(wallet *sendersWallet, linkedList<myString> &btc2deleteInlist);

    void  addAmountAndBtc2receiver(wallet *receiversWallet , linkedList<myString> btcId2extract_list ,linkedList<int> amountInEachBtc2extract_list);

    void  addTheNewNodes2Tree(transaction &potentialTransaction , linkedList<myString> btcId2extract_list ,linkedList<int> amountInEachBtc2extract_list);



    void  updateMaxId(myString id);

    void updateLatestDate(date newDate);


public:

    Synchroniser(myTransacHashMap *senderHT_ptr, myTransacHashMap *receiverHT_ptr, myHashMap<wallet> *walletHT_ptr,
                 myHashMap<bitcoin> *btcHT_ptr, myHashMap<transaction> *transacHT_ptr);

    void insertTransaction(transaction potentialTransaction);


    myTransacHashMap *getSenderHT_ptr() const;

    myTransacHashMap *getReceiverHT_ptr() const;

    myHashMap<wallet> *getWalletHT_ptr() const;

    myHashMap<bitcoin> *getBtcHT_ptr() const;

    myHashMap<transaction> *getTransacHT_ptr() const;

    const date &getLatestTrsansactionDate() const;

    myString createVirtualTransacId();


    void createTransactionNode(myString sender,myString receiver ,int amount);
    void updateWallet(); //will be called two times for sender and receiver

};






//void insertTransaction (myHashMap< myBucket_chain<wallet> , int tableSize , MyKeyHash > walletHT)




//void readSender(); lathos einai edw


#endif //TRANSACTIONBITCOINSYSTEM_SYNCHRONISEFUNCTIONS_H
