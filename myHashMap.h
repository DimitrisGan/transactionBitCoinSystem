//
// Created by dimitrisgan on 4/3/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_MYHASHTABLE_H
#define TRANSACTIONBITCOINSYSTEM_MYHASHTABLE_H



#include "recordsBucket.h"

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

// T = recordsBucket type
/*
 * T : is the recordsBucket_chain type to choose
 * U : is the type of the recordsBucket
 * */
template < typename T, /*type of bucketChain*/unsigned tableSize, typename F = KeyHash< /*key=*/myString, tableSize> >
class myHashMap {

private:

    T *table;
    F hashFunc;

//    unsigned maxNumberOfRecordsInBucket;
//    unsigned tableSize;

public:

    myHashMap() {


        table = new T  [tableSize] ;

//        for (int i = 0; i < tableSize; i++)
//            table[i] = nullptr; //todo maybe initialize the pointer
    }

    ~myHashMap() {

        for (int i = 0; i < tableSize; i++)

//            if (table[i] != nullptr)
//
//                delete table[i];

        delete[] table;

    }

    T *getTable() const {
        return table;
    }

    F getHashFunc() const {
        return hashFunc;
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
