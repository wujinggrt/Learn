# JS 笔记

## 数据类型和变量
### 比较
**==** 比较，它会自动转换数据类型再比较，很多时候，会得到非常诡异的结果；

**===** 比较，它不会自动转换数据类型，如果数据类型不一致，返回false，如果一致，再比较。  

    NaN === NaN; // false
    isNaN(NaN); // true    
false：null,undefined, "", 0, NaN

### 数组
    [1, 2, 3.14, 'Hello', null, true]; //可读性强
    new Array(1, 2, 3); // 创建了数组[1, 2, 3]

### 对象
JavaScript的对象是一组由键(全部为字符串类型)-值组成的无序集合，例如：

    var person = {
        name: 'Bob',
        age: 20,
        tags: ['js', 'web', 'mobile'],
        city: 'Beijing',
        hasCar: true,
        zipcode: null
    };

### 变量
变量名是大小写英文、数字、$和_的组合，且不能用数字开头

    var a; // 申明了变量a，此时a的值为undefined
    var $b = 1; // 申明了变量$b，同时给$b赋值，此时$b的值为1
    var s_007 = '007'; // s_007是一个字符串
    var Answer = true; // Answer是一个布尔值true
    var t = null; // t的值是null

### strict模式
如果一个变量没有通过var申明就被使用，那么该变量就自动被申明为全局变量.
启用strict模式的方法是在JavaScript代码的第一行写上：

    'use strict';


## 字符串
''或""内容。  
\x##

### 多行字符串
由于多行字符串用\n写起来比较费事，所以最新的ES6标准新增了一种多行字符串的表示方法，用反引号 ` ... ` 表示：

    `这是一个
    多行
    字符串`;

### 模板字符串
要把多个字符串连接起来，可以用+号连接：

    var name = '小明';
    var age = 20;
    var message = '你好, ' + name + ', 你今年' + age + '岁了!';
    alert(message);
如果有很多变量需要连接，用+号就比较麻烦。ES6新增了一种模板字符串，表示方法和上面的多行字符串一样，但是它会自动替换字符串中的变量：

    var name = '小明';
    var age = 20;
    var message = `你好, ${name}, 你今年${age}岁了!`;
    alert(message);

### 操作字符串
字符串常见的操作如下(可下标[])：

    var s = 'Hello, world!';
    s.length; // 13

### API
JavaScript为字符串提供了一些常用方法，注意，调用这些方法本身不会改变原有字符串的内容，而是返回一个新字符串：

str.toUpperCase()
    .toLowerCase()
    .indexOf("str")
    substring(0, 5) or (6)


## 数组
    var arr = [1, 2, 3.14, 'Hello', null, true];
    arr.length; // 6

### 注意
* 请注意，直接给Array的length赋一个新的值会导致Array大小的变化：  
* 请注意，如果通过索引赋值时，索引超过了范围，同样会引起Array大小的变化：

### API
* indexOf(contents)
* slice() //然后返回一个新的Array：

    arr.slice(0, 3); // 从索引0开始，到索引3结束，但不包括索引3: ['A', 'B', 'C']
    arr.slice(); // 从头到尾
* push和pop 

    .push(enlements);
    .pop() 
* unshift和shift //如果要往Array的头部添加若干元素，使用unshift()方法，shift()方法则把Array的第一个元素删掉：
* sort
* reverse
* splice
splice()方法是修改Array的“万能方法”，它可以从指定的索引开始删除若干元素，然后再从该位置添加若干元素：

    var arr = ['Microsoft', 'Apple', 'Yahoo', 'AOL', 'Excite', 'Oracle'];  
    // 从索引2开始删除3个元素,然后再添加两个元素:  
    arr.splice(2, 3, 'Google', 'Facebook'); // 返回删除的元素 ['Yahoo', 'AOL', 'Excite']  
    arr; // ['Microsoft', 'Apple', 'Google', 'Facebook', 'Oracle']  
    // 只删除,不添加:  
    arr.splice(2, 2); // ['Google', 'Facebook']  
    arr; // ['Microsoft', 'Apple', 'Oracle']  
    // 只添加,不删除:  
    arr.splice(2, 0, 'Google', 'Facebook'); // 返回[],因为没有删除任何元素  
    arr; // ['Microsoft', 'Apple', 'Google', 'Facebook', 'Oracle']  
* concat

    var added = arr.concat([1, 2, 3]); //并返回一个新的Array,接收任意个元素和Array，并且自动把Array拆开，然后全部添加到新的Array里
* join

    join()方法是一个非常实用的方法，它把当前Array的每个元素都用指定的字符串连接起来，然后返回连接后的字符串
    
