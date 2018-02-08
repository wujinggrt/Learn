# JAVA
在大数据的时候应该用类:BigDecimal
# API
Math.sqrt();
Math.pow(x, y);

throws IOException;

int[] copiedLuckyNumbers = Arrays.copyOf(luckyNumbers, luckyNumbers.length)

超类向子类转换需要 instanceof

常用:API

## StringBuilder
delete(int start, int end) # start: inclusive end:exclusive

## ArrayList<T>
ensureCapacity(100);
size(); // length
trimToSize();
set(int index, Object obj);
get(int index);
add(Object obj);
add(int index, T obj);
toArray(Array[]); // arr.length = size()
remove(int index); 

@SuppressWarnings ("unchecked") 
ArrayList<Employee> result =
(ArrayList<Employee>) employeeDB.find(query); // yields another warning

## Integer/Double...
int i = Integer.parseInt(String s); 
int i = integerObj.intValue();

## 可变数量参数
printf(String fmt , Object... args) 
max(double... values);  
values[0]  // ...像一个数组，可以用下标访问

## enum
枚举类型都是Enum类的子类
class则都是Object的子类，但是也与Class类有关

实例化的对象.getClass();
ClassName.class;

## 反射
手工加载Class类型
Class cl = Class.forName(className); // String 类型， might throw exception

JAVA类型
Class cl1 = Double[].class;

虚拟机为每个类型管理一个 Class 对象。 因此， 可以利用= 运算符实现两个类对象比较
的操作。    
e.getClass().newlnstance(); // 根据Class对象来创建e的对象

## 接口
// Arrays.sort()相关接口
Comparable<T>  // lang

Integer/Double.compare(int x, int y);

default void mousePressed(MouseEvent event) {}

### Comparator<T>
Arrays.sort(t[], Comparator<T>);
Comparator<T> {
    int compare(T first, T second);
}

### Cloneable<T>

### 函数式接口

### 方法引用
Arrays.sort(strings，String::conpareToIgnoreCase)

### 匿名内部类
    ActionListener listener = new ActionListenerO
    {
        public void actionPerformed(ActionEvent event)
        {
            System.out.println("At the tone, the time is " + new DateO)；
            if (beep) Toolkit.getDefaultToolkit().beep();
        }
    }；

### 泛型方法
@SuppressWarnings ("unchecked")   
出现需要镇压警告，最后用了： -Xlint:unchecked

### 类型变量的限定
T extends Comparable****

### 类型擦除
无论何时定义一个泛型类型， 都自动提供了一个相应的原始类型 （ raw type)。
原始类型
的名字就是删去类型参数后的泛型类型名。擦除（ erased) 类型变M , 并替换为限定类型 （无
限定的变量用 Object。)

桥方法 （bridge method):

LocalDate getSecond() // defined in Datelnterval
Object getSecond() // overrides the method defined in Pair to call the first metho

## 集合/AbstractCollection
需要熟悉容器
### Queue
public interface Queue<E> {
    void add(E element);
    E remove();
    int size();
}

## str.split("\\s+");
s+是正则，一个或者多个space

## jar
java cvfe   

# 并发
public static *returntype* Thread.sleep()

实现了Runnable接口的对象，把这个对象最为构造函数的参数到Thread中去，之后
start()方法会运行这个
run()

interrupt()  
#static
Thread.currentThread().isInterrupted()
getState()
setPriority()

private Lock bankLock = new ReentrantLock();
bankLock.lock();
.unlock();
sufficentFunds = bankLock.newCondition();
sufficentFunds.await();
sufficentFunds.signalAll();