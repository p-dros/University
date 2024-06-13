#include <cmath>
#include <iostream>
#include "temp_expression_templates.h"

int main() {
  Expr<double, Variable<int>> x;
  Expr<double, Constant<int>> constExpr(1.0);

  // Całowanie funkcji x + 1 od 0 do 1 z krokiem 0.001
  std::cout << integrate(x + constExpr, 0, 1, 0.001) << std::endl;

  return 0;
}