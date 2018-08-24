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