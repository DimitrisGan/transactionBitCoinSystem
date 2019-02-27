//
// Created by dimitrisgan on 26/2/2019.
//

#include "myHashTable.h"



unsigned hashFunction(char *str, int size_of_table) {
    unsigned hash = 5381 ;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % size_of_table;
}
