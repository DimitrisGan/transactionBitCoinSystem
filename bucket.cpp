//
// Created by dimitrisgan on 27/2/2019.
//

#include "bucket.h"

//bucket::bucket(int recordsRemain) : recordsRemain(recordsRemain) {
//
//  //todo
//}

int globo=0;
int globo2=0;

bucket::bucket(unsigned RecordsCapacity)  {

      cout << "CONSTRUCTOR OF BUCKET IS CALLED #"<<globo2++ <<endl;


    this->recordsAvailableRemain = RecordsCapacity;

    this->recordsArray = new myString [RecordsCapacity ];


}

bucket::~bucket() {
//    delete  recordsArray;

    cout << "DESTRUCTOR OF BUCKET IS CALLED #"<<globo++ <<endl;
    delete  [] recordsArray;
    recordsArray= nullptr;
}

