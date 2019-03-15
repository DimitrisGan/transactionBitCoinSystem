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


    ArgumentsKeeper argmKeeper;
    argmParser(argc, argv , argmKeeper);

//    argmKeeper.printArgs();

    unsigned bucketSizeInBytes = 100;
    unsigned tableSize =1;
    int btcValue = 50;
    unsigned  (*myHashFunc)( const myString&, unsigned)  = & myHash ;



    myHashMap<wallet>       *walletHT  = new myHashMap<wallet>(tableSize , myHashFunc );
    myHashMap< bitcoin>     *btcHT     = new myHashMap< bitcoin> (tableSize , myHashFunc );
    myHashMap<transaction>  *transacHT = new myHashMap<transaction>(tableSize , myHashFunc );

    btcBalancesFile_parsing_and_save(argmKeeper.bitCoinBalancesFile , walletHT , btcHT , btcValue); //save also to walletHT,btcHT


    myTransacHashMap  *senderHT = new myTransacHashMap(tableSize ,myHashFunc   ,bucketSizeInBytes);
    myTransacHashMap  *receiverHT = new myTransacHashMap(tableSize ,myHashFunc   ,bucketSizeInBytes);

    Synchroniser sync (senderHT,receiverHT,walletHT,btcHT ,transacHT); //initiate sync struct

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




    char* buffer;
    char* copybuffer;
    linkedList<char*> cin_list;
    linkedList<char*> cin_list2;

    bool flagExit = false;
    do {

        buffer = getline();

//        strcpy(buffer , "requestTransactions  richard annie 10  ;  richard johnsmith 20 ;");
//        strcpy(buffer , "requestTransactions      inputTransactions2");
//        strcpy(buffer , "findEarnings richard ");
//        strcpy(buffer , "findPayments richard 10:00 15:00");
//        strcpy(buffer , "findEarnings richard 10:12 11-01-2014 15:12 1-3-2030 ");
//        strcpy(buffer , "findEarnings richard  10:12  16:15");
//        strcpy(buffer , "walletStatus lookingforagoogusernametoo");
//        strcpy(buffer , "bitCoinStatus 541");
//        strcpy(buffer , "traceCoin 541");

        copybuffer = (char*)malloc(strlen(buffer)+1);
        strcpy(copybuffer , buffer);

        split(buffer," ",cin_list); //we split into list to take the first word which is the commandType

        char* commandType = cin_list.getHead()->getData(); //take the first node of the list

        char* substr = copybuffer; //we want the substr because we want to shift by one position right to avoid the " "

        removeFirst(substr, commandType); //remove commandType word in the string
        if (substr[0] == '\n' || substr[0] == ' ' )
            substr++;   //shift one letter to avoid " " or "\n"
        if (substr[strlen(substr) -1] == '\n')
            substr[strlen(substr)-1]= '\0';

        if (!strcmp(commandType,"requestTransactions")){ //check here if input is file or transactions

            if (cin_list.getSize() == 2)
                requestTransactionsFromFile(substr, sync); //substr contains the inputFile name
            else
                requestTransactions(substr, sync);
        }


        if (!strcmp(commandType,"findEarnings")){

            findEarnings(substr, sync);
        }


        if (!strcmp(commandType,"findPayments")){

            findPayments(substr, sync);
        }


        if (!strcmp(commandType,"walletStatus")){

            walletStatus(substr, sync);
        }

        if (!strcmp(commandType,"bitCoinStatus")){

            bitCoinStatus(substr, sync);
        }

        if (!strcmp(commandType,"traceCoin")){

            traceCoin(substr, sync);
        }

        if (!strcmp(commandType,"exit")){flagExit =true;}
        cin_list.clear();

        free(buffer);buffer= nullptr;
        free(copybuffer);copybuffer= nullptr;
    }while (! flagExit);



    delete walletHT; walletHT= nullptr;
    delete btcHT; btcHT= nullptr;
    delete transacHT; transacHT= nullptr;

    delete senderHT; senderHT= nullptr;
    delete receiverHT; receiverHT= nullptr;



    cout << "\nend\n";



    return 0;
}