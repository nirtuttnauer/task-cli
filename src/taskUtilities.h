#ifndef TASK_UTILITIES_H
#define TASK_UTILITIES_H

#include <string>
#include "task.h"

std::string currentTime();
bool promptForConfirmation(const std::string &message);
void printTask(const Task &task);



#endif // TASK_UTILITIES_H