#include <iostream>
#include <string>
using namespace std;

// Forward declaration of College class
class College;

// Student class definition
class Student {
private:
    string name, dOB, bloodGroup, address, licenseNo, telephone;
    static string aadhar; // Static member variable shared by all Student instances

public:
    // Default constructor
    Student() {
        // Initialize member variables to default values
        name = "", dOB = "", bloodGroup = "", address = "", licenseNo = "", telephone = "";
    }

    // Method to accept student data
    void acceptStudent() {
        cout << "Enter your Name: ";
        cin >> name;
        cout << "Enter your Date of Birth: ";
        cin >> dOB;
        cout << "Enter your Blood Group: ";
        cin >> bloodGroup;
        cout << "Enter your Address: ";
        cin.get(); // Clear newline character
        getline(cin, address);
        cout << "Enter your License Number: ";
        cin >> licenseNo;
        cout << "Enter your Telephone Number: ";
        cin >> telephone;
    }

    // Friend declaration to allow College class to access private members
    friend class College;
};

// College class definition
class College {
private:
    string className;
    char division;
    int roll;

public:
    // Default constructor
    College() {
        roll = 0;
    }

    // Method to accept college data
    void acceptCollege() {
        cout << "Enter your Roll Number: ";
        cin >> roll;
        cout << "Enter your Class: ";
        cin >> className;
        cout << "Enter your Division: ";
        cin >> division;
    }

    // Method to print student and college data
    void printData(const Student &stud) {
        cout << "| Name: " << stud.name;
        cout << " | DOB: " << stud.dOB;
        cout << " | Blood Group: " << stud.bloodGroup;
        cout << " | Address: " << stud.address;
        cout << " | License: " << stud.licenseNo;
        cout << " | Telephone: " << stud.telephone;
        cout << " | Roll Number: " << roll;
        cout << " | Class: " << className;
        cout << " | Division: " << division;
        cout << endl;
    }
};

// Initialize the static member variable 'aadhar'
string Student::aadhar = "YourAadharNumber";

// Main function
int main() {
    cout << "Welcome to the Student Database System" << endl;

    Student *s[10]; // Array of Student pointers
    College *c[10]; // Array of College pointers
    int i = 0;      // Index counter

    while (1) {
        int ch;
        cout << "\nEnter 1 to Enter Student Data";
        cout << "\nEnter 2 to Display Database";
        cout << "\nEnter 3 to Delete Student Data";
        cout << "\nEnter 0 to Exit: ";
        cin >> ch;

        if (ch == 1) {
            cout << "\n**** Entering New Student Data ****" << endl;
            s[i] = new Student(); // Allocate memory for a new Student instance
            c[i] = new College(); // Allocate memory for a new College instance
            s[i]->acceptStudent(); // Accept student data
            c[i]->acceptCollege(); // Accept college data
            i++; // Increment the index counter
        } else if (ch == 2) {
            cout << "\n**** Displaying Database ****" << endl;
            for (int j = 0; j < i; j++) {
                cout << "\nStudent " << j + 1 << ":" << endl;
                c[j]->printData(*s[j]); // Print student and college data
            }
        } else if (ch == 3) {
            cout << "\n**** Deleting Student Data ****" << endl;
            if (i > 0) {
                int index;
                cout << "Enter the index of the student data to delete (1-" << i << "): ";
                cin >> index;
                if (index >= 1 && index <= i) {
                    delete s[index - 1]; // Deallocate memory for Student instance
                    delete c[index - 1]; // Deallocate memory for College instance
                    for (int j = index - 1; j < i - 1; j++) {
                        s[j] = s[j + 1]; // Shift pointers to fill the gap
                        c[j] = c[j + 1];
                    }
                    i--; // Decrement the index counter
                    cout << "Student data at index " << index << " has been deleted." << endl;
                } else {
                    cout << "Invalid index. No student data deleted." << endl;
                }
            } else {
                cout << "No student data to delete." << endl;
            }
        } else if (ch == 0) {
            for (int j = 0; j < i; j++) {
                delete s[j]; // Deallocate memory for all Student instances
                delete c[j]; // Deallocate memory for all College instances
            }
            cout << "\nExiting the Student Database System. Goodbye!" << endl;
            break;
        } else {
            cout << "\nInvalid choice. Please enter a valid option." << endl;
        }
    }
    return 0;
}
