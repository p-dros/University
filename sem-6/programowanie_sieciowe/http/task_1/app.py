import argparse
import requests
from requests.exceptions import HTTPError

def parse_arguments():
    parser = argparse.ArgumentParser()
    parser.add_argument('domain', type=str)
    args = parser.parse_args()

    return args

def send_request(domain: str):
    try:
       http_response = requests.get(f'http://{domain}', timeout=5)
       https_response = requests.get(f'https://{domain}', timeout=5)
       print(f'port 80: {http_response.headers.get("Server")}')
       print(f'port 443: {https_response.headers.get("Server")}')
    except HTTPError as err:
       print(f"HTTP Error occured: {err}")
    except Exception as err:
       print(f"Other error occured: {err}")

if __name__=="__main__":
   args = parse_arguments()

   send_request(args.domain)
    