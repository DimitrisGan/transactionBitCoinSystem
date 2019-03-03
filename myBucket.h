//
// Created by dimitrisgan on 3/3/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_MYBUCKET_H
#define TRANSACTIONBITCOINSYSTEM_MYBUCKET_H


#include "mylinkedList.h"



template <typename T>
struct myBucket{
    T data;

    explicit myBucket(T data) : data(data) {}
    virtual ~myBucket() = default;
    virtual void insert(T data) = default;

};

template <typename T>
struct btcBucket : public  myBucket<T>{
    void insert(T data);
};


template <typename T ,typename H>
struct walletBucket : public  myBucket<T>{
    void insert(T data);
};


template <typename T>
struct myBucket_chain{
    linkedList<myBucket<T>> myBucketList;

};


#include "myBucket.tpp"

#endif //TRANSACTIONBITCOINSYSTEM_MYBUCKET_H
