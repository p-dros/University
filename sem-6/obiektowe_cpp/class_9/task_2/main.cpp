#include <iostream>
#include <memory>

int main() {
  std::cout << "Rozmiar zwykłego wskaźnika: " << sizeof(int*) << " bajtów"
            << std::endl;
  std::cout << "Rozmiar shared_ptr: " << sizeof(std::shared_ptr<int>)
            << " bajtów" << std::endl;
  std::cout << "Rozmiar unique_ptr: " << sizeof(std::unique_ptr<int>)
            << " bajtów" << std::endl;

  return 0;
}
