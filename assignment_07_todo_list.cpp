#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to add a task to the vector
void addTask(vector<string>& tasks) {
    cout << "Enter task: ";
    string task;
    cin.ignore(); // Clear newline character left in input buffer
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added: \"" << task << "\"" << endl;
}

// Function to view all tasks in the vector
void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your list is currently empty!" << endl;
        return;
    }

    cout << "\nYour Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << (i + 1) << ". " << tasks[i] << endl;
    }
}

// Function to delete a task by its 1-based index
void deleteTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available to delete." << endl;
        return;
    }

    viewTasks(tasks);
    cout << "Enter task number to delete: ";
    int taskNum;
    cin >> taskNum;

    if (taskNum < 1 || taskNum > static_cast<int>(tasks.size())) {
        cout << "Error: Invalid task number." << endl;
    } else {
        string removedTask = tasks[taskNum - 1];
        tasks.erase(tasks.begin() + (taskNum - 1));
        cout << "Task \"" << removedTask << "\" has been removed." << endl;
    }
}

int main() {
    vector<string> tasks;
    int choice = 0;

    while (choice != 4) {
        cout << "\n============================" << endl;
        cout << "      TO-DO LIST MENU       " << endl;
        cout << "============================" << endl;
        cout << "1. Add task" << endl;
        cout << "2. View tasks" << endl;
        cout << "3. Delete task" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
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