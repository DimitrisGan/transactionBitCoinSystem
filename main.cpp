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



    myHashMap<wallet>   walletHT(tableSize , myHashFunc );
    myHashMap< bitcoin> btcHT (tableSize , myHashFunc );
    myHashMap<transaction> transacHT(tableSize , myHashFunc ); 

    argmKeeper.bitCoinBalancesFile = "bitCoinBalancesFile";

    btcBalancesFile_parsing_and_save(argmKeeper.bitCoinBalancesFile , walletHT , btcHT , btcValue); //save also to walletHT,btcHT


    myTransacHashMap  senderHT(tableSize ,myHashFunc   ,bucketSizeInBytes);
    myTransacHashMap  receiverHT(tableSize ,myHashFunc   ,bucketSizeInBytes);


    Synchroniser sync (senderHT,receiverHT,walletHT,btcHT ,transacHT); //initiate sync struct

    argmKeeper.transactionsFile = "transactionFile";
    readTransactionQueries(argmKeeper.transactionsFile ,sync );



    cout <<"end\n";




    return 0;
}