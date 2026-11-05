def main():
    months = [
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December",
    ]

    while True:
        date_str = input("Date: ").strip()

        if "/" in date_str:
            try:
                month, day, year = map(int, date_str.split("/"))

                if 1 <= month <= 12 and 1 <= day <= 31:
                    print(f"{year:04}-{month:02}-{day:02}")
                    break
            except ValueError:
                pass

        elif "," in date_str:
            try:
                month_day_s, year_s = date_str.split(",")
                year = int(year_s.strip())

                month_name, day = month_day_s.strip().split(" ")
                day = int(day)
                if month_name in months:
                    month = months.index(month_name) + 1
                    if 1 <= day <= 31:
                        print(f"{year:04}-{month:02}-{day:02}")
                        break
            except ValueError:
                pass


if __name__ == "__main__":
    main()
