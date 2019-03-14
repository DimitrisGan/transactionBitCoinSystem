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

ostream &operator<<(ostream &os, const transaction &transaction1) {
    os << "TR_ID#: " << transaction1.transacId << setw(10)<< " SENDER: " << transaction1.senderWalletId <<setw(10)
       << " RECEIVER: " << transaction1.receiverWalletId << " DATE: " << transaction1.transacTime
       << " AMOUNT: " << transaction1.amount ;
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

