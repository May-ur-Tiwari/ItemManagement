#include "items.h"
using namespace std;

ITEMS::ITEMS() {
    count = 0;
}

void ITEMS::addItem() {
    if (count >= MAX_ITEMS) {
        cout << "Cannot add more items. Inventory full." << endl;
        return;
    }
    
    int code;
    cout << "Enter item code: ";
    cin >> code;
    
    // Check for duplicate item code
    if (itemCodeExists(code)) {
        cout << "Item code already exists! Please enter a unique code." << endl;
        return;
    }
    
    float price;
    cout << "Enter item cost: ";
    cin >> price;
    
    itemCode[count] = code;
    itemPrice[count] = price;
    count++;
    cout << "Item added successfully!" << endl;
}

void ITEMS::displayTotalValue() const {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += itemPrice[i];
    }
    cout << "\nTotal value of all items: " << sum << endl;
}

void ITEMS::removeItem() {
    int code;
    cout << "Enter item code to remove: ";
    cin >> code;

    int index = findItemIndex(code);
    if (index != -1) {
        // Shift items to the left to fill the gap
        for (int i = index; i < count - 1; i++) {
            itemCode[i] = itemCode[i + 1];
            itemPrice[i] = itemPrice[i + 1];
        }
        count--;  // Decrement the count
        cout << "Item removed successfully!" << endl;
    } else {
        cout << "Item not found!" << endl;
    }
}

void ITEMS::displayItems() const {
    if (count == 0) {
        cout << "No items to display." << endl;
        return;
    }

    cout << "\nCode   Price" << endl;
    cout << "--------------" << endl;
    for (int i = 0; i < count; i++) {
        cout << setw(4) << itemCode[i] << "   " << fixed << setprecision(2) << itemPrice[i] << endl;
    }
}

int ITEMS::findItemIndex(int code) const {
    for (int i = 0; i < count; i++) {
        if (itemCode[i] == code) {
            return i;
        }
    }
    return -1;  // Return -1 if item is not found
}

bool ITEMS::itemCodeExists(int code) const {
    for (int i = 0; i < count; i++) {
        if (itemCode[i] == code) {
            return true;  // Return true if item code already exists
        }
    }
    return false;  // Return false if item code does not exist
}
