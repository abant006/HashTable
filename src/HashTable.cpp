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
    }

    // index is becoming lambda (loading factor)
    index = hash % this->tableSize; // taking modulo of hash/table size
    return index;
}

// add item function which basically works like a push back function
void Hash::AddItem(const std::string &name, const std::string &drink) {
    // holds the location in the hashtable that we want to store the information
    // call the hash function we made
    // pass the name into the hash function, and itll get the name's added ASCII value and return an index to use
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

// number of items in a bucket fucntion
int Hash::numItemInBucket(int index) const{
    int count = 0;

    // if the desired bucket is empty
    if (hashTable[index] == nullptr) {
        return 0;
    } else { // if not
        ItemNode *temp = hashTable[index]; // temp pointer that points to the top of the bucket
        
        // loops thru the bucket list and increments count for each item node visited
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
    }

    return count;
}

// prints the items at the top of each bucket, and tells how many items are in the bucket
void Hash::printTable() const {
    int number = 0; // hold the number of each item in a bucket

    for (int i = 0; i < tableSize; i++) {
        number = numItemInBucket(i); // stores the number of items in each bucket
        std::cout << "---------------------------\n";
        std::cout << "bucket/index = " << i << std::endl;

        // if the bucket is not empty, then print the top item's name and fav drink
        if (hashTable[i] != nullptr) {
            std::cout << hashTable[i]->name << std::endl;
            std::cout << hashTable[i]->drink << std::endl;
        }
        
        std::cout << "# of items = " << number << std::endl;
        std::cout << "---------------------------\n";
    }
}

// function that will print all the items within a bucket
void Hash::PrintItemsInBucket(int index) const {
    // temp ItemNode pointer that points to the first item in the desired bucket
    ItemNode *temp = hashTable[index]; 

    // if there's nothing in the bucket
    if (temp == nullptr) {
        std::cout << "Index/Bucket = " << index << " is empty" << std::endl;
    } else {
        std::cout << "Index/Bucket " << index << " contains the following items: " << std::endl;

        // loop through all the items in the bucket and print info out
        while (temp != nullptr) {
            std::cout << "---------------------------\n";
            std::cout << temp->name << std::endl;
            std::cout << temp->drink << std::endl;
            std::cout << "---------------------------\n";

            temp = temp->next;
        }
    }
}

// ffind drink function associated with a name
// avg successful search is 1 + loading factor / 2 
// avg unsuccessful search is 1 + loading factor (will search the whole bucket)
void Hash::findDrink(const std::string &name) {
    // pass the name into the hash function and it'll return an index
    int index = hash(name);
    bool foundName = false;
    std::string drink;

    // ItemNode pointer that will point to the bucket where the name is stored in
    ItemNode *temp = hashTable[index];

    while (temp != nullptr) {
        // if matching name is found
        if (temp->name == name) { // if the current item the temp pointer is pointing to's name is equal to the param name...
            foundName = true;
            drink = temp->drink; 
        }
        temp = temp->next;
    }

    // check if name is found or not
    if (foundName == true) {
        std::cout << name << "'s Favorite drink is = " << drink << std::endl;
    } else {
        std::cout << name << "'s info was not found in the Hash Table" << std::endl;
    }
}

// will remove the item in the table if it exists
void Hash::RemoveItem(const std::string &name) {
    int index = hash(name); // get the index/bucket where the name would be located

    ItemNode *delPtr = nullptr; // deleted pointer
    ItemNode *ptr1 = nullptr;
    ItemNode *ptr2 = nullptr;

    // Case 0 - bucket is empty
    if (hashTable[index] == nullptr) {
        std::cout << name << " was not found in the Hash Table!" << std::endl;
    }
    // Case 1 - only 1 item contained in bucket and that item has matching name
    else if (hashTable[index]->name == name && hashTable[index]->next == nullptr) {
        delPtr = hashTable[index];
        hashTable[index] = nullptr;
        delete delPtr;

        std::cout << name << " was removed from the Hash Table" << std::endl;
    }
    // Case 2 - match is located in the first item in the bucket, but there are more items in the bucket
    else if (hashTable[index]->name == name) {
        delPtr = hashTable[index]; // set deletion pointer to point to the first item in the bucket (matching)
        // seting the top of the bucket to be(point to) the next item in it
        hashTable[index] = hashTable[index]->next; // second item becomes first item
        delete delPtr;

        std::cout << name << " was removed from the Hash Table" << std::endl;
    }

    // Case 3 - bucket contains items but first item is not a match
    // Case 3.1 - no match
    // Case 3.2 - match is found in the additional items in the bucket
}