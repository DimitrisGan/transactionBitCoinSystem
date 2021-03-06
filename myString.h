//
// Created by dimitrisgan on 26/2/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_MYSTRING_H
#define TRANSACTIONBITCOINSYSTEM_MYSTRING_H


#include <iostream>
using namespace std;


class myString{
private:
    char* myStr;
    unsigned len;
public:
    myString(){myStr= nullptr;len =0;}

    explicit myString(char *sptr);
    myString (char c);
    myString( myString &right); //move operator maybe not needed because of not existing simple constructor
//    myString( myString right); //move operator maybe not needed because of not existing simple constructor

    virtual ~myString();

    char *getMyStr() const;

    void setMyStr(const char *myStr);

    unsigned size() const;

    /*operators overloaded*/
    bool operator==(const myString &rhs) const; //compared with myString
    bool operator==(const char *rhs);           //compared with char *
    bool operator!=(const myString &rhs) const;
    bool operator!=(const char *rhs);           //compared with char *


//    myString& operator=(myString right);   // for assign with myString
    myString& operator=(const myString &right) ;   // for assign with myString
    myString& operator=(const char *right); // for assign with char*

    friend ostream & operator << (ostream &out, const myString &c);
    friend std::istream& operator>> (std::istream& is, myString& s);



};


#endif //TRANSACTIONBITCOINSYSTEM_MYSTRING_H
