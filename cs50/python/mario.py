def print_bricks(height):
    for i in range(height):
        for _ in range(height - i):
            print(" ", end="")
        for _ in range(i + 1):
            print("#", end="")
        print()

