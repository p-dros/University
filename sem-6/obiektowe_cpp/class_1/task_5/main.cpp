#include <iostream>

using namespace std;

template <typename S> typename S::value_type 
sum(S s) {
    typename S::value_type total;

    while (!s.is_empty()) {
        total += s.pop();
    }

    return total;
}

template <typename T = int, size_t N = 100> 
class Stack {
  private:
    T _rep[N];
    size_t _top;

  public:
    typedef T value_type;

    Stack() : _top(0){};

    void push(T val) { _rep[_top++] = val; }
    T pop() { return _rep[--_top]; }
    bool is_empty() const { return (_top == 0); }
};

int main() {
    Stack<string, 3> st;

    st.push("ania");
    st.push("asia");
    st.push("basia");

    while (!st.is_empty()) {
        cout << st.pop() << endl;
    }

    Stack<int, 100> si;
    Stack<int, 101> sd;
    Stack<double, 10> sx;

    sx.push(3.14);
    sx.push(2.71);

    cout << sum(sx) << endl;


    return 0;
}