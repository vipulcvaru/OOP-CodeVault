#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
using namespace std;

// Define a class to store state population
class StatePopulation {
public:
    int population;
};

// Create a map to store state names and corresponding populations
map<string, StatePopulation> stateMap;

// Function to insert a new state and its population
void insertState() {
    string name;
    int population;
    cout << "Enter state name: ";
    cin >> name;
    cout << "Enter population: ";
    cin >> population;
    StatePopulation statePopulation;
    statePopulation.population = population;
    stateMap[name] = statePopulation; // Insert into the map
    cout << "State added." << endl;
}

// Function to display all states and their populations
void displayAllStates() {
    cout << "States and Populations:" << endl;
    for (const auto &entry : stateMap) {
        cout << entry.first << " - Population: " << entry.second.population << endl;
    }
}

// Function to update population of a state
void updatePopulation() {
    string name;
    int newPopulation;
    cout << "Enter state name to update population: ";
    cin >> name;
    if (stateMap.find(name) != stateMap.end()) {
        cout << "Enter new population: ";
        cin >> newPopulation;
        stateMap[name].population = newPopulation; // Update population
        cout << "Population updated." << endl;
    } else {
        cout << "State not found." << endl;
    }
}

// Function to delete a state
void deleteState() {
    string name;
    cout << "Enter state name to delete: ";
    cin >> name;
    if (stateMap.find(name) != stateMap.end()) {
        stateMap.erase(name); // Erase state from the map
        cout << "State deleted." << endl;
    } else {
        cout << "State not found." << endl;
    }
}

// Function to search for states within a population range
void searchByPopulationRange() {
    int lower, upper;
    cout << "Enter lower population range: ";
    cin >> lower;
    cout << "Enter upper population range: ";
    cin >> upper;

    cout << "States within the population range [" << lower << " - " << upper << "]:" << endl;
    for (const auto &entry : stateMap) {
        if (entry.second.population >= lower && entry.second.population <= upper) {
            cout << entry.first << " - Population: " << entry.second.population << endl;
        }
    }
}

// Function to save data to a file
void saveToFile() {
    ofstream outFile("state_data.txt");
    for (const auto &entry : stateMap) {
        outFile << entry.first << " " << entry.second.population << endl;
    }
    outFile.close();
    cout << "Data saved to file." << endl;
}

// Function to load data from a file
void loadFromFile() {
    ifstream inFile("state_data.txt");
    string name;
    int population;
    while (inFile >> name >> population) {
        StatePopulation statePopulation;
        statePopulation.population = population;
        stateMap[name] = statePopulation; // Insert into the map
    }
    inFile.close();
    cout << "Data loaded from file." << endl;
}

int main() {
    int choice;

    while (true) {
        cout << "\n*** Menu ***" << endl;
        cout << "1. Insert State" << endl;
        cout << "2. Display All States" << endl;
        cout << "3. Update Population" << endl;
        cout << "4. Delete State" << endl;
        cout << "5. Search by Population Range" << endl;
        cout << "6. Save to File" << endl;
        cout << "7. Load from File" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insertState();
                break;
            case 2:
                displayAllStates();
                break;
            case 3:
                updatePopulation();
                break;
            case 4:
                deleteState();
                break;
            case 5:
                searchByPopulationRange();
                break;
            case 6:
                saveToFile();
                break;
            case 7:
                loadFromFile();
                break;
            case 8:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}
