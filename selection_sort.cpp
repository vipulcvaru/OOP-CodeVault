#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function template for selection sort
template <typename T>
void sort(T a[], int n) {
    int min_pos;
    T temp;
    for (int i = 0; i < n - 1; i++) {
        min_pos = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_pos])
                min_pos = j;
        }
        if (min_pos != i) {
            temp = a[i];
            a[i] = a[min_pos];
            a[min_pos] = temp;
        }
    }
    cout << "\nSorted elements are: ";
    for (int i = 0; i < n; i++)
        cout << "\t" << a[i];
}

// Function template to display sorted order
template <typename T>
void displaySortedOrder(const T a[], int n) {
    cout << "\nSorted elements in ascending order: ";
    for (int i = 0; i < n; i++) {
        cout << "\t" << a[i];
    }
    cout << endl;
}

// Function template for reverse sorting
template <typename T>
void reverseSort(T a[], int n) {
    int max_pos;
    T temp;
    for (int i = 0; i < n - 1; i++) {
        max_pos = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[max_pos])
                max_pos = j;
        }
        if (max_pos != i) {
            temp = a[i];
            a[i] = a[max_pos];
            a[max_pos] = temp;
        }
    }
    cout << "\nSorted elements in descending order: ";
    for (int i = 0; i < n; i++)
        cout << "\t" << a[i];
    cout << endl;
}

// Function template to measure sorting time
template <typename T>
void measureSortingTime(T a[], int n) {
    clock_t start, end;
    start = clock();
    sort(a, n);
    end = clock();
    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "\nTime taken for sorting: " << time_taken << " seconds" << endl;
}

// Function template to generate a random array
template <typename T>
void generateRandomArray(T a[], int n) {
    srand(time(nullptr));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100; // Generating random numbers between 0 and 99
    }
    cout << "\nRandom array generated." << endl;
}

int main() {
    int n, i, ch;
    int a[100];
    float b[100];

    // Menu-driven program using a do-while loop
    do {
        cout << "\n*** Menu ***\n";
        cout << "1. Sort Integer Numbers\n";
        cout << "2. Sort Floating Point Numbers\n";
        cout << "3. Reverse Sort\n";
        cout << "4. Measure Sorting Time\n";
        cout << "5. Generate Random Array\n";
        cout << "6. Display Sorted Order\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "\nSorting integer numbers.\n";
                cout << "How many numbers to be sorted? ";
                cin >> n;
                cout << "Enter elements: ";
                for (i = 0; i < n; i++)
                    cin >> a[i];
                sort<int>(a, n);
                break;

            case 2:
                cout << "\nSorting floating-point numbers.\n";
                cout << "How many numbers to be sorted? ";
                cin >> n;
                cout << "Enter elements: ";
                for (i = 0; i < n; i++)
                    cin >> b[i];
                sort<float>(b, n);
                break;

            case 3:
                cout << "\nReverse sorting.\n";
                cout << "How many numbers to be sorted? ";
                cin >> n;
                cout << "Enter elements: ";
                for (i = 0; i < n; i++)
                    cin >> a[i];
                reverseSort<int>(a, n);
                break;

            case 4:
                cout << "\nMeasuring sorting time.\n";
                cout << "How many numbers to be sorted? ";
                cin >> n;
                cout << "Enter elements: ";
                for (i = 0; i < n; i++)
                    cin >> a[i];
                measureSortingTime<int>(a, n);
                break;

            case 5:
                cout << "\nGenerating random array.\n";
                cout << "How many numbers to be generated? ";
                cin >> n;
                generateRandomArray<int>(a, n);
                break;

            case 6:
                cout << "\nDisplaying sorted order.\n";
                displaySortedOrder<int>(a, n);
                break;

            case 7:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice. Please select a valid option.\n";
        }
    } while (ch != 7);

    return 0;
}
