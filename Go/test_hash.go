package main

import (
	"hash/fnv"
	"fmt"
	"strconv"
)

func ihash(s string) int {
	h := fnv.New32a()
	h.Write([]byte(s))
	return int(h.Sum32() & 0x7fffffff)
}

func main() {
	for i := 0; i < 100; i++ {
		fmt.Println(ihash(string(i)) % 10, string(i))
		fmt.Println(ihash(strconv.FormatInt(int64(i), 10)) % 10, strconv.FormatInt(int64(i), 10))
	}
}