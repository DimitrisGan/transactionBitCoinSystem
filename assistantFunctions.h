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
#include "wallet.h"
#include "ErrorsCodes.h"
#include "transacHashMap.h"
#include "date.h"
#include "synchroniseFunctions.h"

struct ArgumentsKeeper{
    myString bitCoinBalancesFile;
    myString transactionsFile;
    int bitCoinValue;
    unsigned senderHashtableNumOfEntries;
    unsigned receiverHashtableNumOfEntries;
    unsigned bucketSize;

    void printArgs();
};



void argmParser(int &argc, char **argv, struct ArgumentsKeeper &argmKeeper);

void btcBalancesFile_parsing_and_save(const myString &btcInitialOwnersFile, myHashMap<wallet > *walletHT_ptr,
                                      myHashMap<bitcoin> *btcHT_ptr, int bitCoinValue) ;


void readTransactionQueries(const myString &transacFile, Synchroniser &sync);


void split(char *str, const char *delimiter, linkedList<char *> &result2return) ;


void removeFirst(char * str, const char * toRemove); // https://codeforwin.org/2015/12/c-program-to-remove-first-occurrence-of-word-from-string.html

bool isNumber(char* s);

void filterTransactionsByDate(linkedList<char*> inputList ,linkedList<transaction *> allList , linkedList<transaction *>  &outputList);

char * getline() ;



//========BELOW are not used=======
char * str_slice(char str[], int slice_from, int slice_to);

void trimNoise(char* str); //noise considered '\n' ,whitespace and '\r'


#endif //TRANSACTIONBITCOINSYSTEM_ASSISTANTFUNCTIONS_H
