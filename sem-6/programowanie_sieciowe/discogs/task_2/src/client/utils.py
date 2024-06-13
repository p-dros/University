from functools import wraps
from random import uniform
from time import sleep

from client.exceptions import TooManyAttemptsError


def get_backoff_duration(exponent: int) -> float:
    sleep_duration = 2**exponent

    return uniform(0, sleep_duration)


def backoff(f):

    @wraps(f)
    def wrapper(self, *args, **kwargs):
        MAX_ATTEMPTS = 50

        if not hasattr(self, "backoff_enabled"):
            raise AttributeError("backoff_enabled attribute required on a class")

        if not self.backoff_enabled:
            return f(self, *args, **kwargs)

        for i in range(0, MAX_ATTEMPTS):
            result = f(self, *args, **kwargs)

            if result.status_code != 429:
                return result

            duration = get_backoff_duration(i)
            sleep(duration)

        raise TooManyAttemptsError

    return wrapper
