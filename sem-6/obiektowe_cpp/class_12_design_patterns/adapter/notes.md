**Adapter** jest strukturalnym wzorcem projektowym pozwalającym na współdziałanie ze sobą obiektów o niekompatybilnych interfejsach.

## Zalety:

- Kompatybilność: Pozwala na integrację klas z niekompatybilnymi interfejsami.
- Ochrona przed zmianami: Modyfikacje w klasie, której używasz, nie wpłyną na adaptera.
- Podnoszenie standardu: Adaptery mogą pomóc w standaryzacji interfejsów w systemie.

## Kiedy używać

Stosuj klasę Adapter gdy chcesz wykorzystać jakąś istniejącą klasę, ale jej interfejs nie jest kompatybilny z resztą twojego programu.

Wzorzec Adapter pozwala utworzyć klasę która stanowi warstwę pośredniczącą pomiędzy twoim kodem, a klasą pochodzącą z zewnątrz, lub inną, posiadającą jakiś nietypowy interfejs.

- Integracja zewnętrznych bibliotek: Kiedy chcesz użyć funkcjonalności zewnętrznej biblioteki, która ma inny interfejs niż ten, który jest oczekiwany przez resztę Twojego projektu. Adapter pozwala na "przetłumaczenie" interfejsu biblioteki na bardziej spójny z Twoim projektem.
- Migracja systemów: Podczas migracji z jednego systemu na inny, może być konieczne przystosowanie interfejsów klas do nowego środowiska, które ma inne standardy lub wymagania. Adaptery mogą pomóc w tłumaczeniu starych interfejsów na nowe.
- Interoperacyjność między różnymi platformami: Kiedy pracujesz nad aplikacją, która ma działać na różnych platformach (np. Windows, Linux, macOS), ale różne platformy mają różne API dla podobnych funkcji. Adaptery mogą pomóc w dostosowaniu interfejsów klas do specyfikacji platformy docelowej.
- Zmiana technologii: Kiedy zmienia się technologia używana w projekcie (np. z Java na C++, lub z SQL na NoSQL), ale niektóre części systemu muszą nadal korzystać z starszych technologii. Adaptery mogą służyć jako mosty między nowym a starym kodem.
- Zgodność z API: Kiedy musisz dostosować swój kod do zmieniających się API, które mogą mieć różne wersje z różnymi interfejsami. Adaptery mogą pomóc w utrzymaniu kompatybilności z różnymi wersjami API.
