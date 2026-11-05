import sys
import requests


def main():
    if len(sys.argv) < 2:
        sys.exit("Missing command line arguments")

    try:
        n = float(sys.argv[1])
    except ValueError:
        sys.exit("Command-line argument is not a number")

    try:
        response = requests.get(
            "https://rest.coincap.io/v3/assets/bitcoin?apiKey=ea29a63ad2bf5ae4df8fd5f375d2e774e39834e62135217e21608f03a5dd9972"
        )
        response.raise_for_status()
        data = response.json()

        price_usd = float(data["data"]["priceUsd"])
        total_cost = n * price_usd

        print(f"{total_cost:,.4f}")
    except requests.exceptions.RequestException:
        sys.exit("Error fetching data from API")


if __name__ == "__main__":
    main()
