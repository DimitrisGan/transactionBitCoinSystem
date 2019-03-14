//
// Created by dimitrisgan on 6/3/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_DATE_H
#define TRANSACTIONBITCOINSYSTEM_DATE_H


#include <ostream>
#include "mylinkedList.h"
#include "myString.h"

struct date{

    int year;
    int month;
    int day;
    int hour;
    int minute;

    bool hasDate;
    bool hasTime;

    date(){year=month=day=hour=minute=-1;hasDate= false;hasTime=false;}

    void setDateByGivenList(linkedList<int> setDateList);

    void setDateByGivenList(linkedList<char*> setDateList);

    void timeNow();

    void setDate(myString setDate);
    void setTime(myString setTime);


    bool operator<(const date &rhs) const;

    bool operator>(const date &rhs) const;

    bool operator<=(const date &rhs) const;

    bool operator>=(const date &rhs) const;

    bool operator==(const date &rhs) const;

    bool operator!=(const date &rhs) const;


    friend ostream &operator<<(ostream &os, const date &date1);

};

#endif //TRANSACTIONBITCOINSYSTEM_DATE_H
