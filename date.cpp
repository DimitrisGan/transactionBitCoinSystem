//
// Created by dimitrisgan on 6/3/2019.
//

#include "date.h"



//todo

bool date::operator<(const date &rhs) const {
    if (year < rhs.year)
        return true;
    if (rhs.year < year)
        return false;
    if (month < rhs.month)
        return true;
    if (rhs.month < month)
        return false;
    if (day < rhs.day)
        return true;
    if (rhs.day < day)
        return false;
    if (hour < rhs.hour)
        return true;
    if (rhs.hour < hour)
        return false;
    return minute < rhs.minute;
}

bool date::operator>(const date &rhs) const {
    return rhs < *this;
}

bool date::operator<=(const date &rhs) const {
    return !(rhs < *this);
}

bool date::operator>=(const date &rhs) const {
    return !(*this < rhs);
}

void date::setDateByGivenList(linkedList<int> setDateList) {

    int i=0;
    for ( auto &item : setDateList) {
        switch (i) {
            case 0: this->day = item;break;
            case 1: this->month = item;break;
            case 2: this->year = item;break;
            case 3: this->hour = item;break;
            case 4: this->minute = item;break;
            default: exit(EXIT_FAILURE);
                //execution of subsequent statements is terminated
        }

        i++;
    }
}
