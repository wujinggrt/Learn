# numpy array

## Contents:

## Import
```py
from numpy import *
```

## Generating
from **list**：
```py
lst = [0, 1, 2, 3]
a = array(lst)
a
array([0, 1, 2, 3])
```
from **tuple**:
```py
In [6]: b = (1, 2, 3, 4)

In [7]: a = array(b)

In [8]: a
Out[8]: array([1, 2, 3, 4])
```

## Property
### view type
```py
type(a)
numpy.ndarray
```
### view type of data in array
```py
a.dtype
dtype('int32')
```
### view each byte of data occupy
```py
a.itemsize
4
```
### view shape
```py
a.shape # or shape(a)
(4L,)
```
### view elements count
```py
a.size # or size(a)
4
```
### view the space that all elements occupy
```py
a.nbytes
16
```
### dimension
```py
a.ndim
1
```

## Using method fill to initialize
```
In [12]: a.fill(-4) # note that -4, point

In [13]: a
Out[13]: array([-4, -4, -4, -4])
```

## Index and Slice
most of it same as operation on list and tuple.   
Suppose that we have record the data from hodometer each day,     
and we process it to compute the distance the car runs each day.  
```py
In [17]: od = array((2100, 21180, 21240, 22100, 22400))

In [18]: dist = od[1:] - od[:-1] # end=-1, but is not the last element, is the last ofter one.[start:end:step], exclusive end.

In [19]: dist
Out[19]: array([19080,    60,   860,   300])
```

## method tolist()

## Multidimensional array and property
```py
a = array([[ 0, 1, 2, 3],
           [10,11,12,13]])
a
```

## Slice is reference(method copy)
```py
In [39]:
a = array([0,1,2,3,4])
b = a[2:4].copy()
b[0] = 10
a
Out[39]:
array([0, 1, 2, 3, 4])
```

## Fancy indexing

### One dimension

#### By indices list
```py
In [54]: a = np.arange(0, 80, 10)

In [55]: a
Out[55]: array([ 0, 10, 20, 30, 40, 50, 60, 70])
In [54]: a = np.arange(0, 80, 10)

In [55]: a
Out[55]: array([ 0, 10, 20, 30, 40, 50, 60, 70])

In [56]: indices = [1, 2, -3]

In [57]: y = a[indices]

In [58]: y
Out[58]: array([10, 20, 50])
```

#### By bool array
```py
In [59]: mask = np.array([0, 1, 1, 0, 0, 1, 0, 0], dtype = bool)

In [60]: a[mask]
Out[60]: array([10, 20, 50])
```

#### Using bool expression to generate mask, filting nums greater than 0.5
```py
In [61]: from numpy.random import rand

In [62]: a = rand(10)

In [63]: a
Out[63]:
array([0.97326823, 0.40812936, 0.74118461, 0.695921  , 0.47909402,
       0.92408763, 0.91764725, 0.62879112, 0.09606977, 0.30138123])

In [64]: mask = a > 0.5

In [65]: mask
Out[65]:
array([ True, False,  True,  True, False,  True,  True,  True, False,
       False])

In [66]: a[mask]
```

### 2D
**花式索引返回的是原对象的一个复制而不是引用 ** 
```py
In [70]: a = np.array([[ 0, 1, 2, 3, 4, 5],
    ...:            [10,11,12,13,14,15],
    ...:            [20,21,22,23,24,25],
    ...:            [30,31,32,33,34,35],
    ...:            [40,41,42,43,44,45],
    ...:            [50,51,52,53,54,55]])
### giving row, clo number to index.
In [71]: a[(0, 1, 2, 3, 4), (1, 2, 3, 4, 5)]
Out[71]: array([ 1, 12, 23, 34, 45])
# returns diagnoal line numbers
# row:0, 1, 2, 3, 4,
# clo:1, 2, 3, 4, 5
a[3:, [0,2,5]]
Out[48]: array([[30, 32, 35],
       [40, 42, 45],
       [50, 52, 55]])
# returns the 4th rows until last, and the 1, 3, 5col 
In [77]: mask = np.array([1, 0, 1, 0, 0, 1], dtype = bool)

In [78]: a[mask, 2]
Out[78]: array([ 2, 22, 52])
# indexing by mask
# [0, 2], [2, 2], [5, 2]
```

