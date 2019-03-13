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

void transaction::updateTransacionPtrIn_t_nodes() {

    for (auto tNode : this->t_nodePtrList) {
        tNode->setTransac_ptr(this);
    }
}
//void setTransac_ptr(transaction *transac_ptr);



