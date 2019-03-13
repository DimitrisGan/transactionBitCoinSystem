#include <iostream>
#include "mylinkedList.h"
#include "myString.h"
#include "recordsBucket.h"
#include "assistantFunctions.h"
#include "bitcoinTree.h"
#include "wallet.h"
#include "myBucket.h"
#include "myHashMap.h"
//#include "hashFunction.h"
#include "transacHashMap.h"
#include "synchroniseFunctions.h"
#include "APIfunctions.h"

using  namespace std;

int main(int argc, char **argv) {
    std::cout << "Hello, World!\n" << std::endl;

    ArgumentsKeeper argmKeeper;
    /*
      argmParser(argc, argv , argmKeeper);

      argmKeeper.printArgs();
   */

    unsigned bucketSizeInBytes = 100;
    unsigned tableSize =1;
    int btcValue = 50;
    unsigned  (*myHashFunc)( myString, unsigned)  = & myHash ;



    myHashMap<wallet>       *walletHT = new myHashMap<wallet>(tableSize , myHashFunc );
    myHashMap< bitcoin>     *btcHT  = new myHashMap< bitcoin> (tableSize , myHashFunc );
    myHashMap<transaction>  *transacHT = new myHashMap<transaction>(tableSize , myHashFunc );

    argmKeeper.bitCoinBalancesFile = "bitCoinBalancesFile";

    btcBalancesFile_parsing_and_save(argmKeeper.bitCoinBalancesFile , walletHT , btcHT , btcValue); //save also to walletHT,btcHT


    myTransacHashMap  *senderHT = new myTransacHashMap(tableSize ,myHashFunc   ,bucketSizeInBytes);
    myTransacHashMap  *receiverHT = new myTransacHashMap(tableSize ,myHashFunc   ,bucketSizeInBytes);


    Synchroniser sync (senderHT,receiverHT,walletHT,btcHT ,transacHT); //initiate sync struct

    argmKeeper.transactionsFile = "transactionFile";
    readTransactionQueries(argmKeeper.transactionsFile ,sync );

    //======================================================

    //[1] /requestTransaction senderWalletID receiverWalletID amount date time
    //[1b] /requestTransactions senderWalletID receiverWalletID amount date time;
    //senderWalletID2 receiverWalletID2 amount2 date2 time2;

    //[1c] requestTransactions inputFile
    //[2] ​/findEarnings walletID [time1][year1][time2][year2]
    //[3] ​/findPayments walletID [time1][year1][time2][year2]
    //[4] /walletStatus walletID
    //[5] ​/bitCoinStatus bitCoinID
    //[6] /traceCoin bitCoinID
    //[7] ​/exit


    char* buffer=  new char[5000];
    char* copybuffer=  new char[5000];
    char* initBuffer= nullptr;
    linkedList<char*> cin_list;

    bool flagExit = false;
    do {
//        cin >> buffer;

        strcpy(buffer , "requestTransactions senderWalletID receiverWalletID 30 ;"
                        "senderWalletID2 receiverWalletID2 2 12-01-2012 14:22;");

//        strcpy(buffer , "walletStatus lookingforagoogusernametoo");
//        strcpy(buffer , "bitCoinStatus 541");

        strcpy(copybuffer , buffer);

        split(buffer," ",cin_list); //we split into list to take the first word which is the commandType

        char* commandType = cin_list.getHead()->getData(); //take the first node of the list

        char* substr = copybuffer; //we want the substr because we want to shift by one position right to avoid the " "

        removeFirst(substr, commandType); //remove commandType word in the string
        substr++;   //shift one letter to avoid " "

//        if (strcmp(cin_list.getHead()->getData(),"requestTransaction") ==0){
//
//            requestTransaction(buffer);
//        }


        if (strcmp(commandType,"requestTransactions") ==0){

            requestTransactions(substr, sync);
        }


//        ​/walletStatus walletID



        if (strcmp(commandType,"walletStatus") ==0){

            walletStatus(substr, sync);
        }

        if (strcmp(commandType,"bitCoinStatus") ==0){

            bitCoinStatus(substr, sync);
        }



//        ​/bitCoinStatus bitCoinID





        if ( strcmp(commandType,"exit") ==0){flagExit =true;}
        cin_list.clear();
//        copybuffer--; //don't for


    }while (false);//todo(! flagExit);

    cout << "end\n";


    delete [] buffer;buffer= nullptr;
    delete [] copybuffer;copybuffer= nullptr;
    delete walletHT; walletHT= nullptr;
    delete btcHT; btcHT= nullptr;
    delete transacHT; transacHT= nullptr;

    delete senderHT; senderHT= nullptr;
    delete receiverHT; receiverHT= nullptr;


    cout <<"end2\n";




    return 0;
}