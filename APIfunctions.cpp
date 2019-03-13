//
// Created by dimitrisgan on 12/3/2019.
//

#include <iostream>
#include "APIfunctions.h"
#include "assistantFunctions.h"


void findEarnings(char *buffer,Synchroniser &sync){
    //todo



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

    if (resultList.getSize() == 5){ //there is also the date
        linkedList<char*> dateList2insert ;
        date2insert.setDate(*iter);
//        dateList2insert.insert_last(*iter); //insert  DD-MM-YYYY
        iter++;
//        dateList2insert.insert_last(*iter); //insert  HH:MM
        date2insert.setTime(*iter);
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