package main

import (
	"os"
	"fmt"
)

func main() {
	file, e := os.Open("./test_open_without_create.txt")
	if e != nil {
		fmt.Println("Failed, Trying to create")
		file, e = os.Create("./test_open_without_create.txt")
		if e != nil {
			fmt.Println("Failed to create")
		} else {
			fmt.Println("Create succeed")
		}
	} else {
		fmt.Println("Succeed")
	}
	file.Close()
}
