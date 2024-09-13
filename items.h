#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>
#include <iomanip>  // For std::setw

// Maximum number of items that can be stored
const int MAX_ITEMS = 50;

// Class to manage items with their codes and prices
class ITEMS {
    int itemCode[MAX_ITEMS];
    float itemPrice[MAX_ITEMS];
    int count;  // Number of items currently stored

public:
    // Constructor to initialize the count
    ITEMS();

    // Function to add an item
    void addItem();

    // Function to display the total value of all items
    void displayTotalValue() const;

    // Function to remove an item based on item code
    void removeItem();

    // Function to display all items with their codes and prices
    void displayItems() const;

private:
    // Utility function to find the index of an item by code
    int findItemIndex(int code) const;
    
    // Utility function to check if an item code already exists
    bool itemCodeExists(int code) const;
};

#endif // ITEMS_H
