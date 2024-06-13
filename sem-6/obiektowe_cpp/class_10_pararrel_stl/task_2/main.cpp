#include <algorithm>
#include <execution>
#include <mutex>
#include <vector>

#include <chrono>
#include <iostream>

int main() {
  std::vector<int> vec(10'000'000);
  std::iota(vec.begin(), vec.end(), 0);
  std::vector<int> output;
  std::mutex output_mutex;

  auto start = std::chrono::steady_clock::now();

  std::for_each(
      std::execution::par, vec.begin(), vec.end(), [&output](int& elem) {
        if (elem % 2 == 0) {
          std::lock_guard<std::mutex> lock(output_mutex);
          output.push_back(elem);
        }
      });

  auto end = std::chrono::steady_clock::now();
  auto duration_parallel
      = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << "Parallel execution duration: " << duration_parallel.count()
            << " ms" << std::endl;

  output.clear()
}