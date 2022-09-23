#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

/**
 * Alternatively, instead of each element in the hash table array being an ItemNode pointer,
 * we could make each element (or bucket) hold a linked list so we can directly call
 * functions from the linked list class like "push_back" or "insert_ordered"
 * 
 * Also, think about taking the last number in the ASCII "index" (in hash function)
 * and taking the last digit of the ASCII number for the index using modulo
 * This will allow us to create a hashtable with only 10 elements, instead of say, 100.
 * 
 * hash % 10 will give us last digit for indices
 */

struct ItemNode {
    std::string name;
    std::string drink;
    ItemNode* next;

    ItemNode(std::string p_name, std::string p_drink) : name(p_name), drink(p_drink), next(nullptr) {}
};

class Hash {
    public:
        // constructor
        Hash();
        // destructor
        ~Hash() { delete[] hashTable; }

        // hash function
        int hash(const std::string &key);
        // add item function
        void AddItem(const std::string &name, const std::string &drink);
        // num of items in a bucket
        int numItemInBucket(int index) const; // passes in an index (bucket) as param
        // print table function
        void printTable() const;
        // print items in bucket functions
        void PrintItemsInBucket(int index) const;

    private:
        int tableSize;
        
        // creating a table using a vector: 
        // creating a vector pointer which points to the address of a vector of type ItemNode pointers
        // doing this so I can define a vector dynamically (set the size in compile time, not run time)
        //std::vector<ItemNode *>* hashhTable;

        // creating a table using an array: 
        // ItemNode pointer which points to an array of type ItemNode pointers
        ItemNode** hashTable; // pointer which stores the address of the array of type ItemNode pointers
};

#endif /*__HASHTABLE_H__*/

// think of the hashTable pointer to an array of pointers like this:
    // int* arr[SIZE]; // creates an array of type integer pointers
    // int** val = array; // val is a double pointer in which it stores
                          // the address of the array of pointers