//
// Created by dimitrisgan on 27/2/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_BUCKET_H
#define TRANSACTIONBITCOINSYSTEM_BUCKET_H


#include "mylinkedList.h"
#include "myString.h"



int globo=0;
int globo2=0;


template <class T>
struct record{
    myString walletId;
    linkedList<T> *ptr2transactionLlist;
};

template <class T>
struct bucket{
    unsigned recordsAvailableRemain;
    record<T> *recordTable;


    explicit bucket(unsigned RecordsCapacity){
        cout << "CONSTRUCTOR OF BUCKET IS CALLED #"<<globo2++ <<endl;

        this->recordsAvailableRemain = RecordsCapacity;

        this->recordTable = new record<T> [RecordsCapacity ];

    }
    virtual ~bucket(){
        //    delete  recordsArray;

        cout << "DESTRUCTOR OF BUCKET IS CALLED #"<<globo++ <<endl;
        this->recordsAvailableRemain=0;
        delete  [] recordTable;
        recordTable= nullptr;
    }
    bucket& operator=(bucket right)
    {

        this->recordTable = right.recordTable;
        this->recordsAvailableRemain= right.recordsAvailableRemain;
        return *this;
    }

    bucket(bucket &right)
    {
        recordTable = right.recordTable ;
        recordsAvailableRemain =right.recordsAvailableRemain;
    }



};

template <class T>

struct bucket_chain{
    linkedList<bucket<T>> maybeBucketChain;


    //todo insertRecord2bucket(bucket );
};









#endif //TRANSACTIONBITCOINSYSTEM_BUCKET_H
