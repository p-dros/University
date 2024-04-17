#include <string.h>

#include <iostream>
#include <iterator>

using namespace std;

template <typename T>
struct sum_traits {
    typedef T sum_type;
    static sum_type zero() { return sum_type(); }
};
template <>
struct sum_traits<char> {
    typedef int sum_type;
    static sum_type zero() { return 0; }
};
template <>
struct sum_traits<int> {
    typedef long int sum_type;
    static sum_type zero() { return 0; }
};
template <>
struct sum_traits<float> {
    typedef double sum_type;
    static sum_type zero() { return 0.0; }
};

template <typename Traits, typename T>
typename Traits::sum_type sum(T *beg, T *end) {
    typedef typename Traits::sum_type sum_type;

    sum_type total = Traits::zero();
    while (beg != end) {
        total += *beg;
        beg++;
    }
    return total;
};

template <typename T>
typename sum_traits<T>::sum_type sum(T *beg, T *end) {
    return sum<sum_traits<T>, T>(beg, end);
}

struct char_sum {
    typedef char sum_type;
    static sum_type zero() { return sum_type(); }
};

int main() {
    char name[] = "@ @ @";
    int length = strlen(name);

    cout << (int)sum(name, &name[length]) << endl;

    cout << (int)sum<char_sum>(name, &name[length]) << endl;

    cout << (int)sum<char>(name, &name[length]) << endl;

    double doubles[] = {1.5, 2.2, 3.0, 4.8, 5.4};
    int double_length = sizeof(doubles) / sizeof(doubles[0]);

    cout << "Sum of doubles: " << sum(doubles, &doubles[double_length]) << endl;

    return 0;
}