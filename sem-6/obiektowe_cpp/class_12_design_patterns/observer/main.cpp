#include <iostream>
#include <string>
#include <vector>

class Observer {
 public:
  virtual void update(const std::string& data) = 0;
};

// Subjekt
class Subject {
 private:
  std::vector<Observer*> observers;
  std::string data;

 public:
  void attach(Observer* observer) {
    observers.push_back(observer);
  }

  void detach(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer),
                    observers.end());
  }

  void notify() {
    for (auto observer : observers) {
      observer->update(data);
    }
  }

  void setData(const std::string& newData) {
    data = newData;
    notify();  // Notyfikacja obserwatorów o zmianie danych
  }
};

// Implementacja obserwatora
class ConcreteObserver : public Observer {
 private:
  std::string name;

 public:
  ConcreteObserver(const std::string& name) : name(name) {
  }

  void update(const std::string& data) override {
    std::cout << "Observer " << name << " received data: " << data << std::endl;
  }
};

int main() {
  Subject subject;
  ConcreteObserver observer1("Observer1");
  ConcreteObserver observer2("Observer2");

  subject.attach(&observer1);
  subject.attach(&observer2);

  subject.setData("Hello, Observers!");

  return 0;
}
