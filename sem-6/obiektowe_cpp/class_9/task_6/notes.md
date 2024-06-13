# Weak Pointer

`std::weak_ptr` jest specjalnym rodzajem inteligentnego wskaźnika w C++, który służy do obserwowania obiektu kontrolowanego przez std::shared_ptr bez zwiększania licznika odwołań do niego. Jest to użyteczne w sytuacjach, gdy chcemy uniknąć cyklicznych zależności między obiektami.

Główne cechy `std::weak_ptr`:

- Nie zwiększa licznika odwołań obiektu.
- Może być konwertowany na std::shared_ptr, aby uzyskać dostęp do kontrolowanego obiektu, jeśli istnieje.
- Automatycznie staje się pusty, gdy obiekt kontrolowany przez std::shared_ptr zostanie usunięty.
