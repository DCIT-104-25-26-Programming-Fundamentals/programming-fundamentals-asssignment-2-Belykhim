#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function for Addition
double addNumbers(double a, double b) {
    return a + b;
}

// Function for Subtraction
double subtractNumbers(double a, double b) {
    return a - b;
}

// Function for Multiplication
double multiplyNumbers(double a, double b) {
    return a * b;
}

// Function for Division
void divideNumbers(double a, double b) {
    if (b == 0) {
        cout << "Error: Cannot divide by zero." << endl;
    } else {
        cout << "Result: " << a << " / " << b << " = " 
             << fixed << setprecision(2) << (a / b) << endl;
    }
}

// Function for Modulus (uses integers)
void modulusNumbers(int a, int b) {
    if (b == 0) {
        cout << "Error: Cannot perform modulus by zero." << endl;
    } else {
        cout << "Result: " << a << " % " << b << " = " << (a % b) << endl;
    }
}

// Function for Exponentiation
double powerNumbers(double base, double exponent) {
    return pow(base, exponent);
}

int main() {
    int choice = 0;

    while (choice != 7) {
        cout << "\n============================" << endl;
        cout << "      SIMPLE CALCULATOR     " << endl;
        cout << "============================" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Modulus" << endl;
        cout << "6. Exponentiation" << endl;
        cout << "7. Quit" << endl;
        cout << "Select an operation (1-7): ";
        cin >> choice;

        if (choice >= 1 && choice <= 6) {
            if (choice == 5) {
                int num1, num2;
                cout << "Enter first number: ";
                cin >> num1;
                cout << "Enter second number: ";
                cin >> num2;
                modulusNumbers(num1, num2);
            } else {
                double num1, num2;
                cout << "Enter first number: ";
                cin >> num1;
                cout << "Enter second number: ";
                cin >> num2;

                cout << fixed << setprecision(2);
                switch (choice) {
                    case 1:
                        cout << "Result: " << num1 << " + " << num2 << " = " << addNumbers(num1, num2) << endl;
                        break;
                    case 2:
                        cout << "Result: " << num1 << " - " << num2 << " = " << subtractNumbers(num1, num2) << endl;
                        break;
                    case 3:
                        cout << "Result: " << num1 << " * " << num2 << " = " << multiplyNumbers(num1, num2) << endl;
                        break;
                    case 4:
                        divideNumbers(num1, num2);
                        break;
                    case 6:
                        cout << "Result: " << num1 << " ^ " << num2 << " = " << powerNumbers(num1, num2) << endl;
                        break;
                }
            }
        } else if (choice == 7) {
            cout << "Goodbye!" << endl;
        } else {
            cout << "Error: Invalid selection. Please enter a number between 1 and 7." << endl;
        }
    }

    return 0;
}