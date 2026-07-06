package mario_less

import "fmt"

func PrintBricks(height int) {
	for row := range height {
		for col := 0; col < height-row; col++ {
			fmt.Print(" ")
		}
		for bricks := 0; bricks <= row; bricks++ {
			fmt.Print("#")
		}
		fmt.Println()
	}
}
