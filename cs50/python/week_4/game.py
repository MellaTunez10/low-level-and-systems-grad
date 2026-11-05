import sys
from random import randint


def main():
    while True:
        try:
            level = int(input("Level: "))
            if level > 0:
                break
        except ValueError:
            pass

    target = randint(1, level)

    while True:
        try:
            guess = int(input("Guess: "))
            if guess <= 0:
                continue

            if guess < target:
                print("Too small!")
            elif guess > target:
                print("Too large!")
            else:
                print("Just right!")
                sys.exit()
        except ValueError:
            pass


if __name__ == "__main__":
    main()
