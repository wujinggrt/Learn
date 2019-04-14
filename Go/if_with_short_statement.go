package main

import "fmt"
import "math"

func main() {
	if v := math.Pow(3, 3); v < 10 {
		fmt.Println(v)
	} else {
		fmt.Println("v is less than 10", v)
	}
}
