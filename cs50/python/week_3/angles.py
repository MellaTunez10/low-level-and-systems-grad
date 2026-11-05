def main():
    while True:
        try:
            angle = input("Angle: ")
            if not angle.endswith('"'):
                continue

            clean_angle = angle.replace("'", "°").rstrip('"')
            d, m, s = map(int, clean_angle.split("°"))

            if 0 <= d <= 360 and 0 <= m <= 59 and 0 <= s <= 59:
                decimal_degree = d + (m / 60) + (s / 3600)
                print(f"{decimal_degree:.2f}")
                break
        except ValueError:
            pass


if __name__ == "__main__":
    main()
