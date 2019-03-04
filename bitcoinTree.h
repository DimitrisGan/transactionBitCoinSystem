//
// Created by dimitrisgan on 2/3/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_BITCOINTREE_H
#define TRANSACTIONBITCOINSYSTEM_BITCOINTREE_H


#include "mylinkedList.h"
#include "myString.h"
#include "ErrorsCodes.h"


// https://gist.github.com/toboqus/def6a6915e4abd66e922


//using namespace std;




struct t_node{

    virtual ~t_node();

    myString walletId;
    int amount;
    struct t_node *left; // the receiver user/walletId with the amount that gets
    struct t_node *right; // the sender user/walletId (same as parent walletId) with the remainder amount

    void fillNode( myString id, int amount , t_node* left , t_node* right );

    bool operator==(const t_node &rhs) const;

    bool operator!=(const t_node &rhs) const;
};

class btc_tree{
public:
    btc_tree( myString initWalletIdOwner , int initialBtcValue);
    ~btc_tree();

    t_node *getRoot() const;

    void insert(myString senderWalletId, myString receiverWalletId, int amount);

    t_node *search(int key);
    void destroy_tree();



    void inorder_print();
    void postorder_print();
    void preorder_print();

private:
    void destroy_tree(t_node *leaf);
    void insert(myString receiverWalletID ,int amountToSend , t_node* senderNode); //inserts one t_node

    t_node *search(int key, t_node *leaf);


    void inorder_print(t_node *leaf);
    void postorder_print(t_node *leaf);
    void preorder_print(t_node *leaf);

    t_node *root;
};



void  getLeafs(t_node *root , linkedList<t_node*>  &leafs_list);
void searchKeyIdFromLeafs(myString keyWalletId, linkedList<t_node*> &leafs_list, linkedList<t_node*> &found_list);

//template <typename T>
//class Tree;
//
//template <typename T>
//class t_node
//{
//    friend class Tree<T>;
//
//public:
//    t_node(T);
//    T getData(); //returns data stored in t_node
//
//private:
//    T data;
//    t_node* leftPtr; //pointer to left child t_node of t_node
//    t_node* rightPtr; //pointer to right child t_node of t_node
//};
//
//template <typename T>
//t_node<T>::t_node(T dataIn)
//{
//    data = dataIn;
//    leftPtr = 0; //pointer to left and right child nodes are initilized to NULL
//    rightPtr = 0;
//}
//
//template <typename T>
//T t_node<T>::getData()
//{
//    return data;
//}


#endif //TRANSACTIONBITCOINSYSTEM_BITCOINTREE_H
