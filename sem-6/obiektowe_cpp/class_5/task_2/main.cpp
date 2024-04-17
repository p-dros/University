#include <iostream>
#include <vector>

template <typename T>
class HasValueType {
    typedef char one;
    typedef struct {
        char c[2];
    } two;

    template <typename U>
    static one test(typename U::value_type);

    template <typename U>
    static two test(...);

   public:
    enum { check = (sizeof(test<T>(0)) == sizeof(one)) };
};

using namespace std;

class A {};

int main() {
    cout << "HasValueType<int>: " << HasValueType<int>::check << endl;
    cout << "HasValueType<A>: " << HasValueType<A>::check << endl;
    cout << "HasValueType<vector<double> >: "
         << HasValueType<vector<double> >::check << endl;
}