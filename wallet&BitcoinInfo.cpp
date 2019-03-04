//
// Created by dimitrisgan on 27/2/2019.
//

#include "wallet&BitcoinInfo.h"

bool wallet::operator==(const wallet &rhs) const {
    return id == rhs.id;
}

bool wallet::operator!=(const wallet &rhs) const {
    return !(rhs == *this);
}
