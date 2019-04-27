package main

import (
	"fmt"
)


func main() {
	c := make(chan bool)
	// 两个 goroutine 同时访问一个 m 变量，然后就有 race condition
	m := make(map[string]string)
	go func() {
		m["1"] = "a" // 第一个冲突访问
		c <- true
	}()
	m["2"] = "b" // 第二个冲突访问
	<- c
	for k, v := range m {
		fmt.Println(k, v)
	}
}