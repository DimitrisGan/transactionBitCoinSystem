//
// Created by dimitrisgan on 12/3/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_APIFUNCTIONS_H
#define TRANSACTIONBITCOINSYSTEM_APIFUNCTIONS_H


#include "synchroniseFunctions.h"

void requestTransactions(char *buffer, Synchroniser &sync);

void requestTransaction(char *buffer,Synchroniser& sync);

void findEarnings(char* buffer);

#endif //TRANSACTIONBITCOINSYSTEM_APIFUNCTIONS_H
