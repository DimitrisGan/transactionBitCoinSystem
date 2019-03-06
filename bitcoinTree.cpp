//
// Created by dimitrisgan on 2/3/2019.
//

#include <assert.h>
#include "bitcoinTree.h"


btc_tree::btc_tree( myString initWalletIdOwner , int initialBtcValue){

    root = new t_node (initWalletIdOwner, initialBtcValue, nullptr, nullptr);
//    root->fillNode(initWalletIdOwner,initialBtcValue, nullptr, nullptr);

}

btc_tree::~btc_tree(){
//todo    destroy_tree();
    destroy_tree(this->root);
}

void btc_tree::destroy_tree(t_node *leaf){
    if(leaf != nullptr){
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

t_node::~t_node() {
//    this->left = nullptr;
//    this->right= nullptr;
}

// function to print leaf
// nodes from left to right
//template<class T>

/*pairnw th lista me ta leaf nodes*/
//https://www.geeksforgeeks.org/print-leaf-nodes-left-right-binary-tree/
void  getLeafs(t_node *root , linkedList<t_node*>  &leafs_list)
{
    // if node is null, return
    if (!root)
        return;

    // if node is leaf node, print its data
    if (!root->left && !root->right)
    {
        leafs_list.insert_last(root); //todo tha xw thema edw
        return;
    }

    // if left child exists, check for leaf
    // recursively
    if (root->left)
        getLeafs(root->left , leafs_list);

    // if right child exists, check for leaf
    // recursively
    if (root->right)
        getLeafs(root->right , leafs_list);

}

/*vriskw auta me to sugkerkimeno senderWalletId*/
void searchKeyIdFromLeafs(myString keyWalletId, linkedList<t_node*> &leafs_list, linkedList<t_node*> &found_list){

    for ( auto &item : leafs_list) {
        if (item->walletId == keyWalletId)
            found_list.insert_last(item);
    }

}






//
//
/*basically inserts all the amount asked for the transcation in the tree.
 * Thus,it can add more than 1 node in the tree*/
void btc_tree::insert(myString senderWalletId, myString receiverWalletId, int amount){

//    if ( leaf->amount < amount){ // lathos
//        fprintf(stderr, "Can't divide-send the bitcoin into pieces ");
//        exit(AMOUNT_NOT_POSSIBLE_TO_DIVIDE_IN_BITCOINTREE);
//    }

    linkedList<t_node*> leafs_list; //logika tha paizw me pointers gia na grapsw kateutheian ston komvo
    getLeafs(this->root , leafs_list);
    //kane searchKeyIdFromLeafs ola ta leafs  kai apo kei pare ola ta receiverWalletId pou einia o receiverWalletId sender
    linkedList<t_node*> found_list;
    searchKeyIdFromLeafs(senderWalletId, leafs_list, found_list);
    //todo mhpws na pairna deiktes kai etsi wste na ekana eskava kateutheian panw stous komvous????
    //todo
    //todo
    //todo
    //todo
    //todo
    int amountLeft = amount;
    for (const auto &senderLeafNode : found_list) {
        //todo insert node here
        if ( amountLeft <= senderLeafNode->amount){ //means that we only need one node too add
            //and also that will take only the amountLeft2add because is less than the potential amount to give
            //todo digNode() - createNode()
            //todo add2Tree()
            insert(receiverWalletId ,amountLeft , senderLeafNode);
            amountLeft = 0;
            break;

        }
        else{ //means that the amount of the node is not enough we need to add another node
            //todo digNode() - createNode()
            //todo add2Tree()
            insert(receiverWalletId ,senderLeafNode->amount /*node can give only the amount that contains*/ , senderLeafNode);
            amountLeft = amountLeft - senderLeafNode->amount;
            continue;
        }


    }

    assert(amountLeft == 0);



}


void t_node::fillNode( myString id, int amount , t_node* left , t_node* right ){

    this->walletId = id;
    this->amount = amount;
    this->left = left;
    this->right = right;

}

t_node& t_node::operator=(const t_node &rhs) {
    walletId = rhs.walletId;
    amount = rhs.amount;
    left = rhs.left ;
    right = rhs.right;

    return *this;
}

bool t_node::operator!=( t_node rhs)  {
    return !(rhs == *this);
}

bool t_node::operator==(t_node rhs) {
    return walletId == rhs.walletId && amount == rhs.amount && left ==rhs.left && right == rhs.right;
}

t_node::t_node( myString walletId, int amount, t_node *left, t_node *right) : walletId(walletId), amount(amount),
                                                                                    left(left), right(right) {}

t_node::t_node() {}


/*digs the given node
 * and inserts 2 nodes
 * Left  : the receiver user
 * Right : the remain amount of sender user
 * */
void btc_tree::insert(myString receiverWalletID ,int amountToSend , t_node* senderNode) //inserts 2 t_node
{
//lathos o root de tha nai null
//    if(root != nullptr){
//        insert(key, root);
//    }else{
    senderNode->left = new t_node;

//    senderNode->left->receiverWalletId = receiverWalletID;
//    senderNode->left->amountToSend = ;
//    senderNode->left->left = nullptr ;
//    senderNode->left->right = nullptr ;

    senderNode->left->fillNode(receiverWalletID,amountToSend, nullptr, nullptr);


    int amountRemain = senderNode->amount - amountToSend;
    assert(amountRemain >=0);

    senderNode->right = new t_node;
//    senderNode->right->receiverWalletId = senderNode->receiverWalletId;
//    senderNode->right->amountToSend = ;
//
//    senderNode->right->left = nullptr ;
//    senderNode->right->right = nullptr ;
//

    senderNode->right->fillNode(senderNode->walletId , amountRemain , nullptr , nullptr);
}

t_node *btc_tree::getRoot() const {
    return root;
}

bool btc_tree::operator==(const btc_tree &rhs) const {
    return root->walletId == rhs.root->walletId;
}

bool btc_tree::operator!=(const btc_tree &rhs) const {
    return !(rhs.root->walletId == this->root->walletId);
}




//
//t_node *btc_tree::searchKeyIdFromLeafs(int key){
//    return searchKeyIdFromLeafs(key, root);
//}
//
//void btc_tree::destroy_tree(){
//    destroy_tree(root);
//}
//
//void btc_tree::inorder_print(){
//    inorder_print(root);
//    cout << "\n";
//}
//
//void btc_tree::inorder_print(t_node *leaf){
//    if(leaf != NULL){
//        inorder_print(leaf->left);
//        cout << leaf->value << ",";
//        inorder_print(leaf->right);
//    }
//}
//
//void btc_tree::postorder_print(){
//    postorder_print(root);
//    cout << "\n";
//}
//
//void btc_tree::postorder_print(t_node *leaf){
//    if(leaf != NULL){
//        inorder_print(leaf->left);
//        inorder_print(leaf->right);
//        cout << leaf->value << ",";
//    }
//}
//
//void btc_tree::preorder_print(){
//    preorder_print(root);
//    cout << "\n";
//}
//
//void btc_tree::preorder_print(t_node *leaf){
//    if(leaf != NULL){
//        cout << leaf->value << ",";
//        inorder_print(leaf->left);
//        inorder_print(leaf->right);
//    }
//}