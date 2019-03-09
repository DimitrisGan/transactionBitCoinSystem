//
// Created by dimitrisgan on 8/3/2019.
//

#include "bitcoin.h"





bool bitcoin::operator==( bitcoin &rhs)  {
    return id == rhs.id;
}

bool bitcoin::operator!=( bitcoin &rhs)  {
    return !(rhs.id == this->id);
}


bitcoin::bitcoin( myString id, btc_tree *transactionTree_ptr) : id(id), transactionTree_ptr(
        transactionTree_ptr) {}

ostream &operator<<(ostream &os, const bitcoin &bitcoin1) {
    os << "id: " << bitcoin1.id;
    return os;
}
