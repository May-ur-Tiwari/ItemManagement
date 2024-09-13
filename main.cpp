#include "items.h"
using namespace std;

void displayMenu() {
    cout << "\nChoose an option:\n";
    cout << "1: Add an item\n";
    cout << "2: Display total value\n";
    cout << "3: Remove an item\n";
    cout << "4: Display all items\n";
    cout << "5: Quit\n";
    cout << "Enter your choice: ";
}

int main() {
    ITEMS order;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                order.addItem();
                break;
            case 2:
                order.displayTotalValue();
                break;
            case 3:
                order.removeItem();
                break;
            case 4:
                order.displayItems();
                break;
            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
