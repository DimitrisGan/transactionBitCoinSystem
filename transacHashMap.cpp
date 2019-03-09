//
// Created by dimitrisgan on 4/3/2019.
//

#include "transacHashMap.h"

//transaction &myTransacHashMap::getTransacNodeByRef(myString id) {
//    int index = this->getIndex(id);
//
//    return <#initializer#>;
//}

recordsBucket_chain myTransacHashMap::getTableById(myString id) const {

    int index = this->getIndex(id);

    return table[index];
}

void myTransacHashMap::addTransacNode2appropriateIndex(myString senderId , transaction transac2add){
    int index = this->getIndex(senderId);
    myTransacHashMap::table = table;
}
