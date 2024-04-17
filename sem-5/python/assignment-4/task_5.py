from multipledispatch import dispatch


class Shape(object):
    def __init__(self):
        print("Figura init")


class Rectangle(Shape):
    def __init__(self, x: float, y: float):
        super().__init__()
        self.x = x
        self.y = y


class Square(Rectangle):
    def __init__(self, x: float):
        super().__init__(x, x)


@dispatch(Shape)
def surface(instance: Shape):
    print("Pole: Figura")
    return 0


@dispatch(Rectangle)
def surface(instance: Rectangle):
    print("Pole: Prostokat")
    return instance.x * instance.y


@dispatch(Rectangle, int, int)
def surface(instance: Rectangle, x: int, y: int):
    print("Pole: Prostokat")
    instance.x = x
    instance.y = y
    return instance.x * instance.y


@dispatch(Square)
def surface(instance: Square):
    print("Pole: Kwadrat")
    return instance.x * instance.x


@dispatch(Square, int)
def surface(instance: Square, x: int):
    print("Pole: Kwadrat")
    instance.x = x
    return instance.x * instance.x


# tests

shape = Shape()
rectangle = Rectangle(x=3.0, y=4.0)
square = Square(x=2.5)

# Case 1: Using the base class Shape
result1 = surface(shape)
print(result1)
# Output: Pole: Figura
# 0

# Case 2: Using the derived class Rectangle
result2 = surface(rectangle)
print(result2)
# Output: Pole: Prostokat
# 12.0

# Case 3: Using the derived class Square
result3 = surface(square)
print(result3)
# Output: Pole: Kwadrat
# 6.25

# Case 4: Using the dispatch for Rectangle with explicit dimensions
result4 = surface(rectangle, 2, 3)
print(result4)
# Output: Pole: Prostokat
# 6

# Case 5: Using the dispatch for Square with explicit dimension
result5 = surface(square, 4)
print(result5)
# Output: Pole: Kwadrat
# 16
