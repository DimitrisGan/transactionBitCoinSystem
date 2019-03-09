//
// Created by dimitrisgan on 3/3/2019.
//

#include "myBucket.h"



template<typename T>
void myBucket<T>::insert(T data) {

    this->_data = data;
}

template<typename T>
T* myBucket<T>::get_data()  {
    return &_data;
}

template<typename T>
void myBucket<T>::set_data(T _data) {
    myBucket::_data = _data;
}

template<typename T>
bool myBucket<T>::operator==(T &data)  {
    return _data == data;
}

template<typename T>
bool myBucket<T>::operator!=(T &data)  {
    return !(data == *this);
}

template<typename T>
bool myBucket<T>::operator==(myString &id) {
    return _data == id;
}

template<typename T>
bool myBucket<T>::operator!=(myString &id) {
    return !(id == *this);
}
//template<typename T>
//friend ostream &operator<<(ostream &os,  myBucket<T> bucket){
//    os << "_data: " << bucket._data;
//    return os;
//}
