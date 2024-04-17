#include<iostream> 

using namespace std;

template< template<int N> class  C, int K> 
void f(C<K>){
    cout<<K<<endl;
};

template<int N> struct SomeClass {};

int main() {
    SomeClass<1>  c1;
    SomeClass<2>  c2;

    f(c1);
    f(c2);

    return 0;
}