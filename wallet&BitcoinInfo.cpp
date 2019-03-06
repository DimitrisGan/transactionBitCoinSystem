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


//todo//todo//todo//todo//todo//todo//todo//todo//todo//todo//todo


//===========================================================================================
//===========================================================================================

bool bitcoin::operator==( bitcoin &rhs)  {
    return id == rhs.id;
}

bool bitcoin::operator!=( bitcoin &rhs)  {
    return !(rhs == *this);
}


bitcoin::bitcoin( myString id, btc_tree *transactionTree_ptr) : id(id), transactionTree_ptr(
        transactionTree_ptr) {}