### 多维数组
[[ ] ]  


## 对象
访问属性是通过.操作符完成的，但这要求属性名必须是一个有效的变量名。如果属性名包含特殊字符，就必须用''括起来：

    var xiaohong = {
        name: '小红',
        'middle-school': 'No.1 Middle School'
    };
xiaohong的属性名middle-school不是一个有效的变量，就需要用''括起来。访问这个属性也无法使用.操作符，必须用['xxx']来访问：

    xiaohong['middle-school']; // 'No.1 Middle School'
    xiaohong['name']; // '小红'
    xiaohong.name; // '小红'

由于JavaScript的对象是动态类型，你可以自由地给一个对象添加或删除属性：

    var xiaoming = {
        name: '小明'
    };
    xiaoming.age; // undefined
    xiaoming.age = 18; // 新增一个age属性
    xiaoming.age; // 18
    delete xiaoming.age; // 删除age属性
    xiaoming.age; // undefined
    delete xiaoming['name']; // 删除name属性
    xiaoming.name; // undefined
    delete xiaoming.school; // 删除一个不存在的school属性也不会报错

如果我们要检测xiaoming是否拥有某一属性，可以用in操作符：

    var xiaoming = {
        name: '小明',
        birth: 1990,
        school: 'No.1 Middle School',
        height: 1.70,
        weight: 65,
        score: null
    };
    'name' in xiaoming; // true
    'grade' in xiaoming; // false

因为toString定义在object对象中，而所有对象最终都会在原型链上指向object，所以xiaoming也拥有toString属性。

要判断一个属性是否是xiaoming自身拥有的，而不是继承得到的，可以用hasOwnProperty()方法：

var xiaoming = {
    name: '小明'
};
xiaoming.hasOwnProperty('name'); // true
xiaoming.hasOwnProperty('toString'); // false

## 循环
### for ... in
for循环的一个变体是for ... in循环，它可以把一个对象的所有属性依次循环出来：

    var o = {
        name: 'Jack',
        age: 20,
        city: 'Beijing'
    };
    for (var key in o) {
        console.log(key); // 'name', 'age', 'city'
    }
Array也是对象，而它的每个元素的索引被视为对象的属性

## Map和Set
    var m = new Map([['Michael', 95], ['Bob', 75], ['Tracy', 85]]);
    m.get('Michael'); // 95
初始化Map需要一个二维数组，或者直接初始化一个空Map。Map具有以下方法：

    var m = new Map(); // 空Map
    m.set('Adam', 67); // 添加新的key-value
    m.set('Bob', 59);
    m.has('Adam'); // 是否存在key 'Adam': true
    m.get('Adam'); // 67
    m.delete('Adam'); // 删除key 'Adam'
    m.get('Adam'); // undefined

### Set
    var s2 = new Set([1, 2, 3]); // 含1, 2, 3
通过add(key)方法可以添加元素到Set中，可以重复添加，但不会有效果：
通过delete(key)方法可以删除元素：

## iterable
具有iterable类型的集合可以通过新的for ... of循环来遍历。Array、Map和Set都属于iterable类型  
具有iterable类型的集合可以通过新的for ... of循环来遍历。‘

    for (var x of a) { // 遍历Array
        console.log(x);
    }

for ... in循环由于历史遗留问题，它遍历的实际上是对象的属性名称。一个Array数组实际上也是一个对象，它的每个元素的索引被视为一个属性。

当我们手动给Array对象添加了额外的属性后，for ... in循环将带来意想不到的意外效果：

    var a = ['A', 'B', 'C'];
    a.name = 'Hello';
    for (var x in a) {
        console.log(x); // '0', '1', '2', 'name'
    }
注意，forEach()方法是ES5.1标准引入的，你需要测试浏览器是否支持。

Set与Array类似，但Set没有索引，因此回调函数的前两个参数都是元素本身：

    var s = new Set(['A', 'B', 'C']);
    s.forEach(function (element, sameElement, set) {
        console.log(element);
    });

Map的回调函数参数依次为value、key和map本身：

    var m = new Map([[1, 'x'], [2, 'y'], [3, 'z']]);
    m.forEach(function (value, key, map) {
        console.log(value);
    });


# 函数
函数也是一个对象
**function** 开头.  
第二种定义函数的方式如下，注意;表示对abs的赋值语句结束：

    var abs = function (x) {
        if (x >= 0) {
            return x;
        } else {
            return -x;
        }
    };
允许传入参数大于(or小于)形参，但是没有意义(返回NaN)。

    abs(); // 返回NaN
