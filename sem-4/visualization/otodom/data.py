import json
import pandas as pd
import urllib
from urllib.request import Request
from bs4 import BeautifulSoup as bs

url = "https://www.otodom.pl/pl/oferty/sprzedaz/mieszkanie/krakow?distanceRadius=0&locations=%5Bcities_6-38%5D&viewType=listing&limit=48&page="

pages = []
for page_number in range(1, 30):
    #print(f'Pobieranie strony {page_number}')
    with urllib.request.urlopen(f'{url}{page_number}') as resp:
        processed_page = bs(resp.read().decode('utf-8'), "html.parser")
        pages.append(processed_page)

raw_flats_data = []
for page in pages:
    raw_flats_data += page.find_all(class_='eel6co20 css-1ucvgmr ei6hyam0')

flats_data = []
for entry in raw_flats_data:
    soup = bs(entry.prettify(), 'html.parser')
    data_div = soup.find('div', class_='eel6co20 css-1ucvgmr ei6hyam0')

    data = {}
    spans = data_div.find_all('span', class_='css-1on0450 ei6hyam2')
    check = spans[0].text.strip().replace('\xa0', ' ').replace(' ', '').replace('zł', '')
    if check != 'Zapytajocenę':
        data['price'] = float(spans[0].text.strip().replace('\xa0', ' ').replace(' ', '').replace('zł', '').replace(',', '.'))
        data['price_per_m2'] = int(spans[1].text.strip().replace('\xa0', ' ').replace(' ', '').replace('zł', '').replace('/', '').replace('m²', ''))
        data['rooms'] = int(spans[2].text.strip().replace(' ', '').replace('pokoje', '').replace('pokój', '').replace('pokoi', '').replace('+', ''))
        data['area'] = float(spans[3].text.strip().replace('m²', '').replace(' ', ''))
        flats_data.append(data)

print(flats_data)

with open('data.json', 'w') as file:
    json.dump(flats_data, file)