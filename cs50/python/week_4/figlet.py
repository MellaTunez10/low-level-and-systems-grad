import sys
from random import choice
from pyfiglet import Figlet


def main():
    figlet = Figlet()
    available_fonts = figlet.getFonts()

    if len(sys.argv) == 1:
        font = choice(available_fonts)
    elif len(sys.argv) == 3:
        if sys.argv[1] not in ("-f", "--font"):
            sys.exit("Invalid usage")
        if sys.argv[2] not in available_fonts:
            sys.exit("Invalid usage")
        font = sys.argv[2]
    else:
        sys.exit("Invalid usage")

    figlet.setFont(font=font)
    text = input("Input: ")

    print(f"Output:\n{figlet.renderText(text)}")


if __name__ == "__main__":
    main()