此时abs(x)函数的参数x将收到**undefined**，计算结果为**NaN**。

    if (typeof x !== 'number') {
        throw 'Not a number';
    }
### arguments
关键字arguments，它只在函数内部起作用,类似Array。

    function hehe(x) {
        for(var i = 0; i < arguments.length; ++i) {
            console.log(arguments[i]);
        }
    }

### rest参数
    function foo(a, b, ...rest) {
        console.log('a = ' + a);
        console.log('b = ' + b);
        console.log(rest);
    }

### 变量提升
把所有申明的变量“提升”到函数顶部,类似全部变量在使用之前都已经声明过。

### 全局作用域
全局对象window，全局作用域的变量实际上被绑定到window的一个属性.
全局变量（包括函数如alert('蛤蛤"))都是属于windows对象。

### 名字空间
    // 唯一的全局变量MYAPP:
    var MYAPP = {};

    // 其他变量:
    MYAPP.name = 'myapp';
    MYAPP.version = 1.0;

    // 其他函数:
    MYAPP.foo = function () {
        return 'foo';
    };
把自己的代码全部放入唯一的名字空间MYAPP中，会大大减少全局变量冲突的可能。  

一种常用方法：  

    var ns = ns || {}; #{}是一个空对象

### 局部作用域
let取代var，在block{}形成局部作用域，而不是在函数里面。

### 常量
ES6标准引入了新的关键字const来定义常量，const与let都具有块级作用域：

    'use strict';

    const PI = 3.14;
    PI = 3; // 某些浏览器不报错，但是无效果！
    PI; // 3.14

### 解构赋值
什么是解构赋值？我们先看看传统的做法，如何把一个数组的元素分别赋值给几个变量：

    var array = ['hello', 'JavaScript', 'ES6'];
    var x = array[0];
    var y = array[1];
    var z = array[2];
现在，在ES6中，可以使用解构赋值，直接对多个变量同时赋值：
    
    var [x, y, z] = ['hello', 'JavaScript', 'ES6'];
注意，对数组元素进行解构赋值时，多个变量要用[...]括起来。

如果数组本身还有嵌套，也可以通过下面的形式进行解构赋值，注意嵌套层次和位置要保持一致：

    let [x, [y, z]] = ['hello', ['JavaScript', 'ES6']];
    x; // 'hello'
    y; // 'JavaScript'
    z; // 'ES6'
解构赋值还可以忽略某些元素：

    let [, , z] = ['hello', 'JavaScript', 'ES6']; // 忽略前两个元素，只对z赋值第三个元素
    z; // 'ES6'

对一个对象进行解构赋值时，同样可以直接对嵌套的对象属性进行赋值，只要保证对应的层次是一致的：

    var person = {
        name: '小明',
        age: 20,
        gender: 'male',
        passport: 'G-12345678',
        school: 'No.4 middle school',
        address: {
            city: 'Beijing',
            street: 'No.1 Road',
            zipcode: '100001'
        }
    };
    var {name, address: {city, zip}} = person;
    name; // '小明'
    city; // 'Beijing'
    zip; // undefined, 因为属性名是zipcode而不是zip
    // 注意: address不是变量，而是为了让city和zip获得嵌套的address对象的属性:
    address; // Uncaught ReferenceError: address is not defined
属性不存在，变量将被赋值为undefined.  
解构赋值还可以使用默认值，这样就避免了不存在的属性返回undefined的问题：

    var {name, single=true} = person;
    name; // '小明'
    single; // true
变量已经被声明了,再次赋值的时候，正确的写法也会报语法错误

## 使用场景
解构赋值在很多时候可以大大简化代码。例如，交换两个变量x和y的值，可以这么写，不再需要临时变量：

    var x=1, y=2;
    [x, y] = [y, x]
快速获取当前页面的域名和路径：

    var {hostname:domain, pathname:path} = location;
如果一个函数接收一个对象作为参数，那么，可以使用解构直接把对象的属性绑定到变量中。例如，下面的函数可以快速创建一个Date对象：

    function buildDate({year, month, day, hour=0, minute=0, second=0}) {
        return new Date(year + '-' + month + '-' + day + ' ' + hour + ':' + minute + ':' + second);
    }
它的方便之处在于传入的对象只需要year、month和day这三个属性：

    buildDate({ year: 2017, month: 1, day: 1 });
    // Sun Jan 01 2017 00:00:00 GMT+0800 (CST)

### 方法
var that = this;，你就可以放心地在方法内部定义其他函数，而不是把所有语句都堆到一个方法中。

## 高阶函数
