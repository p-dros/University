#include <set>
#include <iostream>

int main()
{
  // Utworzenie zbioru z funktorem greater<>()
  std::set<int, std::greater<>> reverse_sorted_set;

  reverse_sorted_set.insert(5);
  reverse_sorted_set.insert(3);
  reverse_sorted_set.insert(7);
  reverse_sorted_set.insert(1);

  for (const auto &element : reverse_sorted_set)
  {
    std::cout << element << std::endl;
  }

  return 0;
}