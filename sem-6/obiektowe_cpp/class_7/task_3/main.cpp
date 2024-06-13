#include <iostream>

using namespace std;

template <int N>
double pow(double x) {
  return ((N % 2) ? x : 1) * pow<N / 2>(x * x);
}

template <>
double pow<1>(double x) {
  return x;
}

template <>
double pow<0>(double x) {
  return 1.0;
}

int main() {
  cout << pow<5>(5.0) << endl;

  return 0;
}