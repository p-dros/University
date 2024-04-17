## Polimorfizm dynamiczny

Polimorfizm dynamiczny odnosi się do sytuacji, w której wywołanie konkretnej funkcji jest podejmowane podczas działania programu, a nie na etapie kompilacji.

W języku C++ jest to często osiągane poprzez dziedziczenie i korzystanie z metod wirtualnych, które umożliwiają wywołanie odpowiedniej funkcji na podstawie typu rzeczywistego obiektu.

## Polimorfizm statyczny

Polimorfizm statyczny, z drugiej strony, odnosi się do sytuacji, w której decyzja o wywołaniu konkretnej funkcji jest podejmowana na etapie kompilacji, na podstawie typu zadeklarowanego obiektu.

W języku C++, mechanizm polimorfizmu statycznego można uzyskać poprzez użycie szablonów.

## Klasa abstrakcyjna

**Klasa abstrakcyjna** to klasa, która zawiera co najmniej jedną funkcję czysto wirtualną (ang. pure virtual function).
Funkcje te nie posiadają implementacji w klasie bazowej i muszą być zaimplementowane w klasach pochodnych.

Klasa abstrakcyjna służy jako interfejs, który definiuje zachowanie, ale **nie dostarcza konkretnych implementacji**.

Obiekty klas abstrakcyjnych nie mogą być tworzone bezpośrednio, ale mogą być używane do wskaźników i referencji do obiektów klas pochodnych.

## Funkcja wirtualna

Funkcja wirtualna to funkcja, która jest oznaczona słowem kluczowym `virtual` w klasie bazowej i może być przesłaniana (nadpisywana) w klasach pochodnych. Wywołanie funkcji wirtualnej na obiekcie klasy bazowej spowoduje wywołanie implementacji odpowiedniej dla rzeczywistego typu obiektu, co jest kluczowe w osiągnięciu polimorfizmu dynamicznego. Funkcje wirtualne umożliwiają, aby różne klasy pochodne mogły dostarczyć własne implementacje danej funkcji, co jest istotne w dziedziczeniu i polimorfizmie.
