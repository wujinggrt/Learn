#### Syntax

range 产生的值是复制的，不是左值，不能进行复制。

```Go
strings

func Fields(s string) []string
```

Fields splits the string s around each instance of one or more consecutive white space characters, as defined by unicode.IsSpace, returning an array of substrings of s or an empty list if s contains only white space.


#### 闭包

```Go

package main

import "fmt"

func adder() func(int) int {
	sum := 0
	return func(x int) int {
		sum += x
		return sum
	}
}

func main() {
	pos, neg := adder(), adder()
	for i := 0; i < 10; i++ {
		fmt.Println(
			pos(i),
			neg(-2*i),
		)
	}
}

/*
0 0
1 -2
3 -6
6 -12
10 -20
15 -30
21 -42
28 -56
36 -72
45 -90
*/
```

那个 func 引用的函数体之外的变量，保存起来的。

#### 方法

Go 没有类。不过你可以为结构体类型定义方法。

由于方法经常需要修改它的接收者，指针接收者比值接收者更常用。

#### 值和指针有所差异

若使用值接收者，那么 Scale 方法会对原始 Vertex 值的副本进行操作。（对于函数的其它参数也是如此。）Scale 方法必须用指针接受者来更改 main 函数中声明的 Vertex 的值。

#### 指针和值在接受者的使用可以转换

由于 Scale 方法有一个指针接收者，为方便起见，Go 会将语句 v.Scale(5) 解释为 (&v).Scale(5)。

同样的事情也发生在相反的方向。

方法调用 p.Abs() 会被解释为 (*p).Abs()。

#### 选择值或指针作为接收者

使用指针接收者的原因有二：

首先，方法能够修改其接收者指向的值。

其次，这样可以避免在每次调用方法时复制该值。若值的类型为大型结构体时，这样做会更加高效。

在本例中，Scale 和 Abs 接收者的类型为 *Vertex，即便 Abs 并不需要修改其接收者。

通常来说，所有给定类型的方法都应该有值或指针接收者，但并不应该二者混用。（我们会在接下来几页中明白为什么。）