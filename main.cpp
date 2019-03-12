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
    linkedList<char*> cin_list;

    bool flagExit = false;
    do {
        cin >> buffer;
        split(buffer," ",cin_list);
        char* command = cin_list.getHead()->getData();

//        strcpy(command , "requestTransaction");


        if (strcmp(cin_list.getHead()->getData(),"requestTransaction") ==0){

            //todo call requestTransaction(command);
            cout <<"teleia\n";
            requestTransaction(command);
        }



        if ( strcmp(command,"exit") ==0){flagExit =true;}
        cin_list.clear();

    }while (! flagExit);

    cout << "end\n";


    delete [] buffer;buffer= nullptr;
    delete walletHT; walletHT= nullptr;
    delete btcHT; btcHT= nullptr;
    delete transacHT; transacHT= nullptr;

    delete senderHT; senderHT= nullptr;
    delete receiverHT; receiverHT= nullptr;


    cout <<"end2\n";




    return 0;
}