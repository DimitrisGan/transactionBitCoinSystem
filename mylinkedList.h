//
// Created by dimitrisgan on 25/2/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_MYLINKEDLIST_H
#define TRANSACTIONBITCOINSYSTEM_MYLINKEDLIST_H



#include <iostream>
using namespace std;


template <class T>
struct l_node {

//    virtual ~l_node() {
//            delete next;
//            next = nullptr;
//    }

    explicit l_node(T data) : data(data), next(nullptr) { static  int globo3=0;  /*cout << "CONSTRUCTOR OF list NODE IS CALLED #"<<globo3++ <<endl;*/ }
    T data;
    l_node<T> *next;


    T getData() const {
        return data;
    }
};




template <class T>
class linkedList {

private: //private attributes
    l_node<T> *head;
    l_node<T> *tail;
    int size{0};

public:
    int getSize() const;

private: //private methods
    l_node<T> *createNode(T data);

    template<class U>
    friend std::ostream &operator<<(std::ostream &os, const linkedList<U> &rhs);

public:
    linkedList() : head(nullptr) ,tail(nullptr){this->size =0;};
    linkedList( linkedList &rhs);

    virtual ~linkedList();

    bool deleteNodeByIndex( int index );
    bool deleteNodeByItem( T item2delete);


    void insert_first(T data);
    void insert_last(T data);

    l_node<T> * getByIndex(int index) ;
    void updateByIndex (int index , T data);
    void updateHeadData(T data);
    void updateTailData(T data);

    l_node<T> *getHead() const;

    l_node<T> *getTail() const;

    bool exists(T data) const;
    l_node<T>* search(T data); //searches for a value in the linked list and returns the point to object that contains that value
//    l_node<T>* getNext(l_node<T> baseNode); //get next l_node


//    void remove(T data);
    bool isEmpty() const;
    void clear();

    /*operators overload*/
    linkedList& operator=( linkedList &rhs)  ;




public:
    class Iterator;
    Iterator begin(){ return Iterator(head);};
    Iterator end(){return Iterator(tail);};

};




template <class T>
class linkedList<T>:: Iterator{
private:
    l_node<T> *currPtr;
public:
    Iterator() = default;;

    explicit Iterator(l_node<T> *currPtr) : currPtr(currPtr) {}
    virtual ~Iterator() = default;

    Iterator& operator=(l_node<T>* pNode){currPtr = pNode;return *this;}


    bool operator == (const Iterator &rhs) const { return currPtr == rhs.currPtr; }

    bool operator != (const Iterator &rhs) const {
        if (currPtr != nullptr)
//            std::cout<<"SUGKRINEI : "<<currPtr->data << " $$ "<<rhs.currPtr->data<<endl;
            return currPtr != nullptr;
    }

    T& operator * ()  {return currPtr->data; }

    // Prefix ++ overload
    Iterator& operator ++ () {


        if (currPtr != nullptr) {
            currPtr = currPtr->next;

        }

        return *this;
    }

// Postfix ++ overload
    const Iterator operator++(int)
    {
        Iterator old = *this;
        ++(*this);
        return old;
    }
};


///////===========================================================


//template<class T>
//void linkedList<T>::remove( T data)
//{
//    if(isEmpty())
//    {
//        return;
//    }
//
//    if (head->data == data)
//    {
//        l_node<T> * tmp = head;
//        head = head->next;
//        delete tmp;
//
//        return;
//    }
//
//
//    for (l_node<T> * curr = head->next, prev = head; curr != NULL; curr = curr->next)
//    {
//        if (curr->data == data)
//        {
//            l_node<T> *tmp = curr;
//            prev->next = curr->next;
//            delete tmp;
//
//            return;
//        }
//        prev = curr;
//    }
//}
//



template<class T>
bool linkedList<T>::deleteNodeByIndex( int index )
{
    cout << "MPIKA STH DELETEEEEE\n";
    bool exit;

    l_node<T> *pPre = NULL,
            *pCur = this->head;
    int currentIndex = 0;

    while ( pCur )
    {
        // Here we just loop until we reach our desired index.
        if (currentIndex == index)
        {
            break;
        }

        // Increment the current index and pCur to the next item.
        currentIndex++;
        pPre = pCur;
        pCur = pCur -> next;
    }

    // If pCur is still valid at this point, it means we broke at the
    // proper place and pCur should be at the proper index.
    if ( pCur )
    {
        if ( pPre )
        {
            pPre -> next = pCur -> next;
            delete pCur;
            this->size--;
            exit = false; // return false if successful
        }
        else
        {
            this->head = pCur -> next;
            delete pCur;
            this->size--;
            exit = false; // return false if successful
        }
    }
    else
        exit = true; // return true if unsuccessful

    return exit;
}



