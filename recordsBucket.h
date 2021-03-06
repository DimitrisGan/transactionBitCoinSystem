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




struct record{
    myString walletId;
    linkedList<transaction*> transacLlist_ptr;


    linkedList<transaction *> &getTransacLlist_ptr()  {
        return transacLlist_ptr;
    }


    record() = default;

    virtual ~record() {
//        delete  transacLlist_ptr;
//        transacLlist_ptr = nullptr;
//        transacLlist_ptr->clear();
//        delete transacLlist_ptr;
//        transacLlist_ptr= nullptr;
    }


    record& operator=(record right)
    {

        this->walletId = right.walletId;
        this->transacLlist_ptr = right.transacLlist_ptr;
        return *this;
    }

    record(record &right)
    {
        this->walletId = right.walletId;
        this->transacLlist_ptr = right.transacLlist_ptr;
    }


    void insertTransacNodeInTransacList(transaction *transacNode2add){
        transacLlist_ptr.insert_last(transacNode2add);
    }
};

struct recordsBucket{

    unsigned recordsMaxCapacity{};
    unsigned recordsAlreadyExist{};
    record *recordTable;


    linkedList<transaction *> &getAllTransactions(const myString &walletId) {
        int recordIndex = this->getIndex(walletId);
        return recordTable[recordIndex].getTransacLlist_ptr();
    }

    explicit recordsBucket(unsigned RecordsCapacity){

        this->recordsMaxCapacity = RecordsCapacity;

        this->recordsAlreadyExist = 0;

        this->recordTable = new record [RecordsCapacity ];

    }
    virtual ~recordsBucket(){

        delete  [] recordTable;

        recordTable= nullptr;
    }

    recordsBucket& operator=(recordsBucket right)
    {

        for (int i = 0; i < right.recordsAlreadyExist ; ++i) {
            this->recordTable[i] = right.recordTable[i];
        }
//        right.recordTable= nullptr;
        this->recordsAlreadyExist= right.recordsAlreadyExist;
        this->recordsMaxCapacity= right.recordsMaxCapacity;
        return *this;
    }

    recordsBucket(recordsBucket &right)
    {
        this->recordTable = new record [right.recordsMaxCapacity ];
        recordsAlreadyExist =right.recordsAlreadyExist;
        recordsMaxCapacity =right.recordsMaxCapacity;

        for (int i = 0; i < right.recordsAlreadyExist; ++i) {
            this->recordTable[i] = right.recordTable[i];
        }
//        right.recordTable= nullptr;


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

    int  getIndex(const myString &walletId) const{
        int flagFound = -1;
        int index=0;
        for (int i = 0; i < recordsAlreadyExist; ++i) {

            myString walletIdAlreadyExist = recordTable[i].walletId;
            if (walletIdAlreadyExist == walletId){
                return index;
            }
            index++;
        }
        assert(flagFound != -1);
        return  flagFound;

    }


    bool isFull(){
        return recordsAlreadyExist == recordsMaxCapacity;
    }

    bool recordIsEmpty(int index){
        return recordTable[index].transacLlist_ptr.isEmpty();
    }


    void insertNewRecord( myString key , transaction *newNode){


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

    recordsBucket_chain(){maxNumberOfRecordsInBucket=0;}

    linkedList<transaction *> &getAllTransactions(const myString &walletId) {
        record* record2retrieve = find(walletId);
        return record2retrieve->getTransacLlist_ptr();
    }

    const linkedList<recordsBucket> &getBucketsList() const {
        return bucketsList;
    }

    void setMaxNumberOfRecordsInBucket(unsigned int maxNumberOfRecordsInBucket) {
        recordsBucket_chain::maxNumberOfRecordsInBucket = maxNumberOfRecordsInBucket;
    }

    virtual ~recordsBucket_chain() = default;

    bool recordExistInChain( myString key ) {

        for ( auto &bucket : bucketsList) {
            if (bucket.recordExist(key)) {
                return true;
            }
        }
        return false;
    }

    record* find ( const myString &key){
        int index =-1;
        for (auto &bucket : bucketsList) {
            if (bucket.recordExist(key)){
                index =  bucket.getIndex(key);
                return & bucket.recordTable[index];
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

    bool bucketChainIsEmpty(){
        return this->bucketsList.isEmpty();
    }

    void insert( myString key ,transaction *newNode ){

        if (bucketChainIsEmpty()){
            recordsBucket  newBucket(maxNumberOfRecordsInBucket);
            newBucket.insertNewRecord(key,newNode);
            this->bucketsList.insert_last(newBucket);
            return;
        }

        if (recordExistInChain(key)){
            record* record2add = find(key);
            record2add->insertTransacNodeInTransacList(newNode);
        }

        else{ //we have to write new record

            //check for empty space
            if (! bucketChainIsFull()) { //insert a new record

                for ( auto &bucket : this->bucketsList) {
                    if(!bucket.isFull()){
                        bucket.insertNewRecord(key,newNode);
                    }
                }
            } //if not insert an overflow bucket & insert the record
            else    //insert a new overflow bucket because there is no free-space and then the record
            {

                recordsBucket  newBucket(maxNumberOfRecordsInBucket);
                newBucket.insertNewRecord(key,newNode);
                this->bucketsList.insert_last(newBucket);
            }
        }
    }


};






#endif //TRANSACTIONBITCOINSYSTEM_BUCKET_H
