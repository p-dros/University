from client import DiscogsClient

import argparse
from utils import get_common_bands


def parse_arguments():
    parser = argparse.ArgumentParser(
        description="Application that checks if musicians played together in bands."
    )
    parser.add_argument(
        "ids",
        type=str,
        nargs="+",
        help="IDs or names (or first and last names) of artists to check",
    )
    args = parser.parse_args()

    return args


def main():
    args = parse_arguments()

    user_agent = "MyApp/1.0"
    consumer_key = "EuQzchfIpmeMEImAVOho"
    consumer_secret = "bpMHlfwCvvBfJfYcGDgeKhfgXqljsmYm"
    client = DiscogsClient(user_agent, consumer_key, consumer_secret)

    artists = []
    for id in args.ids:
        if not id.isdigit():
            results = client.search(f"{id}", type="artist").get("results")

            if len(results) == 0:
                continue

            result = results[0]
            if result.get("type") != "artist":
                print(f"Id: {id} is a band, not an artist")
                continue

            print(f"For name: {id}, found artist {result.get('title')}")

            id = result.get("id")

        artist = client.artist(int(id))

        artists.append(artist)

    common_bands = get_common_bands(artists)

    if len(common_bands) == 0:
        print("No common bands found")
    else:
        print("\nResults:")
        for band in common_bands:
            print(band)


if __name__ == "__main__":
    main()
