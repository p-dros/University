#include <cmath>
#include <iostream>

template <typename F>
double integrate(F f, double min, double max, double ds) {
  double integral = .0;

  for (double x = min; x < max; x += ds) {
    integral += f(x);
  }

  return integral * ds;
};

class sina {
  double _a;

 public:
  sina(double a) : _a(a){};
  double operator()(double x) {
    return sin(_a * x);
  }
};

int main() {
  std::cout << ::integrate(sin, 0, 3.1415926, 0.01) << std::endl;

  std::cout << ::integrate(sina(0), 0, 3.1415926, 0.01) << std::endl;
  std::cout << ::integrate(sina(1), 0, 3.1415926, 0.01) << std::endl;
  std::cout << ::integrate(sina(2), 0, 3.1415926, 0.01) << std::endl;

  return 0;
}