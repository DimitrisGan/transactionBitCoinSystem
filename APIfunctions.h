//
// Created by dimitrisgan on 12/3/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_APIFUNCTIONS_H
#define TRANSACTIONBITCOINSYSTEM_APIFUNCTIONS_H


#include "synchroniseFunctions.h"

void findEarnings(char *buffer,Synchroniser &sync);

void findPayments(char *buffer,Synchroniser &sync);

void requestTransactions(char *buffer, Synchroniser &sync);

void requestTransaction(char *buffer,Synchroniser& sync);


void walletStatus(char* buffer, Synchroniser& sync);

void bitCoinStatus(char *buffer, Synchroniser &sync);

void traceCoin(char *buffer, Synchroniser &sync);

#endif //TRANSACTIONBITCOINSYSTEM_APIFUNCTIONS_H
