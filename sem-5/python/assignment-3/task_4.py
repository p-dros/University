import functools


def pamiec(func):
    cache = {}

    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        n = args[0]

        if not n in cache:
            result = func(*args, **kwargs)
            cache[n] = result
        else:
            result = cache[n]

        return result

    return wrapper


@pamiec
def fibonacci(n):
    return n if 0 <= n < 2 else fibonacci(n - 1) + fibonacci(n - 2)


for i in range(100):
    print(fibonacci(i))
