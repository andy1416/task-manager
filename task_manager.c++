#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Define a struct for representing a task
struct Task {
    string description; // Description of the task
    bool completed;     // Flag indicating whether the task is completed or not
};

// Define a class to manage tasks
class TaskManager {
private:
    vector<Task> tasks; // Vector to store tasks

public:
    // Method to add a new task to the list
    void addTask(const string& description) {
        Task newTask;
        newTask.description = description;
        newTask.completed = false;
        tasks.push_back(newTask);
        cout << "Task added successfully." << endl;
    }

    // Method to delete a task from the list
    void deleteTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
            cout << "Task deleted successfully." << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    // Method to mark a task as completed
    void markTaskCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            cout << "Task marked as completed." << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    // Method to display all tasks in the list
    void displayTasks() {
        cout << "Task List:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i+1 << ". "; // Index of the task
            if (tasks[i].completed)
                cout << "[X] "; // Mark as completed if true
            else
                cout << "[ ] "; // Mark as incomplete if false
            cout << tasks[i].description << endl; // Task description
        }
    }
};

int main() {
    TaskManager taskManager;
    int choice;

    // Main menu loop
    do {
        // Display menu options
        cout << "\nTask Manager Menu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Delete Task" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Display Tasks" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
                string description;
                cout << "Enter task description: ";
                getline(cin, description); // Read task description
                taskManager.addTask(description);
                break;
            }
            case 2: {
                int index;
                cout << "Enter index of task to delete (example: 1, 2, 3, ...): ";
                cin >> index;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
                taskManager.deleteTask(index - 1); // Subtract 1 to convert to zero-based index
                break;
            }
            case 3: {
                int index;
                cout << "Enter index of task to mark as completed (example: 1, 2, 3, ...): ";
                cin >> index;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
                taskManager.markTaskCompleted(index - 1); // Subtract 1 to convert to zero-based index
                break;
            }
            case 4:
                taskManager.displayTasks();
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 5); // Continue until user chooses to exit

    return 0;
}