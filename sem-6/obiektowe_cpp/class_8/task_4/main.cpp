#include <cmath>
#include <iostream>
#include "expression_templates.h"

template <typename Arg>
class SinExpr {
  Arg _arg;

 public:
  SinExpr(const Arg& arg) : _arg(arg){};
  double operator()(double x) {
    return sin(_arg(x));
  }
};

template <typename Arg>
SinExpr<Arg> sin(const Arg& a) {
  return SinExpr<Arg>(a);
}

int main() {
  Variable x;

  std::cout << integrate(1. / sin(x + 1.), 0, 1, 0.001) << std::endl;

  return 0;
}