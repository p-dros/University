from bs4 import BeautifulSoup
import requests

URL = "https://books.toscrape.com/"


def get_html(url: str) -> str | None:
    response = requests.get(url, timeout=8)

    if response.status_code != 200:
        return None
    if "text/html" not in response.headers.get("Content-Type"):
        return None

    return response.text


def main():
    page = get_html(URL)

    if not page:
        print("Failed to get html")
        return

    soup = BeautifulSoup(page, "html.parser")

    container = soup.find("ol", class_="row")

    items = container.find_all("li")

    books = []

    for item in items:
        STAR_RATINGS = {"One": 1, "Two": 2, "Three": 3, "Four": 4, "Five": 5}

        image_url = item.find("a").get("href")

        star_rating_class = item.find("p", class_="star-rating").get("class")[1]
        star_rating = STAR_RATINGS[star_rating_class] or "Not Specified"

        title_elem = item.find("h3")
        title = title_elem.text

        product_details_elem = item.find("div", class_="product_price")
        price = product_details_elem.find("p", class_="price_color").text
        avaliable = "instock" in product_details_elem.find(
            "p", class_="availability"
        ).get("class")


if __name__ == "__main__":
    main()
