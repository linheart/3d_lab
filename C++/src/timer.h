#ifndef TIMER_H // TIMER_H
#define TIMER_H

#include <chrono>
#include <iomanip>
#include <iostream>

class Timer {
public:
  void start() { startTime = std::chrono::high_resolution_clock::now(); }
  void elapsed() {
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cout << std::fixed << std::setprecision(9)
              << std::chrono::duration_cast<std::chrono::duration<double>>(
                     endTime - startTime)
                     .count()
              << std::endl;
  }

private:
  std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
};

#endif // TIMER_H
