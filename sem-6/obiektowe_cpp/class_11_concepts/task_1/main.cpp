#include <compare>
#include <iostream>

template <typename T>
  requires std::integral<T>
auto gcd(T a, T b) {
  if (b == 0) return a;

  return gcd(b, a % b);
}

int main() {
  std::cout << "gcd(100, 10) = " << gcd(100, 10) << std::endl;
  return 0;
}
