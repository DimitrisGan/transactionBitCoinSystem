//
// Created by dimitrisgan on 27/2/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_BUCKET_H
#define TRANSACTIONBITCOINSYSTEM_BUCKET_H


#include <assert.h>
#include "mylinkedList.h"
#include "myString.h"
#include "bitcoinTree.h"
#include "date.h"
#include "transaction.h"


//int globo=0;
//int globo2=0;



struct record{
    myString walletId;
    linkedList<transaction*> *transacLlist_ptr; //TODO//TODO//TODO//TODO//TODO//TODO//TODO//TODO


//    record( myString receiverWalletId) : receiverWalletId(receiverWalletId) {
//        transacLlist_ptr = new linkedList<transaction> ;
//    }

    record() {transacLlist_ptr = nullptr;transacLlist_ptr = new linkedList<transaction*> ;}

    virtual ~record() {
        delete  transacLlist_ptr;
        transacLlist_ptr = nullptr;
    }


    record& operator=(record right)
    {

        this->walletId = right.walletId;   //todo AYTA TA 2 EINIA LATHOS//todo AYTA TA 2 EINIA LATHOS//todo AYTA TA 2 EINIA LATHOS//todo AYTA TA 2 EINIA LATHOS//todo AYTA TA 2 EINIA LATHOS
        this->transacLlist_ptr = right.transacLlist_ptr;
        return *this;
    }

    record(record &right)
    {
        this->walletId = right.walletId;   //todo AYTA TA 2 EINIA LATHOS//todo AYTA TA 2 EINIA LATHOS//todo AYTA TA 2 EINIA LATHOS//todo AYTA TA 2 EINIA LATHOS//todo AYTA TA 2 EINIA LATHOS
        this->transacLlist_ptr = right.transacLlist_ptr;
    }



    void insertTransacNodeInTransacList(transaction *transacNode2add){
        transacLlist_ptr->insert_last(transacNode2add);
    }
};

struct recordsBucket{

    unsigned recordsMaxCapacity{};
    unsigned recordsAlreadyExist{};
    record *recordTable;


    explicit recordsBucket(unsigned RecordsCapacity){
        cout << "CONSTRUCTOR OF BUCKET IS CALLED #" <<endl;

        this->recordsMaxCapacity = RecordsCapacity;

        this->recordsAlreadyExist = 0;

        this->recordTable = new record [RecordsCapacity ]; //todo pay attention here

    }
    virtual ~recordsBucket(){
        //    delete  recordsArray;

        cout << "DESTRUCTOR OF BUCKET RECORD TABLE IS CALLED #" <<endl;
//        this->recordsAlreadyExist=0;
        delete  [] recordTable; //todo des ksana//todo des ksana//todo des ksana//todo des ksana//todo des ksana//todo des ksana//todo des ksana//todo des ksana
        recordTable= nullptr;
    }

    recordsBucket& operator=(recordsBucket right)
    {

        for (int i = 0; i < this->recordsMaxCapacity ; ++i) {
            this->recordTable[i] = right.recordTable[i];
        }   //todo AYTA TA 2 EINIA LATHOS//todo AYTA TA 2 EINIA LATHOS//todo AYTA TA 2 EINIA LATHOS//todo AYTA TA 2 EINIA LATHOS//todo AYTA TA 2 EINIA LATHOS
        right.recordTable= nullptr;
        this->recordsAlreadyExist= right.recordsAlreadyExist;
        this->recordsMaxCapacity= right.recordsMaxCapacity;
        return *this;
    }

    recordsBucket(recordsBucket &right)
    {
        for (int i = 0; i < this->recordsMaxCapacity ; ++i) {
            this->recordTable[i] = right.recordTable[i];
        }
        right.recordTable= nullptr;  //todo edw to kanw null gia na mhn koitaei //todo edw to kanw null gia na mhn koitaei //todo edw to kanw null gia na mhn koitaei //todo edw to kanw null gia na mhn koitaei

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


    void insertNewRecord( myString key , transaction *newNode){ //todo//todo//todo//todo//todo//todo//todo//todo

        //todo createRecord;
//        record<T> newRecord()
        if (recordsAlreadyExist < recordsMaxCapacity) { //space recordExist to insert record in this recordsBucket

            recordsAlreadyExist++;
            recordTable[recordsAlreadyExist-1].walletId = key;  //starts from zero 0
            recordTable[recordsAlreadyExist-1].insertTransacNodeInTransacList(newNode); //recordTable[recordsAlreadyExist-1].transacLlist_ptr.insert_last(newNode)

        }
        else{ //no free space.Thus, we must insert an overflow recordsBucket

            assert(1); //tha prepei na exei upologistei ayto apo to recordsBucket_chain
        }
    }

};


//template <unsigned bucketSizeInBytes>
struct recordsBucket_chain{
    linkedList<recordsBucket> bucketsList;
    unsigned maxNumberOfRecordsInBucket;

//    explicit recordsBucket_chain(unsigned bucketSizeInBytes)  {
//        maxNumberOfRecordsInBucket = bucketSizeInBytes/sizeof(record);
//
//    }

    const linkedList<recordsBucket> &getBucketsList() const {
        return bucketsList;
    }

    void setMaxNumberOfRecordsInBucket(unsigned int maxNumberOfRecordsInBucket) {
        recordsBucket_chain::maxNumberOfRecordsInBucket = maxNumberOfRecordsInBucket;
    }

    virtual ~recordsBucket_chain() = default;

    bool recordExistInChain( myString key ) {
        for ( auto &bucket : bucketsList) { //todo tsekarw gia kathe bucket an uparxei
            if (bucket.recordExist(key)) {                //todo an uparxei tote ....
                return true;
            }
        }
        return false;
    }

    record* find ( myString &key){
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
            if (! bucket.isFull()) //bucket has free-space -->thus also bucketChain has space
                return false;
        }
        return true;
    }

    void insert( myString key ,transaction *newNode ){

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

                for ( auto &bucket : this->bucketsList) {
                    if(!bucket.isFull()){
                        bucket.insertNewRecord(key,newNode);
                    }
                }
            }
            else    //insert a new overflow bucket because there is no free-space and then the record
            {

                recordsBucket  newBucket(maxNumberOfRecordsInBucket);
                newBucket.insertNewRecord(key,newNode);
                this->bucketsList.insert_last(newBucket);
            }

        }

    }



    //todo insertRecord2bucket(recordsBucket );
};









#endif //TRANSACTIONBITCOINSYSTEM_BUCKET_H
