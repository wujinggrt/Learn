package main

import (
	"fmt"
	"strconv"
)

func main() {
	fmt.Println(strconv.Itoa(100))
	fmt.Println(strconv.FormatInt(int64(100), 10))
}
