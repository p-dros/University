#include <iostream>

template <typename Target, typename Source>
Target convert(const Source& source) {
    return static_cast<Target>(source);
}

int main() {
    double d = 3.14;
    int i = convert<int>(d);

    std::cout << i << std::endl;
    std::cout << d << std::endl;

    return 0;
}