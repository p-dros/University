# podpunkt A)
# zdefiniować w ramach klasy A funkcję foo(self, x), metodę klasy class_foo, metodę statyczną static_foo,
# tak, żeby kod poniżej drukował treści jak w komentarzach


class A(object):
    def foo(self, x):
        print(f"foo({self}, {x})")

    @classmethod
    def class_foo(cls, x):
        print(f"class_foo({cls}, {x})")

    @staticmethod
    def static_foo(x):
        print(f"wykonanie static_foo({x})")


a = A()
a.foo(123)  # wykonanie foo(<__main__.A object at 0x0000023A680D1F10>, 123)
A.foo(a, 123)  # ditto
a.class_foo(123)  # class_foo(<class '__main__.A'>, 123)
A.class_foo(123)  # ditto
a.static_foo(123)  # wykonanie static_foo(123)
A.static_foo(123)  # ditto

print("\n", "-" * 20, "\n")

# podpunkt B)
# zdefiniować dowolną klasę bazową dziedzicząca z ABC i posiadającą metodę abstrakcyjną
# po czym zdefiniować ze dwie klasy potomne z odpowiednimi definicjami, zademonstrować w działaniu

# podpunkt C)
# zdefiniować dowolną klasę oraz atrybut klasy tak, że stanie się on atrybutem czytanym poprzez
# dekorator @property, a ustawianym za pomocą @nazwa.setter, pokazać w działaniu

from abc import ABC, abstractmethod
import math


class Shape(ABC):
    SIDES = 0

    @abstractmethod
    def area(self):
        pass


class Square(Shape):
    SIDES = 4

    def __init__(self, side):
        self.side = side

    def area(self):
        return self.side * self.side

    @property
    def side(self):
        return self._side

    @side.setter
    def side(self, value):
        if value < 0:
            raise ValueError("Side must be positive")
        self._side = value


class Circle(Shape):
    def __init__(self, radius):
        self.radius = radius

    def area(self):
        return math.pi * self.radius * self.radius

    @property
    def radius(self):
        return self._radius

    @radius.setter
    def radius(self, value):
        if value < 0:
            raise ValueError("Radius must be positive")
        self._radius = value


square = Square(5)
circle = Circle(3)

try:
    square.side = -2
except ValueError as e:
    print(f"Expected Error: {e}")

try:
    circle.radius = -1
except ValueError as e:
    print(f"Expected Error: {e}")

square.side = 8
circle.radius = 4

print(
    f"Updated Square: Side length = {square.side}, Area = {square.area()}, Sides = {Square.SIDES}"
)
print(
    f"Updated Circle: Radius = {circle.radius}, Area = {circle.area()}, Sides = {Circle.SIDES}"
)
