//
// Created by dimitrisgan on 26/2/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_ASSISTANTFUNCTIONS_H
#define TRANSACTIONBITCOINSYSTEM_ASSISTANTFUNCTIONS_H


//todo ArgsParser
//todo inputParser

//todo get opt get long opt



#include "mylinkedList.h"
#include "myString.h"
#include "myHashMap.h"
#include "myBucket.h"
#include "wallet&BitcoinInfo.h"
#include "ErrorsCodes.h"
#include "transacHashMap.h"


struct ArgumentsKeeper{
    myString bitCoinBalancesFile;
    myString transactionsFile;
    int bitCoinValue;
    int senderHashtableNumOfEntries;
    int receiverHashtableNumOfEntries;
    int bucketSize;

    void printArgs();
};


void argmParser(int &argc, char **argv, struct ArgumentsKeeper &argmKeeper);

void btcBalancesFile_parsing_and_save(const myString &btcInitialOwnersFile, myHashMap<wallet > &walletHT_ptr,
                                      myHashMap<bitcoin> &btcHT_ptr, int bitCoinValue) ;

void readTransactionQueries(const myString &initiaTransacFile, myTransacHashMap &senderHT_ptr ,  myTransacHashMap  &receiverHT_ptr,
                            myHashMap<wallet > &walletHT_ptr,myHashMap<bitcoin> &btcHT_ptr);

void split( char* str, char* delimiter , linkedList<char*> & result2return) ;

#endif //TRANSACTIONBITCOINSYSTEM_ASSISTANTFUNCTIONS_H
