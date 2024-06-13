#include <algorithm>
#include <execution>
#include <iostream>
#include <numeric>
#include <vector>

void print_vector(const std::vector<int>& vec) {
  for (const auto& v : vec) {
    std::cout << v << " ";
  }
  std::cout << std::endl;
}

int main() {
  // Wektor danych do sortowania
  std::vector<int> vec(100);
  std::iota(
      vec.begin(), vec.end(), 0);  // Wypełnia wektor wartościami od 0 do 99

  // Kopia wektora dla różnych polityk wykonania
  std::vector<int> vec_seq = vec;
  std::vector<int> vec_par = vec;
  std::vector<int> vec_par_unseq = vec;

  // Sekwencyjne sortowanie
  std::sort(
      std::execution::seq, vec_seq.begin(), vec_seq.end(), std::greater<int>());
  std::cout << "Sequenced sort:" << std::endl;
  print_vector(vec_seq);

  // Równoległe sortowanie
  std::sort(
      std::execution::par, vec_par.begin(), vec_par.end(), std::greater<int>());
  std::cout << "Parallel sort:" << std::endl;
  print_vector(vec_par);

  // Równoległe i nieuporządkowane sortowanie
  std::sort(std::execution::par_unseq,
            vec_par_unseq.begin(),
            vec_par_unseq.end(),
            std::greater<int>());
  std::cout << "Parallel unsequenced sort:" << std::endl;
  print_vector(vec_par_unseq);

  return 0;
}
