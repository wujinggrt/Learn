# Java frequent method

## compile
java compiler需要的是路径， java虚拟机需要的是包名。所以是.，而不是/  
```sh
C:\Users\WuJing\Desktop>javac ./com/company/*.java

C:\Users\WuJing\Desktop>java com.company.Main
Hello
Hel
HelloHel
H / e / ; / o
5
codepoint:4
```

#### String
1. str.substring(beginIndex, endIndex)  # exclusive endindex
2. str_object + str_obj2 
3. String.join(" / ", "H", "e", ";", "o"); # class method
4. s.equals(t) 
5. s.equalsIgnoreCase(t)
6. s.length()
7. s.codePointCount(beginIndex, endIndex) # exclusive endIndex,返回char的个数，codepoint
8. s.charAt(index)
9. s.offsetByCodePoint(index, codePointOffSet) # 得到第i个codepoint,index + codePointOffset，index的偏移co。。个数的索引  
10. s.codePointAt(index) #   
11. s.trim()
12. int[] cp = s.codePoints().toArray()
13. String = new String(cp, 0, cp.length())
14. s.toLowerCase()
15. s.toUpperCase()
16. s.compareTo(other)
17. s.startsWith(prefix)
18. s.endswith(suffix)
19. 

#### StringBuilder
1. var builder = new StringBuilder() # params:1.None, 2.capacity, 3.str, 4.CharSequence
2. builder.append(many_type)
3. var s = builder.toString()
4. builder.delete(start, end) # exclusive end
5. builder.setCharAt(i, char c)
6. builder.insert(offset, str/c) # before offset    
7. builder.replace(start, end, str) # not exlusive any

#### Date
1. new Date().toString()

#### LocalDate
1. LocalDate.now()
2. var date = LocalDate.of(2018, 8, 1)
3. int year = date.getYear();
4. int month = date.getMonthValue();
5. int day = date.getDayOfMonth()
6. date.plusDays(100)
7. date.minusDays(100)
8. DayOfWeek weekDay = date.getDayOfWeek()
9. int value = weekDay.getValue()

#### 输入输出
Scanner 在 java.util.*
1. Scannaer in = new Scanner(System.in)
2. String s = in.nextLine()
3. String s = in.next() # cin
4. int i = in.nextInt()
5. in.hasNext() 

Console:
1. Console cons = System.console();
2. String username = cons.readLine("User name: ")；
3. char[] passwd = cons.readPassword("Password: ");

#### Format
1. System.out.printf()
2. String.format() # 参数和printf同

#### array
1. int[] small = {1, 2, 3};
2. small = new in[] {1, 2, 3, 4};
3. var newArray = Arrays.copyOf(small, small.length)
4. Arrays.toString()

#### Date/LocalDate

#### Objects.equals(l, r)

#### 匿名类
匿名内部类
1. 概念：即内部类的简化写法
1. 前提：存在一个类（可以是具体类也可以是抽象类）或接口
2. 格式：new 类名或接口名{重写的方法}
3. 本质：创建的是继承了类或实现了接口的子类匿名对象。
```java
interface D{
void ShowContext();
}
class B{
public void show() {
//匿名内部类的实现
new D(){
@Override
public void ShowContext() {
System.out.println("hello");
}
};
};
}
```

#### ArrayList<T>
1. var staff = ArrayList<String>() # or initCapacity
2. staff.add("Mike")
3. staff.ensureCapacity(100)
4. staff.size()
5. staff.trimToSize()
6. staff.set(i, value)
7. staff.get(i)
8. staff.remove(index)
9. Arrays.sort(staff)

#### Integer
1. Integer.parseInt(s)
2. iobj.intValue()
3. Integer.toString(i, radix)
4. Integer.valueOf(str, radix)
5. Integer/Double.compare(x, y) # x < y 返回 -1, 相等0, x>y返回1。 感觉里面的判断是return x - y；
6. Number parse(str)

#### 可变参数
1. public PrintStream printf(String fmt, Object... args)

like Object[], autoboxing.

#### enum
1. ordinal() # 返回枚举常量位置

#### interfalce

```java

// for Arrays.sort()
public interface Comparable<T>{
    // x < other : -1
    // x == other : 0
    // x > other : 1
    int compareTo(T other);
}
```
接口可以声明变量，但是不能new成object  

```java
public interface Comparator<T> {

    int compare(T first, T second); 
}

Arrays.sort(arrays, implementedComparator);
```

#### Collection
##### Iterator<E> iterator() // a method returns Iterator
usage:  
```java
for(Iterator<String> it=list.iterator();it.hasNext();)
{
    System.out.println(it.next());
}
```

###### iterable for each
```java
public class Main
{
    public static void main(String[] args)
    {
        MyString s = new MyString("1234567");
        
        for(char c:s)
        {
            System.out.println(c);
        }
    }

}




class MyString implements Iterable<Character>
{
    
    private int length = 0;
    private String ineers = null;
    
    public MyString(String s)
    {
        this.ineers = s;
        this.length = s.length();
    }
    
    
    @Override
    public Iterator<Character> iterator()
    {
        
        class iter  implements Iterator<Character>     //方法内部类
        {
            private int cur= 0;
            
            @Override
            public boolean hasNext()
            {
                return cur != length;
            }

            @Override
            public Character next()
            {
                Character c = ineers.charAt(cur);
                cur++;
                return c;
            }
            
            public void remove()
            {
                 // do nothing 
            }

        }
        return new iter();     //安装Iterable接口的约定，返回迭代器
    }
}
```