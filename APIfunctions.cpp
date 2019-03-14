//
// Created by dimitrisgan on 12/3/2019.
//

#include <iostream>
#include "APIfunctions.h"
#include "assistantFunctions.h"


void findEarnings(char *buffer,Synchroniser &sync){
    linkedList<char*> resultList;
    split(buffer, " " , resultList); /// separate all string commands by ";" and push them to the llist
    char* walletId_str = resultList.getHead()->getData();
    myString walletId(walletId_str);
    linkedList<transaction *> returnedList = sync.getReceiverHT_ptr()->getAllTransactions(walletId);

    linkedList<transaction *> filteredListByDate ;

    if (resultList.getSize() == 1){
        filteredListByDate = returnedList;
    }
    else{
        filterTransactionsByDate( resultList , returnedList , filteredListByDate) ;
    }

    int totalEarnings = 0;
    cout<<"\n";
    for (auto item : filteredListByDate) {
        totalEarnings+=item->getAmount();
        cout << *item <<endl;
    }
    cout <<"The total amount of Earnings for "<<walletId << " is "<<totalEarnings<<endl;
}


void findPayments(char *buffer, Synchroniser &sync) {
    linkedList<char*> resultList;
    split(buffer, " " , resultList); /// separate all string commands by ";" and push them to the llist
    char* walletId_str = resultList.getHead()->getData();
    myString walletId(walletId_str);
    linkedList<transaction *> returnedList = sync.getSenderHT_ptr()->getAllTransactions(walletId); //the only difference with findEarnings

    linkedList<transaction *> filteredListByDate ;

    if (resultList.getSize() == 1){
        filteredListByDate = returnedList;
    }
    else{
        filterTransactionsByDate( resultList , returnedList , filteredListByDate) ;
    }

    int totalPayments = 0;
    cout<<"\n";
    for (auto item : filteredListByDate) {
        totalPayments+=item->getAmount();
        cout << *item <<endl;
    }
    cout <<"The total amount of Payments for "<<walletId << " is "<<totalPayments<<endl;
}




void requestTransactions(char *buffer,Synchroniser &sync) {

    linkedList<char*> resultList;
    split(buffer, ";" , resultList); /// separate all string commands by ";" and push them to the llist

    for ( auto transactionCommand : resultList) {
        requestTransaction(transactionCommand, sync);
    }

}




void requestTransaction(char *buffer,Synchroniser &sync) {


    transaction potentialTransac;

    potentialTransac.transacId = sync.createVirtualTransacId(); //create a virtualId

    linkedList<char*> resultList;
    split(buffer, " " , resultList); /// separate all string commands by " " and push them to the llist

    // Declaring iterator to a llist
    linkedList<char*>::Iterator iter;

    // Displaying llist elements using begin() and end()
    int i=0;
    for (iter = resultList.begin(); iter != resultList.end() && i<3; iter++){
        switch (i){
            case 0: potentialTransac.senderWalletId = *iter;break;
            case 1: potentialTransac.receiverWalletId = *iter;break;
            case 2: if (!isNumber(*iter) ) {fprintf(stderr, "AMOUNT IN TRANSACTION IS NOT A NUMBER : %s\n", *iter);exit(EXIT_FAILURE);}
                potentialTransac.amount = atoi(*iter);break;
            default: exit(EXIT_FAILURE);
        }
        i++;
    }
    //now we have to check if in transaction there is given a date

    date date2insert;
    myString token;

    if (resultList.getSize() == 5){ //there is also the date
        linkedList<char*> dateList2insert ;
        token = *iter;
        date2insert.setDate(token);
//        dateList2insert.insert_last(*iter); //insert  DD-MM-YYYY
        iter++; token = *iter;
//        dateList2insert.insert_last(*iter); //insert  HH:MM
        date2insert.setTime(token);
        potentialTransac.transacTime = date2insert;


    }
    else if (resultList.getSize() == 3){ //means that we need to give date from the pc

        potentialTransac.transacTime.timeNow();
    }
    else{
        assert(1);
    }


    cout <<"";

    sync.insertTransaction(potentialTransac);

    //todo edw tha ginei insertTransaction() --> fusika edw tha ginei kai to update tou transacId
}



void walletStatus(char *buffer, Synchroniser &sync) {
    myString walletId(buffer);
    int current_balance = sync.getWalletHT_ptr()->getData(walletId)->getBalance();
    cout << "The current wallet status of #"<<buffer<< " is: "<< current_balance<<endl;
}


void bitCoinStatus(char *buffer, Synchroniser &sync){

    myString btcId(buffer);

    int initBtcValue = sync.getBtcHT_ptr()->getData(btcId)->getInitialValue();

    linkedList<myString> numberOfTransacUsed_list ;
    sync.getBtcHT_ptr()->getData(btcId)->getTransactionTree_ptr()->getUniqueTransacIdsList(
            sync.getBtcHT_ptr()->getData(btcId)->getTransactionTree_ptr()->getRoot(), numberOfTransacUsed_list);
//    cout << numberOfTransacUsed_list <<endl;

    bool hasUnspent = sync.getBtcHT_ptr()->getData(btcId)->getTransactionTree_ptr()->hasUnspentAmount(
            sync.getBtcHT_ptr()->getData(btcId)->getTransactionTree_ptr()->getRoot());

    int unspentAmount;
    if (hasUnspent){
        unspentAmount = sync.getBtcHT_ptr()->getData(btcId)->getTransactionTree_ptr()->getUnspentAmount(sync.getBtcHT_ptr()->getData(btcId)->getTransactionTree_ptr()->getRoot());
    }
    else{
        unspentAmount=0;
    }

    cout << "btcID #"<< buffer << ": [InitValue]:"<<initBtcValue<<"\t [numberOfTransactionsInvolved]:"<<numberOfTransacUsed_list.getSize()<<"\t [unspentAmount]:"<<unspentAmount<<endl;

}

void traceCoin(char *buffer, Synchroniser &sync) {

    myString btcId(buffer);

    int initBtcValue = sync.getBtcHT_ptr()->getData(btcId)->getInitialValue();

    linkedList<transaction*> transacInvolved_list ;
    sync.getBtcHT_ptr()->getData(btcId)->getTransactionTree_ptr()->getUniqueTransacList(
            sync.getBtcHT_ptr()->getData(btcId)->getTransactionTree_ptr()->getRoot(), transacInvolved_list);


    for (const auto &item : transacInvolved_list) {
        cout<< *item<<endl;
    }


}


