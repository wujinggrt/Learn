# JS
## 变量
        typeof number;    # 查询变量类型、
        num instanceof Object;    # 判断：true/false
装箱:

    var num = 3;
    // 创建包装对象
    var S = new Number(n);
可以用**parseInpt()**和**parseFloat()**.

    var num = parseInt('34', 10);    # 第二个参数为10进制

## undefined/null
undefined是声明为定义，null变量不引用任何对象

## 条件判断
    !!obj; #把对象转换为bool值
    null,undefined, "", 0, NaN; #false

## 多值选择
    switch(choice)
    {
        case 0:
            CaseZero();
            break;
        case 1:
            CaseOne();
            break;
        default:
            CaseOthers();
            break;
    }

## 循环
同大多数,break/continue同样适用

## 数据集合的遍历/foreach
    for(var element in arr){
        console.log(element + '：' + arr[element]);
    }
    
## 函数基础
独立的变量作用域、函数是一个对象、一等公民

    function add(x, y){
        return x + y;
    }

    # 匿名函数
    var square = function (x) {
        return x * x;
    }

### 立即执行的匿名函数
    var add = function (x, y) {
        return x + y;
    }
    console.info(add(100, 200));

    # 等价
    console.info(
        function (x, y) {
            return x + y;
        } (100, 200)
    );

### 返回值
没有return或者return为空，返回undefined

### 一个大坑
return之后不要加回车，因为每行自动加 **";"** 的机制。
  
    function add(x, y) {
        return
        {
            name: wujing
        };
    }
### 调用之前先定义

### 参数
如果参数过少，剩下部分为：**undefined**  
如果过多，则被:**忽略**

#### 参数监测
    function sayHello(name, message) {
        if (typeof message === 'undefined') {
            message = '你好';
        }
        console.info(name + ', ' + message);
    }
    sayHello('蛤蛤');

#### 保存参数的arguments对象
    function sumNumbers() {
        var result = 0;
        for (var i = 0; i < arguments.length; ++i) {
            result += arguments[i];
        }
        return result;
    }
    console.info(sumNumbers(1, 2, 3, 54));
arguments像一个数组，但不是  

### 一段小代码  
    <button id="btnClick">Click Me!</button>
    <input type="text" id="result" />
    <script>
        var button = document.getElementById('btnClick');
        var result = document.getElementById('result');
        var clickCount = 0;
        button.addEventListener('click', function() {
            clickCount++;
            result.setAttribute('value', clickCount + ': Hello World!');
        })
    </script>

### 嵌套函数
函数内部定义另外一个函数，并且能够访问外部变量  

    function outerFunc(a, b) {
        function innerFunc(x) {
            return x * x;
        }
        return Math.sqry(innerFunc(a) + innerFunc(b));
    }
    console.info(outerFunc(3, 4)); // 5

### 返回函数的函数
由于函数是对象,所以,我们可以返回  

    function func(x, y) {
        var value = 100;
        return function () {
            return value + x + y;
        }
    }
    console.info(func(100, 200)()); // 600

## 变量作用域
<a href="#FuncArea"><strong>函数作用域</strong></a>
和
<a href="#GlobalArea"><strong>全局作用域</strong></a>  

### JavaScript没有块作用域
在块中创建的变量不会覆盖外部变量

### 变量提升(Hoist)
应该在函数前集中定义变量,不要再“中途”.  
函数中的变量可以访问外部以及全局。  
变量查找为：
1. 在函数作用域
2. 全局

## 对象的创建于使用
两种对象：
1. Native
2. Host

### 创建对象

#### 定义空对象之后再添加成员
    var myObject = {};
    myObject.name = 'Haha';
    myObject.age = 'infinity';

#### 使用对象字面量
    var person = {
        "name": "zhangsan",
        age: 29    // ""可有可无
        inner: {
            id: 0,
            value: 100
        },
        arr: ["one", "two", "three"]
    };

#### 定义对象方法:一个函数类型属性
    var obj = {
        sayHello: function (name) {
            console.info("nihao, " + name + "!");
        }
    };
    // 可以追加
    var obj2 = {};
    obj2.sayHello = function (name) {
        console.info("nihao");
    };

### []或者.访问属性
    var exampleObj = {
        info: "information"
    };
    console.info(exampleObj.info);
    // 如果没有，则设置为默认值
    console.info(exampleObj.notExist || "default");
    console.info(exampleObj['info']);

### 枚举对象属性
对象可以看成属性的集合

    for (var p in exampleObj) {
        console.info((typeof exampleObj[p]) + "leixing: " + p);
    }

### 对象属性t添加与删除
    delete exampleObj.info;
对象属性删除之后再访问得到undefined  
可以使用<strong>obj.p === undefined</strong>对它进行检查。  

### 将对象作为函数参数
    function displayPerson(person) {
        console.info('name=' + (person.name || 'none'));
        console.info('age=' + (person.age || -1));
    };
    displayPerson({
        name: "Haha",
        age: 100000
    });
    displayPerson({});

## 对象工厂与构造函数
