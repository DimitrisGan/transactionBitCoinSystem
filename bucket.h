//
// Created by dimitrisgan on 27/2/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_BUCKET_H
#define TRANSACTIONBITCOINSYSTEM_BUCKET_H


#include "mylinkedList.h"
#include "myString.h"





//todo tha paiksei kai memcpy
struct bucket{
    //todo
    unsigned recordsAvailableRemain;
    myString* recordsArray; //walletId; //RECORD == walletId
//    OXI GT EINAI TO LLIST KATALLHLO GI AUTObucket* next;


//    bucket() {recordsAvailableRemain = 0;recordsArray= nullptr;};

    explicit bucket(unsigned RecordsCapacity);
    virtual ~bucket();
    bucket& operator=(bucket right)
    {
        this->recordsArray = right.recordsArray;
        this->recordsAvailableRemain= right.recordsAvailableRemain;
        return *this;
    }

    bucket(bucket &right)
    {
        recordsArray = right.recordsArray ;
         recordsAvailableRemain =right.recordsAvailableRemain;
    }



};

//TODO EDW EXW MEINEI
struct bucket_chain{
    linkedList<bucket> maybeBucketChain;


    //todo insertRecord2bucket(bucket );
};


#endif //TRANSACTIONBITCOINSYSTEM_BUCKET_H
