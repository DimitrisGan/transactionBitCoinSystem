//
// Created by dimitrisgan on 27/2/2019.
//

#include "bucket.h"

//bucket::bucket(int recordsRemain) : recordsRemain(recordsRemain) {
//
//  //todo
//}



bucket::bucket(unsigned RecordsCapacity)  {

    this->recordsAvailableRemain = RecordsCapacity;

    this->recordsArray = new myString [RecordsCapacity ];



}

bucket::~bucket() {
//    delete  recordsArray;


    delete [] recordsArray;
    recordsArray= nullptr;
}

