//
// Created by dimitrisgan on 2/3/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_BITCOINTREE_H
#define TRANSACTIONBITCOINSYSTEM_BITCOINTREE_H


#include "mylinkedList.h"
#include "myString.h"
#include "ErrorsCodes.h"

class transaction;



struct t_node{

    t_node();

    t_node( myString walletId, int amount, t_node *left, t_node *right);

    t_node( t_node &n);

    virtual ~t_node();

    myString walletId;
    int amount;
    t_node *left; // the receiver user/receiverWalletId with the amount that gets
    t_node *right; // the sender user/receiverWalletId (same as parent receiverWalletId) with the remainder amount

    transaction *transac_ptr;

    void fillNode( myString id, int amount , t_node* left , t_node* right );

    t_node& operator=(const t_node &rhs);

    void setTransac_ptr(transaction *transac_ptr);

    bool operator==( t_node rhs) ;

    bool operator!=( t_node rhs) ;
};

class btc_tree{
public:
    btc_tree( myString initWalletIdOwner , int initialBtcValue);
    ~btc_tree();

    btc_tree( btc_tree &rhs);

    t_node *getRoot() const;

    void insert(myString senderWalletId, myString receiverWalletId, int amount , linkedList<t_node*> &returnPtrs2t_nodes );

    bool operator==(const btc_tree &rhs) const;

    bool operator!=(const btc_tree &rhs) const;

    void getUniqueTransacIdsList(t_node *node, linkedList<myString> &transIdUnique_list);

    void getUniqueTransacList(t_node *node, linkedList<transaction*> &trans_list);

    bool hasUnspentAmount(t_node *node);
    int getUnspentAmount(t_node *node);


/*  NOT IMPLEMENTED
    void inorder_print();
    void postorder_print();
    void preorder_print();
    t_node *search(int key);
    void destroy_tree();
*/

private:
    void destroy_tree(t_node *leaf);
    void insert(myString receiverWalletID ,int amountToSend , t_node* senderNode); //inserts one t_node
/* NOT IMPLEMENTED
    t_node *search(int key, t_node *leaf);
    void inorder_print(t_node *leaf);
    void postorder_print(t_node *leaf);
    void preorder_print(t_node *leaf);
*/

    t_node *root;
};


void  getLeafs(t_node *root , linkedList<t_node*>  &leafs_list);
void searchKeyIdFromLeafs(myString keyWalletId, linkedList<t_node*> &leafs_list, linkedList<t_node*> &found_list);




// Source: https://gist.github.com/toboqus/def6a6915e4abd66e922

#endif //TRANSACTIONBITCOINSYSTEM_BITCOINTREE_H
