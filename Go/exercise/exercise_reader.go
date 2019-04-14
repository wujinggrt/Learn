package main

import "golang.org/x/tour/reader"
import "io"

type MyReader struct{}

func (r MyReader) Read(b []byte) (int, error) {
	if b == nil {
		return 0, io.EOF
	}
	for i := range b {
		b[i] = 'A'
	}
	return len(b), nil	
}
// TODO: 给 MyReader 添加一个 Read([]byte) (int, error) 方法

func main() {
	reader.Validate(MyReader{})
}
