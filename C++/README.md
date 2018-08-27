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
1. `copy_backward(iter_first, iter_end, iter_result)`