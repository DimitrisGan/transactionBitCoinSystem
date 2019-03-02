//
// Created by dimitrisgan on 2/3/2019.
//

#include "bitcoinTree.h"


btree::btree(){
    root = nullptr;
    //todo logika arxikopoihsh me to walletID tou prwtou katoxou kai valuw thn arxikh timh t

}

btree::~btree(){
//    destroy_tree();
}

//void btree::destroy_tree(t_node *leaf){
//    if(leaf != NULL){
//        destroy_tree(leaf->left);
//        destroy_tree(leaf->right);
//        delete leaf;
//    }
//}


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

//void insert(myString walletId ,int amount, t_node *leaf);
void btree::insert(myString senderWalletId ,myString receiverWalletId ,int amount, t_node *leaf){

//    if ( leaf->amount < amount){ // lathos
//        fprintf(stderr, "Can't divide-send the bitcoin into pieces ");
//        exit(AMOUNT_NOT_POSSIBLE_TO_DIVIDE_IN_BITCOINTREE);
//    }

    linkedList<t_node*> leafs_list; //logika tha paizw me pointers gia na grapsw kateutheian ston komvo
    getLeafs(this->root , leafs_list);
    //kane searchKeyIdFromLeafs ola ta leafs  kai apo kei pare ola ta walletId pou einia o walletId sender
    linkedList<t_node*> found_list;
    searchKeyIdFromLeafs(senderWalletId, leafs_list, found_list);
    //todo mhpws na pairna deiktes kai etsi wste na ekana eskava kateutheian panw stous komvous????
    //todo
    //todo
    //todo
    //todo
    //todo
//
//    if(key < leaf->value){
//        if(leaf->left != NULL){
//            insert(key, leaf->left);
//        }else{
//            leaf->left = new t_node;
//            leaf->left->value = key;
//            leaf->left->left = NULL;
//            leaf->left->right = NULL;
//        }
//    }else if(key >= leaf->value){
//        if(leaf->right != NULL){
//            insert(key, leaf->right);
//        }else{
//            leaf->right = new t_node;
//            leaf->right->value = key;
//            leaf->right->right = NULL;
//            leaf->right->left = NULL;
//        }
//    }

}
//
//void btree::insert(myString walletId ,int amount){
//    if(root != nullptr){
//        insert(key, root);
//    }else{
//        root = new t_node;
//        root->walletId = walletId;
//        root->amount = amount;
//        root->left = nullptr;
//        root->right = nullptr;
//    }
//}
//


//
//t_node *btree::searchKeyIdFromLeafs(int key){
//    return searchKeyIdFromLeafs(key, root);
//}
//
//void btree::destroy_tree(){
//    destroy_tree(root);
//}
//
//void btree::inorder_print(){
//    inorder_print(root);
//    cout << "\n";
//}
//
//void btree::inorder_print(t_node *leaf){
//    if(leaf != NULL){
//        inorder_print(leaf->left);
//        cout << leaf->value << ",";
//        inorder_print(leaf->right);
//    }
//}
//
//void btree::postorder_print(){
//    postorder_print(root);
//    cout << "\n";
//}
//
//void btree::postorder_print(t_node *leaf){
//    if(leaf != NULL){
//        inorder_print(leaf->left);
//        inorder_print(leaf->right);
//        cout << leaf->value << ",";
//    }
//}
//
//void btree::preorder_print(){
//    preorder_print(root);
//    cout << "\n";
//}
//
//void btree::preorder_print(t_node *leaf){
//    if(leaf != NULL){
//        cout << leaf->value << ",";
//        inorder_print(leaf->left);
//        inorder_print(leaf->right);
//    }
//}