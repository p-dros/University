Dekorator to strukturalny wzorzec projektowy pozwalający dodawać nowe obowiązki obiektom poprzez umieszczanie tych obiektów w specjalnych obiektach opakowujących, które zawierają odpowiednie zachowania.

## Zalety:

Elastyczność: Pozwala na dynamiczne dodawanie lub usuwanie funkcjonalności bez konieczności modyfikowania kodu źródłowych obiektów.
Zachowanie polimorfizmu: Nowo dodane funkcjonalności mogą być traktowane jako część oryginalnego obiektu, zachowując jego typ.
Prostota: Nie wymaga znaczących zmian w kodzie źródłowym obiektów, które ma dekorować.

## Kiedy używać

- Rozszerzanie funkcjonalności: Kiedy masz obiekt, który już wykonuje pewną funkcję, ale chcesz dodać do niego dodatkowe funkcjonalności, które nie są związane z jego głównym celem. Na przykład, możesz mieć klasę Image do renderowania obrazów, a chcesz dodać do niej opcjonalne filtry graficzne, które nie są integralną częścią jej funkcjonalności.
- Logowanie i monitorowanie: Chcesz śledzić działanie obiektów w czasie rzeczywistym, dodając logowanie lub monitorowanie do istniejących obiektów bez modyfikowania ich kodu źródłowego. Na przykład, możesz chcieć śledzić, kiedy określone metody są wywoływane w klasie biznesowej.
- Adaptacja interfejsu: Kiedy musisz dostosować interfejs obiektu do różnych wymagań klientów, ale nie chcesz modyfikować oryginalnego kodu obiektu. Na przykład, możesz mieć klasę bazową Shape dla różnych figur geometrycznych, a chcesz dostosować jej interfejs do specyficznych wymagań biblioteki graficznej.
- Dodawanie funkcjonalności w warunkach dynamicznych: Kiedy funkcjonalność, którą chcesz dodać, jest dostępna tylko w określonym środowisku lub warunkach, które mogą się zmieniać. Na przykład, możesz chcieć dodać obsługę błędów tylko w środowisku produkcyjnym, ale nie chcesz, aby te mechanizmy były obecne w środowisku deweloperskim.
- Tworzenie wariantów produktów: Kiedy oferujesz różne warianty produków lub usług, które mają podobne właściwości, ale różnią się niektórymi funkcjami. Na przykład, możesz mieć klasę Product z różnymi opcjami dodatkowymi, które mogą być dynamicznie dodawane lub usuwane w zależności od wybranego planu.
