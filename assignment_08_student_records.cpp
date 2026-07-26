#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Struct to represent a student record
struct Student {
    string name;
    int id;
    vector<double> scores;
};

// Helper function to calculate a student's average score
double calculateAverage(const Student& s) {
    if (s.scores.empty()) return 0.0;
    double sum = 0.0;
    for (double score : s.scores) {
        sum += score;
    }
    return sum / s.scores.size();
}

// Function to add a student
void addStudent(vector<Student>& students) {
    Student newStudent;
    
    cout << "Student name: ";
    cin.ignore(); // Clear newline buffer
    getline(cin, newStudent.name);

    cout << "Student ID: ";
    cin >> newStudent.id;

    int numScores;
    cout << "How many scores? ";
    cin >> numScores;

    for (int i = 0; i < numScores; i++) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        cin >> score;
        newStudent.scores.push_back(score);
    }

    students.push_back(newStudent);
    cout << "Student \"" << newStudent.name << "\" added successfully." << endl;
}

// Function to display all students
void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records available." << endl;
        return;
    }

    cout << "\n========================================================" << endl;
    cout << left << setw(10) << "ID" 
         << setw(20) << "Name" 
         << setw(15) << "Scores" 
         << setw(10) << "Average" << endl;
    cout << "--------------------------------------------------------" << endl;

    for (const auto& s : students) {
        string scoreList = "";
        for (size_t i = 0; i < s.scores.size(); i++) {
            scoreList += to_string((int)s.scores[i]);
            if (i < s.scores.size() - 1) scoreList += ", ";
        }

        cout << left << setw(10) << s.id
             << setw(20) << s.name
             << setw(15) << scoreList
             << fixed << setprecision(2) << calculateAverage(s) << endl;
    }
    cout << "========================================================\n" << endl;
}

// Function to calculate and display average for a specific student ID
void calculateStudentAverage(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records available." << endl;
        return;
    }

    int searchId;
    cout << "Enter student ID: ";
    cin >> searchId;

    for (const auto& s : students) {
        if (s.id == searchId) {
            double avg = calculateAverage(s);
            cout << s.name << "'s average score: " << fixed << setprecision(2) << avg << endl;
            return;
        }
    }

    cout << "Error: Student ID " << searchId << " not found." << endl;
}

int main() {
    vector<Student> students;
    int choice = 0;

    while (choice != 4) {
        cout << "\n================================" << endl;
        cout << "   STUDENT RECORD SYSTEM MENU   " << endl;
        cout << "================================" << endl;
        cout << "1. Add student" << endl;
        cout << "2. Display all students" << endl;
        cout << "3. Calculate average score" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                calculateStudentAverage(students);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Error: Invalid choice. Please enter a number between 1 and 4." << endl;
                break;
        }
    }

    return 0;
}