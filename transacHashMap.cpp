//
// Created by dimitrisgan on 4/3/2019.
//

#include "transacHashMap.h"


recordsBucket_chain myTransacHashMap::getTableById(myString id) const {

    int index = this->getIndex(id);

    return table[index];
}


void myTransacHashMap::addTransacNode2appropriateIndex(myString walletId , transaction* transac2add){

    int index = this->getIndex(walletId);
    myTransacHashMap::table[index].insert(walletId,transac2add);
}


