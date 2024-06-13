import requests
import sys
import argparse
from requests.exceptions import HTTPError

DEFAULT_URL = "https://th.if.uj.edu.pl/"
DEFAULT_EXPECTED_TEXT = "Institute of Theoretical Physics"
DEFAULT_CONTENT_TYPE = "text/html"


def website_status(
    url: str, expected_text: str, expected_content_type: str
) -> tuple[int, str]:
    try:
        response = requests.get(url, timeout=5)

        if response.status_code != 200:
            return (1, "Failed to fetch website")

        content_type = response.headers.get("Content-Type")

        if not content_type or expected_content_type not in content_type:
            return (1, "Reponse is not of expected content-type")

        if expected_text not in response.text:
            return (1, "Page does not contain expected text")

        return (0, "Website is working properly")

    except HTTPError as err:
        return (1, "HTTPError occured")
    except Exception as err:
        return (1, "Something went wrong")


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "-u", "--url", type=str, help="URL address to fetch from", default=DEFAULT_URL
    )
    parser.add_argument(
        "-e",
        "--expected",
        type=str,
        help="Expected text to exist on a webpage",
        default=DEFAULT_EXPECTED_TEXT,
    )
    parser.add_argument(
        "-c",
        "--content",
        type=str,
        help="content-type to expect from website",
        default=DEFAULT_CONTENT_TYPE,
    )

    args = parser.parse_args()

    (status, message) = website_status(args.url, args.expected, args.content)

    print("-" * 50)
    print(f"Url: {args.url}")
    print(f"Status: {status}")
    print(f"Message: {message}")
    print("-" * 50)
    sys.exit(status)


if __name__ == "__main__":
    main()
