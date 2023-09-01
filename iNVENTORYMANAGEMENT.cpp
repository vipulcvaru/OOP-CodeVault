#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Class representing an inventory item
class Item {
public:
    char name[10];
    int quantity;
    int cost;
    int code;
    
    // Overloading equality operator for finding items by code
    bool operator==(const Item &i1) {
        if (code == i1.code)
            return true;
        return false;
    }
    
    // Overloading less than operator for sorting items by code
    bool operator<(const Item &i1) {
        if (code < i1.code)
            return true;
        return false;
    }
};

vector<Item> o1; // Vector to store inventory items

// Function to print an item's details
void print(Item &i1) {
    cout << "\n";
    cout << "Item Name: " << i1.name << endl;
    cout << "Item Quantity: " << i1.quantity << endl;
    cout << "Item Cost: " << i1.cost << endl;
    cout << "Item Code: " << i1.code << endl;
}

// Function to display all items in the inventory
void display() {
    cout << "\nDisplaying all items:\n";
    for_each(o1.begin(), o1.end(), print);
}

// Function to insert a new item into the inventory
void insert() {
    Item i1;
    cout << "\nEnter Item Name: ";
    cin >> i1.name;
    cout << "Enter Item Quantity: ";
    cin >> i1.quantity;
    cout << "Enter Item Cost: ";
    cin >> i1.cost;
    cout << "Enter Item Code: ";
    cin >> i1.code;
    o1.push_back(i1);
    cout << "Item added.\n";
}

// Function to search for an item by its code
void search() {
    vector<Item>::iterator p;
    Item i1;
    cout << "\nEnter Item Code to search: ";
    cin >> i1.code;
    p = find(o1.begin(), o1.end(), i1);
    if (p == o1.end()) {
        cout << "\nItem not found.\n";
    } else {
        cout << "\nItem found:\n";
        print(*p);
    }
}

// Function to delete an item from the inventory
void dlt() {
    vector<Item>::iterator p;
    Item i1;
    cout << "\nEnter Item Code to delete: ";
    cin >> i1.code;
    p = find(o1.begin(), o1.end(), i1);
    if (p == o1.end()) {
        cout << "\nItem not found.\n";
    } else {
        o1.erase(p);
        cout << "\nItem deleted.\n";
    }
}

// Function to compare items for sorting based on cost
bool compare(const Item &i1, const Item &i2) {
    return i1.cost < i2.cost;
}

int main() {
    cout << "Inventory Management System\n"; // Program header

    int ch;
    do {
        cout << "\n*** Menu ***\n";
        cout << "1. Insert\n";
        cout << "2. Display\n";
        cout << "3. Search\n";
        cout << "4. Sort\n";
        cout << "5. Delete\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                sort(o1.begin(), o1.end(), compare);
                cout << "\nSorted on Cost\n";
                display();
                break;
            case 5:
                dlt();
                break;
            case 6:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please select a valid option.\n";
        }
    } while (ch != 6);

    return 0;
}
