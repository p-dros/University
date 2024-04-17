#include <iostream>
#include <vector>

template <typename T, typename U>
class IsConvertible {
    typedef char first;
    typedef struct {
        char c[2];
    } second;

    static first test(U);

    static second test(...);

    static T makeT();

   public:
    enum { check = sizeof(test(makeT())) == sizeof(first), same_type = false };
};

template <typename T>
class IsConvertible<T, T> {
   public:
    enum { check = true, same_type = true };
};

using namespace std;

int main() {
    cout << "IsConvertible<int, double>: " << IsConvertible<int, double>::check
         << endl;
    cout << "IsConvertible<double, int>: " << IsConvertible<double, int>::check
         << endl;

    cout << "IsConvertible<double, int>: same_type:  "
         << IsConvertible<double, int>::same_type << endl;

    cout << "IsConvertible<size_t, unsigned>: same_type:  "
         << IsConvertible<size_t, unsigned int>::same_type << endl;
    cout << "IsConvertible<vector<double>::value_type, double>: same_type:  "
         << IsConvertible<vector<double>::value_type, double>::same_type
         << endl;

    cout << "IsConvertible<vector<double>::iterator, double *>: same_type:  "
         << IsConvertible<vector<double>::iterator, double *>::same_type
         << endl;
}