### Not complete indexing
giving a certain row and return it.  
```py
In [50]:
y = a[:3]
y
Out[50]:
array([[ 0,  1,  2,  3,  4,  5],
       [10, 11, 12, 13, 14, 15],
       [20, 21, 22, 23, 24, 25]])
In [51]:
condition = array([0,1,1,0,1],
                 dtype=bool)
a[condition]
Out[51]:
array([[10, 11, 12, 13, 14, 15],
       [20, 21, 22, 23, 24, 25],
       [40, 41, 42, 43, 44, 45]])
```

### 3D
```py
In [52]:
a = arange(64)
a.shape = 4,4,4
a
Out[52]:
array([[[ 0,  1,  2,  3],
        [ 4,  5,  6,  7],
        [ 8,  9, 10, 11],
        [12, 13, 14, 15]],

       [[16, 17, 18, 19],
        [20, 21, 22, 23],
        [24, 25, 26, 27],
        [28, 29, 30, 31]],

       [[32, 33, 34, 35],
        [36, 37, 38, 39],
        [40, 41, 42, 43],
        [44, 45, 46, 47]],

       [[48, 49, 50, 51],
        [52, 53, 54, 55],
        [56, 57, 58, 59],
        [60, 61, 62, 63]]])

In [53]:
y = a[:,:,[2, -1]]
y
Out[53]:
array([[[ 2,  3],
        [ 6,  7],
        [10, 11],
        [14, 15]],

       [[18, 19],
        [22, 23],
        [26, 27],
        [30, 31]],

       [[34, 35],
        [38, 39],
        [42, 43],
        [46, 47]],

       [[50, 51],
        [54, 55],
        [58, 59],
        [62, 63]]])
```

## Where
where(array) # returns a tuple

### 1D
```py
In [54]: a = array([0, 12, 5, 20])

In [55]: a > 10
Out[55]: array([False,  True, False,  True], dtype=bool)  
In [86]: np.where(a > 10)
Out[86]: (array([1, 3], dtype=int64),)  
# returns a tuple
In [89]: indices = np.where(a > 10)

In [90]: indices = indices[0]

In [91]: indices
Out[91]: array([1, 3], dtype=int64)
```
可以直接用 where 的返回值进行索引：
```py
In [92]: loc = np.where(a > 10)

In [93]: a[loc]
Out[93]: array([12, 20])
```

### 多维
```py
In [60]:
a = array([[0, 12, 5, 20],
           [1, 2, 11, 15]])
loc = where(a > 10)
返回结果是一个二维的元组，每一维代表这一维的索引值：

In [61]:
loc
Out[61]:
(array([0, 0, 1, 1], dtype=int64), array([1, 3, 2, 3], dtype=int64))
也可以直接用来索引a：

In [62]:
a[loc]
Out[62]:
array([12, 20, 11, 15])
或者可以这样：

In [63]:
rows, cols = where(a>10)
In [64]:
rows
Out[64]:
array([0, 0, 1, 1], dtype=int64)
In [65]:
cols
Out[65]:
array([1, 3, 2, 3], dtype=int64)
In [66]:
a[rows, cols]
Out[66]:
array([12, 20, 11, 15])
再看另一个例子：

In [67]:
a = arange(25)
a.shape = 5,5
a
Out[67]:
array([[ 0,  1,  2,  3,  4],
       [ 5,  6,  7,  8,  9],
       [10, 11, 12, 13, 14],
       [15, 16, 17, 18, 19],
       [20, 21, 22, 23, 24]])
In [68]:
a > 12
Out[68]:
array([[False, False, False, False, False],
       [False, False, False, False, False],
       [False, False, False,  True,  True],
       [ True,  True,  True,  True,  True],
       [ True,  True,  True,  True,  True]], dtype=bool)
In [69]:
where(a > 12)
Out[69]:
(array([2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4], dtype=int64),
 array([3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4], dtype=int64))
 ```