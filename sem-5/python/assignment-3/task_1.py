import json
import re

FILE_PATH = "tramwaje.json"
OUPUT_FILE_PATH = "tramwaje_out.json"


def remove_numbers(name):
    return re.sub(r"\s*\d+$", "", name)


with open(FILE_PATH, "r", encoding="utf-8") as file:
    data = json.load(file)

result = {}
trams = data["tramwaje"]

for tram in trams:
    line_number = tram["linia"]
    tram_stops = tram["przystanek"]
    result[line_number] = tuple(remove_numbers(stop["nazwa"]) for stop in tram_stops)

with open(OUPUT_FILE_PATH, "w", encoding="utf-8") as file:
    json.dump(result, file, ensure_ascii=False)


print("-" * 50)
print("Number of stops for each tram in sorted order:")
sorted_trams = sorted(trams, key=lambda tram: len(tram["przystanek"]), reverse=True)
for tram in sorted_trams:
    line_number = tram["linia"]
    tram_stops = tram["przystanek"]
    print(f"{line_number} - {len(tram_stops)}")

print("-" * 50)

all_stops = set()
for tram in trams:
    line_number = tram["linia"]
    tram_stops = tram["przystanek"]
    for stop in tram_stops:
        all_stops.add(stop["nazwa"])


print(f"Number of stops: {len(all_stops)}")
