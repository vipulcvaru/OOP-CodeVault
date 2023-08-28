#include <iostream>
#include <algorithm> // Required for algorithms like find and sort
#include <vector> // Required for using the vector container
using namespace std;

class Item {
public:
    char name[10];
    int quantity;
    int cost;
    int code;

    // Operator for comparing items based on code
    bool operator==(const Item &i1) {
        if (code == i1.code)
            return 1;
        return 0;
    }

    // Operator for comparing items for sorting based on code
    bool operator<(const Item &i1) {
        if (code < i1.code)
            return 1;
        return 0;
    }
};

vector<Item> o1; // A vector container to store Item records

void print(Item &i1); // Function prototype for printing an Item
void display(); // Function prototype for displaying all Items
void insert(); // Function prototype for inserting an Item
void search(); // Function prototype for searching an Item
void dlt(); // Function prototype for deleting an Item

// Function to compare two items based on cost for sorting
bool compare(const Item &i1, const Item &i2) {
    return i1.cost < i2.cost;
}

int main() {
    int ch;
    do {
        cout<<"\n Welcome to grocery shop \n";
        cout << "\n*** Menu ***";
        cout << "\n1.Insert";
        cout << "\n2.Display";
        cout << "\n3.Search";
        cout << "\n4.Sort";
        cout << "\n5.Delete";
        cout << "\n6.Exit";
        cout << "\nEnter your choice:";
        cin >> ch;

        switch (ch) {
            case 1:
                insert(); // Call insert function
                break;

            case 2:
                display(); // Call display function
                break;

            case 3:
                search(); // Call search function
                break;

            case 4:
                sort(o1.begin(), o1.end(), compare); // Sort items based on cost
                cout << "\n\n Sorted on Cost";
                display(); // Call display function
                break;

            case 5:
                dlt(); // Call delete function
                break;

            case 6:
                exit(0); // Exit the program
        }
    } while (ch != 7); // Continue loop until user chooses to exit
    return 0;
}

// Function to insert an Item into the vector
void insert() {
    Item i1;
    cout << "\nEnter Item Name:";
    cin >> i1.name;
    cout << "\nEnter Item Quantity:";
    cin >> i1.quantity;
    cout << "\nEnter Item Cost:";
    cin >> i1.cost;
    cout << "\nEnter Item Code:";
    cin >> i1.code;
    o1.push_back(i1); // Add the Item to the vector
}

// Function to display all Items in the vector
void display() {
    for_each(o1.begin(), o1.end(), print); // Print each Item
}

// Function to print details of an Item
void print(Item &i1) {
    cout << "\n";
    cout << "\nItem Name:" << i1.name;
    cout << "\nItem Quantity:" << i1.quantity;
    cout << "\nItem Cost:" << i1.cost;
    cout << "\nItem Code:" << i1.code;
}

// Function to search for an Item by code
void search() {
    vector<Item>::iterator p;
    Item i1;
    cout << "\nEnter Item Code to search:";
    cin >> i1.code;
    p = find(o1.begin(), o1.end(), i1); // Search for the Item in the vector
    if (p == o1.end()) {
        cout << "\nNot found.";
    } else {
        cout << "\nFound." << endl;
        cout << "Item Name : " << p->name << endl;
        cout << "Item Quantity : " << p->quantity << endl;
        cout << "Item Cost : " << p->cost << endl;
        cout << "Item Code: " << p->code << endl;
    }
}

// Function to delete an Item by code
void dlt() {
    vector<Item>::iterator p;
    Item i1;
    cout << "\nEnter Item Code to delete:";
    cin >> i1.code;
    p = find(o1.begin(), o1.end(), i1); // Search for the Item in the vector
    if (p == o1.end()) {
        cout << "\nNot found.";
    } else {
        o1.erase(p); // Remove the Item from the vector
        cout << "\nDeleted.";
    }
}
