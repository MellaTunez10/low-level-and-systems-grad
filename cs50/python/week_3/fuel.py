def main():
    percentage = get_percentage("Fraction: ")

    if percentage <= 1:
        print("E")
    elif percentage >= 99:
        print("F")
    else:
        print(f"{percentage}%")


def get_percentage(prompt: str):
    while True:
        try:
            fraction = input(prompt)

            x_str, y_str = fraction.split("/")

            x_int = int(x_str)
            y_int = int(y_str)

            if x_int < 0 or x_int > y_int:
                continue

            return round((x_int / y_int) * 100)
        except (ValueError, ZeroDivisionError):
            pass


if __name__ == "__main":
    main()
