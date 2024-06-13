#include <compare>
#include <iostream>

class MyNumber {
 public:
  int value;

  MyNumber(int v) : value(v) {
  }

  auto operator<=>(const MyNumber& other) const = default;
};

// Koncept std::three_way_comparable sprawdza, czy dla danego typu T można
// wykonać operację trójstronnego porównania (<=>) i czy wynik tej operacji jest
// zgodny z określonym typem porównania

static_assert(std::three_way_comparable<MyNumber>,
              "MyNumber should be three_way_comparable");

int main() {
  MyNumber a(10);
  MyNumber b(20);

  if (a < b) {
    std::cout << "a is less than b" << std::endl;
  } else if (a > b) {
    std::cout << "a is greater than b" << std::endl;
  } else {
    std::cout << "a is equal to b" << std::endl;
  }

  return 0;
}
