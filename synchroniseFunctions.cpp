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

void Synchroniser::insertTransaction(myString sender, transacNode &transNode) {

    //todo 1#  koitaw apo senders wallet an exei to apaitoumeno poso
    //todo 2#  an oxi :exit()
    //todo 3#  an nai sortarw an goustarw apo th lista me ta btc kai anoigw auta me to megalutero poso
    //todo 4#  paw sta dentra twn chosenBtc kai ta skavw ---> ta xwnw se mia lista kai to poso pou phra ---> ta xwnw sto transacNode mou (forse pointer)
    //todo 5#  sto skapsimo h sunarthsh prepei na mou epistrepsei pointers (stous pateres) sta kainourgia nodes pou anoiksa
    //todo 6#  autous tous pointers tous xwnw sto transNode.treeNodeList_ptrs<t_nodes*>.PROSOXH! xwnw to aristero paidi ston sender kai deksi sto wallet
    //todo edw dhmiourgeitai h aporia mhpws prepei na xw sa parametro 2 transacNodes --> ena tou sender kai ena tou receiver


    this->walletHT_ptr.

    //todo last#  kanw update ta upoloipo--btcList--amountBtcList sta wallets tou sender kai receiveer




}
