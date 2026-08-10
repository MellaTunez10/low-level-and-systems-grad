# Version 1
# print("Hello, world")

# Version 2


def manual_palindrome(text):
    text = text.strip().lower()

    last = len(text) - 1

    for char in text:
        if char == text[last]:
            return True
        last -= 1

    return False


manual_palindrome("Hello")
