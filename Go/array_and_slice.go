package main

import "fmt"

func main() {
	var a = [3]int {1, 2, 3}
	s := a[:2]
	fmt.Println(s[0])
	fmt.Println(s, len(s), cap(s))
	b := make([]int, 0, 5)
	fmt.Println(b, len(b), cap(b))
	as := []int{1, 2, 3, 4}
	as[0] = 10
	for _, v := range as {
		v = 44
		j := v
		a[0] = j
	}
	fmt.Println(as)
}
