#include "taskManager.h"
#include <iostream>
#include <vector>
#include <cassert>


int main(int argc, char *argv[]) {
    // Run tests if needed
    // tests();

    // Validate argument count
    if (argc < 2 || argc > 4) {
        std::cerr << "Usage: task-cli <command> [argument] [extra]" << std::endl;
        return 1;
    }

    // Get the command
    std::string command = argv[1];

    // Handle optional argument
    std::string argument = (argc >= 3) ? argv[2] : "";
    std::string extra = (argc >= 4) ? argv[3] : "";


    // Initialize TaskManager
    TaskManager taskManager("tasks.json");

    // Process command
    taskManager.processCommand(command, argument, extra);

    return 0;
}