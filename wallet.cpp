//
// Created by dimitrisgan on 27/2/2019.
//

#include "wallet.h"

bool wallet::operator==(const wallet &rhs) const {
    return id == rhs.id;
}

bool wallet::operator!=(const wallet &rhs) const {
    return !(rhs == *this);
}

bool wallet::operator==(const myString &id2) const {
    return id == id2;;
}

bool wallet::operator!=(const myString &id2) const {
    return !(id2 == this->id);
}






void wallet::setBalance(int balance) {
    wallet::balance = balance;
}

void wallet::setBtcIdsOwned_list( linkedList<myString> &btcIdsOwned_list) {
    wallet::btcIdsOwned_list = btcIdsOwned_list;
}

void wallet::setAmountOnEachBtc( linkedList<int> &amountOnEachBtc) {
    wallet::amountOnEachBtc = amountOnEachBtc;
}

wallet::wallet( myString id, int balance,  linkedList<myString> btcIdsOwned_list,
                linkedList<int> amountOnEachBtc) : id(id), balance(balance), btcIdsOwned_list(btcIdsOwned_list),
                                                   amountOnEachBtc(amountOnEachBtc) {}

void wallet::setId(const myString &id) {
    wallet::id = id;
}

myString wallet::getId()  {
    return this->id;
}

linkedList<myString> wallet::getBtcIdsOwned_list()  {
    return btcIdsOwned_list;
}

ostream &operator<<(ostream &os, const wallet &wallet1) {
    os << "id: " << wallet1.id;
    return os;
}

int wallet::getBalance() const {
    return balance;
}

wallet::wallet( wallet &right) {



    this->id = right.id;
    this->balance = right.balance;
    this->btcIdsOwned_list = right.btcIdsOwned_list;
    this->amountOnEachBtc = right.amountOnEachBtc;
}



//todo//todo//todo//todo//todo//todo//todo//todo//todo//todo//todo


//===========================================================================================
//===========================================================================================
