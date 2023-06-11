#ifndef SET_HPP
#define SET_HPP

#include <iostream>
#include <random>

template <typename T>
class Set
{
private:
    static float NARROW_FACTOR;
    static float EXPAND_FACTOR;
    static float MINIMUM_CAPACITY;

    int randomNumber(int min, int max);
    T *array;
    int length;
    int capacity;
    void resize(bool expand);
    void removeAtIndex(int index);

public:
    Set();
    ~Set();
    void insert(T x);
    bool isMember(T x);
    bool remove(T x);
    T pop();
    int size();
    Set intersection(Set &S2);
    Set difference(Set &S2);
    Set Union(Set &S2);

    // for testing
    void print()
    {
        std::cout << "Set values:" << std::endl;
        for (int i = 0; i < length; i++)
        {
            std::cout << array[i] << ", ";
        }
        std::cout << std::endl
                  << "-------------" << std::endl;
    }
};

template <typename T>
float Set<T>::EXPAND_FACTOR = 2;

template <typename T>
float Set<T>::NARROW_FACTOR = 0.4;

template <typename T>
float Set<T>::MINIMUM_CAPACITY = 10;

template <typename T>
Set<T>::Set()
{
    capacity = MINIMUM_CAPACITY;
    length = 0;
    array = new T[capacity];
}

template <typename T>
Set<T>::~Set()
{
    delete[] array;
}

template <typename T>
void Set<T>::resize(bool expand)
{
    float factor = expand ? EXPAND_FACTOR : NARROW_FACTOR;
    if (capacity * factor < 5 || capacity * factor < size())
    {
        return;
    }
    capacity *= factor;

    T *tempArray = new T[capacity];

    for (int i = 0; i < size(); i++)
    {
        tempArray[i] = array[i];
    }

    delete[] array;

    array = tempArray;
}

template <typename T>
void Set<T>::insert(T x)
{
    if (isMember(x))
        return;
    if (size() + 1 > capacity)
        resize(true);

    int i;
    for (i = size() - 1; (i >= 0 && array[i] > x); i--)
    {
        array[i + 1] = array[i];
    }
    array[i + 1] = x;

    ++length;
}

template <typename T>
bool Set<T>::isMember(T x)
{
    int left = 0;
    int right = size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (array[mid] == x)
        {
            return true;
        }

        if (array[mid] > x)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return false;
}

template <typename T>
bool Set<T>::remove(T x)
{
    if (size() - 1 < int(0.25 * capacity))
        resize(false);
    int left = 0;
    int right = size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (array[mid] == x)
        {
            removeAtIndex(mid);
            return true;
        }

        if (array[mid] > x)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return false;
}

template <typename T>
void Set<T>::removeAtIndex(int index)
{
    for (int i = index; i < size() - 1; i++)
    {
        array[i] = array[i + 1];
    }
    --length;
}

template <typename T>
T Set<T>::pop()
{
    int randomIndex = randomNumber(0, size() - 1);
    T value = array[randomIndex];

    removeAtIndex(randomIndex);
    return value;
}

template <typename T>
int Set<T>::size()
{
    return length;
}

template <typename T>
Set<T> Set<T>::intersection(Set &S2)
{
    Set<T> intersectionSet;

    int i = 0;
    int j = 0;

    while (i < size() && j < S2.size())
    {
        if (array[i] == S2.array[j])
        {
            intersectionSet.insert(array[i]);
            ++i;
            ++j;
        }
        else if (array[i] < S2.array[j])
        {
            ++i;
        }
        else
        {
            ++j;
        }
    }
    return intersectionSet;
}

template <typename T>
Set<T> Set<T>::difference(Set &S2)
{
    Set<T> differenceSet;

    int i = 0;
    int j = 0;
    while (i < size() && j < S2.size())
    {
        if (array[i] == S2.array[j])
        {
            ++i;
            ++j;
        }
        else if (array[i] < S2.array[j])
        {
            differenceSet.insert(array[i]);
            ++i;
        }
        else
        {
            ++j;
        }
    }

    while (i < size())
    {
        differenceSet.insert(array[i]);
        ++i;
    }

    return differenceSet;
}

template <typename T>
Set<T> Set<T>::Union(Set &S2)
{
    Set<T> unionSet;

    int i = 0;
    int j = 0;
    while (i < size() && j < S2.size())
    {
        if (array[i] == S2.array[j])
        {
            unionSet.insert(array[i]);
            ++i;
            ++j;
        }
        else if (array[i] < S2.array[j])
        {
            unionSet.insert(array[i]);
            ++i;
        }
        else
        {
            unionSet.insert(S2.array[j]);
            ++j;
        }
    }

    while (i < size())
    {
        unionSet.insert(array[i]);
        ++i;
    }

    while (j < S2.size())
    {
        unionSet.insert(S2.array[j]);
        ++j;
    }

    return unionSet;
}

template <typename T>
int Set<T>::randomNumber(int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, max);

    return distr(gen);
}

// recursive - slower

// template <typename T>
// bool Set<T>::isMember(T x) {
//     return binarySearch(x, 0, size() - 1);
// }

// template <typename T>
// bool Set<T>::binarySearch(T target, int left, int right) {
//     if (left > right) {
//         return false;
//     }

//     int mid = (left + right) / 2;

//     if (array[mid] == target) {
//         return true;
//     }

//     if (array[mid] > target) {
//         return binarySearch(target, left, mid - 1);
//     }
//     return binarySearch(target, mid + 1, right);
// }

#endif
