//
// Created by dimitrisgan on 4/3/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_MYHASHTABLE_H
#define TRANSACTIONBITCOINSYSTEM_MYHASHTABLE_H


#include "myString.h"
#include "hashFunction.h"





// https://www.quora.com/How-do-I-implement-a-hash-table-and-a-hash-map-in-C++

//template <typename K, typename V>

// T = recordsBucket type
/*
 * T : is the recordsBucket_chain type to choose
 * U : is the type of the recordsBucket
 * */
//template < typename T, /*type of bucketChain*/unsigned tableSize, typename F = KeyHash< /*key=*/myString, tableSize> >
template < typename T  >
class myHashMap {

private:

    T *table;
//    F hashFunc;

    unsigned  (*hashFunc)(myString, unsigned)  ;
    unsigned tableSize;

//    unsigned maxNumberOfRecordsInBucket;
//    unsigned tableSize;



public:

    myHashMap(unsigned tableSize ,unsigned (*hashF)( myString, unsigned)  ) {

        this->tableSize = tableSize;

        this->table = new T  [tableSize] ;

//        this->hashFunc = hashF;

    }



    ~myHashMap() {

        delete[] table;
        table = nullptr;
    }

    T *getTable() const {
        return table;
    }


    unsigned int getTableSize() const {
        return tableSize;
    }

    unsigned int getIndex(myString s) const {
        this->hashFunc(s, this->tableSize);
        return tableSize;
    }



//    void insertInTransacHT(myString key,transacNode transacNode2Insert ){
//
//        int indexHash = hashFunc(key);
//        if (table[indexHash] == nullptr) //if table[index] is null then we have to initialize a recordsBucket chain
//            table[indexHash] = new T ;
//
//        this->table[indexHash].insertNewRecord(transacNode2Insert);
//    }




//todo    void getTransacNodeByRef();

//    bool get(const K &key, V &value)
//    {
//        unsigned long hashValue = hashFunc(key);
//        HashNode<K, V> *entry = table[hashValue];
//
//        while (entry != NULL) {
//            if (entry->getKey() == key) {
//                value = entry->getValue();
//                return true;
//            }
//
//            entry = entry->getNext();
//        }
//
//        return false;
//    }
//
//    void put(int key, int value) {
//
//        int hash = (key % TableSize);
//
//        while (table[hash] != NULL && table[hash]->getKey() != key)
//
//            hash = (hash + 1) % TableSize;
//
//        if (table[hash] != NULL)
//
//            delete table[hash];
//
//        table[hash] = new HashEntry(key, value);
//
//    }


};



#endif //TRANSACTIONBITCOINSYSTEM_MYHASHTABLE_H
