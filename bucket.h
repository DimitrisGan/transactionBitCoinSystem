//
// Created by dimitrisgan on 27/2/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_BUCKET_H
#define TRANSACTIONBITCOINSYSTEM_BUCKET_H


#include "mylinkedList.h"
#include "myString.h"
#include "bitcoinTree.h"


int globo=0;
int globo2=0;

//template <class U ,class B>

//todo to transactionNode list tha pairnei se template to sender walletId opote de xreiazetai sthn insert
//todo apo to walletID tha pairnw ta btcIds pou tha peiraksw mazi me to poso
//todo kai tha phgainw sto tree pou tha epistrefei deiktes pou tha tous xwnw
struct transactionNode{
    myString WalletId; //in sender table is receiverWalletId

    //mporei na exoun dhmiourgithei parapanw apo ena nodes se diaforetika bitcoins trees
    linkedList<myString> bitcoinId;
    linkedList<t_node *> treeNode_ptr;

    transactionNode(myString WalletId ) : WalletId(WalletId) {

        //todo apo hashing sto senderId pairnw to wallet kai ara ta btc pou exei
        //todo mazeuw to poso pou thelei ara kai ta btc's
        //todo apo hashing  sta btc pairnw ta btcTree
        //todo kanw pollapla (an xreiazetai) insert sto/a dentro/a
        //todo mou epistrefontai oi deiktes sta t-nodes kai tous xwnw
    }

    void insertUinList(){
        //todo createTreeNode(& to pointer that returns a list with created t_nodes)
        //todo take the pointer
    }
};

struct record{
    myString walletId;
    linkedList<transactionNode> *ptr2transactionLlist; //TODO//TODO//TODO//TODO//TODO//TODO//TODO//TODO
};

struct bucket{

    unsigned recordsMaxCapacity{};
    unsigned recordsAlreadyExist{};
    record *recordTable;


    explicit bucket(unsigned RecordsCapacity){
        cout << "CONSTRUCTOR OF BUCKET IS CALLED #"<<globo2++ <<endl;

        this->recordsMaxCapacity = RecordsCapacity;

        this->recordsAlreadyExist = 0;

        this->recordTable = new record [RecordsCapacity ];

    }
    virtual ~bucket(){
        //    delete  recordsArray;

        cout << "DESTRUCTOR OF BUCKET IS CALLED #"<<globo++ <<endl;
        this->recordsAlreadyExist=0;
        delete  [] recordTable;
        recordTable= nullptr;
    }
    bucket& operator=(bucket right)
    {

        this->recordTable = right.recordTable;
        this->recordsAlreadyExist= right.recordsAlreadyExist;
        this->recordsMaxCapacity= right.recordsMaxCapacity;
        return *this;
    }

    bucket(bucket &right)
    {
        recordTable = right.recordTable ;
        recordsAlreadyExist =right.recordsAlreadyExist;
        recordsMaxCapacity =right.recordsMaxCapacity;
    }



    void insertNewRecord(myString key){

        //todo createRecord;
//        record<T> newRecord()
        if (recordsAlreadyExist < recordsMaxCapacity) { //space exist to insert record in this bucket

            recordsAlreadyExist++;
//            recordTable[recordsAlreadyExist] = key;

        }
        else{ //no free space.Thus, we must insert an overflow bucket


        }
    }

};

template <unsigned bucketSizeInBytes>

struct bucket_chain{
    linkedList<bucket> bucketsList;
    unsigned maxNumberOfRecordsInBucket;

    explicit bucket_chain()  {
        maxNumberOfRecordsInBucket = bucketSizeInBytes/sizeof(record);

    }

    virtual ~bucket_chain() = default;


    void insertRecordInChain(myString key){

//        createRecord(walletId2insert);


        for (const auto &bucket : bucketsList) {
            if (bucket.recordsAlreadyExist < maxNumberOfRecordsInBucket ) {
//                bucket.insertNewRecord(record<T> record2insert)
                break;
            }
        }
    }



    void insertOverflowBucket(){
        this->bucketsList.insert_last(new bucket (maxNumberOfRecordsInBucket) ); //todo edw mporei lathos
    }


    //todo insertRecord2bucket(bucket );
};









#endif //TRANSACTIONBITCOINSYSTEM_BUCKET_H
