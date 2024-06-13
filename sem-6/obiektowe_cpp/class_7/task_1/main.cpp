#include <iostream>

// Szablon wyliczajacy funckje silnia

using namespace std;

template <int N>
int factorial() {
  return N * factorial<N - 1>();
}

template <>
int factorial<0>() {
  return 1;
}

int main() {
  cout << factorial<10>() << endl;

  return 0;
}