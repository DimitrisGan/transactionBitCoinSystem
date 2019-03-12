//
// Created by dimitrisgan on 12/3/2019.
//

#include <iostream>
#include "APIfunctions.h"
#include "assistantFunctions.h"


void requestTransactions(char* buffer){


    linkedList<char*> resultList;
    split(buffer, ";" , resultList); /// push all char* tokens to the list
    cout <<resultList;


//    split()
}

void requestTransaction(char* buffer){

//todo edw tha elegxw ti einai apo to buffer kai poia sunartisi tha kalesw
    std::cout << "mpika gtxmmou\n";

    linkedList<char*> resultList;
    split(buffer, ";" , resultList); /// push all char* tokens to the list
    cout <<resultList;


    exit(2);
//    split()
}