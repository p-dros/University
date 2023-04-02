#include "../include/pqueue.hpp"

#include <utility>

template <typename T>
pqueue<T>::pqueue() {
    capacity = 5;
    length = 0;
    heap = new QueueElem<T>[capacity];
}

template <typename T>
pqueue<T>::~pqueue() {
    delete[] heap;
}

template <typename T>
void pqueue<T>::resize(bool expand) {
    const float factor = expand ? 2.0 : 0.5;

    if (capacity * factor < 5 || capacity * factor < length) return;

    capacity *= factor;

    QueueElem<T>* newHeap = new QueueElem<T>[capacity];

    for (int i = 0; i < length; i++) {
        newHeap[i] = heap[i];
    }

    delete[] heap;

    heap = newHeap;
}

template <typename T>
void pqueue<T>::insert(int priority, T value) {
    if(length + 1 > capacity) resize(true);

    QueueElem<T> newElement = QueueElem<T> { priority, value };

    heap[length] = newElement;
    siftUp(length);

    ++length;
}

template <typename T>
void pqueue<T>::siftUp(int i) {
    int parent = (i - 1) / 2;
    while(i != 0 && heap[i].priority > heap[parent].priority) {
        std::swap(heap[i], heap[parent]);
        i = parent;
        parent = (i - 1) / 2;
    }
}

template <typename T>
void pqueue<T>::siftDown(int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    int largest = i;


    if (left < length && heap[left].priority > heap[largest].priority) {
        largest = left;
    }

    if (right < length && heap[right].priority > heap[largest].priority) {
        largest = right;
    }

    if (i != largest) {
        std::swap(heap[i], heap[largest]);
        siftDown(largest);
    }
}

template <typename T>
QueueElem<T> pqueue<T>::max() {
    if (length == 0) {
        throw std::out_of_range("The heap is empty.");
    }
    return heap[0];
}

template <typename T>
QueueElem<T> pqueue<T>::extractMax() {
    if (length == 0) {
        throw std::out_of_range("The heap is empty.");
    }
    if (length - 1 < int(0.25 * capacity)) resize(false);

    QueueElem<T> maxElement = heap[0];
    std::swap(heap[0], heap[length - 1]);

    --length;

    siftDown(0);
    return maxElement;
}   

template <typename T>
void pqueue<T>::print() {
    std::cout << "------------------------" << std::endl;
    for (int i = 0; i < length; i++) {
        std::cout << "index: " << i << std::endl;
        std::cout << "\tpriority: " << heap[i].priority << std::endl;
        std::cout << "\telement: " << heap[i].obj << std::endl;
    }
    std::cout << "------------------------" << std::endl;
}

