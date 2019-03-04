//
// Created by dimitrisgan on 4/3/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_MYHASHMAP_H
#define TRANSACTIONBITCOINSYSTEM_MYHASHMAP_H


#include "transacBucket.h"

unsigned hashFunction(char *str, int size_of_table);



// https://www.quora.com/How-do-I-implement-a-hash-table-and-a-hash-map-in-C++

struct MyKeyHash {
    unsigned long operator()(const int& k) const
    {
        return k % 10;
    }
};


// Default hash function class
template <typename K, unsigned tableSize>
struct KeyHash {
    unsigned long operator()(const K &key) const
    {
        return reinterpret_cast<unsigned long>(key) % tableSize;
    }
};



//template <typename K, typename V>

// T = transacBucket type
/*
 * T : is the transacBucket_chain type to choose
 * U : is the type of the transacBucket
 * */
template < unsigned tableSize,unsigned bucketSizeInBytes, typename F = KeyHash< /*key=*/myString, tableSize> >
class transactionHashMap {

private:

    transacBucket_chain<bucketSizeInBytes> *table;
    F hashFunc;

//    unsigned maxNumberOfRecordsInBucket;
//    unsigned tableSize;

public:

    transactionHashMap(unsigned bucketSize) {


        table = new transacBucket_chain< bucketSizeInBytes>  [tableSize] ;

        for (int i = 0; i < tableSize; i++)
            table[i] = nullptr; //todo maybe initialize the pointer
    }

    ~transactionHashMap() {

        for (int i = 0; i < tableSize; i++)

            if (table[i] != nullptr)

                delete table[i];

        delete[] table;

    }

    void insertInTransacHT(myString key,transactionNode transacNode2Insert ){

        int indexHash = hashFunc(key);
        if (table[indexHash] == nullptr) //if table[index] is null then we have to initialize a transacBucket chain
            table[indexHash] = new transacBucket_chain<bucketSizeInBytes> ;

        this->table[indexHash].insertNodeInChain(transacNode2Insert);
    }




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



#endif //TRANSACTIONBITCOINSYSTEM_MYHASHMAP_H
