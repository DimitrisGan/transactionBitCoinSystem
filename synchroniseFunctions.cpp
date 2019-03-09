//
// Created by dimitrisgan on 4/3/2019.
//

#include "synchroniseFunctions.h"


//Synchroniser sync (&senderHT,&receiverHT,&walletHT,&btcHT ,&transacHT); //initiate sync struct




void Synchroniser::insertTransaction(transaction &potentialTransaction) {

    //todo [DONE]1#  koitaw apo senders wallet an exei to apaitoumeno poso
    //todo [DONE]2#  an oxi :exit()
    //todo 3#  an nai sortarw an goustarw apo th lista me ta btc kai anoigw auta me to megalutero poso
    //todo 4#  paw sta dentra twn chosenBtc kai ta skavw ---> ta xwnw se mia lista kai to poso pou phra ---> ta xwnw sto transaction mou (forse pointer)
    //todo 5#  sto skapsimo h sunarthsh prepei na mou epistrepsei pointers (stous pateres) sta kainourgia nodes pou anoiksa
    //todo 6#  autous tous pointers tous xwnw sto potentialTransaction.treeNodeList_ptrs<t_nodes*>.PROSOXH! xwnw to aristero paidi ston sender kai deksi sto wallet
    //todo edw dhmiourgeitai h aporia mhpws prepei na xw sa parametro 2 transacNodes --> ena tou sender kai ena tou receiver


    wallet  *sendersWallet =  this->walletHT_ptr.getData(potentialTransaction.getSenderWalletId());


    if (!transactionIsValid(potentialTransaction, sendersWallet->getBalance())){
        std::cerr << "CANT APPLY THE TRANSACTION WITH ID# "<<potentialTransaction.getTransacId()<<endl;
        exit(NOT_VALID_TRSANSACTION);
    }



    




    //todo last#  kanw update ta upoloipo--btcList--amountBtcList sta wallets tou sender kai receiveer




}

Synchroniser::Synchroniser(const myTransacHashMap &senderHT_ptr, const myTransacHashMap &receiverHT_ptr,
                           const myHashMap<wallet> &walletHT_ptr, const myHashMap<bitcoin> &btcHT_ptr,
                           const myHashMap<transaction> &transacHT_ptr) : senderHT_ptr(senderHT_ptr),
                                                                          receiverHT_ptr(receiverHT_ptr),
                                                                          walletHT_ptr(walletHT_ptr),
                                                                          btcHT_ptr(btcHT_ptr),
                                                                          transacHT_ptr(transacHT_ptr) {}


bool Synchroniser::transactionIsValid(transaction potentialTransac, int sendersBalance) {
    return (potentialTransac.getAmount() <= sendersBalance);
}

//            this->walletHT_ptr.getData(potentialTransac.getSenderWalletId()).getBalance());


