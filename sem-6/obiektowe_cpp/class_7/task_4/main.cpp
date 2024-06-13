#include <iostream>

using namespace std;

// pow

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

// factorial
template <int N>
int factorial() {
  return N * factorial<N - 1>();
}

template <>
int factorial<0>() {
  return 1;
}

// sin
template <int N>
double sin(double x) {
  return sin<N - 1>(x)
         + (N % 2 ? 1 : -1) * pow<(2 * N - 1)>(x) / factorial<(2 * N - 1)>();
}

template <>
double sin<0>(double x) {
  return 0;
}

int main() {
  cout << sin<3>(4) << endl;
  return 0;
}