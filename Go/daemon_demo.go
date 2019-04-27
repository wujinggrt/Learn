package main

import (
	"fmt"
	"time"
)

func say() {
	timeout := 300 // 300 ms
	for {
		t := time.NewTimer(time.Millisecond)
		<- t.C
		timeout--
		fmt.Println(timeout)
	}
}

func foo() {
	go say()
	for {
	}
}

func repeat() string {
	go foo()
	return "end"
}

func main() {
	s := repeat()
	fmt.Println(s)
	for {

	}
}
