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

    bool hasDate;
    bool hasTime;

    date(){hasDate= false;hasTime=false;}

    void setDateByGivenList(linkedList<int> setDateList);

    void setDateByGivenList(linkedList<char*> setDateList);

    void timeNow();

    void setDate(char* setDate);
    void setTime(char* setTime);


    bool operator<(const date &rhs) const;

    bool operator>(const date &rhs) const;

    bool operator<=(const date &rhs) const;

    bool operator>=(const date &rhs) const;



};

#endif //TRANSACTIONBITCOINSYSTEM_DATE_H
