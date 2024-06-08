# Matlab
sin(a)
cos(a)
magic(4)
rand(3, 5, 2)
save myfile.mat
load myfile.mat
myText = 'Hello, world';
whos myText
max(A)
max(A, B) // 比较AB
[maxA,location] = max(A)
disp('hello world') %DISPLAY

## 基础
```mat
>> a = 1

a =

     1
```
If you end a statement with a semicolon, MATLAB performs the computation, but
suppresses the display of output in the Command Window.
```mat
e = a*b;
```

## Array Creation
separate the elements with either a
comma (,) or a space.
```mat
a = [1 2 3 4]
a = 1×4
1 2 3 4
```
This type of array is a row vector.
To create a matrix that has multiple rows, separate the rows with semicolons.
```mat
a = [1 2 3; 4 5 6; 7 8 10]
a = 3×3
1 2 3
4 5 6
7 8 10
```

```mat
z = zeros(5,1)
z = 5×1
    0
    0
    0
    0
    0
```

## Operation
To transpose a matrix, use a single quote ('):
```mat
a'
ans = 3×3
1 4 7
2 5 8
3 6 10
```

inverse:
```mat
p = a * inv(a)
p = 3×3
1.0000 0 -0.0000
0 1.0000 0
0 0 1.0000
```
Notice that p is not a matrix of integer values.MATLAB stores numbers as ﬂoating-point
values, and arithmetic operations are sensitive to small diﬀerences between the actual
value and its ﬂoating-point representation. You can display more decimal digits using the
format command:
```mat
format long
format short
```

## Element-wise multiplication
The matrix operators for multiplication, division, and power each have a corresponding
array operator that operates element-wise.
```mat
p = a.*a
p = 3×3
1 4 9
16 25 36
49 64 100

a.^3
ans = 3×3
1 8 27
64 125 216
343 512 1000
```

## Concatenation
```mat
A = [a, a] //  horizontal concatenation
A = 3×6
    1 2 3 1 2 3
    4 5 6 4 5 6
    7 8 10 7 8 10

A = [a; a] //  vertically 
A = 6×3
1 2 3
    4 5 6
    7 8 10
    1 2 3
    4 5 6
    7 8 10
```

## Complex Numbers

## start:step:end.
The colon operator also allows you to create an equally spaced vector of values using the
more general form start:step:end.

## 2-D and 3-D Plots
```mat
x = 0:pi/100:2*pi;
y = sin(x);
plot(x,y)
```

## 扩充数组
>> a

a =

    0.5949
    0.2622
    0.6028
    0.7112

>> a(5)
Index exceeds matrix dimensions.
 
>> a(5) = 1ku