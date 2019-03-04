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
};




template <typename T>
struct myBucket_chain{
    linkedList<myBucket<T>> myBucketList;

};


#include "myBucket.tpp"


#endif //TRANSACTIONBITCOINSYSTEM_MYBUCKET_H
