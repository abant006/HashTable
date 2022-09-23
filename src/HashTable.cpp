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

// add item function which basically works like a push back function
void Hash::AddItem(const std::string &name, const std::string &drink) {
    // holds the location in the hashtable that we want to store the information
    // call the hash function we made
    int index = hash(name);

    // if the bucket we want to insert into in the hashtable is pointing to nullptr, then it's empty
    if (hashTable[index] == nullptr) {
        // gets the pointer at the desired bucket, and point it to a newly created Item node
        hashTable[index] = new ItemNode(name, drink);
    } else { // if not, then the bucket already stores an item
        // temp ItemNode pointer
        ItemNode *temp = hashTable[index]; // points to the first item in the desired bucket
        ItemNode *n = new ItemNode(name, drink); // another pointer which points to a new item we are adding at the bucket

        // temp starts at the "head node" of the desired bucket
        // loop until temp reaches the end of the list in the bucket
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        // now temp is pointing to the last item in the list
        temp->next = n; // links the last item to the newly created item n is pointing to
    }
}
