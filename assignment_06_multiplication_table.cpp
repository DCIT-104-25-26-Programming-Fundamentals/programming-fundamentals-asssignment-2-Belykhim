#include <iostream>
using namespace std;

// Part A: Print a single multiplication table from 1 to 12
void printTable(int num) {
    if (num <= 0) {
        cout << "Error: Number must be positive." << endl;
        return;
    }

    cout << "\nMultiplication Table for " << num << ":" << endl;
    for (int i = 1; i <= 12; i++) {
        cout << num << " x " << i << " = " << (num * i) << endl;
    }
}

// Part B: Print multiplication tables from 1 up to N
void printAllTables(int n) {
    if (n <= 0) {
        cout << "Error: Number must be positive." << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        printTable(i);
        if (i < n) {
            cout << "---------------------------" << endl;
        }
    }
}

int main() {
    int choice;
    cout << "=== Multiplication Table Generator ===" << endl;
    cout << "1. Single Table (Part A)" << endl;
    cout << "2. Tables from 1 to N (Part B)" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        printTable(num);
    } else if (choice == 2) {
        int n;
        cout << "Enter N: ";
        cin >> n;
        printAllTables(n);
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}