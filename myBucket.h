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

//    friend ostream &operator<<(ostream &os,  myBucket<T> bucket);


    //todo overload == , =
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
        //todo
        if (existInChain(data)){
            cout << "YPARXEI HDH !!!!!"<<endl;
            exit(100);
        }
        else{
            myBucket<T> newBucket(data);
            myBucketList.insert_last(newBucket);
            size++;
        }
    }

    //todo to update ginetai apo tis alles domes

    bool existInChain(T &data){
        for ( auto &item : myBucketList) {
            if (item == data){
                return true;
            }
        }
        return false;
    }

    friend ostream &operator<<(ostream &os, const myBucket_chain &chain) {
        os << "myBucketList: " << chain.myBucketList;
        return os;
    }
};


#include "myBucket.tpp"


#endif //TRANSACTIONBITCOINSYSTEM_MYBUCKET_H
