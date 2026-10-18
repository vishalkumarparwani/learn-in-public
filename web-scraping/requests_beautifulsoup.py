import requests
import os
from bs4 import BeautifulSoup
from urllib.parse import urljoin

URL = "https://books.toscrape.com/catalogue/page-1.html"
HEADERS = {"User-Agent": "FlyRankInternshipA9/1.0 (https://github.com/vishalkumarparwani/FlyRank_VishalKmar)"}

def fetch_page(url, cache_filename):
    cache_path = f"../cache/{cache_filename}"
    if os.path.exists(cache_path):
        with open(cache_path, "r", encoding="utf-8") as f:
            content = f.read()
        print("CACHE HIT", len(content), "bytes")
        return content
    else:
        print("no cache yet, need to fetch")
        try:
            response = requests.get(url, headers=HEADERS, timeout=5)
        except requests.RequestException as e:
            print("Request failed:", e)
            return None

        if response.status_code == 200:
            with open(cache_path, "w", encoding="utf-8") as f:
                f.write(response.text)
            print("FETCH", len(response.text), "bytes")
            return response.text
        else:
            print("Failed with status", response.status_code)
            return None
       


def extract_links(current_url, html):
    soup = BeautifulSoup(html, "html.parser")
    books = soup.select("article.product_pod")

    links = set()
    for book in books:
        href = book.find("a")["href"]
        absolute_link = urljoin(current_url, href)
        links.add(absolute_link)


    next_link_tag = soup.select_one("li.next a")
    if next_link_tag:
        next_url = urljoin(current_url, next_link_tag["href"])
    else:
        next_url = None
        print("no next page")

    return links, next_url


def extract_book_details(book_url, html):
    soup = BeautifulSoup(html, "html.parser")
    title = soup.select_one("div.product_main h1").text.strip()
    price_text = soup.select_one("p.price_color").text.strip()
    availability_text = soup.select_one("p.availability").text.strip()
    rating_text = soup.select_one("p.star-rating")
    desc_tag = soup.select_one("#product_description")
    description = desc_tag.find_next_sibling("p").text.strip() if desc_tag else None
    return {
        "title": title,
        "product_url": book_url,
        "price_text": price_text,
        "availability": availability_text,
        "rating_text": rating_text,
        "description": description,
    }



all_links = set()
current_url = URL
page_number = 1

while page_number <= 3:
    html = fetch_page(current_url, f"catalogue-page-{page_number}.html")
    if html is None:
        break
    links, next_url = extract_links(current_url, html)
    all_links.update(links)

    if next_url:
        current_url = next_url
        page_number += 1
    else:
        break

print(f"catalogue_pages={page_number}")
print(f"discovered={len(all_links)}")
print(f"unique_urls={len(all_links)}")


for book_url in all_links:
    cache_filename = book_url.split("/")[-2] + ".html"
    book_html = fetch_page(book_url, cache_filename)

    if book_html is None:
        continue

    book_details = extract_book_details(book_url, book_html)
    print(book_details)