# Numpy
## 导入  
    from numpy import *
    from numpy import *
    from numpy import array, sin
    import numpy as np
或者在**ipython**中使用magic命令  
    
    In [3]: %pylab
    Using matplotlib backend: Qt5Agg  
    Populating the interactive namespace from numpy and matplotlib

## 一些数组操作
    In [4]: a = [1, 2, 3, 4]

    In [5]: a
    Out[5]: [1, 2, 3, 4]
    In [6]: a + 1
    ---------------------------------------------------------------------------
    TypeError                                 Traceback (most recent call last)
    <ipython-input-6-ca42ed42e993> in <module>()
    ----> 1 a + 1

    TypeError: can only concatenate list (not "int") to list

转换成**array**, array接受[], ()的类型，混合也OK  

    In [4]: a = array(a)

    In [5]: a
    Out[5]: array([1, 2, 3, 4])

    In [6]: a + 1
    Out[6]: array([2, 3, 4, 5])

    In [7]: b = array([2, 3, 4, 5])

    In [8]: a * b
    Out[8]: array([ 2,  6, 12, 20])
可以在数组上进行一系列的+,-,*,/,**的操作，而数组之间的点乘需要使用:

    In [9]: c = np.dot(a, b)

    In [10]: c
    Out[10]: 40

## 提取元素（切片)
    In [11]: a[:2] + a[-2:]
    Out[11]: array([4, 6])

## 修改数组形状(property:shape, method:reshape)
    In [12]: a.shape
    Out[12]: (4,)

    In [13]: a.shape = 2,2 # (2, 2)也OK
    #a.reshape(2, 2)OK
    In [14]: a
    Out[14]:
    array([[1, 2],
        [3, 4]])

## 多维数组
    In [18]: a + a
    Out[18]:
    array([[2, 4],
        [6, 8]])
a目前已经是多维数组

## 画图
linspace 用来生成一组等间隔的数据：

    In [20]: a = linspace(0, 2 * pi, 21)
    In [22]: a
    Out[22]:
    array([0.        , 0.31415927, 0.62831853, 0.9424778 , 1.25663706,
        1.57079633, 1.88495559, 2.19911486, 2.51327412, 2.82743339,
        3.14159265, 3.45575192, 3.76991118, 4.08407045, 4.39822972,
        4.71238898, 5.02654825, 5.34070751, 5.65486678, 5.96902604,
        6.28318531])

    In [24]: b = sin(a)

    In [25]: b
    Out[25]:
    array([ 0.00000000e+00,  3.09016994e-01,  5.87785252e-01,  8.09016994e-01,
            9.51056516e-01,  1.00000000e+00,  9.51056516e-01,  8.09016994e-01,
            5.87785252e-01,  3.09016994e-01,  1.22464680e-16, -3.09016994e-01,
        -5.87785252e-01, -8.09016994e-01, -9.51056516e-01, -1.00000000e+00,
        -9.51056516e-01, -8.09016994e-01, -5.87785252e-01, -3.09016994e-01,
        -2.44929360e-16])

## 从数组中选择元素
    In [31]: b >= 0
    Out[31]:
    array([ True,  True,  True,  True,  True,  True,  True,  True,  True,
            True,  True, False, False, False, False, False, False, False,
        False, False, False])
    In [32]: mask = b >= 0

    In [33]: mask
    Out[33]:
    array([ True,  True,  True,  True,  True,  True,  True,  True,  True,
            True,  True, False, False, False, False, False, False, False,
        False, False, False])


    In [35]: c = np.arange(20)

    In [36]: c
    Out[36]:
    array([ 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16,
        17, 18, 19])
        In [45]: c[c > 5] = 100

    In [46]: c
    Out[46]:
    array([  0,   1,   2,   3,   4,   5, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100])
    In [47]: c * 2
    Out[47]:
    array([  0,   2,   4,   6,   8,  10, 200, 200, 200, 200, 200, 200, 200,
        200, 200, 200, 200, 200, 200, 200])

# Summary
1. import numpy as np
2. a = np.array([[1, 2], [3, 4]])
3. a.shape = (4,) # a.reshape(4,)
4. slice
5. c = np.dot(a, b)
6. a * b # a * 2, same as +, -, **, /
7. sin(a) # make manipulate on all of a
8. c[c>5] = 100