template<class T>
bool linkedList<T>::deleteNodeByItem( T item2delete)
{
    cout << "MPIKA STH DELETEEEEE\n";
    bool exit;

    l_node<T> *pPre = NULL,
            *pCur = this->head;

    while ( pCur )
    {
        // Here we just loop until we reach our desired index.
        if (pCur->data == item2delete)
        {
            break;
        }

        // Increment the current index and pCur to the next item.
        pPre = pCur;
        pCur = pCur -> next;
    }

    // If pCur is still valid at this point, it means we broke at the
    // proper place and pCur should be at the proper index.
    if ( pCur )
    {
        if ( pPre )
        {
            pPre -> next = pCur -> next;
            delete pCur;
            this->size--;
            exit = false; // return false if successful
        }
        else
        {
            this->head = pCur -> next;
            delete pCur;
            this->size--;
            exit = false; // return false if successful
        }
    }
    else
        exit = true; // return true if unsuccessful

    return exit;
}

//template<class T>
//linkedList<T>::linkedList( linkedList & rhs) : head(nullptr) ,tail(nullptr)
//{
////    this->clear(); // the function at the start of this review
////
////
////    for ( auto item : rhs) {
////        this->insert_last(item);
////    }
//
////    return *this;
//}


template<class T>
linkedList<T>::~linkedList()
{
    clear();
}



template<class T>
void linkedList<T>::clear () {
    static const bool IS_POINTER = std::is_pointer<T>::value;
//    if (IS_POINTER) {
        if (!isEmpty()) { // List is not empty

            l_node<T> *currPtr = head;
            l_node<T> *tempPtr;
            while (currPtr != nullptr) { // delete remaining nodes
                tempPtr = currPtr;
                currPtr = currPtr->next;
                delete tempPtr;
            }
            head = nullptr;
            tail = nullptr;
            size=0;

        }
//    }
//    else{
//        head = nullptr;
//        tail = nullptr;
//        size=0;
//    }
}

template<class T>
l_node<T>* linkedList<T>::search(T keyData) { //searches for a value in the linked list and returns the point to object that contains that value
    l_node<T>* nodePtr;
    bool found = false;

    nodePtr = head;

    while((!found) && (nodePtr != nullptr)) //runs through list until data is found within a l_node or end of list is reached
    {
        if(nodePtr->data == keyData) //if the l_node's data equals the key then the l_node has been found
            found = true;
        else
            nodePtr = nodePtr->next; //moves to next l_node in list
    }
    return nodePtr; //returns pointer to the l_node that contains data equal to key (NULL if not found)
}

//template <class T>
//linkedList<T> & linkedList<T>::operator=(const linkedList<T> &rhs)
//{
//    if (this != &rhs)
//    {
//        l_node<T> *temp;
//        while (head != NULL)
//        {
//            temp = head;
//            head = head->next;
//            delete temp;
//        }
//
//        if (rhs.head != NULL)
//            head = new l_node<T>(rhs.head->data);
//
//        l_node<T> *tmpHead = head;
//
//        for (l_node<T> *tmp = rhs.head->next; tmp != NULL; tmp = tmp->next)
//        {
//            tmpHead->next = new l_node<T>(tmp->data);
//            tmpHead = tmpHead->next;
//        }
//    }
//    return *this;
//}



template <class T>
linkedList<T> &  linkedList<T>::operator=(  linkedList<T> &rhs)
{

//        linkedList *tmp = new linkedList;

    this->clear(); // the function at the start of this review

//        if (rhs.isEmpty()) {
//            // short cut, since the other list is empty
//            linkedList<T> tmp = new linkedList<T>();
//            this = tmp;
//            return *this;
//        }


    for ( auto item : rhs) {
        this->insert_last(item);
    }
    this->size = rhs.size; //peritto

    return *this;

}







//===========================================================
//===========================================================

template<class T>
void linkedList<T>::insert_first( T data)
{

    l_node<T> *temp = createNode(data);
    temp = nullptr;

//    auto temp =  new l_node<T>(data);//createNode(data);


    if (isEmpty())
    {
        head = temp;
        tail = temp;
        temp = nullptr;
    }
    else
    {

        temp->next = head;
        head = temp;

        //de thelw sto tail
        //        l_node<T> *temp = head;
        //        for (temp = head; temp->next != NULL; temp = temp->next);
        //        temp->next = new l_node<T>(data);
    }

    size++;
}



