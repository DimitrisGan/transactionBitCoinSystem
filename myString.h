//
// Created by dimitrisgan on 26/2/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_MYSTRING_H
#define TRANSACTIONBITCOINSYSTEM_MYSTRING_H



class myString{
private:
    char* myStr;
public:
    //todo myString(); na kskekinaei me char* opote na mh desmeuei epipleon xwro
    explicit myString(char *sptr);
    myString(myString &right); //move operator maybe not needed because of not existing simple constructor

    virtual ~myString();

    char *getMyStr() const;
    unsigned size();
//    void myString::makeOneToken(char delimeter);
    //todo split () for date dd:mm:yyyy and time hh:mm
    //todo ousiastika tha pernw parametro to symbol ":" kai tha to spaw ws pros auto

    /*operators overloaded*/
    bool operator==(const myString &rhs) const; //compared with myString
    bool operator==(const char *rhs);           //compared with char *
    bool operator!=(const myString &rhs) const;
    bool operator!=(const char *rhs);           //compared with char *


    myString operator=(myString right);   // for assign with myString
    myString operator=(const char *right); // for assign with char*



};


#endif //TRANSACTIONBITCOINSYSTEM_MYSTRING_H
