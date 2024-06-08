package main

import "fmt"

type Vertex struct {
	X, Y int
}

var (
	v1 = Vertex{1, 2}
	v2 = Vertex{X: 3}
	p = &Vertex{1, 1}
)

func main() {
	fmt.Println(v1, v2, p)
}
