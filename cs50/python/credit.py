def main():
    card = get_number()

    if not check_luhn(card):
        print("INVALID")
        return

    length = get_length(card)
    print_brand(card, length)


def get_number():
    # Loop until the user provides a valid integer
    while True:
        try:
            return int(input("Number: "))
        except ValueError:
            print("Retry with numbers only.")


def check_luhn(card):
    total_sum = 0
    multiply = False

    while card > 0:
        digit = card % 10
        if multiply:
            product = digit * 2
            total_sum += (product // 10) + (product % 10)
        else:
            total_sum += digit

        multiply = not multiply
        card //= 10

    return total_sum % 10 == 0


def get_length(card):
    length = 0
    while card > 0:
        card //= 10
        length += 1
    return length


def print_brand(card, length):
    first_two = card
    while first_two >= 100:
        first_two //= 10

    first_digit = first_two // 10

    if length == 16 and (51 <= first_two <= 55):
        print("MASTERCARD")
    elif (length == 13 or length == 16) and first_digit == 4:
        print("VISA")
    elif length == 15 and (first_two == 34 or first_two == 37):
        print("AMEX")
    else:
        print("INVALID")


if __name__ == "__main__":
    main()
