#ifndef PQUEUE_HPP
#define PQUEUE_HPP

template <typename T>
struct QueueElem {
    int priority;
    T obj;
};

template <typename T>
class PriorityQueue {
    private: 
        void resize(bool expand);
        void heapify(int i);

        QueueElem<T> *heap;
        int capacity;
        int length;

    public:
        PriorityQueue();
        ~PriorityQueue();

        QueueElem<T> max();
        QueueElem<T> extractMax();
};

template <typename T>
PriorityQueue<T>::PriorityQueue() {
    capacity = 5;
    length = 0;
    heap = new QueueElem<T>[capacity];
};

template <typename T>
PriorityQueue<T>::~PriorityQueue() {
    delete[] heap;
};

template <typename T>
void PriorityQueue<T>::resize(bool expand) {
    const float factor = expand ? 2.0 : 0.5;

    if (capacity * factor < 5 || capacity * factor < length) return;

    capacity *= factor;

    QueueElem<T>* newHeap = new QueueElem[capacity];

    for (int i = 0; i < length; i++) {
        newHeap[i] = heap[i];
    }

    delete[] heap;

    heap = newHeap;
};

// max heapify
template <typename T>
void PriorityQueue<T>::heapify(int i) {
    int left = 2*i;
    int right = 2*i + 1;

    int largest = i;

    if (left < length && heap[left] > heap[largest]) {
        largest = left;
    } 
    if (right < length && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(heap[i], heap[largest]);
        heapify(largest); 
    }
}

#endif
