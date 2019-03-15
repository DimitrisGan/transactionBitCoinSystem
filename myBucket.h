//
// Created by dimitrisgan on 4/3/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_MYBUCKET_H
#define TRANSACTIONBITCOINSYSTEM_MYBUCKET_H


#include <ostream>
#include <assert.h>
#include "mylinkedList.h"
#include "myString.h"
#include "wallet.h"

template <typename T>
struct myBucket{
    T _data;

    explicit myBucket(T &data) : _data(data) {}
    virtual ~myBucket() = default;
    void insert(T data);

    T* get_data() ;

    void set_data(T _data);


    bool operator==(T &data) ;
    bool operator==(myString &id) ;

    bool operator!=(T &data) ;
    bool operator!=(myString &id) ;

};




template <typename T>
struct myBucket_chain{
    linkedList<myBucket<T>> myBucketList;
    int size;

    myBucket_chain() {size =0;}

    T* getData(myString key)  {


        for (  auto &dataNode : myBucketList) { //dataNode : myBucket<T>
            if (dataNode == key){

                return dataNode.get_data();
            }

        }
        assert(1);//means that we didnt found the data that we were expecting
    }


    void insert(T data){

        if (existInChain(data)){
            std::cerr << "ERROR IN INSERTION --ITEM ALREADY EXIST [HINT:CHECK EQUAL ID'S]"<<endl;
            exit(INSERTION);
        }
        else{
            myBucket<T> newBucket(data);
            myBucketList.insert_last(newBucket);
            size++;
        }
    }


    bool existInChain(T &data){
        for ( auto &item : myBucketList) {
            if (item == data){
                return true;
            }
        }
        return false;
    }

    bool exist(myString key){
        for ( auto &item : myBucketList) {
            if (item == key){
                return true;
            }
        }
        return false;
    }


   
};


#include "myBucket.tpp"


#endif //TRANSACTIONBITCOINSYSTEM_MYBUCKET_H