//  https://www.codementor.io/codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr
template<class T>
void linkedList<T>::insert_last( T data)
{


    auto *temp =  new l_node<T>(data);//createNode(data);
    temp->next = nullptr;

    if (this->isEmpty()){
        head=temp;
        tail=temp;
    }
    else{

        tail->next = temp;
        tail = temp;
    }


    size++;

}



//void delete_position(int pos)
//{
//    l_node *current=new l_node;
//    l_node *previous=new l_node;
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

    for (l_node<T> *tmp = head; tmp != nullptr; tmp = tmp->next)
        if (tmp->data == data)
            return true;

    return false;
}

//template<class T>
//void linkedList<T>::remove(const T data)
//{
//    bool removed = false;
//    l_node<T> *curr = head;
//    l_node<T> *prev = head;
//
//    for (; curr != NULL && removed == false; curr = curr->next)
//    {
//        if (head->data == data)
//        {
//            l_node<T> *tmp = head;
//            head = head->next;
//            delete tmp;
//            removed = true;
//        }
//        else if (curr->data == data)
//        {
//            l_node<T> *tmp = curr;
//            prev->next = curr->next;
//            delete tmp;
//            removed = true;
//        }
//        prev = curr;
//    }
//}

template<class T>
bool linkedList<T>::isEmpty() const
{
    //todo tha mporousa apla size == 0;
//    return head == nullptr && tail == nullptr; //if the start pointer and end pointer are NULL then the list is empty
//    return head ==  tail ; //if the start pointer and end pointer are NULL then the list is empty
    return (! this->size);
}

template<class T>
std::ostream & operator<<(std::ostream & os, const linkedList<T>& rhs)
{
    if (rhs.isEmpty()){
        os << "EMPTY LIST";

    }
    for (l_node<T> *temp = rhs.head; temp != nullptr; temp = temp->next)
    {
        os << temp->data;
        if (temp->next != nullptr)
            os << ", ";
    }
//    os<<"\n";
    return os;
}

template<class T>
l_node<T> *linkedList<T>::createNode(T data) {
    //todo an dothei gia data recordsBucket object anti gia ptr trww seg ston destructor tou recordsBucket
    l_node<T> *temp = new l_node<T>(data);


    return temp;
}

template<class T>
linkedList<T>::linkedList(linkedList &rhs) {



//    this->clear(); // the function at the start of this review
    this->head = nullptr;
    this->tail= nullptr;

    for ( auto item : rhs) {
        this->insert_last(item);

    }

//    return *this;


}

template<class T>
void linkedList<T>::updateHeadData(T data) {
    linkedList::head->data = data;
}

template<class T>
void linkedList<T>::updateTailData(T data) {
    linkedList::tail->data = data;
}

template<class T>
l_node<T> *linkedList<T>::getHead() const {
    return head;
}

template<class T>
l_node<T> *linkedList<T>::getTail() const {
    return tail;
}

template<class T>
int linkedList<T>::getSize() const {
    return size;
}




template<class T>
void linkedList<T>::updateByIndex(int index, T data) {

    l_node<T> *pCur = this->head;
    int currentIndex = 0;

    while ( pCur )
    {
        // Here we just loop until we reach our desired index.
        if (currentIndex == index)
        {
            break;
        }

        // Increment the current index and pCur to the next item.
        currentIndex++;
        pCur = pCur -> next;
    }

    // If pCur is still valid at this point, it means we broke at the
    // proper place and pCur should be at the proper index.
    if ( pCur )
    {
        pCur->data = data;
    }
    else {
        fprintf(stderr, "ERROR IN UPDATEBYINDEX FUNCTION IN LINKED LIST");
        exit(1);
    }
}


template<class T>
l_node<T> *linkedList<T>::getByIndex(int index) {

    l_node<T> *pCur = this->head;
    int currentIndex = 0;

    while ( pCur )
    {
        // Here we just loop until we reach our desired index.
        if (currentIndex == index)
        {
            break;
        }

        // Increment the current index and pCur to the next item.
        currentIndex++;
        pCur = pCur -> next;
    }

    // If pCur is still valid at this point, it means we broke at the
    // proper place and pCur should be at the proper index.
    if ( pCur )
    {
        return pCur;
    }
    else{
        fprintf(stderr, "ERROR IN GETBYINDEX FUNCTION IN LINKED LIST");
        exit(1);
    }

}


#endif //TRANSACTIONBITCOINSYSTEM_MYLINKEDLIST_H
