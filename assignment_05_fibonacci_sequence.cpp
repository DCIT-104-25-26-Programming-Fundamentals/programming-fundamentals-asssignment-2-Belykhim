#include <iostream>
using namespace std;

// Part A: Print the first N terms of the Fibonacci sequence
void printFibonacci(int n) {
    if (n <= 0) {
        cout << "Error: Number of terms must be positive." << endl;
        return;
    }

    cout << "Fibonacci sequence: ";
    long long first = 0, second = 1;

    for (int i = 1; i <= n; i++) {
        cout << first << (i == n ? "" : " ");
        long long next = first + second;
        first = second;
        second = next;
    }
    cout << endl;
}

// Part B: Check if a given number belongs to the Fibonacci sequence
bool isFibonacci(long long num) {
    if (num < 0) return false;
    if (num == 0 || num == 1) return true;

    long long first = 0, second = 1, next = first + second;

    while (next <= num) {
        if (next == num) {
            return true;
        }
        first = second;
        second = next;
        next = first + second;
    }

    return false;
}

int main() {
    int choice;
    cout << "=== Fibonacci Sequence Operations ===" << endl;
    cout << "1. Print the first N terms" << endl;
    cout << "2. Check if a number belongs to the sequence" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        int n;
        cout << "How many terms? ";
        cin >> n;
        printFibonacci(n);
    } else if (choice == 2) {
        long long num;
        cout << "Enter a number to check: ";
        cin >> num;
        if (isFibonacci(num)) {
            cout << num << " is a Fibonacci number." << endl;
        } else {
            cout << num << " is NOT a Fibonacci number." << endl;
        }
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}