//
// Created by dimitrisgan on 5/3/2019.
//

#include "hashFunction.h"

unsigned myHash( myString id, unsigned  size_of_table) {
    unsigned hash = 5381 ;
    int c =0;

    char *str = new char[id.size() + 1];
    strcpy(str, id.getMyStr())   ;



    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return (hash % size_of_table);
}