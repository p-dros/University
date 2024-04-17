#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <list>
using std::list;

#include <iterator>
using std::forward_iterator_tag;
using std::iterator_traits;
using std::random_access_iterator_tag;

// iterator o swwobodnm dostepie
template <typename Iter>
int perform(Iter i, std::random_access_iterator_tag) {
    std::cout << "Swobodny dostep iterator\n";
    return 1;
}

// iterator jednokierunkowy -> przod
template <typename Iter>
int perform(Iter i, std::forward_iterator_tag) {
    std::cout << "Jednokierunkowy iterator\n";
    return 2;
}

// iterator dwukierunkowy -> przod i tyl
template <typename Iter>
int perform(Iter i, std::bidirectional_iterator_tag) {
    std::cout << "dwu kierunkowy iterator\n";
    return 3;
}

// Funkcja operacja_impl dla iteratorów jednokierunkowych lub lepszych
template <typename Iter>
int operacja_impl(Iter i, forward_iterator_tag) {
    cout << "Iterator jednokierunkowy (albo lepszy).\n";
    return 1;
}

// Funkcja operacja - interfejs dla użytkownika
template <typename Iter>
inline int operacja(Iter i) {
    return operacja_impl(
        i, typename std::iterator_traits<Iter>::iterator_category()
    );
}

int main() {
    // Wybierze implementację dla iteratora jednokierunkowego.
    list<int> l;
    operacja(l.begin());

    // Wybierze implementację dla iteratora o swobodnym dostępie (tablica).
    int t[3];
    operacja(t);

    // Wybierze implementację dla iteratora dwukierunkowego.
    list<int>::iterator it = l.begin();
    std::advance(it, 1);
    operacja(it);

    return 0;
}