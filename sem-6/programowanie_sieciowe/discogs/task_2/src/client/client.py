import json

from client.fetcher import KeySecretFetcher, RequestsFetcher
from client.exceptions import HTTPError


class DiscogsClient:
    _base_url = "https://api.discogs.com"

    def __init__(
        self, user_agent: str, consumer_key: str = None, consumer_secret: str = None
    ) -> None:
        self.user_agent = user_agent
        self.verbose = False

        if consumer_key and consumer_secret:
            self._fetcher = KeySecretFetcher(consumer_key, consumer_secret)
        else:
            self._fetcher = RequestsFetcher()

    def _request(self, method: str, endpoint: str, params: dict = None):
        if self.verbose:
            print(f"{method} {self._base_url}{endpoint}")

        headers = {"User-Agent": self.user_agent}

        content, status_code = self._fetcher.fetch(
            method, f"{self._base_url}{endpoint}", headers, params
        )

        if status_code == 204:
            return None

        body = json.loads(content)

        if 200 <= status_code <= 300:
            return body
        else:
            raise HTTPError(body.get("message"), status_code)

    def _get(self, endpoint: str, params=None):
        return self._request("GET", endpoint, params)

    def search(self, query: str, type: str = "release"):
        params = {"q": query, "type": type}
        return self._get("/database/search", params)

    def artist(self, artist_id: int):
        return self._get(f"/artists/{artist_id}")

    @property
    def backoff_enabled(self) -> bool:
        return self._fetcher.backoff_enabled
