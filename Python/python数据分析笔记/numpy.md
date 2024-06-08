# Python for Data Analysis
  
#### numpy
```py
In [66]: data = np.random.randn(2, 3)

In [67]: data
Out[67]:
array([[ 1.14731275,  0.8072179 ,  0.94108568],
       [ 1.89501394, -0.56970741,  1.0832612 ]])

In [68]: data * 10
Out[68]:
array([[11.47312746,  8.072179  ,  9.41085676],
       [18.9501394 , -5.69707412, 10.83261197]])

In [69]: data + data
Out[69]:
array([[ 2.29462549,  1.6144358 ,  1.88217135],
       [ 3.79002788, -1.13941482,  2.16652239]])

In [70]: data.dtype
Out[70]: dtype('float64')
```
#### creating
```py
np.empty((2, 3, 2))
np.eye(3, 3)
np.zeros((3, 6))

In [77]: np.arange(15)
Out[77]: array([ 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14])
```

#### function
1. array
2. asarray
3. arange
4. ones, ones_like
5. zeros, zeros_like
6. empty, empty_like
7. fuul, full_lie
8. eye, identity

#### manipulate
convert type:
```py
float_arr = arr.astype(np.float)
```

```py
In [59]: arr2 > arr
Out[59]:
array([[False, True, False],
    [ True, False, True]], dtype=bool)
```

```py
In [101]: arr[:2, :2] = 0

In [102]: arr
Out[102]:
array([[0, 0, 3],
       [0, 0, 6],
       [7, 8, 9]])
```
#### Boolean indxing: we can use the array of boolean type to index what we want.
```py
In [105]: data > 0
Out[105]:
array([[ True,  True,  True],
       [ True, False,  True]])
In [106]: data[data>0]
Out[106]: array([1.14731275, 0.8072179 , 0.94108568, 1.89501394, 1.0832612 ])
In [107]: data[data>0] = 7

In [108]: data
Out[108]:
array([[ 7.        ,  7.        ,  7.        ],
       [ 7.        , -0.56970741,  7.        ]])
```

#### Fancy indexing
```py
In [112]: data
Out[112]:
array([[ 0.09401445,  1.50327516, -1.10311581,  0.25953533],
       [-0.89623452, -0.63991078,  0.91892872,  0.67703665],
       [-0.58612338,  1.70032025,  0.23917402,  0.94483574],
       [ 0.98017615,  0.43685488,  0.41710332,  1.0439825 ]])

In [113]: data[0]=1

In [114]: data
Out[114]:
array([[ 1.        ,  1.        ,  1.        ,  1.        ],
       [-0.89623452, -0.63991078,  0.91892872,  0.67703665],
       [-0.58612338,  1.70032025,  0.23917402,  0.94483574],
       [ 0.98017615,  0.43685488,  0.41710332,  1.0439825 ]])
```       

select subrow:
```py
In [114]: data
Out[114]:
array([[ 1.        ,  1.        ,  1.        ,  1.        ],
       [-0.89623452, -0.63991078,  0.91892872,  0.67703665],
       [-0.58612338,  1.70032025,  0.23917402,  0.94483574],
       [ 0.98017615,  0.43685488,  0.41710332,  1.0439825 ]])

In [115]: data[[-1, -3, -2]]
Out[115]:
array([[ 0.98017615,  0.43685488,  0.41710332,  1.0439825 ],
       [-0.89623452, -0.63991078,  0.91892872,  0.67703665],
       [-0.58612338,  1.70032025,  0.23917402,  0.94483574]])

In [117]: data[[-1, -3, -2], [0, 1, 3]]
Out[117]: array([ 0.98017615, -0.63991078,  0.94483574])

```

