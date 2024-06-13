#include <iostream>
#include <memory>

struct MyClass {
  MyClass() {
    std::cout << "Constructor called" << std::endl;
  }

  ~MyClass() {
    std::cout << "Destructor called" << std::endl;
  }
};

int main() {
  {
    std::shared_ptr<MyClass> ptr1(new MyClass);
    std::cout << "ptr1.use_count() = " << ptr1.use_count() << std::endl;

    {
      std::shared_ptr<MyClass> ptr2 = ptr1;
      std::cout << "ptr1.use_count() = " << ptr1.use_count() << std::endl;
      std::cout << "ptr2.use_count() = " << ptr2.use_count() << std::endl;
    }

    std::cout << "ptr1.use_count() = " << ptr1.use_count() << std::endl;
  }

  std::cout << "Out of scope" << std::endl;

  return 0;
}
