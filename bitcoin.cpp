//
// Created by dimitrisgan on 8/3/2019.
//

#include "bitcoin.h"








bitcoin::bitcoin( myString id, btc_tree *transactionTree_ptr) : id(id), transactionTree_ptr(
        transactionTree_ptr) {}

ostream &operator<<(ostream &os, const bitcoin &bitcoin1) {
    os << "id: " << bitcoin1.id;
    return os;
}

const myString &bitcoin::getId() const {
    return id;
}

btc_tree *bitcoin::getTransactionTree_ptr()  {
    return transactionTree_ptr;
}


bool bitcoin::operator==( bitcoin &rhs)  {
    return id == rhs.id;
}

bool bitcoin::operator!=( bitcoin &rhs)  {
    return !(rhs.id == this->id);
}

bool bitcoin::operator==(const myString &id) const {
    return this->id == id;
}

bool bitcoin::operator!=(const myString &id) const {
    return !(this->id == id);
}

bitcoin::~bitcoin() {

    delete transactionTree_ptr;
    transactionTree_ptr = nullptr;
}

bitcoin::bitcoin(bitcoin &right) { //todo deep copy

    this->id =right.id;
    this->transactionTree_ptr = new btc_tree (*right.transactionTree_ptr);
//    this->transactionTree_ptr = makeDeepCopy (right.transactionTree_ptr);
//    this->transactionTree_ptr = nullptr;
}

int bitcoin::getInitialValue() {
    return  this->transactionTree_ptr->getRoot()->amount;
}




