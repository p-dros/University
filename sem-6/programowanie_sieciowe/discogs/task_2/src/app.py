from client import DiscogsClient
from argparse import ArgumentParser
from utils import get_common_bands


def parse_arguments():
    parser = ArgumentParser(
        prog="Common bands",
        description="Application that checks if musicians played together in bands.",
    )
    parser.add_argument("ids", nargs="+", type=str, help="ids of artists to check")
    args = parser.parse_args()

    return args


def create_client():
    user_agent = "MyApp/1.0"
    consumer_key = "EuQzchfIpmeMEImAVOho"
    consumer_secret = "bpMHlfwCvvBfJfYcGDgeKhfgXqljsmYm"
    client = DiscogsClient(user_agent, consumer_key, consumer_secret)

    return client


def main():
    args = parse_arguments()
    ids = args.ids

    client = create_client()

    artists = [client.artist(id) for id in ids]

    artists = []
    for id in ids:
        resource = client.artist(id)
        if not "groups" in resource:
            print(
                f"Skipping resource with id {id}. It is not an artist or has been part of no group."
            )
            continue

        artists.append(resource)

    common_bands = get_common_bands(artists)

    if len(common_bands) == 0:
        print("No common bands found")
    else:
        sorted_common_bands = sorted(common_bands, key=lambda band: band.name)

        for band in sorted_common_bands:
            print(band)


if __name__ == "__main__":
    main()
