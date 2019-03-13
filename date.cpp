//
// Created by dimitrisgan on 6/3/2019.
//

#include "date.h"
#include "assistantFunctions.h"



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
            case 0: this->day    =  item;break;
            case 1: this->month  =  item;break;
            case 2: this->year   =  item;break;
            case 3: this->hour   =  item;break;
            case 4: this->minute =  item;break;
            default: exit(EXIT_FAILURE);
                //execution of subsequent statements is terminated
        }

        i++;
    }
}

void date::setDateByGivenList(linkedList<char *> setDateList) {

    int i=0;
    int j=0;
    for (auto& item1 : setDateList){

        linkedList<char*> formatList;
        if (i==0)
            split(item1, "-" , formatList); /// separate all string commands by "-" and push them to the llist
        else
            split(item1, ":" , formatList); /// separate all string commands by ":" and push them to the llist

        for ( auto &item2 : formatList) {
            int itemInt = atoi(item2);
            switch (j) {
                case 0: this->day     =   itemInt;break;
                case 1: this->month   =   itemInt;break;
                case 2: this->year    =   itemInt;break;
                case 3: this->hour    =   itemInt;break;
                case 4: this->minute  =   itemInt;break;
                default: exit(EXIT_FAILURE);
                    //execution of subsequent statements is terminated
            }
            j++;
        }
        i++;
    }

}

// Store the formatted string of time in the output
void date::timeNow(){
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );


    this->year = timeinfo->tm_year + 1900;
    this->month = timeinfo->tm_mon + 1;
    this->day = timeinfo->tm_mday ;
    this->hour = timeinfo->tm_hour;
    this->minute = timeinfo->tm_min;

    this->hasDate = true;
    this->hasTime = true;

}

void date::setDate(char * setDate) {
    linkedList<char*> formatList;
    split(setDate, "-" , formatList); /// separate all string commands by "-" and push them to the llist

    if (formatList.getSize()!=3){std::cerr << "DATE : "<<setDate<< " NOT VALID"<<endl;exit(NOT_VALID_DATE);}

    linkedList<char*>::Iterator iter;
    iter = formatList.begin();

    if (!isNumber(*iter)){std::cerr << "DATE : "<<setDate<< " NOT VALID"<<endl;exit(NOT_VALID_DATE);}
    this->year =  atoi(*iter);

    iter++;
    if (!isNumber(*iter)){std::cerr << "DATE : "<<setDate<< " NOT VALID"<<endl;exit(NOT_VALID_DATE);}
    this->month = atoi(*iter);

    iter++;
    if (!isNumber(*iter)){std::cerr << "DATE : "<<setDate<< " NOT VALID"<<endl;exit(NOT_VALID_DATE);}
    this->day = atoi(*iter);

    this->hasDate=true;

}

void date::setTime(char *setTime) {
    linkedList<char*> formatList;
    split(setTime, ":" , formatList); /// separate all string commands by "-" and push them to the llist

    if (formatList.getSize()!=2){std::cerr << "TIME : "<<setTime<< " NOT VALID"<<endl;exit(NOT_VALID_TIME);}

    linkedList<char*>::Iterator iter;
    iter = formatList.begin();

    if (!isNumber(*iter)){std::cerr << "TIME : "<<setTime<< " NOT VALID"<<endl;exit(NOT_VALID_TIME);}
    this->hour =  atoi(*iter);

    iter++;
    if (!isNumber(*iter)){std::cerr << "TIME : "<<setTime<< " NOT VALID"<<endl;exit(NOT_VALID_TIME);}
    this->minute = atoi(*iter);


    this->hasTime=true;

}




