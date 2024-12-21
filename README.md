
# TODO CLI Application

## 📋 Overview

The TODO CLI application is a command-line tool for managing tasks effectively. It allows users to add, edit, delete, and list tasks, as well as manage their statuses (`todo`, `in-progress`, and `done`). This lightweight application ensures you stay organized and on top of your to-do list.

This project is an idea of the Roadmap.sh project:
https://roadmap.sh/projects/task-tracker

## ✨ Features

- Add tasks with a description.
- Edit tasks by ID and update descriptions.
- Delete tasks individually or clear all tasks.
- List tasks by status or display all tasks.
- Mark tasks as `todo`, `in-progress`, or `done`.
- Manage tasks with an intuitive command-line interface.

## 🛠️ Installation

1. **Clone the Repository**:
   ```bash
   git clone <repository-url>
   cd todo-cli
   ```

2. **Build the Project**:
   Ensure you have `cmake` and a C++ compiler installed.
   ```bash
   mkdir build
   cd build
   cmake ..
   cmake --build .
   ```

3. **Run the Application**:
   ```bash
   ./todo
   ```

4. **Install the Application**:
   MacOS:
   ```bash
    sudo cp ./todo /usr/local/bin/todo
    ```
    Linux:
    ```bash
    sudo cp ./todo /usr/bin/todo
    ```
    Windows:
    ```bash
    todo.exe
    ```
    
5. **Run the Application**:
   ```bash
   todo
   ```

## 📖 Usage

### Commands

| Command                    | Description                                   |
|----------------------------|-----------------------------------------------|
| `add <description>`        | Add a new task with the provided description. |
| `list`                     | List all tasks.                              |
| `list <status>`            | List tasks filtered by `todo`, `in-progress`, or `done`. |
| `edit <id> <description>`  | Edit the description of a task by its ID.     |
| `delete <id>`              | Delete a task by its ID.                     |
| `status <id>`              | Update the status of a task (`todo`, `in-progress`, or `done`). |
| `clear`                    | Clear all tasks.                             |

### Examples

#### Add a Task
```bash
./todo add "Buy groceries"
```

#### Edit a Task
```bash
./todo edit 1 "Buy groceries and cook dinner"
```

#### List Tasks
```bash
./todo list
```

#### Filter Tasks by Status
```bash
./todo list done
```

#### Mark a Task as `in-progress`
```bash
./todo status 1 <<< "2"
```

#### Delete a Task
```bash
./todo delete 1
```

#### Clear All Tasks
```bash
./todo clear <<< "y"
```

## 🧪 Testing

### Run the Automated Test Script
A comprehensive test script is available to test all functionalities. Run it using:
```bash
bash test_script.sh
```

The script performs the following:
- Adds multiple tasks.
- Edits task descriptions.
- Deletes specific tasks.
- Marks tasks as `in-progress` or `done`.
- Lists tasks filtered by status.
- Clears all tasks.

### Sample Output
The test script provides detailed outputs, indicating success or failure for each operation.

## 🌟 Features to Add
- Support for due dates and priority levels.
- Export tasks to a file (e.g., JSON or CSV).
- Import tasks from a file.
- Add encryption for sensitive data.
- (MacOS Feature) Create an hidden folder in icloud to store tasks.

## 📂 Project Structure

```plaintext
task-cli/
├── src/
│   ├── main.cpp          # Entry point of the application
│   ├── taskManager.cpp   # Implementation of task management logic
│   ├── taskManager.h     # Header file for the task manager
│   ├── jsonManager.cpp   # Handles file I/O for task persistence
│   ├── jsonManager.h     # Header file for the JSON manager
├── test_script.sh        # Automated script for testing
├── CMakeLists.txt        # Build configuration
├── README.md             # Project documentation
```

## 🛡️ License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## 🤝 Contributing

Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a new branch for your feature/bugfix.
3. Commit your changes and submit a pull request.

---

Stay organized and boost your productivity with **TODO CLI**! 🚀
