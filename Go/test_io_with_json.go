package main

import (
	"os"
	"io/ioutil"
)

func main() {
	b := []byte("ABCCC")
	ioutil.WriteFile("test_file.txt", b, os.ModePerm)
}
