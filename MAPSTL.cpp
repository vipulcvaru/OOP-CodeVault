#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    typedef map<string, int> mapType;
    mapType populationMap;

    char addMore;
    do
    {
        string state;
        int population;
        cout << "Enter state name: ";
        cin >> state;
        cout << "Enter population: ";
        cin >> population;
        populationMap[state] = population;

        cout << "Do you want to add more data? (y/n): ";
        cin >> addMore;
    } while (addMore == 'y' || addMore == 'Y');

    cout << "Total states and UTs of India with Size of populationMap: " << populationMap.size() << '\n';

    cout << "\nStates and Populations:" << endl;
    for (const auto &entry : populationMap)
    {
        cout << entry.first << " - Population: " << entry.second << " million" << endl;
    }

    int choice;
    while (true)
    {
        cout << "\n*** Menu ***" << endl;
        cout << "1. Sort by Population" << endl;
        cout << "2. Calculate Average Population" << endl;
        cout << "3. Find Largest and Smallest Population States" << endl;
        cout << "4. Update Population Data (including adding new state)" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                // Sorting code (same as before)
                break;
            case 2:
                // Calculate average population code (same as before)
                break;
            case 3:
                // Find largest and smallest populations code (same as before)
                break;
            case 4:
                {
                    string stateToUpdate;
                    int newPopulation;
                    cout << "\nEnter the state to update its population: ";
                    cin >> stateToUpdate;
                    if (populationMap.find(stateToUpdate) != populationMap.end())
                    {
                        cout << "Enter the new population: ";
                        cin >> newPopulation;
                        populationMap[stateToUpdate] = newPopulation;
                        cout << "Population updated." << endl;

                        char addNewData;
                        cout << "Do you want to add new data for this state? (y/n): ";
                        cin >> addNewData;
                        if (addNewData == 'y' || addNewData == 'Y')
                        {
                            cout << "Enter state name: ";
                            cin >> stateToUpdate;
                            cout << "Enter population: ";
                            cin >> newPopulation;
                            populationMap[stateToUpdate] = newPopulation;
                            cout << "New data added for " << stateToUpdate << "." << endl;
                        }
                    }
                    else
                    {
                        char addNewState;
                        cout << "State not found. Do you want to add a new state with population? (y/n): ";
                        cin >> addNewState;
                        if (addNewState == 'y' || addNewState == 'Y')
                        {
                            cout << "Enter state name: ";
                            cin >> stateToUpdate;
                            cout << "Enter population: ";
                            cin >> newPopulation;
                            populationMap[stateToUpdate] = newPopulation;
                            cout << "New state added: " << stateToUpdate << "." << endl;
                        }
                    }
                    break;
                }
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}
