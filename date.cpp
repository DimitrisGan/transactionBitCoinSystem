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
