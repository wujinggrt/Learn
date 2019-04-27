# 学习C++的一些小demo

## 1. 学习《深度探索C++对象模型》的demo
---
代码在[model](./model)里保存

## 函数指针
返回函数指针的函数应该是这样`void (*b(void (*f)()))() {}`，表示这个函数`b`接受的参数是`void (*f)()`类型，返回的类型是：可以解引用（`*`的操作，即是看成`(* function_b_return)()`这样的调用，再接着就是`void (* function_b_return)()`，即是对这个函数完整的声明了，`b()`返回一个返回类型为`void`、接受参数为`()`的函数指针，定义的话也只需在其后加上`{}`。

```C++
// 《STL源码剖析》第57页
// C++11
// auto set_malloc_handler(void (*f) ()) -> void (*) ()
void (*set_malloc_handler(void (*f) ()))()
{
    void (*old) () = __malloc_alloc_oom_handler;
    __malloc_alloc_oom_handler = f;
    
    return old;
}
```

## 2. STL

### 2.1 容器(container)

#### 2.1.1 内存相关

使用序列容器的时候，需要注意内存方面的问题。

* vector的扩张发生的拷贝。
* 在容器使用clear()方法之后，虽然item为空，但是空间依旧被占据。

知道数据量的估计值的话，在使用vector的时候，应该注意使用`vec.reserve(count)`来预留足够的空间。

（此项`list, forward_list`除外，因为其使用了链表）在使用`container.clear()`之后，使用：
1. `shrink_to_fit() `
2. `swap(empty_container)`  

以此来裁剪、释放不必要的空间。

#### 2.1.2 迭代器(iterator)

1. `list, forward_list`不支持随机访问，迭代器类型为`Bidirectional,  ForwardIterator`
2. `vector, deque`支持随机访问，迭代器类型为` RandomAccessIterator`

#### 2.1.3 list

