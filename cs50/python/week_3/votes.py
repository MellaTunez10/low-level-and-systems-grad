def main():
    votes = {}
    while True:
        try:
            candidate = input("Vote: ").strip().upper()

            if not candidate:
                continue

            if candidate in votes:
                votes[candidate] += 1
            else:
                votes[candidate] = 1
        except EOFError:
            print()
            break

        for candidate in sorted(votes):
            print(f"{candidate}: {votes[candidate]}")


if __name__ == "__main__":
    main()
