#include "taskManager.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdexcept>

void TaskManager::addTask(const std::string &description)
{
    const std::string colorReset = "\033[0m";
    const std::string colorGreen = "\033[32m";
    const std::string colorCyan = "\033[36m";

    Task newTask(tasks.size() + 1, description, "todo", currentTime(), currentTime());
    tasks.push_back(newTask);
    save();

    std::cout << colorGreen << "✅ Task added successfully!" << colorReset << std::endl
              << colorCyan << "🆔: " << newTask.getId() << " | 📋: " << description << colorReset << std::endl;
}

void TaskManager::deleteTask(const std::string &taskIdStr)
{
    try
    {
        int taskId = std::stoi(taskIdStr);
        auto it = findTaskById(taskId);
        if (it != tasks.end())
        {
            tasks.erase(it);
            save();
            std::cout << "Task with ID " << taskId << " deleted successfully.\n";
        }
        else
        {
            std::cerr << "Task with ID " << taskId << " not found.\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Invalid task ID: " << taskIdStr << "\n";
    }
}

void TaskManager::updateTaskStatus(const std::string &taskIdStr)
{
    try
    {
        int taskId = std::stoi(taskIdStr);
        auto it = findTaskById(taskId);
        if (it != tasks.end())
        {
            Task &task = *it;
            std::cout << "Enter new status (1: todo, 2: in-progress, 3: done): ";
            int statusOption;
            std::cin >> statusOption;
            std::cin.ignore();

            std::string newStatus = getStatusFromOption(statusOption);
            if (!newStatus.empty())
            {
                task.setStatus(newStatus);
                task.setUpdatedAt(currentTime());
                save();
                std::cout << "Task status updated successfully.\n";
            }
            else
            {
                throw std::invalid_argument("Invalid status option.");
            }
        }
        else
        {
            std::cerr << "Task with ID " << taskId << " not found.\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

void TaskManager::editTask(const std::string &taskIdStr, const std::string &description)
{

    if (taskIdStr.empty())
    {
        std::cerr << "❌ Task ID cannot be empty.\n";
        return;
    }

    try
    {
        int taskId = std::stoi(taskIdStr);

        auto it = findTaskById(taskId);
        if (it != tasks.end())
        {
            Task &task = *it;

            std::string newDescription = description;
            if (newDescription.empty())
            {
                std::cout << "Enter new description: ";
                std::getline(std::cin, newDescription);
            }

            if (newDescription.empty())
            {
                std::cerr << "❌ Description cannot be empty.\n";
                return;
            }

            task.setDescription(newDescription);
            task.setUpdatedAt(currentTime());
            save();
            std::cout << "✅ Task updated successfully.\n";
        }
        else
        {
            std::cerr << "❌ Task with ID " << taskId << " not found.\n";
        }
    }
    catch (const std::invalid_argument &)
    {
        std::cerr << "❌ Invalid task ID: " << taskIdStr << ". Task ID must be a number.\n";
    }
    catch (const std::out_of_range &)
    {
        std::cerr << "❌ Task ID is out of range: " << taskIdStr << ".\n";
    }
}

void TaskManager::listTasks(const std::string &status)
{
    auto filteredTasks = filterTasksByStatus(status);
    if (filteredTasks.empty())
    {
        std::cout << "No tasks found.\n";
        return;
    }

    for (const auto &task : filteredTasks)
    {
        printTask(task);
    }
}

void TaskManager::markTaskAsInProgress(const std::string &taskIdStr){
    try {
        int taskId = std::stoi(taskIdStr);
        auto it = findTaskById(taskId);
        if (it != tasks.end())
        {
            Task &task = *it;
            task.setStatus("in-progress");
            task.setUpdatedAt(currentTime());
            save();
            std::cout << "Task marked as in-progress.\n";
        }
        else
        {
            std::cerr << "Task with ID " << taskId << " not found.\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Invalid task ID: " << taskIdStr << "\n";
    }
}
void TaskManager::markTaskAsDone(const std::string &taskIdStr){
    try {
        int taskId = std::stoi(taskIdStr);
        auto it = findTaskById(taskId);
        if (it != tasks.end())
        {
            Task &task = *it;
            task.setStatus("done");
            task.setUpdatedAt(currentTime());
            save();
            std::cout << "Task marked as done.\n";
        }
        else
        {
            std::cerr << "Task with ID " << taskId << " not found.\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Invalid task ID: " << taskIdStr << "\n";
    }
}
void TaskManager::unmarkTask(const std::string &taskIdStr){
    try {
        int taskId = std::stoi(taskIdStr);
        auto it = findTaskById(taskId);
        if (it != tasks.end())
        {
            Task &task = *it;
            task.setStatus("todo");
            task.setUpdatedAt(currentTime());
            save();
            std::cout << "Task unmarked.\n";
        }
        else
        {
            std::cerr << "Task with ID " << taskId << " not found.\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Invalid task ID: " << taskIdStr << "\n";
    }
}

//utils
std::vector<Task> TaskManager::filterTasksByStatus(const std::string &status) const
{
    if (status.empty())
        return tasks;

    std::vector<Task> filteredTasks;
    std::copy_if(tasks.begin(), tasks.end(), std::back_inserter(filteredTasks), [&status](const Task &task) {
        return task.getStatus() == status;
    });
    return filteredTasks;
}

std::string TaskManager::getStatusFromOption(int option) const
{
    switch (option)
    {
    case 1:
        return "todo";
    case 2:
        return "in-progress";
    case 3:
        return "done";
    default:
        return "";
    }
}
std::vector<Task>::iterator TaskManager::findTaskById(int taskId)
{
    return std::find_if(tasks.begin(), tasks.end(), [taskId](const Task &task) {
        return task.getId() == taskId;
    });
}
