#include <iostream>
#include <getopt.h>
#include "mylinkedList.h"
#include "myString.h"
#include "bucket.h"
#include "assistantFunctions.h"

using  namespace std;

int main(int argc, char **argv) {
    std::cout << "Hello, World!\n" << std::endl;

    ArgumentsKeeper argmKeeper;
    ArgmParser(argc, argv , argmKeeper);

    argmKeeper.printArgs();

    exit(1);
//    //todo call linked list
//    linkedList<int> llist;
//    llist.insert_last(1);
//    llist.insert_last(2);
//    llist.insert_last(3);
////    llist.insert_first(0);
//    cout << llist<<endl;
////    cout<<    llist.isEmpty() <<endl;
////    llist.clear();
////    cout << llist<<endl;
////    llist.insert_first(1);
////    llist.insert_first(-1);
////    llist.insert_last(10);
////    cout << llist<<endl;
//
////    cout << "~~~~EXISTS~~~\n";
////    cout << llist.exists(3)<<endl;
////
//////    for (node<int> *tmp = llist.; tmp != NULL; tmp = tmp->next)
//////        if (tmp->data == data)
//////            return true;
////
////cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
////    node<int>* nodeFound = llist.search(-1);
////    cout << nodeFound->data<<endl;
////    cout << nodeFound->next->data<<endl;
//////    while ()
//
//    cout << "~~~~~~~~~~TESTING ITERATOR~~~~~~~~~~~~~~~\n";
//
//
//    linkedList<int>::Iterator it;
//    for (it = llist.begin();it != llist.end(); ++it) {
//
//        cout <<*it<<endl;
//    }
//    cout << "~~~~~~~~~~TESTING AYTO ITERATOR~~~~~~~~~~~~~~~\n";
//
//    for (auto nod : llist) {
//
//        cout <<nod<<endl;
//    }

//    it = llist.begin();
//    while (it != llist.end()){
//        cout <<*it<<endl;
//        it++;
//    }
//    cout<<"last l_node:"<<endl;
//    cout <<*it<<endl;

/*

*/
/*test myString*/

    char* ch = const_cast<char *>("hello1!");
    char* ch2 = const_cast<char *>("hello!");
    myString myS (ch);
    myString myS2 (ch2);
    bool val = myS2 == ch ;
    cout << val<<endl;
    cout << myS.size();

    linkedList<myString> llistString;
    llistString.insert_last(myS);
    llistString.insert_last(myS2);


    cout<< llistString<<endl;
//
//*/
//PAIZEI
    linkedList<bucket*> listForBuckets;
//    unsigned recrodsAvailable = 2;
    auto *  newBucket0 = new bucket (1);
    auto *  newBucket1 = new bucket (2);
    bucket*  newBucket2 = new bucket (3);
    listForBuckets.insert_last(newBucket0);
    listForBuckets.insert_last(newBucket1);
    listForBuckets.insert_last(newBucket2);

//
//
////    //DEN PAIZEI
////    linkedList<bucket> listForBucketsWRONG;
//////    unsigned recrodsAvailable = 2;
////    bucket  newBucket0W(1) ;
//////    bucket  newBucket1W(2) ;
//////    bucket  newBucket2W(3) ;
////    listForBucketsWRONG.insert_last(newBucket0W);
////    listForBucketsWRONG.insert_last(newBucket0W);
//////    listForBucketsWRONG.insert_last(newBucket1W);
//////    listForBucketsWRONG.insert_last(newBucket2W);
//
//

    linkedList<int> listOFints;
    int n1=1;
    int n2=2;
    int n4=4;
    listOFints.insert_last(n1);
    listOFints.insert_last(n2);
    listOFints.insert_last(n4);


//
////    char* c1 = const_cast<char *>("hi0dfgfdgfd");
////    char* c2 = const_cast<char *>("hi1");
////    char* c3 = const_cast<char *>("hi2");
//
////    myString* dynamicArray = new  myString [3];
////    myString staticArray[3] ;//= new myString[3];
//
////    dynamicArray[0] = c1;
////    dynamicArray[1] = c2;
////    dynamicArray[2] = c3;
////
////    staticArray[0] = c1;
////    staticArray[1] = c2;
////    staticArray[2] = c3;
//
//
    cout<< "ok?"<<endl;
//
////        cout << array;
//
    delete  newBucket0;
    delete  newBucket1;
    delete  newBucket2;
////        array = nullptr;
////    cout<<listForBuckets<<endl;


    //todo 1# ftiaxnw to bucket apo ysvd


    return 0;
}