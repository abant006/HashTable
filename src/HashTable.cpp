#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "../header/HashTable.h"

Hash::Hash() {
    tableSize = 10;
    //hashhTable = new std::vector<ItemNode *>(tableSize);

    hashTable = new ItemNode*[tableSize]; // creates an array of type Item pointers and stores its address in hashTable

    // initializes each pointer in the array to point to nullptr
    for (int i = 0; i < tableSize; i++) {
        hashTable[i] = nullptr;
    }
}

int Hash::hash(const std::string &key) {
    int hash = 0;
    int index;

    for (int i = 0; i < key.length(); i++) {
        // adding up all the ASCII values of the string passed in
        hash = hash + (int)key[i]; // type casting the letter to an int (letter -> ASCII value)
        std::cout << "hash = " << hash << std::endl;
    }

    // index is becoming lambda (loading factor)
    index = hash % this->tableSize; // taking modulo of hash/table size
    return index;
}

int arr[];