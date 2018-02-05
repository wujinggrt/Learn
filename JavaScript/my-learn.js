var i = 100;
console.info(typeof i);

function sumNumbers() {
    var result = 0;
    for(i = 0; i < arguments.length; i++) {
        result += arguments[i];
    }
    return result;
}

var myObj = {
    name: "Haha",
    age: 1000000,
    job: "waiter"
};

var status = myObj.hasOwnProperty('sayName');
if(status == true) {
    myObj.sayName();
}
else
{
    (myObj.sayName || function () {
        console.info(myyObj.name);
    })(); // Haha
}

function Person(name, age, job) {
    this.name = name;
    this.age = age;
    this.job = job;
    this.sayName = function () {
        console.info(this.name);
    };
}

var p = new Person("haha", 21, "engineer");

var arr = ["Alibaba", "Baidu", "Tenccent", "Wangyi"];
//["Alibaba", "Baidu", "XiaoMi", "Jingdong", "Tenccent", "Wangyi"]
arr.splice(2, 0, "XiaoMi", "Jingdong");

