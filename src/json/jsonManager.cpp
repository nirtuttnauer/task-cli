#include "json/jsonManager.h"


jsonManager::jsonManager(const char *fileName) : fileName(fileName)
{
    if (!std::filesystem::exists(fileName))
    {
        create();
    }
}

void jsonManager::create(){
    std::ofstream outFile(this->fileName, std::ios::trunc);  // Use 'this->fileName'
    if (!outFile.is_open()) {
        throw std::runtime_error("Failed to open file for writing: " + this->fileName);
    }
    outFile << "[]";
    outFile.close();
}

// Utility to escape JSON strings
std::string escapeJsonString(const std::string& str) {
    std::ostringstream escaped;
    for (char c : str) {
        switch (c) {
            case '\"': escaped << "\\\""; break;
            case '\\': escaped << "\\\\"; break;
            case '\b': escaped << "\\b"; break;
            case '\f': escaped << "\\f"; break;
            case '\n': escaped << "\\n"; break;
            case '\r': escaped << "\\r"; break;
            case '\t': escaped << "\\t"; break;
            default: escaped << c;
        }
    }
    return escaped.str();
}

std::string extractJsonValue(const std::string& json, const std::string& key, size_t startPos) {

    size_t keyPos = json.find("\"" + key + "\":", startPos);
    if (keyPos == std::string::npos) {
        throw std::runtime_error("Key \"" + key + "\" not found in JSON.");
    }

    size_t valueStart = json.find_first_not_of(": \t", keyPos + key.length() + 2);
    if (valueStart == std::string::npos) {
        throw std::runtime_error("Value for key \"" + key + "\" is not found.");
    }

    // Determine if the value is a string or a number
    char firstChar = json[valueStart];
    size_t valueEnd;
    if (firstChar == '"') { // String value
        valueStart++;
        valueEnd = json.find('"', valueStart);
    } else { // Numeric or boolean value
        valueEnd = json.find_first_of(",}", valueStart);
    }

    if (valueEnd == std::string::npos) {
        throw std::runtime_error("Value for key \"" + key + "\" is not terminated.");
    }

    std::string value = json.substr(valueStart, valueEnd - valueStart);
    return value;
}

// Convert a vector of tasks to JSON
std::string jsonManager::tasksToJson(const std::vector<Task>& tasks) {
    std::ostringstream json;
    json << "["; // Begin JSON array

    for (size_t i = 0; i < tasks.size(); ++i) {
        const Task& task = tasks[i];
        json << "{"
             << "\"id\":" << task.getId() << ","
             << "\"description\":\"" << escapeJsonString(task.getDescription()) << "\","
             << "\"status\":\"" << escapeJsonString(task.getStatus()) << "\","
             << "\"createdAt\":\"" << escapeJsonString(task.getCreatedAt()) << "\","
             << "\"updatedAt\":\"" << escapeJsonString(task.getUpdatedAt()) << "\""
             << "}";

        if (i < tasks.size() - 1) {
            json << ","; // Add a comma between objects
        }

    }

    json << "]"; // End JSON array
    return json.str();
}

// Parse JSON to create a vector of Task objects
std::vector<Task> jsonManager::jsonToTasks(const std::string& json) {
    std::vector<Task> tasks;
    size_t pos = 0;

    while ((pos = json.find("{", pos)) != std::string::npos) {
        try {
            size_t objectEnd = json.find("}", pos);
            if (objectEnd == std::string::npos) {
                throw std::runtime_error("Mismatched braces in JSON.");
            }
            std::string object = json.substr(pos, objectEnd - pos + 1);

            std::string idStr = extractJsonValue(object, "id", 0);
            std::string description = extractJsonValue(object, "description", 0);
            std::string status = extractJsonValue(object, "status", 0);
            std::string createdAt = extractJsonValue(object, "createdAt", 0);
            std::string updatedAt = extractJsonValue(object, "updatedAt", 0);

            Task task(std::stoi(idStr), description, status, createdAt, updatedAt);
            tasks.push_back(task);

            pos = objectEnd + 1;
        } catch (const std::exception& e) {
            pos = json.find("}", pos) + 1;
        }
    }

    return tasks;
}

// Save tasks to a file
void jsonManager::saveToFile(const std::vector<Task>& tasks) {
    std::ofstream outFile(this->fileName, std::ios::trunc);  // Use 'this->fileName'
    if (!outFile.is_open()) {
        throw std::runtime_error("Failed to open file for writing: " + this->fileName);
    }

    outFile << tasksToJson(tasks);
    outFile.close();
}

std::vector<Task> jsonManager::loadFromFile() {
    std::ifstream inFile(this->fileName);  // Use 'this->fileName'
    if (!inFile.is_open()) {
        throw std::runtime_error("Failed to open file for reading: " + this->fileName);
    }

    std::ostringstream buffer;
    buffer << inFile.rdbuf();
    inFile.close();

    return jsonToTasks(buffer.str());
}
