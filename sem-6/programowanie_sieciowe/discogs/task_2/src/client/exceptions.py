class TooManyAttemptsError(Exception):
    def __init__(self):
        self.msg = "Returning 429, rate limited response"

    def __str__(self) -> str:
        return self.msg


class HTTPError(Exception):
    def __init__(self, message: str, code: int):
        self.status_code = code
        self.msg = f"{code}: {message}"

    def __str__(self) -> str:
        return self.msg


class AuthorizationError(HTTPError):

    def __init__(self, message, code, response):
        super(AuthorizationError, self).__init__(message, code)
        self.msg = "{0} Response: {1!r}".format(self.msg, response)
