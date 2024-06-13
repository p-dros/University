#include <iostream>

using namespace std;

template <int N, typename T = double>
struct Inner {
  static T dot(T* a, T* b) {
    return (*a) * (*b) + Inner<N - 1, T>::dot(++a, ++b);
  }
};

template <typename T>
struct Inner<1, T> {
  static T dot(T* a, T* b) {
    return (*a) * (*b);
  }
};

int main() {
  double a[] = {1.0, 2.0, 3.0};
  double b[] = {1.0, 2.0, 3.0};

  cout << Inner<3>::dot(a, b) << endl;

  return 0;
}