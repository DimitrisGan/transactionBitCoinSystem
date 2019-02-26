#include <iostream>
#include "mylinkedList.h"
using  namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << "commit from laptop!" << std::endl;


    //todo call linked list
    linkedList<int> llist;
    llist.insert_last(1);
    llist.insert_last(2);
    llist.insert_last(3);
//    llist.insert_first(0);
    cout << llist<<endl;
//    cout<<    llist.isEmpty() <<endl;
//    llist.clear();
//    cout << llist<<endl;
//    llist.insert_first(1);
//    llist.insert_first(-1);
//    llist.insert_last(10);
//    cout << llist<<endl;

//    cout << "~~~~EXISTS~~~\n";
//    cout << llist.exists(3)<<endl;
//
////    for (node<int> *tmp = llist.; tmp != NULL; tmp = tmp->next)
////        if (tmp->data == data)
////            return true;
//
//cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//    node<int>* nodeFound = llist.search(-1);
//    cout << nodeFound->data<<endl;
//    cout << nodeFound->next->data<<endl;
////    while ()

    cout << "~~~~~~~~~~TESTING ITERATOR~~~~~~~~~~~~~~~\n";

    linkedList<int>::Iterator it ;
    for (it = llist.begin();
         it != llist.end(); it++) {

        cout << *it<<endl;
    }

    cout << *it<<endl;

    return 0;
}