package credit

func Credit(card int) string {
	// Get the length of the card
	length := cardLength(card)
}

func printBrand(card int, length int) {
	firstTwo := card
	for firstTwo > 100 {
		firstTwo /= 10
	}

	firstDigit := firstTwo / 10
}

func checkLuhn(card int) bool {
	var sum int
	multiply := false

	for card > 0 {
		digit := card % 10
		if multiply {
			product := digit * 2
			sum += (product / 10) + (product % 10)
		} else {
			sum += digit
		}
		multiply = !multiply
		card /= 10
	}
	return sum%10 == 0
}

func cardLength(card int) int {
	length := 0
	for card > 0 {
		card /= 10
		length++
	}
	return length
}
