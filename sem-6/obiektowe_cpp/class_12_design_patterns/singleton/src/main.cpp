#include <iostream>

class Singleton {
 private:
  static inline Singleton* instance_ = nullptr;
  std::string value_;

  Singleton(const std::string value) : value_(value) {
  }

 public:
  /**
   * Singletons should not be cloneable.
   */
  Singleton(Singleton& other) = delete;
  /**
   * Singletons should not be assignable.
   */
  void operator=(const Singleton&) = delete;

  static Singleton* getInstance(const std::string value) {
    if (!instance_) {
      instance_ = new Singleton(value);
    }

    return instance_;
  }

  std::string value() const {
    return value_;
  }

  ~Singleton() {
    delete instance_;
    instance_ = nullptr;
  }
};

int main() {
  // Pierwsze wywołanie - tworzenie instancji
  Singleton* s1 = Singleton::getInstance("Hello World");

  // Drugie wywołanie - ponowne użycie tej samej instancji
  Singleton* s2 = Singleton::getInstance("This will not be saved");

  // Sprawdzenie, czy s1 i s2 są tymi samymi obiektami
  if (s1 == s2) {
    std::cout << "Both instances point to the same memory location."
              << std::endl;
  }

  // Użycie metody singletona
  std::cout << s1->value() << std::endl;
  std::cout << s2->value() << std::endl;

  return 0;
}
