#include <iostream>
#include <vector>
#include <thread>
#include "Task.h"

int main() {
    std::cout << "Обчислення розпочато.\n";

    // Задання кількості потоків та наборів дій
    int nt = 5; // Кількість потоків
    int a = 6, b = 6, c = 5, d = 6, e = 4, f = 7, g = 8, h = 6, i = 6, j = 6;

    // Створення об'єктів Task для кожного набору дій
    std::vector<Task> tasks;
    tasks.reserve(a + b + c + d + e + f + g + h + i + j);

    for (int id = 1; id <= a; ++id) tasks.emplace_back("a", id);
    for (int id = 1; id <= b; ++id) tasks.emplace_back("b", id);
    for (int id = 1; id <= c; ++id) tasks.emplace_back("c", id);
    for (int id = 1; id <= d; ++id) tasks.emplace_back("d", id);
    for (int id = 1; id <= e; ++id) tasks.emplace_back("e", id);
    for (int id = 1; id <= f; ++id) tasks.emplace_back("f", id);
    for (int id = 1; id <= g; ++id) tasks.emplace_back("g", id);
    for (int id = 1; id <= h; ++id) tasks.emplace_back("h", id);
    for (int id = 1; id <= i; ++id) tasks.emplace_back("i", id);
    for (int id = 1; id <= j; ++id) tasks.emplace_back("j", id);

    // Створення та запуск потоків
    std::vector<std::thread> threads;
    threads.reserve(nt);

    for (int threadId = 0; threadId < nt; ++threadId) {
        threads.emplace_back([threadId, &tasks, nt]() {
            for (int i = threadId; i < tasks.size(); i += nt) {
                tasks[i].execute();
            }
        });
    }

    // Очікування завершення потоків
    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "Обчислення завершено.\n";

    return 0;
}
