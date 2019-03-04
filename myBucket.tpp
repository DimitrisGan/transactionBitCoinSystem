//
// Created by dimitrisgan on 3/3/2019.
//

#include "myBucket.h"



template<typename T>
void myBucket<T>::insert(T data) {

    this->_data = data;
}

template<typename T>
T myBucket<T>::get_data() const {
    return _data;
}

template<typename T>
void myBucket<T>::set_data(T _data) {
    myBucket::_data = _data;
}

template<typename T>
bool myBucket<T>::operator==(const myBucket &rhs) const {
    return _data == rhs._data;
}

template<typename T>
bool myBucket<T>::operator!=(const myBucket &rhs) const {
    return !(rhs == *this);
}
