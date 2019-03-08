//
// Created by dimitrisgan on 26/2/2019.
//

#include <cstring>
#include <fstream>
#include "assistantFunctions.h"



void argmParser(int &argc, char **argv, struct ArgumentsKeeper &argmKeeper){

    bool flagA=false;
    bool flagT=false;
    bool flagV=false;
    bool flagH1=false;
    bool flagH2=false;
    bool flagB=false;

    int i=1;
    while (i < argc ) {
        if (argv[i] == nullptr ){break;}

        if(strcmp(argv[i],"-a")==0 && !flagA && argv[i + 1] != nullptr){
            argmKeeper.bitCoinBalancesFile = argv[++i];
            flagA = true;
            i++;
            continue;
        }

        if(strcmp(argv[i],"-t")==0 && !flagT && argv[i + 1] != nullptr){
            argmKeeper.transactionsFile = argv[++i];
            flagT = true;
            i++;
            continue;
        }

        if(strcmp(argv[i],"-v")==0 && !flagV && argv[i + 1] != nullptr){
            argmKeeper.bitCoinValue = atoi(argv[++i]);
            flagV = true;
            i++;
            continue;
        }

        if(strcmp(argv[i],"-h1")==0 && !flagH1 && argv[i + 1] != nullptr){
            argmKeeper.senderHashtableNumOfEntries = atoi(argv[++i]);
            flagH1 = true;
            i++;
            continue;
        }

        if(strcmp(argv[i],"-h2")==0 && !flagH2 && argv[i + 1] != nullptr){
            argmKeeper.receiverHashtableNumOfEntries = atoi(argv[++i]);
            flagH2 = true;
            i++;
            continue;
        }

        if(strcmp(argv[i],"-b")==0 && !flagB && argv[i + 1] != nullptr){
            argmKeeper.bucketSize = atoi(argv[++i]);
            flagB = true;
            i++;
            continue;
        }

        fprintf(stderr, "Unknown argument OR not given argument for flag: %s\n", argv[i]);
        exit(UNKNOWN_CMDARGUMENT);

    }


    if (!flagA){
        cout << "Provide bitCoinBalancesFile : ";
        cin >> argmKeeper.bitCoinBalancesFile ;

    }
    if (!flagT){

        cout << "Provide transactionsFile : ";
        cin >> argmKeeper.transactionsFile;
    }
    if (!flagV){
        cout << "Provide bitCoinValue : ";
        cin >> argmKeeper.bitCoinValue;
    }
    if (!flagH1){
        cout << "Provide senderHashtableNumOfEntries : ";
        cin >> argmKeeper.senderHashtableNumOfEntries;
    }
    if (!flagH2){
        cout << "Provide receiverHashtableNumOfEntries : ";
        cin >> argmKeeper.receiverHashtableNumOfEntries;
    }
    if (!flagB ){
        cout << "Provide bucketSize : ";
        cin >> argmKeeper.bucketSize;

    }

}


void ArgumentsKeeper::printArgs() {

    cout << "~~~~   Arguments Given    ~~~~~"<<endl;
    cout << "bitCoinBalancesFile (-a) : \t\t" << bitCoinBalancesFile <<endl;
    cout << "transactionsFile (-t) : \t\t" << transactionsFile <<endl;
    cout << "bitCoinValue (-v) : \t\t\t" << bitCoinValue <<endl;
    cout << "senderHashtableNumOfEntries (-h1) : \t" << senderHashtableNumOfEntries <<endl;
    cout << "receiverHashtableNumOfEntries (-h2) : \t" << receiverHashtableNumOfEntries <<endl;
    cout << "bucketSize (-b) : \t\t\t" << bucketSize <<endl;
}





void split( char* str, char* delimiter , linkedList<char*> & result2return) {

    char* token ;
//    linkedList<char*> result;

    token = strtok(str , delimiter);

    while (token!= nullptr){
//        printf("'%s'\n", token);
        result2return.insert_last(token);
        token = strtok(nullptr, delimiter);

    }

}



//23 richard crystalsmith 20 13-02-2018 12:32
//
//45 novaldach hackerman 30 11-01-2017 14:46


