#include <iostream>
#include <vector>
#include <string>

class ToDoListManager {
private:
    std::vector<std::string> tasks; // Store tasks

public:
    void addTask(const std::string& task) { 
        tasks.push_back(task); 
        std::cout << "Task added successfully!\n"; 
    }

    void removeTask(int index) {
        if (index < 1 || index > tasks.size()) {
            std::cout << "Invalid task number.\n"; 
        } else {
            tasks.erase(tasks.begin() + (index - 1));
            std::cout << "Task removed successfully!\n";
        }
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks available.\n"; 
        } else {
            std::cout << "To-Do List:\n";
            for (size_t i = 0; i < tasks.size(); ++i)
                std::cout << i + 1 << ". " << tasks[i] << "\n";
        }
    }
};

void displayMenu() {
    std::cout << "\n--- To-Do List Manager ---\n";
    std::cout << "1. Add Task\n2. Remove Task\n3. View Tasks\n4. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    ToDoListManager manager; int choice;
    do {
        displayMenu();
        std::cin >> choice; std::cin.ignore();
        switch (choice) {
        case 1: {
            std::cout << "Enter the task: ";
            std::string task; std::getline(std::cin, task);
            manager.addTask(task);
            break;
        }
        case 2: {
            std::cout << "Enter the task number to remove: ";
            int index; std::cin >> index;
            manager.removeTask(index);
            break;
        }
        case 3: manager.viewTasks(); break;
        case 4: std::cout << "Exiting the program. Goodbye!\n"; break;
        default: std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
    return 0;
}
