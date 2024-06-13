#include <iostream>

using namespace std;

template <int N>
double inner(double* a, double* b) {
  return (*a) * (*b) + inner<N - 1>(++a, ++b);
}

template <>
double inner<1>(double* a, double* b) {
  return (*a) * (*b);
}

int main() {
  double a[] = {1.0, 2.0, 3.0};
  double b[] = {1.0, 2.0, 3.0};

  cout << inner<3>(a, b) << endl;

  return 0;
}