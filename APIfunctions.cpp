//
// Created by dimitrisgan on 12/3/2019.
//

#include <iostream>
#include "APIfunctions.h"
#include "assistantFunctions.h"


void requestTransactions(char *buffer,Synchroniser &sync) {


    linkedList<char*> resultList;
    split(buffer, ";" , resultList); /// separate all string commands by ";" and push them to the llist
    cout <<resultList;

    //todo call the requestTransaction(char* buffer) to handle the transaction

    for ( auto transactionCommand : resultList) {
        requestTransaction(transactionCommand, sync);
    }

}

void requestTransaction(char *buffer,Synchroniser &sync) {

    linkedList<char*> resultList;
    split(buffer, " " , resultList); /// separate all string commands by " " and push them to the llist

    cout << resultList;

    if (resultList.getSize() == 5){
        //todo call insertTransaction()
//        sync.insertTransaction()
    }

    if (resultList.getSize() == 3){
        //vale wra pc
    }

//    exit(2);
//    split()
}



void walletStatus(char *buffer, Synchroniser &sync) {
    myString walletId(buffer);
    int current_balance = sync.getWalletHT_ptr()->getData(walletId)->getBalance();
    cout << "The current balance of wallet ID #"<<buffer<< "is:\t"<< current_balance<<endl;
}


void bitCoinStatus(char *buffer, Synchroniser &sync){

}