void readTransactionQueries(const myString &initiaTransacFile,  Synchroniser &sync){

    FILE * fp;
    char * line = nullptr;
    size_t len = 0;
    ssize_t read;
    fp = fopen(initiaTransacFile .getMyStr(), "r");
    if (fp == nullptr)
        exit(EXIT_FAILURE);


    linkedList<char*> resultList;
    char delim[] = " ";
    while ((read = getline(&line, &len, fp)) != -1) {

        if (line[0] == '\n'){continue;} //skip empty lines

        split(line, delim , resultList); /// push all char* tokens to the list

        myString new_transactionId;
        myString receiverId;
        date transacDate;
        transacNode new_transacNode;
        myString sender;

        linkedList<int> transacDateList;
        int i=0;
        for ( auto tokenStr : resultList){
            //convert token to myString

            myString token(tokenStr);
//            cout <<token <<"\t";


//
            if (i==0) { //transacId
                new_transacNode.setTransacId(token);
            }
            if (i==1) { //senderId
                sender = token; //it is the hash key to the sender HashMap
            }
            if (i==2) { //receiverId
                new_transacNode.setWalletId(token);
            }
            if (i==3) { //amount to transfer
                new_transacNode.setAmount(atoi(tokenStr));
            }
            if (i==4) {//todo make it optional
                //todo split (-) meta convert to int

                linkedList<char*> dateNumbersChar;
                split(tokenStr,"-",dateNumbersChar);
                for (auto &item : dateNumbersChar) {
                    transacDateList.insert_last(atoi(item));
                }
            }
            if (i==5) {//todo make it optional
                //todo split (:) meta convert to int

                linkedList<char*> hourNumbersChar;
                split(tokenStr,":",hourNumbersChar);
                for (auto &item : hourNumbersChar) {
                    transacDateList.insert_last(atoi(item));
                }
            }

            i++;
        }


        //todo set here the date object
        transacDate.setDateByGivenList(transacDateList);

        new_transacNode.setTransacTime(transacDate);


        //todo tha ftiaksw thn insertSync pou legame kai tha ta kanei ekeinh insert me ta katallhla exceptions
        sync.insertTransaction( sender , new_transacNode );

        resultList.clear();
    }



    fclose(fp);
    if (line)
        free(line);
}







//richard 541 896 453 670 432
//annie 235 5490 325

void btcBalancesFile_parsing_and_save(const myString &btcInitialOwnersFile, myHashMap<wallet > &walletHT_ptr,
                                      myHashMap<bitcoin> &btcHT_ptr, int bitCoinValue) {
    //todo ftiaxnw domh wallet edw
    //todo + ftiaxnw tis rizes twn btcTrees (gia tous prokatoxous) ara ftiaxnw domh btcTree-->bitcoin
    //todo ta xwne sta walletHT , btcHT


    FILE * fp;
    char * line = nullptr;
    size_t len = 0;
    ssize_t read;

    fp = fopen(btcInitialOwnersFile .getMyStr(), "r");
    if (fp == nullptr)
        exit(EXIT_FAILURE);




    linkedList<char*> resultList;
    char delim[] = " ";
    while ((read = getline(&line, &len, fp)) != -1) {

        if (line[0] == '\n'){continue;} //skip empty lines

        split(line, delim , resultList); /// push all char* tokens to the list

        myString new_walletId;

        int balance =0;
        linkedList<myString> btcList;
        linkedList<int> amountList;

        bool  isUserName= true;



        for ( auto tokenStr : resultList) {
            //convert token to myString

            myString token(tokenStr);
//
            if (isUserName) { //means that we have the user name (=new_walletId)
                new_walletId = token;
                isUserName = false;


            }

            else{ //there is a btc id to insert in wallet's user


                btcList.insert_last(token);
                amountList.insert_last(bitCoinValue);
                balance+= bitCoinValue;

            }

            if (resultList.getSize() == 1) {  // in case that the user doesn't have a wallet [avoid seg for user with empty wallet]
                break;
            }

        }


        if (resultList.getSize() == 1){  // in case that the user doesn't have a wallet [avoid seg for user with empty wallet]

            new_walletId.getMyStr()[new_walletId.size() -1] = '\0';  //remove '\n'
        }
        else{
            //trim the last btc myString to cut "\n" delimiter
            myString cutLastChar = btcList.getTail()->data;
            linkedList<char*> tmpList;
            split(cutLastChar.getMyStr() , const_cast<char *>("\n"), tmpList);
            btcList.updateTailData(cutLastChar);

        }

        //insert to wallet HashTable
        wallet wallet2insert(new_walletId,balance,btcList,amountList);
        myString key = new_walletId;
        walletHT_ptr.insert(key , wallet2insert);

        if (resultList.getSize() != 1) { //avoid to create btcTree for empty wallets
            // in case that the user has a wallet with coins
            //insert to btc HashTable
            for (auto item: wallet2insert.getBtcIdsOwned_list()) {
                //create a btcTree and add it to the new btc struct
                btc_tree *new_btcTreePtr = new btc_tree(new_walletId, bitCoinValue);
                bitcoin new_btc(item, new_btcTreePtr);
                btcHT_ptr.insert(new_btc.id, new_btc);

            }
        }

        resultList.clear();
    }



    fclose(fp);
    if (line)
        free(line);
}


