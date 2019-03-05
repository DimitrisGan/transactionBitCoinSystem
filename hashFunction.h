//
// Created by dimitrisgan on 27/2/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_HASHFUNCTION_H
#define TRANSACTIONBITCOINSYSTEM_HASHFUNCTION_H


#include <cstring>
#include "myString.h"

unsigned myHash( myString id, unsigned  size_of_table) {
    unsigned hash = 5381 ;
    int c =0;

    char *str = new char[id.size() + 1];
    strcpy(str, id.getMyStr())   ;



    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return (hash % size_of_table);
}
////=========================================================




//unsigned hash(char *str, long int size_of_table) {
//    unsigned hash = 5381 ;
//    int c;
//
//    while ((c = *str++))
//        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
//
//    return hash % size_of_table;
//}




#endif //TRANSACTIONBITCOINSYSTEM_HASHFUNCTION_H
