//
// Created by dimitrisgan on 4/3/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_MYBUCKET_H
#define TRANSACTIONBITCOINSYSTEM_MYBUCKET_H


#include "mylinkedList.h"

template <typename T>
struct myBucket{
    T _data;

    explicit myBucket(T data) : _data(data) {}
    virtual ~myBucket() = default;
    void insert(T data);

    T get_data() const;

    void set_data(T _data);




    //todo overload == , =
    bool operator==(const myBucket &rhs) const;

    bool operator!=(const myBucket &rhs) const;

};




template <typename T>
struct myBucket_chain{
    linkedList<myBucket<T>> myBucketList;



    void insert(T data){
        //todo
        if (existInChain(data)){
            cout << "YPARXEI HDH !!!!!"<<endl;
            exit(10);
        }
        else{
            myBucket<T> newBucket(data);
            myBucketList.insert_last(newBucket);
        }
    }

    //todo to update ginetai apo tis alles domes

    bool existInChain(T data){
        for ( auto &item : myBucketList) {
            if (item == data){
                return true;
            }
        }
        return false;
    }

};


#include "myBucket.tpp"


#endif //TRANSACTIONBITCOINSYSTEM_MYBUCKET_H
