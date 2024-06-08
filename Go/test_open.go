package main

import (
	"os"
	"fmt"
)

func main() {
	f, err := os.Create("test_file.txt")
	if err != nil {
		fmt.Println("Create fail!")
	} else {
		fmt.Println("Create succeed!")
	}
	f.Close()
}

