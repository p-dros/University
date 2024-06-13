#include <compare>
#include <iostream>

struct NotCopyable {
  NotCopyable() = default;
  NotCopyable(const NotCopyable&) = delete;
};

template <typename T>
struct MyVector {
  void push_back(const T&)
    requires std::copyable<T>
  {
    std::cout << "Element added to MyVector\n";
  }
};

int main() {
  MyVector<int> vec1;
  vec1.push_back(10);

  MyVector<NotCopyable> vec2;
  NotCopyable obj;
  vec2.push_back(obj);

  return 0;
}
