//
// Created by dimitrisgan on 27/2/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_BUCKET_H
#define TRANSACTIONBITCOINSYSTEM_BUCKET_H


#include <assert.h>
#include "mylinkedList.h"
#include "myString.h"
#include "bitcoinTree.h"


int globo=0;
int globo2=0;

//template <class U ,class B>

//todo to transacNode list tha pairnei se template to sender walletId opote de xreiazetai sthn insert
//todo apo to walletID tha pairnw ta btcIds pou tha peiraksw mazi me to poso
//todo kai tha phgainw sto tree pou tha epistrefei deiktes pou tha tous xwnw
struct transacNode{
    myString WalletId; //in sender table is receiverWalletId

    //mporei na exoun dhmiourgithei parapanw apo ena nodes se diaforetika bitcoins trees
    linkedList<myString> bitcoinId;
    int amount;
    linkedList<t_node *> treeNode_ptr;


    transacNode& operator=( transacNode rhs)  {
        WalletId = rhs.WalletId ;
        bitcoinId = rhs.bitcoinId ;
        treeNode_ptr = rhs.treeNode_ptr;
        amount = rhs.amount;
        return *this;
    }



};

struct record{
    myString walletId;
    linkedList<transacNode> *transacLlist_ptr; //TODO//TODO//TODO//TODO//TODO//TODO//TODO//TODO


    record( myString walletId, linkedList<transacNode> *transacLlist_ptr) : walletId(walletId), transacLlist_ptr(transacLlist_ptr) {}

    record() {transacLlist_ptr = nullptr;}

    virtual ~record() {
        delete [] transacLlist_ptr;
        transacLlist_ptr = nullptr;
    }

    void insertTransacNodeInTransacList(transacNode transacNode2add){
        transacLlist_ptr->insert_last(transacNode2add);
    }
};

struct recordsBucket{

    unsigned recordsMaxCapacity{};
    unsigned recordsAlreadyExist{};
    record *recordTable;


    explicit recordsBucket(unsigned RecordsCapacity){
        cout << "CONSTRUCTOR OF BUCKET IS CALLED #"<<globo2++ <<endl;

        this->recordsMaxCapacity = RecordsCapacity;

        this->recordsAlreadyExist = 0;

        this->recordTable = new record [RecordsCapacity ]; //todo pay attention here

    }
    virtual ~recordsBucket(){
        //    delete  recordsArray;

        cout << "DESTRUCTOR OF BUCKET IS CALLED #"<<globo++ <<endl;
        this->recordsAlreadyExist=0;
        delete  [] recordTable;
        recordTable= nullptr;
    }
    recordsBucket& operator=(recordsBucket right)
    {

        this->recordTable = right.recordTable;
        this->recordsAlreadyExist= right.recordsAlreadyExist;
        this->recordsMaxCapacity= right.recordsMaxCapacity;
        return *this;
    }

    recordsBucket(recordsBucket &right)
    {
        recordTable = right.recordTable ;
        recordsAlreadyExist =right.recordsAlreadyExist;
        recordsMaxCapacity =right.recordsMaxCapacity;
    }

    bool recordExist(const myString &walletId){
        for (int i = 0; i < recordsAlreadyExist; ++i) {

            myString walletIdAlreadyExist = recordTable[i].walletId;
            if (walletIdAlreadyExist == walletId){
                return true;
            }
        }
        return false;
    }

    int  getIndex(const myString &walletId){
        int flagFound = -1;
        for (int i = 0; i < recordsAlreadyExist; ++i) {

            myString walletIdAlreadyExist = recordTable[i].walletId;
            if (walletIdAlreadyExist == walletId){
                break;
            }
        }
        assert(flagFound != -1);
        return  flagFound;

    }


    bool isFull(){
        return recordsAlreadyExist == recordsMaxCapacity;
    }

    bool recordIsEmpty(int index){
        return recordTable[index].transacLlist_ptr == nullptr;
    }


    void insertNewRecord(const myString &key , transacNode newNode){ //todo//todo//todo//todo//todo//todo//todo//todo

        //todo createRecord;
//        record<T> newRecord()
        if (recordsAlreadyExist < recordsMaxCapacity) { //space recordExist to insert record in this recordsBucket

            recordsAlreadyExist++;
            recordTable[recordsAlreadyExist].walletId = key;
            recordTable[recordsAlreadyExist].insertTransacNodeInTransacList(newNode);

        }
        else{ //no free space.Thus, we must insert an overflow recordsBucket

            assert(1); //tha prepei na exei upologistei ayto apo to recordsBucket_chain
        }
    }

};


template <unsigned bucketSizeInBytes>
struct recordsBucket_chain{
    linkedList<recordsBucket> bucketsList;
    unsigned maxNumberOfRecordsInBucket;

    explicit recordsBucket_chain()  {
        maxNumberOfRecordsInBucket = bucketSizeInBytes/sizeof(record);

    }

    virtual ~recordsBucket_chain() = default;

    bool recordExistInChain(const myString &key ) {
        for (const auto &bucket : bucketsList) { //todo tsekarw gia kathe bucket an uparxei
            if (bucket.recordExist(key)) {                //todo an uparxei tote ....
                return true;
            }
        }
        return false;
    }

    record* find (const myString &key){
        int index =-1;
        for (auto &bucket : bucketsList) {
            if (bucket.recordExist(key)){
                index =  bucket.getIndex(key);
                return & bucket.recordTable[index]; //todo & maybe wrong
            }
        }
        assert(1);
    }



    bool bucketChainIsFull(){
        for (auto &bucket : bucketsList) { //insert a new record
            if (bucket.isFull()){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }

    void insert(const myString &key ,transacNode newNode ){

        //todo tsekarw gia kathe bucket an uparxei
        //todo an uparxei tote ....

        if (recordExistInChain(key)){ //if exists

            record* record2add = find(key);
            //todo add in it a transaction node in transList //todo//todo//todo//todo//todo//todo//todo//todo//todo//todo//todo//todo
            record2add->insertTransacNodeInTransacList(newNode);
        }
        else{
            //todo check for empty space
            //todo if not ftiakse overflow bucket kai kanw insert to recors sto kainourgio bucket
            if (! bucketChainIsFull()) { //insert a new record

                for (const auto &bucket : this->bucketsList) {
                    if(!bucket.isFull()){
                        bucket.insertNewRecord(key,newNode);
                    }
                }
            }
            else    //insert a new overflow bucket because there is no free-space and then the record
            {
                recordsBucket newBucket(maxNumberOfRecordsInBucket);
                newBucket.insertNewRecord(key,newNode);
                this->bucketsList.insert_last(newBucket);
            }

        }

    }



    //todo insertRecord2bucket(recordsBucket );
};









#endif //TRANSACTIONBITCOINSYSTEM_BUCKET_H
