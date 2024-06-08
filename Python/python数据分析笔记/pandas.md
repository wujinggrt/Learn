# Pandas part
#### 
```py
In [3]: obj = pd.Series([4, 7, -5, 3])

In [4]: obj
Out[4]:
0    4
1    7
2   -5
3    3
dtype: int64

In [5]: obj.index
Out[5]: RangeIndex(start=0, stop=4, step=1)
```

```py
In [101]: data[pd.Series([False, False, True, True], index = data.index)]
Out[101]:
          one  two  three  four
Utah        8    9     10    11
New York   12   13     14    15

In [98]: type(data['three'] > 5)
Out[98]: pandas.core.series.Series

In [99]: data[data['three'] > 5]
Out[99]:
          one  two  three  four
Colorado    4    5      6     7
Utah        8    9     10    11
New York   12   13     14    15
```