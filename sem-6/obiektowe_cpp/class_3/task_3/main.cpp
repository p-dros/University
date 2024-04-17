#include <iostream>

using namespace std;

// Base class
template <typename T, int N = 100>
class Stack
{
public:
  Stack()
  {
    cerr << "T,N" << endl;
  };
};

// Specializations
template <typename T>
class Stack<T, 666>
{
public:
  Stack()
  {
    cerr << "T,666" << endl;
  };
};

template <typename T, int N>
class Stack<T *, N>
{
public:
  Stack()
  {
    cerr << "T*,N" << endl;
  };
};

template <int N>
class Stack<double, N>
{
public:
  Stack()
  {
    cerr << "double,N" << endl;
  };
};

template <int N>
class Stack<int *, N>
{
public:
  Stack()
  {
    cerr << "int *,N" << endl;
  };
};

template <>
class Stack<double, 666>
{
public:
  Stack()
  {
    cerr << "double,666" << endl;
  };
};

template <>
class Stack<double *, 44>
{
public:
  Stack()
  {
    cerr << "double *,44" << endl;
  };
};

int main()
{

  Stack<int, 20> s0;

  Stack<int, 666> s1;
  Stack<double *, 30> s2;
  Stack<double, 30> s3;
  Stack<double *, 44> s4;
  Stack<int *, 20> s5;
  Stack<double, 666> s6;

  return 0;
}