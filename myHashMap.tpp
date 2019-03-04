//
// Created by dimitrisgan on 26/2/2019.
//

#include "myHashMap.h"



unsigned hashFunction(char *str, int size_of_table) {
    unsigned hash = 5381 ;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % size_of_table;
}




//
//struct transacBucket_chain  //hash table's transacBucket
//{
//    vector<string> vector_id_bucket_chain;  // basically a transacBucket is a vector that contains pointers to already saved vector_item_id's
//
//    void add_vector_id_to_bucket_chain(string vector_id);
//    void print_bucket_chain();
//
//    const vector<string> &getVector_id_bucket_chain() const;
//};
//
////=========================================================
//
//struct hash_table
//{
//    unsigned int HT_SIZE;
//    vector<transacBucket_chain *> bucket_chain_index; //basically a hash table is a vector that contains pointers to its buckets
//
//
//    hash_table(unsigned int& HT_SIZE , LshSimple *lsh);
//
//    virtual ~hash_table();
//
//    const vector<string> &getBucket_chain_index(unsigned int& index) const;
//
//    const unsigned int  get_index2HT(myVector& q ) const;
//
//    void insert_vector_id_to_HT(string vector_id, unsigned int HT_index);
//
//    const vector<string> getFiltered_by_g_collision_chain_bucket(myVector& query ,unordered_map<string, myVector >& in_umap  ) const ;
//
//    void print_HT();
//
//};
