package main

import (
	"fmt"
	"time"
)

func main() {
	fmt.Println("When's Saturday?")
	today := time.Now().Weekday()
	switch time.Saturday {
	case today + 0:
		fmt.Println("Today is it.")
	case today + 1:
		fmt.Println("Tomorror.")
	case today + 2:
		fmt.Println("The day after tomorror.")
	default:
		fmt.Println("Too far.")
	}

	t := time.Now()
	switch {
	case t.Hour() < 12:
		fmt.Println("Morning.")
	case t.Hour() < 17:
		fmt.Println("Afternoon.")
	default:
		fmt.Println("Evening.")
	}
}