#### Transposing and multiplication
```py
In [118]: arr = np.arange(15).reshape(3, 5)

In [119]:

In [119]: arr
Out[119]:
array([[ 0,  1,  2,  3,  4],
       [ 5,  6,  7,  8,  9],
       [10, 11, 12, 13, 14]])

In [120]: arr.T
Out[120]:
array([[ 0,  5, 10],
       [ 1,  6, 11],
       [ 2,  7, 12],
       [ 3,  8, 13],
       [ 4,  9, 14]])

In [121]: np.dot(arr.T, arr)
Out[121]:
array([[125, 140, 155, 170, 185],
       [140, 158, 176, 194, 212],
       [155, 176, 197, 218, 239],
       [170, 194, 218, 242, 266],
       [185, 212, 239, 266, 293]])

In [122]: arr.T * arr
---------------------------------------------------------------------------
ValueError                                Traceback (most recent call last)
<ipython-input-122-fec0bbf8d75b> in <module>()
----> 1 arr.T * arr

ValueError: operands could not be broadcast together with shapes (5,3) (3,5)
```
the 1 and 2 axes swaped, 0 axes did nothing:
```py
In [129]: arr
Out[129]:
array([[[ 0,  1,  2,  3],
        [ 4,  5,  6,  7]],

       [[ 8,  9, 10, 11],
        [12, 13, 14, 15]]])

In [130]: arr.swapaxes(1, 2)
Out[130]:
array([[[ 0,  4],
        [ 1,  5],
        [ 2,  6],
        [ 3,  7]],

       [[ 8, 12],
        [ 9, 13],
        [10, 14],
        [11, 15]]])
```
pass the axes number, the last axis unchanged,  
it means that the original ```arr[axis_0][axis_1]axis_[2]``` transposes into ```arr[axis_1][axis_0][axis_2]```:
```py
In [131]: arr = np.arange(16).reshape((2, 2, 4))

In [132]: arr
Out[132]:
array([[[ 0,  1,  2,  3],
        [ 4,  5,  6,  7]],

       [[ 8,  9, 10, 11],
        [12, 13, 14, 15]]])

In [133]: arr.transpose((1, 0, 2))
Out[133]:
array([[[ 0,  1,  2,  3],
        [ 8,  9, 10, 11]],

       [[ 4,  5,  6,  7],
        [12, 13, 14, 15]]])
```        

#### Expression conditional
```py
In [150]: arr
Out[150]:
array([[ 0.09243473, -1.35185538,  0.57804815, -0.37339435],
       [ 0.48300189,  0.5891799 ,  0.98339862,  0.07432041],
       [-1.36060812,  1.48039152, -1.45836365,  0.89824314],
       [ 1.30100501, -1.37532796,  0.86003389,  0.39634016]])

In [151]: np.where(arr > 0, 2, -2)
Out[151]:
array([[ 2, -2,  2, -2],
       [ 2,  2,  2,  2],
       [-2,  2, -2,  2],
       [ 2, -2,  2,  2]])
       
In [152]: np.where(arr > 0, 2, arr)
Out[152]:
array([[ 2.        , -1.35185538,  2.        , -0.37339435],
       [ 2.        ,  2.        ,  2.        ,  2.        ],
       [-1.36060812,  2.        , -1.45836365,  2.        ],
       [ 2.        , -1.37532796,  2.        ,  2.        ]])
```

#### Mathematical and Statistical Method
```py
arr.mean()
arr.sum()
arr.mean(axis = 1)
arr.sum(axis = 0)
arr.cumsum() # accumulation

In [158]: arr
Out[158]:
array([[ 0.09243473, -1.35185538,  0.57804815, -0.37339435],
       [ 0.48300189,  0.5891799 ,  0.98339862,  0.07432041],
       [-1.36060812,  1.48039152, -1.45836365,  0.89824314],
       [ 1.30100501, -1.37532796,  0.86003389,  0.39634016]])

In [159]: arr.mean(axis = 0)
Out[159]: array([ 0.12895838, -0.16440298,  0.24077925,  0.24887734])

# axis 0 is the first row, that is why to use [:, 0]
In [160]: a_0 = arr[:, 0]

In [161]: a_0
Out[161]: array([ 0.09243473,  0.48300189, -1.36060812,  1.30100501])

In [162]: a_0.mean()
Out[162]: 0.12895837781292063

In [164]: arr.cumsum()
Out[164]:
array([ 0.09243473, -1.25942065, -0.6813725 , -1.05476685, -0.57176496,
        0.01741495,  1.00081356,  1.07513398, -0.28547414,  1.19491737,
       -0.26344627,  0.63479687,  1.93580187,  0.56047391,  1.4205078 ,
        1.81684796])
```

#### Methods for Boolean Arrays
```py
In [191]: (arr > 0).sum() # Number of positive values

bools.any()
bools.all()

In [174]: bools = np.array([True, False, False])
In [176]: bools.any()
Out[176]: True

In [177]: bools.all()
Out[177]: False
```w