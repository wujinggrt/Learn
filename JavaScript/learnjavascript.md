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

### 使用工厂函数创建对象
    function createPerson(name, age, job) {
        var o = {};
        o.name = name;
        o.age = age;
        o.job = job;
        o.sayName = function () {
            console.info(this.name);
        };
        return o;
    }
    var person1 = createPerson('zhangsan', 20, 'chengxuyuan');
    var person2 = createPerson('lisi', 32, 'yisheng');

### 定义对象“构造”函数
    // 首字母大写
    function Person(name, age, job) {
        this.name = name;
        this.age = age;
        this.job = job;
        this.sayName = function () {
            console.info(this.name);
        };
    }
    // 使用new关键字
    var person1 = new Person('zhangsan', 20, 'engineer');

### 对象的constructor属性
使用对象构造函数创建对象,每个对象的constructor属性引用这个构造函数(此处注意，函数是对象)  

    var p = new Person('zhangsan', 20, 'engineer');
    //使用对象构造函数创建对象
    //每个对象的constructor属性，引用这个构造函数
    console.info(p.constructor === Person); //true
使用对象工厂函数创建对象，每个对象的constructor属性引用Object()  

    var person = createPerson('张三', 29, '软件工程师');
    //使用工厂方法创建对象，其constructor属性引用Object()函数
    console.info(person.constructor === Object); //true

### 以普通方式调用的“构造函数
构造函数其实也是一个函数，不同之处在于调用它时必须要加
一个“new”关键字，如果不加这个关键字，则对它的调用被认
为是普通函数调用  

    //不用new，对象不会创建。
    console.info(Person('张三', 29, '软件工程师'));//undefined
    //作为普通函数调用的构造函数，通过this添加的属性，
    //成为了window对象的属性与方法。
    console.info(window.name);//张三
    console.info(window.age); //29
    console.info(window.job); //软件工程师

### 对象构造函数与对象工厂方法的区别
1. 对象构造函数中没有显式的对象创建代码
2. 新对象应具备的属性与方法是通过this引用添加
的.
3. 对象构造函数中没有return语句  

<em>通常会把对象构造函数的首字母设置为大写的，以区别于普通函数</em>

## 数组
是个“多态数组”，可以存放个各种数据类型的对象   
  
    var arr = ["one", 2, true,
        function (a, b) { return a + b; },
        [1,2,3]
    ];
数组是一个对象， 拥有自己的属性与方法

    arr.length;

### 写入
    var arr = [1, 2, 3];
    arr.length; // 3
    // 跳着赋值，导致数组增长
    arr[4] = 4;
    console.info(arr.length); // 5
    // 中间的值为undefined
    console.info(arr[3]); // undefined

### 尾部添加
    var arr2 = [];
    for(var i = 0; i < 5; i++) {
        arr2[arr2.length] = i;
    }
    console.info(arr2);

### 数组的拼接 
    var left = [1, 2, 3];
    var right = [4, 5, 6];
    // [1, 2, 3, 4, 5, 6]
    console.info(left.contact(right));

    var words = ["锤子", "剪刀", "布"];
    var result = words.join('<-->');
    //锤子<-->剪刀<-->布
    console.info(result);

### JavaScript的数组可以当做堆/栈使用
    var stack = [1, 2, 3, 4];
    stack.push(5);
    //[1, 2, 3, 4, 5]
    var value = stack.pop(); // value = 5  
    
    // 删除，之后这个变成undefined，但是还在
    delete stack[2];

### 为对象排序
    //定义一个Person构造函数
    function Person(name, age) {
        this.name = name;
        this.age = age;
    };

    //生成测试数据
    var people = [];
    for (var i = 1; i < 5; i++) {
        var age = Math.floor(Math.random() * 100);
        people[people.length] = new Person('用户' + i, age);
    }

    //自定义排序
    //比较函数具有两个参数 a 和 b，其返回值如下：
    //若 a 小于 b，在排序后的数组中 a 应该出现在 b 之前，则返
    回一个小于 0 的值。
    //若 a 等于 b，则返回 0。 a,b视为相等
    //若 a 大于 b，则返回一个大于 0 的值。 b应该排在a的后面
    people.sort(
        function (p1, p2) {
            if (p1.age > p2.age) return 1;
            if (p1.age < p2.age) return -1;
            return 0;
    });

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

## 事件响应
### 事件响应代码
<元素名字 on事件名称=“<语句块>|<函数名>”>   
简短的可以镶嵌在<>中，反之应该写出函数  

    // 1
    <button onclick="alert('Hello World!');">
        Run Some JavaScript
    </button>

    // 2
    <script>
        function show() {
            var str = '建议屏幕分辨率:800 * 600''
            alert(str);
        }
    </script>
    <body onload="show();">
也可以全部用代码实现:  
对象名.on事件=<语句>|<函数名>  

    myelement.onclick = function() {
        // code
    };

### 注册/取消事件监听函数的方法参数
DOM:  
element.addEventListener('click', observer, useCapture);  
addEventListener方法接收三个参数。第一个参数是事件名称;第二个参数
observer是回调处理函数;第三个参数注明该处理回调函数是在事件传递过程中
的捕获阶段被调用还是冒泡阶段被调用。

移除：  
element.removeEventListener('click', observer, useCapture);

## 开发中的常用事件简介
### 页面触发的事件
+ onload
+ onunload

### HTML元素常见事件列表
属性  事件
+ onabort 图像加载被中断
+ onblur 元素失去焦点
+ onchange 用户改变域的内容
+ onclick 鼠标点击某个对象
+ ondblclick 鼠标双击某个对象
+ onerror 当加载文档或图像时发生某个错误
+ onfocus 元素获得焦点
+ onkeydown 某个键盘的键被按下
+ onkeypress 某个键盘的键被按下或按住
+ onkeyup 某个键盘的键被松开
+ onload 某个页面或图像被完成加载
+ onmousedown 某个鼠标按键被按下
+ onmousemove 鼠标被移动
+ onmouseout 鼠标从某元素移开
+ onmouseover 鼠标被移到某元素之上
+ onmouseup 某个鼠标按键被松开
+ onreset 重置按钮被点击
+ onresize 窗口或框架被调整尺寸
+ onselect 文本被选定
+ onsubmit 提交按钮被点击
+ onunload 用户退出页面

### 事件对象的获取

### 事件对象示例
<div id=“mydiv” onclick=“dealClick(event,this)”>这是一个层</div>

    function divClick(event){
    if(event.type == “click”){ //事件类型
    alert(“click”);
    }
    var iKeyCode = event.keyCode; //获取按钮
    var iClientX = event.clientX; //事件的客户端X坐标
    var iClientY = event.clientY; //事件的客户端Y坐标
    //……
    }