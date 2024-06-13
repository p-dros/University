#include <iostream>

using namespace std;

template <int N, int M>
struct Pow {
  enum { val = N * Pow<N, M - 1>::val };
};

template <int N>
struct Pow<N, 0> {
  enum { val = 1 };
};

int main() {
  cout << Pow<3, 2>::val << endl;

  return 0;
}