//
// Created by dimitrisgan on 6/3/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_DATE_H
#define TRANSACTIONBITCOINSYSTEM_DATE_H


#include "mylinkedList.h"

struct date{

    int year;
    int month;
    int day;
    int hour;
    int minute;


    void setDateByGivenList(linkedList<int> setDateList);

    bool operator<(const date &rhs) const;

    bool operator>(const date &rhs) const;

    bool operator<=(const date &rhs) const;

    bool operator>=(const date &rhs) const;

};

#endif //TRANSACTIONBITCOINSYSTEM_DATE_H
