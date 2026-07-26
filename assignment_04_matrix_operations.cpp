#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

// Helper function to print a matrix in a clean grid layout
void printMatrix(const int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}

// Helper function to input elements into a matrix
void readMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols, const string& name) {
    cout << "Enter elements for Matrix " << name << " (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "  Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

// Part A: Transpose a Matrix
void transposeMatrix(const int src[MAX_SIZE][MAX_SIZE], int dest[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dest[j][i] = src[i][j];
        }
    }
}

// Part B: Add Two Matrices
void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Part C: Multiply Two Matrices
void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int choice;
    cout << "=== Matrix Operations ===" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    if (choice == 1) {
        int rows, cols;
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        int mat[MAX_SIZE][MAX_SIZE];
        int transposed[MAX_SIZE][MAX_SIZE];

        readMatrix(mat, rows, cols, "A");

        cout << "\nOriginal Matrix:" << endl;
        printMatrix(mat, rows, cols);

        transposeMatrix(mat, transposed, rows, cols);

        cout << "\nTransposed Matrix:" << endl;
        printMatrix(transposed, cols, rows);

    } else if (choice == 2) {
        int rows, cols;
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], sum[MAX_SIZE][MAX_SIZE];

        readMatrix(A, rows, cols, "A");
        readMatrix(B, rows, cols, "B");

        addMatrices(A, B, sum, rows, cols);

        cout << "\nResultant Matrix (A + B):" << endl;
        printMatrix(sum, rows, cols);

    } else if (choice == 3) {
        int m, n, p;
        cout << "Enter rows for Matrix A (M): ";
        cin >> m;
        cout << "Enter columns for Matrix A / rows for Matrix B (N): ";
        cin >> n;
        cout << "Enter columns for Matrix B (P): ";
        cin >> p;

        int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], product[MAX_SIZE][MAX_SIZE];

        readMatrix(A, m, n, "A");
        readMatrix(B, n, p, "B");

        multiplyMatrices(A, B, product, m, n, p);

        cout << "\nResultant Matrix (A x B):" << endl;
        printMatrix(product, m, p);

    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}