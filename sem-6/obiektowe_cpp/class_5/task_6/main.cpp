#include <iostream>
#include <type_traits>

// Funkcja zwracająca długość listy typów
template <typename... Types>
constexpr std::size_t length() {
    return sizeof...(Types);
}

// Funkcja zwracająca typ dla określonego indeksu listy typów
template <std::size_t Index, typename... Types>
struct TypeAtIndex;

template <std::size_t Index, typename T, typename... Types>
struct TypeAtIndex<Index, T, Types...> {
    using type = typename TypeAtIndex<Index - 1, Types...>::type;
};

template <typename T, typename... Types>
struct TypeAtIndex<0, T, Types...> {
    using type = T;
};

// Funkcja sprawdzająca, czy dany typ jest wymieniony w podanej liście typów
template <typename T, typename... Types>
constexpr bool contains() {
    return std::disjunction<std::is_same<T, Types>...>::value;
}

int main() {
    // Testowanie funkcji
    std::cout << "Długość listy typów: " << length<int, double, char>()
              << std::endl;

    using Type1 = TypeAtIndex<1, int, double, char>::type;
    std::cout << "Typ dla indeksu 1: " << typeid(Type1).name() << std::endl;

    std::cout << "Czy int jest w liście typów? "
              << contains<int, double, char>() << std::endl;
    std::cout << "Czy float jest w liście typów? "
              << contains<float, double, char>() << std::endl;

    return 0;
}
