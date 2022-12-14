#include <cstdlib>
#include <iostream>
#include <string>

#include "../header/HashTable.h"

int main() {
    Hash myHash;
    std::string name = "";

    myHash.AddItem("Paul", "Locha");
    myHash.AddItem("Kim", "Iced Mocha");
    myHash.AddItem("Emma", "Strawberry Smoothie");
    myHash.AddItem("Annie", "Hot Chocolate");
    myHash.AddItem("Sarah", "Passion Tea");
    myHash.AddItem("Pepper", "Caramel Mocha");
    myHash.AddItem("Mike", "Chai Tea");
    myHash.AddItem("Steve", "Apple Cider");
    myHash.AddItem("Bill", "Root Beer");
    myHash.AddItem("Marie", "Skinny Latte");
    myHash.AddItem("Susan", "Water");
    myHash.AddItem("Joe", "Green Tea");

    //myHash.printTable();

    //myHash.PrintItemsInBucket(0);
    //myHash.PrintItemsInBucket(9);
    //myHash.PrintItemsInBucket(8);

    // searching for a specific key and associated info testing
    while (name != "exit") {
        std::cout << "Search for a name: ";
        std::cin >> name;

        if (name != "exit") {
            myHash.findDrink(name);
        }
    }
    
}