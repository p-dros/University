#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

class SequenceGen {
private:
    int current;

public:
    SequenceGen() : current(1) {}

    int operator()() {
        int value = current;
        current += 2; 
        return value;
    }
};

int main() {
    const size_t n = 20;
    std::vector<int> numbers(n);
    std::generate_n(numbers.begin(), n, SequenceGen());

    std::vector<int>::iterator it = std::find_if(numbers.begin(), numbers.end(), std::bind(std::greater<int>(), std::placeholders::_1, 4)); 

    std::cout << *it << std::endl;

    return 0;
}
