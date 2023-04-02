#include "../include/pqueue.hpp"
#include "./pqueue.cpp"
#include <iostream>

template <typename T>
void printQueueElement(QueueElem<T> elem) {
        std::cout << "Priority: " << elem.priority << std::endl;
        std::cout << "Element: " << elem.obj << std::endl;
}

int main(int argc, char const *argv[])
{
    pqueue<int> queue;

    queue.insert(1, 1);
    queue.insert(1, 2);
    queue.insert(1, 3);
    
    queue.print();

    printQueueElement(queue.extractMax());
    printQueueElement(queue.extractMax());
    printQueueElement(queue.extractMax());
    

    return 0;
}


