camelCase = input("camelCase: ")

snake_case = ""

for c in camelCase:
    if c.isupper():
        snake_case += "_" + c.lower()
    else:
        snake_case += c


print(f"snake_case: {snake_case}")
