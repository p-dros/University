class Bug:
    """
    Klasa reprezentująca obiekt Bug.

    Attributes:
        count (int): Licznik całkowitej liczby obiektów Bug.
        id (int): Unikalny identyfikator obiektu Bug.

    Methods:
        __init__(): Inicjalizuje obiekt Bug, zwiększa licznik i nadaje identyfikator.
        __del__(): Usuwa obiekt Bug, zmniejsza licznik i wyświetla informację o zniszczeniu.
        __str__(): Zwraca string z informacją o liczniku i identyfikatorze obiektu Bug.
    """

    count = 0

    def __init__(self) -> None:
        Bug.count += 1
        self.id = Bug.count

    def __del__(self) -> None:
        Bug.count -= 1
        print(f"End - count: {Bug.count}, id: {self.id}")

    def __str__(self) -> str:
        return f"Count: {Bug.count}, id: {self.id}"


if __name__ == "__main__":
    bugs = []

    for i in range(100):
        bugs.append(Bug())
        print(bugs[-1])
