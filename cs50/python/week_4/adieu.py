import inflect


def main():
    names = []
    p = inflect.engine()
    while True:
        try:
            name = input("Name: ")
            names.append(name)
        except EOFError:
            print()
            break

    formatted = p.join(names)

    print(f"Adieu, adieu, to {formatted}")


if __name__ == "__main__":
    main()
