import requests

CONSUMER_KEY = "EuQzchfIpmeMEImAVOho"
CONSUMER_SECRET = "bpMHlfwCvvBfJfYcGDgeKhfgXqljsmYm"


class DiscogsClient:
    API_URL = "https://api.discogs.com"

    def __init__(self, key, secret) -> None:
        self.key = key
        self.secret = secret

    def get_artist_id(self, artist_name):
        params = {
            "key": self.key,
            "secret": self.secret,
            "q": f"{artist_name}",
            "type": "artist",
        }

        response = requests.get(f"{self.API_URL}/database/search", params=params)

        body = response.json()
        results = body["results"]

        artist_id = results[0]["id"]

        return artist_id

    def search_artist(self, artist_name):
        artist_id = self.get_artist_id(artist_name)

        response = requests.get(f"{self.API_URL}/artists/{artist_id}")

        print(response.text)


def main():
    client = DiscogsClient(CONSUMER_KEY, CONSUMER_SECRET)

    client.search_artist("Budka Suflera")


if __name__ == "__main__":
    main()
