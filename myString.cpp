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

    int len = static_cast<int>(strlen(sptr));
    this->myStr= new char[len + 1];
    strcpy(this->myStr, sptr);
}

//**************************************************
// Destructor to delete/free the allocate memory   *
//**************************************************

myString::~myString() {
    delete[] this->myStr;
    this->myStr= nullptr;

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
}

//************************************************
// Overloaded = operator. Called when operand    *
// on the right is another MyString object.      *
// Returns the calling object.                   *
//************************************************

myString myString::operator=(myString right)
{
    if (this->size() != 0)
        delete [] myStr;
    myStr = new char[right.size() + 1];
    strcpy(myStr, right.getMyStr());
    return *this;
}

//***********************************************
// Overloaded = operator. Called when operand   *
// on the right is a string.                    *
// Returns the calling object.                  *
//***********************************************

myString myString::operator=(const char *right)
{
    if (this->size() != 0)
        delete [] myStr;
    int len = static_cast<int>(strlen(right));
    myStr = new char[len + 1];
    strcpy(myStr, right);
    return *this;
}


//===============================================================



char *myString::getMyStr() const {
    return myStr;
}

unsigned myString::size() {
    return static_cast<unsigned int>(strlen(this->myStr));

}

//void myString::makeOneToken(char delimeter) {
//    char* token = strtok(this->myStr, "-"); //todo ???
//}
