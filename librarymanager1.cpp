#include <iostream>
#include <vector>
using namespace std;

class publication {
protected:
    string title;
    float price;

public:
    publication() {
        title = "";
        price = 0.0;
    }

    publication(string t, float p) {
        title = t;
        price = p;
    }

    virtual void display() {
        cout << "This is a base publication." << endl;
    }
};

class book : public publication {
private:
    int pages;

public:
    book() : publication() {
        pages = 0;
    }

    book(string t, int p, float pr) : publication(t, pr) {
        if (p > 0 && pr > 0.0) {
            pages = p;
        } else {
            throw(0);
        }
    }

    void display() override {
        cout << title << "-" << price << "-" << pages << "-" << endl;
    }
};

class tape : public publication {
private:
    float minutes;

public:
    tape() : publication() {
        minutes = 0.0;
    }

    tape(string t, float p, float pr) : publication(t, pr) {
        if (p > 0 && pr > 0.0) {
            minutes = p;
        } else {
            throw(0);
        }
    }

    void display() override {
        cout << title << "-" << price << "-" << minutes << "-" << endl;
    }
};

int main() {
    vector<publication *> library;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Add Tape" << endl;
        cout << "3. Display Library" << endl;
        cout << "4. Delete Publication" << endl;
        cout << "5. Exit" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string title;
                int pages;
                float price;
                cout << "Enter book details: Title Pages Price" << endl;
                cin >> title >> pages >> price;
                try {
                    book *b = new book(title, pages, price);
                    library.push_back(b);
                    cout << "Book added." << endl;
                } catch (...) {
                    cout << "Invalid input. Book not added." << endl;
                }
                break;
            }
            case 2: {
                string title;
                float minutes, price;
                cout << "Enter tape details: Title Minutes Price" << endl;
                cin >> title >> minutes >> price;
                try {
                    tape *t = new tape(title, minutes, price);
                    library.push_back(t);
                    cout << "Tape added." << endl;
                } catch (...) {
                    cout << "Invalid input. Tape not added." << endl;
                }
                break;
            }
            case 3:
                cout << "Library Contents:" << endl;
                for (int i = 0; i < library.size(); ++i) {
                    cout << "[" << i << "] ";
                    library[i]->display();
                }
                break;
            case 4: {
                cout << "Enter the index of the publication to delete: ";
                int indexToDelete;
                cin >> indexToDelete;

                if (indexToDelete >= 0 && indexToDelete < library.size()) {
                    delete library[indexToDelete]; // Delete dynamically allocated object
                    library.erase(library.begin() + indexToDelete); // Remove from vector
                    cout << "Publication deleted." << endl;
                } else {
                    cout << "Invalid index. Publication not found." << endl;
                }
                break;
            }
            case 5:
                // Clean up and delete dynamically allocated objects
                for (publication *pub : library) {
                    delete pub;
                }
                return 0;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
                break;
        }
    }

    return 0;
}
