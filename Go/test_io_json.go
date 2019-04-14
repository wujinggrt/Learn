package main

import (
	"fmt"
	"os"
	"encoding/json"
)

type Person struct {
	Name string
	Age int
	Gender bool
}

func main() {
	p := Person {
		"Qiangdong",
		35,
		true,
	}
	p2 := Person {
		"Zetian",
		32,
		false,
	}
	f, _ := os.Open("json_file.txt")
	dec := json.NewDecoder(f)
	dec.Decode(&p)
	fmt.Println(p)
	dec.Decode(&p2)
	fmt.Println(p2)
}
