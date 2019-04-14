package main

import "golang.org/x/tour/tree"
import "fmt"

// Walk 步进 tree t 将所有的值从 tree 发送到 channel ch。
func Walk(t *tree.Tree, ch chan int) {
	if t.Left != nil {
		Walk(t.Left, ch)
	}
	ch <- t.Value
	if t.Right != nil {
		Walk(t.Right, ch)
	}
}

// Same 检测树 t1 和 t2 是否含有相同的值。
func Same(t1, t2 *tree.Tree) bool {
	ch1 := make(chan int, 10)
	go Walk(t1, ch1)
	s := make([]int, 10)
	for i := range s {
		s[i] = <- ch1
	}
	ch2 := make(chan int, 10)
	go Walk(t2, ch2)
	s2 := make([]int, 10)
	for i := range s2 {
		s2[i] = <- ch2
	}
	for i := range s {
		if s[i] != s2[i] {
			return false
		}
	}
	return true
}

func main() {
	fmt.Println(Same(tree.New(1), tree.New(2)))
}
