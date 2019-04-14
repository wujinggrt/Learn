package main

import "fmt"
import "./inner"

func main() {
	fmt.Println("Outer pack")
	inner.Test()
}