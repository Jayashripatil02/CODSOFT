#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to display the menu
void displayMenu() {
    cout << "\nTo-Do List Manager" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option: ";
}

// Function to add a task
void addTask(vector<string>& tasks, vector<bool>& completed)
{
    string task;
    cout << "Enter the task: ";
    cin.ignore();  // Clear the input buffer
    getline(cin, task);
    tasks.push_back(task);
    completed.push_back(false);  // Initially, the task is not completed
    cout << "Task added successfully." << endl;
}

// Function to view tasks
void viewTasks(const vector<string>& tasks, const vector<bool>& completed) {
    if (tasks.empty()) 
	{
        cout << "No tasks to show." << endl;
    } else {
        cout << "\nTasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) 
		{
            cout << i + 1 << ". " << tasks[i] << " [" << (completed[i] ? "Completed" : "Pending") << "]" << endl;
        }
    }
}

// Function to mark a task as completed
void markTaskCompleted(vector<bool>& completed) {
    int taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;
    
    if (taskNumber > 0 && taskNumber <= completed.size()) {
        completed[taskNumber - 1] = true;
        cout << "Task marked as completed." << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

// Function to remove a task
void removeTask(vector<string>& tasks, vector<bool>& completed) {
    int taskNumber;
    cout << "Enter the task number to remove: ";
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        completed.erase(completed.begin() + taskNumber - 1);
        cout << "Task removed successfully." << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

int main() {
    vector<string> tasks;  // List of tasks
    vector<bool> completed;  // Status of each task (completed or not)
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks, completed);
                break;
            case 2:
                viewTasks(tasks, completed);
                break;
            case 3:
                markTaskCompleted(completed);
                break;
            case 4:
                removeTask(tasks, completed);
                break;
            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    } while (choice != 5);
}
