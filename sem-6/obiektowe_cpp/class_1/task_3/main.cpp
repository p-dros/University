#include <iostream>

template <size_t N, typename T>
T dot_product(T *a, T *b) {
    T total = 0.0;
    
    for (size_t i = 0; i < N; i++) {
        total += a[i] * b[i];
    }

    return total;
}

int main() {
    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};

    int result = dot_product<3>(a, b);

    std::cout << result << std::endl;

    return 0;
}