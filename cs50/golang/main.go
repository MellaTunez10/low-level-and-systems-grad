package main

import (
	"fmt"

	"golang/mario_less"
)

func main() {
	var height int

	fmt.Print("height: ")
	fmt.Scanf("%d", &height)

	for height < 0 || height > 8 {
		fmt.Print("height: ")
		fmt.Scanf("%d", &height)
	}

	mario_less.PrintBricks(height)
}
