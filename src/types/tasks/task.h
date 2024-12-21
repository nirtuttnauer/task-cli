#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>

class Task {
private:
    int id;
    std::string description;
    std::string status;
    std::string createdAt;
    std::string updatedAt;

public:
    Task(int id, std::string description, std::string status, std::string createdAt, std::string updatedAt)
        : id(id), description(description), status(status), createdAt(createdAt), updatedAt(updatedAt) {}

    int getId() const { return id; }
    std::string getDescription() const { return description; }
    std::string getStatus() const { return status; }
    std::string getCreatedAt() const { return createdAt; }
    std::string getUpdatedAt() const { return updatedAt; }

    void setId(int id) { this->id = id; }
    void setDescription(const std::string &description) { this->description = description; }
    void setStatus(const std::string &status) { this->status = status; }
    void setCreatedAt(const std::string &createdAt) { this->createdAt = createdAt; }
    void setUpdatedAt(const std::string &updatedAt) { this->updatedAt = updatedAt; }

};

#endif // TASK_H