// Task.h

#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <mutex>

class Task {
public:
    Task(const std::string& setName, int setId) : name(setName), id(setId) {}

    void execute() {
        // Симуляція виконання дії
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Виведення результату
        {
            std::lock_guard<std::mutex> lock(outputMutex);
            std::cout << "З набору " << name << " виконано дію " << id << ".\n";
        }
    }

private:
    std::string name;
    int id;
    static std::mutex outputMutex; // М'ютекс для синхронізації виведення
};

std::mutex Task::outputMutex;

#endif // TASK_H
