//
// Created by dimitrisgan on 4/3/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_MYHASHTABLE_H
#define TRANSACTIONBITCOINSYSTEM_MYHASHTABLE_H


#include "myString.h"
#include "hashFunction.h"
#include "myBucket.h"





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

public://todo private:

    myBucket_chain<T> *table;

    unsigned  (*hashFunc)(const myString&, unsigned);
    unsigned tableSize;


    unsigned int getIndex(myString s) const {
        this->hashFunc(s, this->tableSize);
        return tableSize;
    }

public:

    myHashMap(unsigned tableSize ,unsigned (*hashF)(const myString&, unsigned )) {

        this->tableSize = tableSize;

        this->table = new myBucket_chain<T>  [tableSize] ;

        this->hashFunc = hashF;

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


    T* getData(myString key) {
        int indexHash = hashFunc(key,this->tableSize);

        return this->table[indexHash].getData(key);

    }

    bool exists (myString key){
        int indexHash = hashFunc(key,this->tableSize);
        return this->table[indexHash].exist(key);
    }


    void insert( myString key,T data2insert){

        int indexHash = hashFunc(key,this->tableSize);

        this->table[indexHash].insert(data2insert);
    }


};



#endif //TRANSACTIONBITCOINSYSTEM_MYHASHTABLE_H
