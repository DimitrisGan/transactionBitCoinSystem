//
// Created by dimitrisgan on 8/3/2019.
//

#include "transaction.h"

bool transaction::operator==(const transaction &rhs) const {
    return transacId == rhs.transacId;
}

bool transaction::operator!=(const transaction &rhs) const {
    return !(rhs.transacId == this->transacId);;
}

bool transaction::operator==(const myString &id) const {
    return transacId == id;
}

bool transaction::operator!=(const myString &id) const {
    return !(id == this->transacId);
}



