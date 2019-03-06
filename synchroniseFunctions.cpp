//
// Created by dimitrisgan on 4/3/2019.
//

#include "synchroniseFunctions.h"

Synchroniser::Synchroniser(myTransacHashMap *senderHT_ptr, myTransacHashMap *receiverHT_ptr,
                           myHashMap<wallet> *walletHT_ptr, myHashMap<bitcoin> *btcHT_ptr) : senderHT_ptr(senderHT_ptr),
                                                                                             receiverHT_ptr(
                                                                                                     receiverHT_ptr),
                                                                                             walletHT_ptr(walletHT_ptr),
                                                                                             btcHT_ptr(btcHT_ptr) {}
