#ifndef PQUEUE_hpp
#define PQUEUE_hpp

#include <iostream>

/**
 * @file PQUEUE.hpp
 * @brief Header file for the `pqueue` class, a priority queue 
 * implementation using binary heap
 */

template <typename T>
struct QueueElem {
    int priority; ///< The priority of the element
    T obj; ///< The element itself
};

/**
 * @brief A priority queue implementation using binary heap
 */
template <typename T>
class pqueue {
    private:
        /**
         * @brief Resizes the heap array.
         *
         * If `expand` is true, the array is doubled in size, 
         * otherwise it is halved.
         */
        void resize(bool expand);

        /**
         * @brief Restores the heap property at a given index.
         *
         * Assumes that the subtree rooted at the given index 
         * satisfies the heap property,
         * except for the element at the given index. 
         * This function moves the element
         * down the heap until the subtree satisfies the heap property.
         *
         * @param i The index of the element to be moved down.
         */
        void siftDown(int i);
        void siftUp(int i);

        QueueElem<T>* heap; ///< The binary heap array
        int length; ///< The number of elements in the binary heap
        int capacity; ///< The capacity of the binary heap array
    public:
        /**
         * @brief Constructor for the `pqueue` class.
         *
         * Initializes an empty priority queue.
         */
        pqueue();

        /**
         * @brief Destructor for the `pqueue` class.
         *
         * Frees the memory used by the binary heap array.
         */
        ~pqueue();

        /**
         * @brief Returns the element with the highest priority without removing it.
         *
         * 
         * This function returns the element with the highest priority in the 
         * priority queue, without removing it from the queue. 
         * If the queue is empty, this function 
         * throws an std::out_of_range exception with an error 
         * message "The heap is empty.".
         * 
         * @return The element with the highest priority.
         * @throws std::out_of_range if the queue is empty
         */
        QueueElem<T> max();

        /**
         * @brief Removes and returns the element with the highest priority.
         * 
         * This function returns the element with the highest priority in the 
         * priority queue and removes it from the queue. 
         * If the queue is empty, this function 
         * throws an std::out_of_range exception with an error 
         * message "The heap is empty.".
         *
         * @return The element with the highest priority.
         * @throws std::out_of_range if the queue is empty
         */
        QueueElem<T> extractMax();

        /**
         * @brief Add a new element to queue.
         * 
         * Add an element keeping the priority of the queue
        */
        void insert(int priority, T value);

        /**
         * For development purposes
        */
        void print();
};


#endif
