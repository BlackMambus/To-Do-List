#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct Task {
    string description;
};

vector<Task> tasks;
const string filename = "tasks.txt";

// Load tasks from file
void loadTasks() {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            tasks.push_back({line});
        }
    }
    file.close();
}

// Save tasks to file
void saveTasks() {
    ofstream file(filename);
    for (const auto& task : tasks) {
        file << task.description << endl;
    }
    file.close();
}

// Add a new task
void addTask() {
    cin.ignore();
    Task newTask;
    cout << "Enter task description: ";
    getline(cin, newTask.description);
    tasks.push_back(newTask);
    cout << "Task added.\n";
}

// View all tasks
void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    cout << "To-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description << endl;
    }
}

// Delete a task
void deleteTask() {
    int index;
    viewTasks();
    cout << "Enter task number to delete: ";
    cin >> index;
    if (index >= 1 && index <= (int)tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task deleted.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

int main() {
    loadTasks();
    int choice;
    do {
        cout << "\nTo-Do List Menu:\n";
        cout << "1. View Tasks\n";
        cout << "2. Add Task\n";
        cout << "3. Delete Task\n";
        cout << "4. Save & Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: viewTasks(); break;
            case 2: addTask(); break;
            case 3: deleteTask(); break;
            case 4: saveTasks(); cout << "Tasks saved. Goodbye!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}