`list`有`splice()`成员函数， 如下(来自[cppreference](https://en.cppreference.com/w/cpp/container/list/splice))：
1. `void splice( const_iterator pos, list& other );` (1)
2. `void splice( const_iterator pos, list&& other );` (1)	(since C++11)
3. `void splice( const_iterator pos, list& other, const_iterator it );` (2)	
4. `void splice( const_iterator pos, list&& other, const_iterator it );` (2)	(since C++11)
5. `void splice( const_iterator pos, list& other, 
             const_iterator first, const_iterator last);` (3)	
6. `void splice( const_iterator pos, list&& other, 
             const_iterator first, const_iterator last );` (3)	(since C++11)

#### 2.1.4 insert

1. `iterator insert( const_iterator pos, const T& value );` (since C++11)
2. `iterator insert( const_iterator pos, T&& value );` (2)	(since C++11)
3. `iterator insert( const_iterator pos, size_type count, const T& value );` (since C++11)
4. `template< class InputIt >
iterator insert( const_iterator pos, InputIt first, InputIt last );` (since C++11)
5. `iterator insert( const_iterator pos, std::initializer_list<T> ilist );` (5)	(since C++11)

#### 2.1.5 copy/copy_backward

1. `copy(iter_first, iter_end, iter_result)`
1. `copy_backward(iter_first, iter_end, iter_result)`M, 

### 2.2 关联容器

`set, map`的底层为`RB-tree`，所以进行存储的时候，会变得有序。

`unoredered_xxx`则是`hash`机制来实现，所以存储不会变得有序。

使用`range for`可以遍历每一个`vallue type`的容器元素，`map`的为`pair<T, U>`类型。

#### 2.1.1 有序容器

使用的API：

1. `c.find(k)`
2. `c.count(k)`
3. `c.lower_bound(k)`
4. `c.upper_bound(k)`

```C++
    set<int> iset = {4, 1, 1, 7, 5, 4, 2, 3};
    cout << "iset:";
    for(auto &e: iset)
    {
        cout << e << " ";
    }
    cout << endl;
// iset:1 2 3 4 5 7
// 显然排好了序，因为底层是RB-tree

    multiset<int> miset = {4, 1, 1, 7, 5, 4, 2, 3};
    cout << "miset:";
    for(auto &e: miset)
    {
        cout << e << " ";
    }
    cout << endl;
// miset:1 1 2 3 4 4 5 7    

    auto it_4 = miset.lower_bound(4);
    auto it_4_end = miset.upper_bound(4);

    cout << "*it_4:" << *it_4 << endl;
    cout << "*it_4_end:" << *it_4_end << endl;
// *it_4:4
// *it_4_end:5
```

#### 2.1.2 无序容器

以`unordered_multiset`为例子，无需容器以`hash function`来运算，且在存储上组织为一组`buket`，可以保存0或多个元素， `hash function`映射到这个`buket`上。 

[unordered_multiset测试代码](./STL/unordered_container_test.cpp)

1. `c.buket(key`)
2. `c.begin(buket_index)`

```C++
unordered_multiset<int> uiset = {4, 1, 1, 1, 7, 5, 4, 2, 3};
cout << "unoredered_set:";
for (const auto &e: uiset)
{
    cout << e << " ";
}
cout << endl;
// unoredered_set:3 2 5 7 1 1 1 4 4

cout << "buket_count:" << uiset.bucket_count() << endl;
// buket_count:11

cout << "buket index:" << endl;
for(const auto &e: uiset)
{
    cout << e << " : " << uiset.bucket(e) << endl;;
}
// buket index:
// 3 : 3
// 2 : 2
// 5 : 5
// 7 : 7
// 1 : 1
// 1 : 1
// 1 : 1
// 4 : 4
// 4 : 4

cout << "uiset.bucket_size(1):" << uiset.bucket_size(1) << endl;
auto it = uiset.begin(1);
while (it != uiset.end(1))
{
    cout << *it << endl;
    ++it;
}
// uiset.bucket_size(1):3
// 1
// 1
// 1
```
### 2.1.3 algorithm

#### 2.1.3.1 accumulate

```C++
template< class InputIt, class T, class BinaryOperation >
T accumulate( InputIt first, InputIt last, T init,
              BinaryOperation op );
```

## 3 Some tips

#### 3.1.1 implicit transform 

```C++
cout << "(3.3 / 2):" << (3.3 / 2) << endl;
cout << "(3 / 2):" << (3 / 2) << endl;
cout << "(3.0 / 2):" << (3.0 / 2) << endl;
cout << "(3 / 2.0):" << (3 / 2.0) << endl;
// (3.3 / 2):1.65
// (3 / 2):1
// (3.0 / 2):1.5
// (3 / 2.0):1.5
```

## 4 GDB


GDB 的 TUI:

    gdb a.out
    (gdb)start arg1 arg2 ...
    (gdb)list
    ctrl + x + a # UI
    next
    CTRL + L 清屏，避免花屏
    ctrl + X + 2 查看汇编 如果在 ctrl + X again 获得寄存器。

    tui reg float 获取 float 的寄存器？

    CTRL + P 再次可以使得以前的命令, up-arrow 是控制界面

    print x
    set x = 3  // modify

    backtrace // 看到函数调用 trace
    step

*NOTE* the next and step commands are different. On a line of code that has a function call, next will go 'over' the function call to the next line of code, while step will go 'into' the function call.

#### call

gdb 可以调用这个运行文件里面已经定义了的函数，比如执行

    (gdb)call func(a)

传入的参数也是当前的变量。

#### Return from function

    finish

#### info

    info frame
    info args
    info locals

#### break

    break 14 // set breakpoint at line 14

If you have more than one file, you must give the break command a filename as well:

    break test.c:19

set a breakpoint on a C function:

    break func1

set a breakpoint on a C++ function:

    break TestClass::test_func(int)

set a temporary breakpoint, A temporary breakpoint only stops the program once, and is then removed.

    tbreak ...

get a list of breakpoints:

    info breakpoints

disable bp:

    disable 2 // break num in info breakpoints

skip breakpoints,two arguments: the breakpoint number to skip, and the number of times to skip it.:

    ignore 2 5

### watch point
---

the variabel you want to set a watchpoint on must be in the current scope.

观察点只能设置在当前的 scope，所以需要在这个 scope 先设置断点。设置观察点后，然后 c，每次当观察的变量有变化的时候就会停止，然后在等待执行 c。

    watch x
    rwatch x
    awatch x

disable 用法同断点，先 i breakpoints 然后在对应到 num 上。

### examine memory

use the x command to examine memory.

If we have char *s = "Hello World\n", some uses of the x command could be:

Examine the variable as a string:


Examine the variable as a string:


    (gdb) x/s s
    0x8048434 <_IO_stdin_used+4>:    "Hello World\n"
Examine the variable as a character:


    (gdb) x/c s
    0x8048434 <_IO_stdin_used+4>:   72 'H'
Examine the variable as 4 characters:


    (gdb) x/4c s
    0x8048434 <_IO_stdin_used+4>:   72 'H'  101 'e' 108 'l' 108 'l'

Examine the first 32 bits of the variable:


    (gdb) x/t s
    0x8048434 <_IO_stdin_used+4>:   01101100011011000110010101001000
Examine the first 24 bytes of the variable in hex:


    (gdb) x/3x s
    0x8048434 <_IO_stdin_used+4>:   0x6c6c6548      0x6f57206f      0x0a646c72

#### core dump, use core core

When your program segfaults and leaves a core dump file, you can use gdb to look at the program state when it crashed. Use the core command to load a core file. The argument to the core command is the filename of the core dump file, which is usually "core", making the full command core core.


    prompt > myprogram
    Segmentation fault (core dumped)
    prompt > gdb myprogram
    ...
    (gdb) core core
    ...

    nexti, stepi

    (gdb) disassemble main

#### registers

    i registers // CTRL + X + 2