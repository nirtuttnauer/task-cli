#include "tasks/taskManager.h"
#include "utils/tasks/taskUtilities.h"

// Constructor and Destructor
TaskManager::TaskManager(const char *fileName) : fileName(fileName), jsonFile(fileName)
{
    load();
    if (tasks.empty())
    {
        this->jsonFile.create();
    }
}

TaskManager::~TaskManager()
{
    save();
}

// Command Processing
void TaskManager::processCommand(const std::string &command, const std::string &argument , const std::string &extra)
{
    if (command == "add")
    {
        addTask(argument);
    }
    else if (command == "list")
    {
        listTasks(argument);
    }
    else if (command == "delete")
    {
        deleteTask(argument);
    }
    else if (command == "edit")
    {
        editTask(argument , extra);
    }
    else if (command == "mark-in-progress"){
        markTaskAsInProgress(argument);
    }
    else if (command == "mark-done"){
        markTaskAsDone(argument);
    }
    else if (command == "unmark"){
        unmarkTask(argument);
    }
    else if (command == "status")
    {
        updateTaskStatus(argument);
    }
    else if (command == "clear")
    {
        clear();
    }
    else
    {
        std::cerr << "\033[31m❌ Unknown command: " << command << "\033[0m" << std::endl;
    }
}

// Saving and Loading
void TaskManager::save()
{
    jsonFile.saveToFile(tasks);
}

void TaskManager::load()
{
    tasks = jsonFile.loadFromFile();
}

void TaskManager::clear()
{
    tasks.clear();
    save();
    std::cout << "All tasks cleared.\n";
}