#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "json/jsonManager.h"
#include "utils/tasks/taskUtilities.h"

class TaskManager {
    // Member variables
    jsonManager jsonFile;
    std::vector<Task> tasks;
    std::string fileName;

public:
    // Constructor and Destructor
    explicit TaskManager(const char *fileName);
    ~TaskManager();

    // Public API
    void processCommand(const std::string &command, const std::string &argument , const std::string &extra);

    void addTask(const std::string &description);
    void listTasks(const std::string &status = "");
    void deleteTask(const std::string &taskIdStr);
    void editTask(const std::string &taskIdStr ,const std::string &description);
    void updateTaskStatus(const std::string &taskIdStr);
    void printHelp();

    void unmarkTask(const std::string &taskIdStr);
    void markTaskAsInProgress(const std::string &taskIdStr);
    void markTaskAsDone(const std::string &taskIdStr);

    // Utilities
    std::vector<Task> filterTasksByStatus(const std::string &status) const;
    std::string getStatusFromOption(int option) const;
    std::vector<Task>::iterator findTaskById(int taskId);

private:
    // Internal Helpers
    void save();
    void load();
    void clear();
};

#endif // TASK_MANAGER_H