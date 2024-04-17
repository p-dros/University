from functools import singledispatch, singledispatchmethod
from datetime import datetime


@singledispatch
def greet(arg):
    return "Hello, world!"


@greet.register(str)
def _(name):
    return f"Cześć {name}!"


@greet.register(datetime)
def _(datetime):
    if 5 <= datetime.hour < 12:
        return "Good morning!"
    elif 12 <= datetime.hour < 18:
        return "Good afternoon!"
    else:
        return "Good evening!"


@greet.register(int)
def _(random):
    greetings = ["Witaj!", "Hej!", "Dzień dobry!"]
    return greetings[random % len(greetings)]


print(greet(None))
print(greet("Jan"))
print(greet(datetime(2020, 12, 12, 10, 0, 0)))
print(greet(2))

# singledispatchmethod


class Event:
    pass


class UserSignedUp(Event):
    def __init__(self, email):
        self.email = email


class CustomerCanceledSubscription(Event):
    def __init__(self, email):
        self.email = email


class EventHandler:
    @singledispatchmethod
    def handle(self, event):
        raise NotImplementedError("Unsupported event")

    @handle.register
    def _(self, event: UserSignedUp):
        print(f"Send welcome email to {event.email}")

    @handle.register
    def _(self, event: CustomerCanceledSubscription):
        print(f"Send confirmation email to {event.email}")


events = [
    UserSignedUp(email="example@exp.com"),
    CustomerCanceledSubscription(email="example@exp.com"),
]

handler = EventHandler()

for event in events:
    handler.handle(event)
