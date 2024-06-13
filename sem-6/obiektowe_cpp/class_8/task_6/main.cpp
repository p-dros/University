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

class First {
 public:
  double operator()(double x) {
    return x;
  }
  double operator()(double x, double) {
    return x;
  }
};

class Second {
 public:
  double operator()(double, double y) {
    return y;
  }
};

class Constant {
  double _c;

 public:
  Constant(double c) : _c(c){};
  double operator()(double) {
    return _c;
  }
  double operator()(double, double) {
    return _c;
  }
};

template <typename LHS, typename RHS>
class AddExpr {
  LHS _lhs;
  RHS _rhs;

 public:
  AddExpr(const LHS& l, const RHS& r) : _lhs(l), _rhs(r){};
  double operator()(double x) {
    return _lhs(x) + _rhs(x);
  }
  double operator()(double x, double y) {
    return _lhs(x, y) + _rhs(x, y);
  }
};

template <typename LHS>
AddExpr<LHS, Constant> operator+(const LHS& l, double r) {
  return AddExpr<LHS, Constant>(l, Constant(r));
};

int main() {
  First first;
  Second second;
  Constant constExpr(1.0);

  // Całowanie funkcji x + y od 0 do 1 z krokiem 0.001
  std::cout << integrate(
      AddExpr<First, Second>(first, second) + constExpr, 0, 1, 0.001)
            << std::endl;
  return 0;
}