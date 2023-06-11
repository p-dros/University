import json
from typing import TypedDict

class Entry(TypedDict): 
    price: float
    price_per_m2: int
    rooms: int
    area: float
    
    

file_path = 'data.json'

def get_data(path: str) -> list[Entry]:
    with open(path, 'r') as json_file:
        data = json.load(json_file) 
    return data


data = get_data(file_path)

print(data[0].price)