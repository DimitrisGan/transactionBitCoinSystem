//
// Created by dimitrisgan on 2/3/2019.
//

#include <assert.h>
#include "bitcoinTree.h"
#include "transaction.h"


btc_tree::btc_tree( myString initWalletIdOwner , int initialBtcValue){

    root = new t_node (initWalletIdOwner, initialBtcValue, nullptr, nullptr);

}

btc_tree::~btc_tree(){
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


/*take the leaf nodes of the tree*/
//https://www.geeksforgeeks.org/print-leaf-nodes-left-right-binary-tree/
void  getLeafs(t_node *root , linkedList<t_node*>  &leafs_list)
{
    // if node is null, return
    if (!root)
        return;

    // if node is leaf node, insert its data
    if (!root->left && !root->right)
    {
        leafs_list.insert_last(root);
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

/*find-retrieve these with the specific walletId*/
void searchKeyIdFromLeafs(myString keyWalletId, linkedList<t_node*> &leafs_list, linkedList<t_node*> &found_list){

    for ( auto &item : leafs_list) {
        if (item->walletId == keyWalletId)
            found_list.insert_last(item);
    }

}



/*basically inserts all the amount asked for the transcation in the tree.
 * Thus, can add more than 2 nodes in the tree*/
void btc_tree::insert(myString senderWalletId, myString receiverWalletId, int amount , linkedList<t_node*> &returnPtrs2t_nodes ){


    linkedList<t_node*> leafs_list; //play with pointers to write/insert directly in the tree
    getLeafs(this->root , leafs_list);

    /*search all leafs and take the ones that the key is identical*/
    linkedList<t_node*> found_list;
    searchKeyIdFromLeafs(senderWalletId, leafs_list, found_list);

    int amountLeft = amount;
    for (const auto &senderLeafNode : found_list) {

        if ( amountLeft <= senderLeafNode->amount){ //means that we only need one node too add
            //and also that [the newly created node]will take only the amountLeft2add because is less than the potential amount to give

            returnPtrs2t_nodes.insert_last(senderLeafNode); //add a pointer to the t_node before we insert children

            this->insert(receiverWalletId ,amountLeft , senderLeafNode);
            amountLeft = 0;
            break;

        }
        else{ //means that the amount of the node is not enough thus we need to add another node

            returnPtrs2t_nodes.insert_last(senderLeafNode); //add a pointer to the t_node before we insert children

            this->insert(receiverWalletId ,senderLeafNode->amount /*node can give only the amount that contains*/ , senderLeafNode);
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
    this->transac_ptr= nullptr;

}

t_node& t_node::operator=(const t_node &rhs) {
    walletId = rhs.walletId;
    amount = rhs.amount;
    left = rhs.left ;
    right = rhs.right;
    this->transac_ptr = right->transac_ptr;

    return *this;
}

bool t_node::operator!=( t_node rhs)  {
    return !(rhs == *this);
}

bool t_node::operator==(t_node rhs) {
    return walletId == rhs.walletId && amount == rhs.amount && left ==rhs.left && right == rhs.right;
}

t_node::t_node( myString walletId, int amount, t_node *left, t_node *right) : walletId(walletId), amount(amount),
                                                                              left(left), right(right) {this->transac_ptr= nullptr;}

t_node::t_node() {}


/*digs the given node
 * and inserts 2 nodes
 * Left  : the receiver user
 * Right : the remain amount of sender user
 * */
void btc_tree::insert(myString receiverWalletID ,int amountToSend , t_node* senderNode) //inserts 2 t_node
{

    senderNode->left = new t_node;
    senderNode->left->fillNode(receiverWalletID,amountToSend, nullptr, nullptr);

    int amountRemain = senderNode->amount - amountToSend;
    assert(amountRemain >=0);

    senderNode->right = new t_node;
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


btc_tree::btc_tree( btc_tree &rhs) /*here we achieve deep copy of the btc_tree*/
        : root(new t_node(*rhs.root)){}

// recursively call copy constructor

t_node::t_node( t_node &n) : walletId(n.walletId) , amount(n.amount) ,left(nullptr) ,right(nullptr){

    if (n.left)
        left = new t_node(*n.left);
    if (n.right)
        right = new t_node(*n.right);
}


void t_node::setTransac_ptr(transaction *transac_ptr) {
    t_node::transac_ptr = transac_ptr;
}

/*get all the transactions[Ids] that the current btc is involved*/
void btc_tree::getUniqueTransacIdsList(t_node *node, linkedList<myString> &transIdUnique_list) { //with the help of preorder traverse

    if (!node)
        return;
    if ( node->transac_ptr) {
        if (!transIdUnique_list.exists(
                node->transac_ptr->transacId)) { //if the transaction Id doesnt exist then push it to the list
            transIdUnique_list.insert_last(node->transac_ptr->transacId);
        }
    }
    getUniqueTransacIdsList(node->left, transIdUnique_list);
    getUniqueTransacIdsList(node->right, transIdUnique_list);

}

/*get all the transactions that the current btc is involved*/
void btc_tree::getUniqueTransacList(t_node *node, linkedList<transaction*> &trans_list) { //with the help of preorder traverse

    {
        if (!node)
            return;
        if ( node->transac_ptr) {
            if (!trans_list.exists(
                    node->transac_ptr)) { //if the transaction Id doesnt exist then push it to the list
                trans_list.insert_last(node->transac_ptr);
            }
        }

        getUniqueTransacList(node->left, trans_list);
        getUniqueTransacList(node->right, trans_list);
    }
}

bool btc_tree::hasUnspentAmount(t_node *node) {

    if (node->right)
        return hasUnspentAmount(node->right);

    return node->walletId == root->walletId && node->amount!=0;

}


int btc_tree::getUnspentAmount(t_node *node) {

    if (node->right)
        return getUnspentAmount(node->right);

    return node->amount;

}






//next time these will be implemented

//TreeNode::TreeNode(const TreeNode &n)
//        : value(n.value), count(n.count), left(nullptr), right(nullptr) {
//    if (n.left)
//        left = new TreeNode(*n.left);  // recursively call copy constructor
//    if (n.right)
//        right = new TreeNode(*n.right);  // recursively call copy constructor
//}

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