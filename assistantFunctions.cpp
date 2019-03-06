//
// Created by dimitrisgan on 26/2/2019.
//

#include <cstring>
#include <fstream>
#include "assistantFunctions.h"
#include "ErrorsCodes.h"


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

        if (line[0] == '\n'){continue;}

        split(line, delim , resultList); /// push all char* tokens to the list

        myString walletId;
        int balance =0;
        linkedList<myString> btcList;
        linkedList<int> amountList;

        bool  isUserName= true;

        for ( auto tokenStr : resultList) {
            //convert token to myString
            myString token(tokenStr);

            if (isUserName){ //means that we have the user name (=walletId)
                walletId = token;
                isUserName = false;
            }
            else{ //is a btc id
                btcList.insert_last(token);
                amountList.insert_last(bitCoinValue);
                balance+= bitCoinValue;
            }

        }


            //trim the last btc myString to cut "\n" delimiter
            myString cutLastTime = btcList.getTail()->data;
            linkedList<char*> tmpList;
            split(cutLastTime.getMyStr() , const_cast<char *>("\n"), tmpList);
            btcList.updateTailData(cutLastTime);


//        btcList.updateTailData()
        wallet wallet2insert(walletId,balance,btcList,amountList);

        myString key = walletId;

        cout << "key = " <<key<<endl;

        walletHT_ptr.insert(key , wallet2insert);


        printf("Retrieved line of length %zu:\n", read);
        printf("%s", line);

    }



    fclose(fp);
    if (line)
        free(line);
}

//    ifstream inFile;
//    inFile.open(inCoinsFileName.getMyStr());
//    if (!inFile) {
//        cout << "Unable to open inCoinsFile\n";
//        //todo stderr unable to open input file ...
//        exit(1); // terminate with error
//    }
//
//    string line;
//
//    int index = 0; //line number
//    while (getline(inFile, line, '\n')) {
//        int column=0;
//
//// skip empty lines:
//        if (line.empty()) continue;
//
//        if (line[line.size() - 1] == '\r')
//            line.erase(line.size() - 1);
//
//
//    myfile.close();
//}
//
//
//fp = fopen("/etc/motd", "r");
//if (fp == NULL)
//exit(EXIT_FAILURE);
//
//while ((read = getline(&line, &len, fp)) != -1) {
//printf("Retrieved line of length %zu:\n", read);
//printf("%s", line);
//}
//
//fclose(fp);
//
//



void split( char* str, char* delimiter , linkedList<char*> & result2return) {

    char* token ;
//    linkedList<char*> result;

    token = strtok(str , delimiter);

    while (token!= nullptr){
        printf("'%s'\n", token);
        result2return.insert_last(token);
        token = strtok(nullptr, delimiter);

    }

}