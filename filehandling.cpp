#include <iostream>
#include <fstream>
#include <vector> // For using vector container
using namespace std;

int main() {
    ofstream o1;
    o1.open("temp1.txt", ios::app); // Open the file in append mode

    if (!o1.is_open()) {
        cout << "Error opening file for writing." << endl;
        return 1;
    }

    ifstream i1;
    vector<string> lines; // Store lines of the file
    string s;
    bool exitFlag = false;

    while (!exitFlag) {
        cout << "Menu:\n";
        cout << "1. Write text\n";
        cout << "2. Add text\n";
        cout << "3. Delete text\n";
        cout << "4. Display text\n";
        cout << "5. Exit\n";
        
        int choice;
        cin >> choice;
        cin.ignore(); // Clear the newline character

        switch (choice) {
            case 1:
            case 2:
                cout << "Enter text: ";
                getline(cin, s);
                o1 << s << endl; // Write to the file
                break;
            case 3:
                cout << "Enter the line number to delete: ";
                int lineNumber;
                cin >> lineNumber;
                cin.ignore(); // Clear the newline character

                i1.open("temp1.txt", ios::in);

                if (!i1.is_open()) {
                    cout << "Error opening file for reading." << endl;
                    return 1;
                }

                lines.clear();
                while (getline(i1, s)) {
                    lines.push_back(s); // Store each line in the vector
                }

                i1.close();

                if (lineNumber >= 1 && lineNumber <= lines.size()) {
                    lines.erase(lines.begin() + lineNumber - 1); // Remove the specified line
                    o1.open("temp1.txt", ios::out | ios::trunc); // Open in write mode, truncating existing content
                    for (const string &line : lines) {
                        o1 << line << endl; // Write the modified lines back to the file
                    }
                    o1.close();
                    cout << "Line " << lineNumber << " deleted." << endl;
                } else {
                    cout << "Invalid line number." << endl;
                }
                break;
            case 4:
                cout << "File contents:\n";
                i1.open("temp1.txt", ios::in);

                if (!i1.is_open()) {
                    cout << "Error opening file for reading." << endl;
                    return 1;
                }

                while (getline(i1, s)) {
                    cout << s << endl; // Display the contents of the file
                }

                i1.close();
                break;
            case 5:
                cout << "Exiting..." << endl;
                exitFlag = true;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    o1.close();
    return 0;
}
