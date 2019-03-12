//
// Created by dimitrisgan on 12/3/2019.
//

#include <iostream>
#include "APIfunctions.h"
#include "assistantFunctions.h"


void requestTransactions(char* buffer){


    linkedList<char*> resultList;
    split(buffer, ";" , resultList); /// separate all string commands by ";" and push them to the llist
    cout <<resultList;

    //todo call the requestTransaction(char* buffer) to handle the transaction

    for ( auto transactionCommand : resultList) {
        requestTransaction(transactionCommand);
    }

}

void requestTransaction(char* buffer){

    linkedList<char*> resultList;
    split(buffer, " " , resultList); /// separate all string commands by " " and push them to the llist

    cout << resultList;


//    exit(2);
//    split()
}