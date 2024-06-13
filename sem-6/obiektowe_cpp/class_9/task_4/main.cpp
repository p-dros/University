#include <iostream>
#include <memory>

struct MyClass {
  MyClass(int a, double b) : data(a * b) {
    std::cout << "MyClass constructor with values: " << a << " and " << b
              << std::endl;
  }
  double data;
};

int main() {
  // Tworzenie obiektu za pomocą operatora new z wywołaniem konstruktora
  auto ptr2 = std::unique_ptr<MyClass>(new MyClass(42, 3.14));
  std::cout << "ptr2->data: " << ptr2->data << std::endl;

  // Utworzenie obiektu za pomocą std::make_unique z wywołaniem konstruktora
  auto ptr1 = std::make_unique<MyClass>(42, 3.14);
  std::cout << "ptr1->data: " << ptr1->data << std::endl;

  // Tworzenie tablicy obiektów za pomocą std::make_unique
  auto arr1 = std::make_unique<int[]>(5);
  for (int i = 0; i < 5; ++i) {
    arr1[i] = i;
    std::cout << "arr1[" << i << "]: " << arr1[i] << std::endl;
  }

  // Tworzenie tablicy obiektów za pomocą operatora new
  auto arr2 = std::unique_ptr<int[]>(new int[5]);
  for (int i = 0; i < 5; ++i) {
    arr2[i] = i;
    std::cout << "arr2[" << i << "]: " << arr2[i] << std::endl;
  }

  return 0;
}
