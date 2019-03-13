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



// Store the formatted string of time in the output
void format_time( date& returnPCtime){
    char output[20];
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    sprintf(output, "[%d %d %d %d:%d:%d]",timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

    returnPCtime.year = timeinfo->tm_year + 1900;
    returnPCtime.month = timeinfo->tm_mon + 1;
    returnPCtime.day = timeinfo->tm_mday ;
    returnPCtime.hour = timeinfo->tm_hour;
    returnPCtime.minute = timeinfo->tm_min;


}

void requestTransaction(char *buffer,Synchroniser &sync) {


    transaction potentialTransac;

    potentialTransac.transacId = sync.createVirtualTransacId(); //create a virtualId

    linkedList<char*> resultList;
    split(buffer, " " , resultList); /// separate all string commands by " " and push them to the llist

    cout << resultList;

    // Declaring iterator to a llist
    linkedList<char*>::Iterator iter;

    // Displaying llist elements using begin() and end()
    int i=0;
    for (iter = resultList.begin(); iter != resultList.end() && i<3; iter++){
        switch (i){
            case 0: potentialTransac.senderWalletId = *iter;break;
            case 1: potentialTransac.receiverWalletId = *iter;break;
            case 2: if (!isNumber(*iter) ) {
                        fprintf(stderr, "AMOUNT IN TRANSACTION IS NOT A NUMBER : %s\n", *iter);
                        exit(EXIT_FAILURE);
                    }
                    potentialTransac.amount = atoi(*iter);break;
            default: exit(EXIT_FAILURE);
        }
        i++;
    }
    //now we have to check if in transaction there is given a date

    date date2insert;

    if (resultList.getSize() == 5){ //there is also the date
        linkedList<char*> dateList2insert ;
        dateList2insert.insert_last(*iter); //insert  DD-MM-YYYY
        iter++;
        dateList2insert.insert_last(*iter); //insert  HH:MM
        date2insert.setDateByGivenList(dateList2insert);

    }
    else if (resultList.getSize() == 3){ //means that we need to give date from the pc

        format_time(date2insert);
    }

    potentialTransac.transacTime = date2insert;



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