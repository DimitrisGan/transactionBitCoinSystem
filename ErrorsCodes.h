//
// Created by dimitrisgan on 28/2/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_ERRORSCODES_H
#define TRANSACTIONBITCOINSYSTEM_ERRORSCODES_H


typedef enum ERRORCODE { OK=0,
    UNKNOWN_CMDARGUMENT=1,  //unknown flag at cmd arguments
    AMOUNT_NOT_POSSIBLE_TO_DIVIDE_IN_BITCOINTREE ,
    NOT_VALID_TRSANSACTION,
    INSERTION,
    DELETION,
    NOT_VALID_DATE,
    NOT_VALID_TIME
//    FILE_ACCESS,  //couldnt open a file
//    BAD_STREAM,   //a fstream did not return goodbit
//    UNKNOWN_METRIC, //unknown metric in file @metric
//    MOD_ZERO_EXCEPTION, //tred to modulo 0
//    UNDEFINED_COSINE_ZERO_VECTOR, //cosine similarity for zero ve-
//    //ctor is poinless and undefined
//    //don't use it for data that has
//            BAD_CONFIG_FILE
} ERRORCODE;

#endif //TRANSACTIONBITCOINSYSTEM_ERRORSCODES_H
