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
  std::weak_ptr<MyClass> weakPtr;

  {
    std::shared_ptr<MyClass> ptr1(new MyClass);
    std::cout << "ptr1.use_count() = " << ptr1.use_count() << std::endl;

    weakPtr = ptr1;

    {
      std::shared_ptr<MyClass> ptr2 = ptr1;
      std::cout << "ptr1.use_count() = " << ptr1.use_count() << std::endl;
      std::cout << "ptr2.use_count() = " << ptr2.use_count() << std::endl;
    }

    std::cout << "ptr1.use_count() = " << ptr1.use_count() << std::endl;
  }

  std::cout << "Out of scope" << std::endl;

  if (auto sharedPtr = weakPtr.lock()) {
    std::cout << "Weak pointer still pointing to the object" << std::endl;
  } else {
    std::cout << "Weak pointer is expired, object is deleted" << std::endl;
  }

  return 0;
}
