#include <iostream>
#include <vector>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& desc) {
        tasks.push_back(Task(desc));
        cout << "Task added: " << desc << endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks available." << endl;
        } else {
            cout << "Tasks:\n";
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << (tasks[i].completed ? "[X] " : "[ ] ") << tasks[i].description << endl;
            }
        }
    }

    void deleteTask(int index) {
        if (index >= 1 && static_cast<size_t>(index) <= tasks.size()) {
            cout << "Task deleted: " << tasks[index - 1].description << endl;
            tasks.erase(tasks.begin() + index - 1);
        } else {
            cout << "Invalid task index." << endl;
        }
    }
};

int main() {
    TodoList todoList;

    while (true) {
        cout << "\n======= To-Do List Manager =======\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Delete Task\n";
        cout << "4. Exit\n";
        cout << "===================================\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter task description: ";
                cin.ignore(); // Clear the input buffer
                string description;
                getline(cin, description);
                todoList.addTask(description);
                break;
            }
            case 2:
                todoList.viewTasks();
                break;
            case 3: {
                cout << "Enter the task index to delete: ";
                int index;
                cin >> index;
                todoList.deleteTask(index);
                break;
            }
            case 4:
                cout << "Exiting the program. Bye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
