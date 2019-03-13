//
// Created by dimitrisgan on 12/3/2019.
//

#include <iostream>
#include "APIfunctions.h"
#include "assistantFunctions.h"


void requestTransactions(char *buffer,Synchroniser &sync) {


    linkedList<char*> resultList;
    split(buffer, ";" , resultList); /// separate all string commands by ";" and push them to the llist
    cout <<resultList;

    //todo call the requestTransaction(char* buffer) to handle the transaction

    for ( auto transactionCommand : resultList) {
        requestTransaction(transactionCommand, sync);
    }

}

void requestTransaction(char *buffer,Synchroniser &sync) {



    //long int strtol(const char *nptr, char **endptr, int base);


    linkedList<char*> resultList;
    split(buffer, " " , resultList); /// separate all string commands by " " and push them to the llist

    cout << resultList;

    if (resultList.getSize() == 5){
        //todo call insertTransaction()
//        sync.insertTransaction()
    }

    if (resultList.getSize() == 3){
        //vale wra pc
    }

//    exit(2);
//    split()
}



void walletStatus(char *buffer, Synchroniser &sync) {
    myString walletId(buffer);
    int current_balance = sync.getWalletHT_ptr()->getData(walletId)->getBalance();
    cout << "The current balance of wallet ID #"<<buffer<< " is:\t"<< current_balance<<endl;
}


void bitCoinStatus(char *buffer, Synchroniser &sync){

    myString btcId(buffer);

    int initBtcValue = sync.getBtcHT_ptr()->getData(btcId)->getInitialValue();
    //call btc::getInitValue()
    cout<< "initial value for btc ID #"<<buffer <<" is:\t"<< initBtcValue <<endl;


    linkedList<myString> numberOfTransacUsed_list ;
    sync.getBtcHT_ptr()->getData(btcId)->getTransactionTree_ptr()->getUniqueTransacList(sync.getBtcHT_ptr()->getData(btcId)->getTransactionTree_ptr()->getRoot() , numberOfTransacUsed_list);
    cout << numberOfTransacUsed_list; //todo exei thema gt den kserw an xwsw ta transacIds sta t_nodes h valw deiktes na koitane apo to tree sta t_nodes

    bool hasUnspent = sync.getBtcHT_ptr()->getData(btcId)->getTransactionTree_ptr()->hasUnspentAmount(
            sync.getBtcHT_ptr()->getData(btcId)->getTransactionTree_ptr()->getRoot());
    if (hasUnspent){
        int unspentAmount = sync.getBtcHT_ptr()->getData(btcId)->getTransactionTree_ptr()->getUnspentAmount(sync.getBtcHT_ptr()->getData(btcId)->getTransactionTree_ptr()->getRoot());
        //todo take the unspent value and print it ///tha mporousa kai na pairna kateutheian thn timh ka
        cout << "unspent amount is "<<unspentAmount<<endl;
    }
}