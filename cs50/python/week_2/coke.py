VALID_COINS = (25, 10, 5)

amount_due = 50

while amount_due > 0:
    print(f"Amound Due: {amount_due}")
    coin = int(input("Insert Coin: "))

    if coin in VALID_COINS:
        amount_due -= coin


print(f"Change Owed: {abs(amount_due)}")
