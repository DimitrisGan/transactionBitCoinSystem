//
// Created by dimitrisgan on 4/3/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_MYHASHMAP_H
#define TRANSACTIONBITCOINSYSTEM_MYHASHMAP_H

#include "recordsBucket.h"
#include "hashFunction.h"



class myTransacHashMap {

public://todo change to --->private:

    recordsBucket_chain *table;

    unsigned  (*hashFunc)(const myString&, unsigned)  ;
    unsigned tableSize;


public:

    myTransacHashMap(unsigned tableSize ,unsigned (*hashF)(const myString&, unsigned)  ,unsigned bucketSizeInBytes) {

        this->tableSize = tableSize;

        table = new recordsBucket_chain  [tableSize] ;

        unsigned maxNumberOfRecordsInBucket = bucketSizeInBytes/sizeof(record);

        table->setMaxNumberOfRecordsInBucket(maxNumberOfRecordsInBucket);

        this->hashFunc = hashF;

    }


    ~myTransacHashMap() {
        if (table!= nullptr) {
            delete[] table;
            table = nullptr;
        }
    }


    unsigned int getTableSize() const {
        return tableSize;
    }

    unsigned int getIndex(const myString &s) const {
        return  this->hashFunc(s, this->tableSize);;
    }


    recordsBucket_chain getTableById(myString id) const ;

    void addTransacNode2appropriateIndex(myString walletId , transaction *transac2add);


    linkedList<transaction *> &getAllTransactions(const myString &walletId) {
        int index2table = this->getIndex(walletId);
        return this->table[index2table].getAllTransactions(walletId);
    }



};






#endif //TRANSACTIONBITCOINSYSTEM_MYHASHMAP_H
