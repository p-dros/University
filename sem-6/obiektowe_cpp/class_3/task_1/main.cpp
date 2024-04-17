#include <iostream>
#include <string.h>

// OVERLOADING
template <typename T>
T max(T *data, size_t n) {
    std::cout << "Using template version" << std::endl;
    
    T _max = data[0];

    for (size_t i = 0; i < n; i++) {
        if (data[i] > _max) {
            _max = data[i];
        }
    }

    return _max;
}

template<typename T> 
T max(T a,T b) {
    std::cout << "Using normal version" << std::endl;
    return (a>b)?a:b;
};

template<typename T> 
T* max(T *a, T *b) {
    std::cout << "Using pointer version" << std::endl;
    return ((*a) > (*b)) ? a : b;
}

// SPECIALIZATION
template<> 
char *max<char *>(char *a, char *b) {
    return (strcmp(a, b) > 0) ? a : b;
}

template<> 
const char* max(const char *a,const char *b) {
  return (strcmp(a,b)>0) ? a : b;
}

// FOR char and const char

template<typename T> const T* max(T *a,const T*b) {
  return ((*a)>(*b))?a:b;
}

template<> 
const char* max<const char*>(const char* a, const char* b) {
    return (strcmp(a, b) > 0) ? a : b;
}

int main() {
    std::cout << "\nOVERLOADING" << std::endl;
    // Test with integers
    int a = 5, b = 10;
    std::cout << "Max of " << a << " and " << b << " is " << max(a, b) << std::endl;

    // Test with floating point numbers
    float c = 5.5, d = 10.5;
    std::cout << "Max of " << c << " and " << d << " is " << max(c, d) << std::endl;

    // Test with pointers
    int *p1 = &a, *p2 = &b;
    int *pMax = max(p1, p2);
    std::cout << "Max of " << *p1 << " and " << *p2 << " is " << *pMax << std::endl;

    // specialization

    std::cout << "\nSPECIALIZAATION" << std::endl;

    char* s1 = "Hello";
    const char* s2 = "World";
    const char* sMax = max(s1, s2);
    std::cout << "Max of " << s1 << " and " << s2 << " is " << sMax << std::endl;


    return 0;
}
