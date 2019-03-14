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

ostream &operator<<(ostream &os, const transaction &transaction1) {
    os << "transacId: " << transaction1.transacId << " senderWalletId: " << transaction1.senderWalletId
       << " receiverWalletId: " << transaction1.receiverWalletId << " transacTime: " << transaction1.transacTime
       << " amount: " << transaction1.amount << " t_nodePtrList: " << transaction1.t_nodePtrList;
    return os;
}
//void setTransac_ptr(transaction *transac_ptr);

//std::ostream & operator<<(std::ostream & os, const linkedList<T>& rhs)
//{
//    if (rhs.isEmpty()){
//        os << "EMPTY LIST\n";
//
//    }
//    for (l_node<T> *temp = rhs.head; temp != nullptr; temp = temp->next)
//    {
//        os << temp->data;
//        if (temp->next != nullptr)
//            os << ", ";
//    }
////    os<<"\n";
//    return os;
//}

