//
// Created by dimitrisgan on 26/2/2019.
//

#ifndef TRANSACTIONBITCOINSYSTEM_MYHASHTABLE_H
#define TRANSACTIONBITCOINSYSTEM_MYHASHTABLE_H

unsigned hashFunction(char *str, int size_of_table);



// https://www.quora.com/How-do-I-implement-a-hash-table-and-a-hash-map-in-C++

struct MyKeyHash {
    unsigned long operator()(const int& k) const
    {
        return k % 10;
    }
};


// Default hash function class
template <typename K, unsigned tableSize>
struct KeyHash {
    unsigned long operator()(const K &key) const
    {
        return reinterpret_cast<unsigned long>(key) % tableSize;
    }
};

// Hash l_node class template
template <typename K, typename V>
class HashEntry {
public:
    HashEntry(const K &key, const V &value) :
            key(key), value(value) {
    }

    K getKey() const {
        return key;
    }

    V getValue() const {
        return value;
    }

    void setValue(V value) {
        HashEntry::value = value;
    }



private:
    // key-value pair
    K key;
    V value;
};






///todo ayrio tha ulopoihsw to katw me voitheia tou panw gia ta templates
//todo2 getopt()
// *********************************************



//template <typename K, typename V>
template <typename K, typename V, unsigned tableSize, typename F = KeyHash<K, tableSize> >
class HashMap {

private:

    HashEntry<K,V> **table;
    F hashFunc;

public:

    HashMap() {

        table = new HashEntry<K, V> *[tableSize];

        for (int i = 0; i < tableSize; i++)
            table[i] = nullptr; //todo maybe initialize the pointer
    }

    ~HashMap() {

        for (int i = 0; i < tableSize; i++)

            if (table[i] != nullptr)

                delete table[i];

        delete[] table;

    }



    bool freeSpaceExist2insertRecordInBucket();

//    bool get(const K &key, V &value)
//    {
//        unsigned long hashValue = hashFunc(key);
//        HashNode<K, V> *entry = table[hashValue];
//
//        while (entry != NULL) {
//            if (entry->getKey() == key) {
//                value = entry->getValue();
//                return true;
//            }
//
//            entry = entry->getNext();
//        }
//
//        return false;
//    }
//
//    void put(int key, int value) {
//
//        int hash = (key % TableSize);
//
//        while (table[hash] != NULL && table[hash]->getKey() != key)
//
//            hash = (hash + 1) % TableSize;
//
//        if (table[hash] != NULL)
//
//            delete table[hash];
//
//        table[hash] = new HashEntry(key, value);
//
//    }





};








//
//struct bucket_chain  //hash table's bucket
//{
//    vector<string> vector_id_bucket_chain;  // basically a bucket is a vector that contains pointers to already saved vector_item_id's
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
//    vector<bucket_chain *> bucket_chain_index; //basically a hash table is a vector that contains pointers to its buckets
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





#endif //TRANSACTIONBITCOINSYSTEM_MYHASHTABLE_H
