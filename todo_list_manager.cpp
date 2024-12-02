#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class ToDoListManager {
private:
    std::vector<std::string> tasks;

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

    void editTask(int index, const std::string& newTask) {
        if (index < 1 || index > tasks.size()) {
            std::cout << "Invalid task number.\n";
        } else {
            tasks[index - 1] = newTask;
            std::cout << "Task updated successfully!\n";
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

    void saveTasks(const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const auto& task : tasks) {
                file << task << "\n";
            }
            file.close();
            std::cout << "Tasks saved to " << filename << " successfully!\n";
        } else {
            std::cout << "Error saving tasks.\n";
        }
    }

    void loadTasks(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            tasks.clear();
            std::string line;
            while (std::getline(file, line)) {
                tasks.push_back(line);
            }
            file.close();
            std::cout << "Tasks loaded from " << filename << " successfully!\n";
        } else {
            std::cout << "Error loading tasks.\n";
        }
    }
};

void displayMenu() {
    std::cout << "\n--- To-Do List Manager ---\n";
    std::cout << "1. Add Task\n2. Remove Task\n3. Edit Task\n";
    std::cout << "4. View Tasks\n5. Save Tasks\n6. Load Tasks\n7. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    ToDoListManager manager;
    int choice;
    std::string filename = "tasks.txt";

    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: {
            std::cout << "Enter the task: ";
            std::string task;
            std::getline(std::cin, task);
            manager.addTask(task);
            break;
        }
        case 2: {
            std::cout << "Enter the task number to remove: ";
            int index;
            std::cin >> index;
            manager.removeTask(index);
            break;
        }
        case 3: {
            std::cout << "Enter the task number to edit: ";
            int index;
            std::cin >> index;
            std::cin.ignore();
            std::cout << "Enter the new task: ";
            std::string newTask;
            std::getline(std::cin, newTask);
            manager.editTask(index, newTask);
            break;
        }
        case 4:
            manager.viewTasks();
            break;
        case 5:
            manager.saveTasks(filename);
            break;
        case 6:
            manager.loadTasks(filename);
            break;
        case 7:
            std::cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
