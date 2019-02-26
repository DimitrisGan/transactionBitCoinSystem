//
// Created by dimitrisgan on 25/2/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_MYLINKEDLIST_H
#define TRANSACTIONBITCOINSYSTEM_MYLINKEDLIST_H



#include <iostream>
//using namespace std;

template <class T>
struct node {
    node(T data) : data(data), next(NULL) {}
    T data;
    node<T> *next;


    typedef node<T> node_type;
    typedef node_type* node_ptr;
};




template <class T>
class linkedList {

private: //private attributes
    node<T> *head;
    node<T> *tail;
private: //private methods
    node<T> *createNode(T data);

    template<class U>
    friend std::ostream &operator<<(std::ostream &os, const linkedList<U> &rhs);

public:
    linkedList() : head(NULL) ,tail(NULL){};
    linkedList(const linkedList &rhs);
    ~linkedList();

    void insert_first(T data);
    void insert_last(T data);

    bool exists(T data) const;
    node<T>* search(T data); //searches for a value in the linked list and returns the point to object that contains that value

    void remove(T data);
    bool isEmpty() const;
    void clear();

    /*operators overload*/
    linkedList &operator=(const linkedList &rhs);

public:
    class Iterator;
    Iterator begin(){ return Iterator(head->next);};
    Iterator end(){return Iterator(tail);};
};




template <class T>
class linkedList<T>:: Iterator{
private:
    node<T> *ptr;
public:
    explicit Iterator(node<T> *currPtr) : ptr(currPtr) {}
    virtual ~Iterator() = default;

    bool operator==(const Iterator &rhs) const { return ptr == rhs.ptr; }
    bool operator!=(const Iterator &rhs) const {return !(rhs == *this); }
    T& operator * ()  {return ptr->data; }
    Iterator& operator ++ () {ptr->next;return *this; }

};







template<class T>
linkedList<T>::linkedList(const linkedList & rhs) : head(NULL) ,tail(NULL)
{
    *this = rhs;
}


template<class T>
linkedList<T>::~linkedList()
{
    clear();
}



template<class T>
void linkedList<T>::clear () {
    if ( !isEmpty() ) { // List is not empty

        node<T> *currPtr = head;
        node<T> *tempPtr ;
        while (currPtr != NULL) { // delete remaining nodes
            tempPtr = currPtr;
            currPtr = currPtr->next;
            delete tempPtr;
        }
        head= nullptr;
        tail= nullptr;

    }
}

template<class T>
node<T>* linkedList<T>::search(T keyData) { //searches for a value in the linked list and returns the point to object that contains that value
    node<T>* nodePtr;
    bool found = false;

    nodePtr = head;

    while((!found) && (nodePtr != NULL)) //runs through list until data is found within a node or end of list is reached
    {
        if(nodePtr->data == keyData) //if the node's data equals the key then the node has been found
            found = true;
        else
            nodePtr = nodePtr->next; //moves to next node in list
    }
    return nodePtr; //returns pointer to the node that contains data equal to key (NULL if not found)
}

//template <class T>
//linkedList<T> & linkedList<T>::operator=(const linkedList<T> &rhs)
//{
//    if (this != &rhs)
//    {
//        node<T> *temp;
//        while (head != NULL)
//        {
//            temp = head;
//            head = head->next;
//            delete temp;
//        }
//
//        if (rhs.head != NULL)
//            head = new node<T>(rhs.head->data);
//
//        node<T> *tmpHead = head;
//
//        for (node<T> *tmp = rhs.head->next; tmp != NULL; tmp = tmp->next)
//        {
//            tmpHead->next = new node<T>(tmp->data);
//            tmpHead = tmpHead->next;
//        }
//    }
//    return *this;
//}



template <class T>
linkedList<T> & linkedList<T>::operator=(const linkedList<T> &rhs)
{
    if (this == &rhs){
        return *this;
    }
    else {


        this->clear(); // the function at the start of this review

        if (rhs.isEmpty()) {
            // short cut, since the other list is empty
            return *this;
        }
        else{

        }


        //perittooo
        /*head = new node<T>(rhs.head->data);

        node<T> * current = head;

        for (node<T> *tmp = rhs.head->next; tmp != NULL; tmp = tmp->next)
        {
            current->next = new node<T>(tmp->data);
            current = current->next;
        }*/
    }

}



//===========================================================
//===========================================================

template<class T>
void linkedList<T>::insert_first(const T data)
{

    node<T> *temp = createNode(data);


    if (isEmpty())
    {
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else
    {

        temp->next = head;
        head = temp;

        //de thelw sto tail
        //        node<T> *temp = head;
        //        for (temp = head; temp->next != NULL; temp = temp->next);
        //        temp->next = new node<T>(data);
    }
}



//  https://www.codementor.io/codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr
template<class T>
void linkedList<T>::insert_last(const T data)
{


    node<T> *temp = createNode(data);

    if (isEmpty()){
        head=temp;
        tail=temp;
        temp = NULL;
    }
    else{

        tail->next = temp;
        tail = temp;
    }


}



//void delete_position(int pos)
//{
//    node *current=new node;
//    node *previous=new node;
//    current=head;
//    for(int i=1;i<pos;i++)
//    {
//        previous=current;
//        current=current->next;
//    }
//    previous->next=current->next;
//}
//

template<class T>
bool linkedList<T>::exists(const T data) const
{
    if (isEmpty())
        return false;

    for (node<T> *tmp = head; tmp != NULL; tmp = tmp->next)
        if (tmp->data == data)
            return true;

    return false;
}

template<class T>
void linkedList<T>::remove(const T data)
{
    bool removed = false;
    node<T> *curr = head;
    node<T> *prev = head;

    for (; curr != NULL && removed == false; curr = curr->next)
    {
        if (head->data == data)
        {
            node<T> *tmp = head;
            head = head->next;
            delete tmp;
            removed = true;
        }
        else if (curr->data == data)
        {
            node<T> *tmp = curr;
            prev->next = curr->next;
            delete tmp;
            removed = true;
        }
        prev = curr;
    }
}

template<class T>
bool linkedList<T>::isEmpty() const
{
    return head == NULL && tail == NULL; //if the start pointer and end pointer are NULL then the list is empty
}

template<class T>
std::ostream & operator<<(std::ostream & os, const linkedList<T>& rhs)
{
    if (rhs.isEmpty()){
        os << "EMPTY LIST";

    }
    for (node<T> *temp = rhs.head; temp != NULL; temp = temp->next)
    {
        os << temp->data;
        if (temp->next != NULL)
            os << ", ";
    }
//    os<<"\n";
    return os;
}

template<class T>
node<T> *linkedList<T>::createNode(T data) {
    node<T> *temp = new node<T>(data);
    temp->data = data;
    temp->next = NULL;
    return temp;
}




#endif //TRANSACTIONBITCOINSYSTEM_MYLINKEDLIST_H
