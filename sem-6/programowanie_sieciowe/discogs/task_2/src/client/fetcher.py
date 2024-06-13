from requests.api import request
from client.utils import backoff


class Fetcher:
    backoff_enabled = True

    def fetch(
        self, method: str, url: str, headers=None, params=None
    ) -> tuple[bytes, int]:
        raise NotImplementedError()

    @backoff
    def request(self, method, url, headers, params=None):
        return request(
            method=method,
            url=url,
            headers=headers,
            params=params,
        )


class RequestsFetcher(Fetcher):
    def fetch(
        self, method: str, url: str, headers=None, params=None
    ) -> tuple[bytes, int]:
        response = self.request(method=method, url=url, headers=headers, params=params)

        return response.content, response.status_code


class KeySecretFetcher(Fetcher):
    def __init__(self, key, secret):
        self.key = key
        self.secret = secret

    def fetch(self, method, url, headers=None, params=None) -> tuple[bytes, int]:
        if params is None:
            params = {}
        params.update({"key": self.key, "secret": self.secret})

        response = self.request(
            method=method,
            url=url,
            headers=headers,
            params=params,
        )

        return response.content, response.status_code
