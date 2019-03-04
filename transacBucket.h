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
    int amount;
    linkedList<t_node *> treeNode_ptr;


     transactionNode& operator=( transactionNode rhs)  {
        WalletId = rhs.WalletId ;
        bitcoinId = rhs.bitcoinId ;
        treeNode_ptr = rhs.treeNode_ptr;
        amount = rhs.amount;
        return *this;
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

struct transacBucket{

    unsigned recordsMaxCapacity{};
    unsigned recordsAlreadyExist{};
    record *recordTable;


    explicit transacBucket(unsigned RecordsCapacity){
        cout << "CONSTRUCTOR OF BUCKET IS CALLED #"<<globo2++ <<endl;

        this->recordsMaxCapacity = RecordsCapacity;

        this->recordsAlreadyExist = 0;

        this->recordTable = new record [RecordsCapacity ];

    }
    virtual ~transacBucket(){
        //    delete  recordsArray;

        cout << "DESTRUCTOR OF BUCKET IS CALLED #"<<globo++ <<endl;
        this->recordsAlreadyExist=0;
        delete  [] recordTable;
        recordTable= nullptr;
    }
    transacBucket& operator=(transacBucket right)
    {

        this->recordTable = right.recordTable;
        this->recordsAlreadyExist= right.recordsAlreadyExist;
        this->recordsMaxCapacity= right.recordsMaxCapacity;
        return *this;
    }

    transacBucket(transacBucket &right)
    {
        recordTable = right.recordTable ;
        recordsAlreadyExist =right.recordsAlreadyExist;
        recordsMaxCapacity =right.recordsMaxCapacity;
    }



    void insertNewRecord(myString key){

        //todo createRecord;
//        record<T> newRecord()
        if (recordsAlreadyExist < recordsMaxCapacity) { //space exist to insert record in this transacBucket

            recordsAlreadyExist++;
//            recordTable[recordsAlreadyExist] = key;

        }
        else{ //no free space.Thus, we must insert an overflow transacBucket


        }
    }

};


template <unsigned bucketSizeInBytes>
struct transacBucket_chain{
    linkedList<transacBucket> bucketsList;
    unsigned maxNumberOfRecordsInBucket;

    explicit transacBucket_chain()  {
        maxNumberOfRecordsInBucket = bucketSizeInBytes/sizeof(record);

    }

    virtual ~transacBucket_chain() = default;


    void insertNodeInChain(transacBucket_chain node){

//        createRecord(walletId2insert);


        for (const auto &bucket : bucketsList) {
            if (bucket.recordsAlreadyExist < maxNumberOfRecordsInBucket ) {
//                transacBucket.insertNewRecord(record<T> record2insert)
                break;
            }
        }
    }



    void insertOverflowBucket(){
        this->bucketsList.insert_last(new transacBucket (maxNumberOfRecordsInBucket) ); //todo edw mporei lathos
    }


    //todo insertRecord2bucket(transacBucket );
};









#endif //TRANSACTIONBITCOINSYSTEM_BUCKET_H
