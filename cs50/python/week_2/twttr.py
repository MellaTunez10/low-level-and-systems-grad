text = input("Input: ")

result = "".join(char for char in text if char.lower() not in "aeiou")

print(result)
