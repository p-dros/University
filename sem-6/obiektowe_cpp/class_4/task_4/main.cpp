#include <iostream>
#include <iterator>
#include <vector>

template <typename T>
struct sum_traits {
    typedef T sum_type;
    static sum_type zero() { return sum_type(); }
};

template <>
struct sum_traits<double> {
    typedef double sum_type;
    static sum_type zero() { return 0.0; }
};

template <>
struct sum_traits<int> {
    typedef int sum_type;
    static sum_type zero() { return 0; }
};

template <typename II>
typename sum_traits<typename std::iterator_traits<II>::value_type>::sum_type
sum(II beg, II end) {
    typedef typename std::iterator_traits<II>::value_type value_type;
    typedef typename sum_traits<value_type>::sum_type sum_type;
    sum_type total = sum_traits<value_type>::zero();

    while (beg != end) {
        total += *beg;
        ++beg;
    }
    return total;
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "Suma elementów w wektorze: " << sum(vec.begin(), vec.end())
              << std::endl;

    int arr[] = {1, 2, 3, 4, 5};
    std::cout << "Suma elementów w tablicy: " << sum(arr, arr + 5) << std::endl;

    return 0;
}
