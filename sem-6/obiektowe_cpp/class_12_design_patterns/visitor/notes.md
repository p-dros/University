**Odwiedzający** to behawioralny wzorzec projektowy pozwalający oddzielić algorytmy od obiektów na których pracują.

Jest to szczególnie przydatne, gdy masz zestaw klas, które mają wspólne operacje, ale te operacje są różne dla każdej klasy. Wzorzec Visitor pozwala na definiowanie nowych operacji w osobnym obiekcie (Visitor), który "odwiedza" (czyli wykonuje operacje na) obiektach, które implementują określony interfejs.

## Zalety:

Separacja algorytmu od struktury: Algorytmy są definiowane w osobnych klasach, co ułatwia ich zarządzanie i modyfikację.
Elastyczność: Możliwość łatwego dodawania nowych operacji bez modyfikowania istniejących klas.
Polimorfizm: Operacje są definiowane w sposób polimorficzny, co ułatwia rozszerzanie funkcjonalności.

## Kiedy używać
