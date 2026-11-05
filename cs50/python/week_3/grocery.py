def main():
    groceries = {}

    while True:
        try:
            item = input().upper().strip()
        except EOFError:
            print()
            break

        if item in groceries:
            groceries[item] += 1
        else:
            groceries[item] = 1

    for item in sorted(groceries):
        print(f"{groceries[item]} {item}")


if __name__ == "__main__":
    main()
