//
// Created by dimitrisgan on 26/2/2019.
//

#include <cstring>
#include "myString.h"


//**************************************************
// Constructor to initialize the str member        *
// with a string constant.                         *
//**************************************************

myString::myString(char *sptr)  {

    this->len = static_cast<int>(strlen(sptr));
    this->myStr= new char[len + 1];
    strcpy(this->myStr, sptr);
}

//**************************************************
// Destructor to delete/free the allocate memory   *
//**************************************************

myString::~myString() {

    if (len != 0)
        delete [] this->myStr;
    this->myStr= nullptr;
    len=0;

}

//***************************************************************
// Overloaded == , != operators.                                *
// Called when the operand on the right is a MyString           *
// object.                                                      *
// == :Returns true if right.str is the same as str.            *
// != :Returns true if not right.str is the different from str. *
//***************************************************************

bool myString::operator==(const myString &rhs) const {
    return !strcmp(myStr, rhs.getMyStr());
}

bool myString::operator!=(const myString &rhs) const {
    return strcmp(myStr, rhs.getMyStr()) != 0;
}

//***************************************************************
// Overloaded == , != operators.                                *
// Called when the operand on the right is a string.            *
// == :Returns true if right.str is the same as str.            *
// != :Returns true if not right.str is the different from str. *
//***************************************************************


bool myString::operator==(const char *rhs)
{
    return !strcmp(myStr, rhs);
}

bool myString::operator!=(const char *rhs)
{
    return strcmp(myStr, rhs) != 0;
}


//*************************************************
// Copy constructor.                              *
//*************************************************

myString::myString(myString &right)
{
    myStr = new char[right.size() + 1];
    strcpy(myStr, right.getMyStr());
    len = right.size();
}

//************************************************
// Overloaded = operator. Called when operand    *
// on the right is another MyString object.      *
// Returns the calling object.                   *
//************************************************

//myString& myString::operator=(myString right)
//{
////    if (this->size() != 0)
////        delete [] myStr;
//    myStr = new char[right.size() + 1];
//    strcpy(myStr, right.getMyStr());
//    len  = right.size();
//    return *this;
//}


myString &myString::operator=(const myString &right)  {
    myStr = new char[right.size() + 1];
    strcpy(myStr, right.getMyStr());
    len  = right.size();
    return *this;
}

//***********************************************
// Overloaded = operator. Called when operand   *
// on the right is a string.                    *
// Returns the calling object.                  *
//***********************************************

myString& myString::operator=(const char *right)
{
    if (len != 0)
        delete [] myStr;
    int lenRight = static_cast<int>(strlen(right));
    myStr = new char[lenRight + 1];
    strcpy(myStr, right);
    len = static_cast<unsigned int>(strlen(right));
    return *this;
}


//===============================================================



char *myString::getMyStr() const {
    return myStr;
}

unsigned myString::size() const {
    return  len;
}

void myString::setMyStr(char *myStr) {

    if (myStr != nullptr) {
        this->myStr = new char[len + 1];
        strcpy(this->myStr, myStr);
    }
    else{
        this->myStr = nullptr;
    }

}

//    ostream & operator << (ostream &out, myString &c)
//    {
//        for (int i = 0; i < c.size(); ++i) {
//
//        }
//        out << c.getMyStr();
//        return out;
//    }

ostream& operator<<(ostream &os, const myString &string) {
    if (string.myStr) {
        os << string.myStr;
    }
    return os;
}


std::istream& operator>> (std::istream& is, myString& s)
{
    char* c = new char[100];
    is >> c;
    s.setMyStr(c);
    delete[] c;

    return is;
}



//void myString::makeOneToken(char delimeter) {
//    char* token = strtok(this->myStr, "-"); //todo ???
//}
