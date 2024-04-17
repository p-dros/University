#include <iostream>
#include <vector>

template <typename T>
class IsClass {
    typedef char first;
    typedef struct {
        char c[2];
    } second;

    template <typename U>
    static first test(int U::*);

    template <typename U>
    static second test(...);

   public:
    enum { check = (sizeof(test<T>(nullptr)) == sizeof(first)) };
};

using namespace std;

class A {};

int main() {
    cout << "IsClass<int>: " << IsClass<int>::check << endl;
    cout << "IsClass<A>: " << IsClass<A>::check << endl;
    cout << "IsClass<vector<double> >: " << IsClass<vector<double> >::check
         << endl;

    return 0;
}