//
// Created by dimitrisgan on 8/3/2019.
//

#include <iomanip>
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


//889 Maria Ronaldo 50 25-12-2018 20:08
//776 Lionel Antonella 150 14-02-2019 10:05
ostream &operator<<(ostream &os, const transaction &transaction1) {
    os << transaction1.transacId <<" " << transaction1.senderWalletId <<" " << transaction1.receiverWalletId << " " << transaction1.transacTime
       << " " << transaction1.amount ;
    return os;
}

