//
// Created by dimitrisgan on 27/2/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_BUCKET_H
#define TRANSACTIONBITCOINSYSTEM_BUCKET_H


#include "mylinkedList.h"
#include "myString.h"

struct bucket{
    //todo
    int recordsToRemain;
    myString record; //walletId; //RECORD == walletId
//    OXI GT EINAI TO LLIST KATALLHLO GI AUTObucket* next;


    bucket(int recordsToRemain);
};

//TODO EDW EXW MEINEI
struct bucket_chain{
    linkedList<bucket*> maybeBucketChain;
};


#endif //TRANSACTIONBITCOINSYSTEM_BUCKET_H
