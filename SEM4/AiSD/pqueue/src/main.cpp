#include "../include/pqueue.hpp"
#include "./pqueue.cpp"
#include <iostream>

using namespace std;

template <typename T>
void printQueueElement(QueueElem<T> elem) {
        std::cout << "Priority: " << elem.priority << std::endl;
        std::cout << "Element: " << elem.obj << std::endl;
}

class Date
{
    int mo, da, yr;
public:
    Date() : mo(0), da(0), yr(0) {}
    Date(int m, int d, int y)
    {
        mo = m; da = d; yr = y;
    }
    friend ostream& operator<<(ostream& os, const Date& dt);
};

ostream& operator<<(ostream& os, const Date& dt)
{
    os << dt.mo << '/' << dt.da << '/' << dt.yr;
    return os;
}

int main(int argc, char const *argv[])
{
    pqueue<Date> queue;

    Date dt1(1, 2, 3);
    Date dt2(2, 3, 4);
    Date dt3(3, 4, 5);

    queue.insert(1, dt1);
    queue.insert(1, dt2);
    queue.insert(1, dt3);

    queue.print();
    
    

    return 0;
}


