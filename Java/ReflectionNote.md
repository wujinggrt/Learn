# java.lang.reflect
1. Field
2. Method
3. Constructor

相同的地方：  
```java
obj.getName() // 返回项目名称
obj.getSuperClass() // class<? super T>
obj.getInterface() // class<?>[]
```

#### java.lang.Class
1. String getName() 
2. Class<? super T> getSuperClass()
3. Class<?>[] getInterface()
4. Field[] getFields() // 私有的不会出现
4. Field[] getDeclaredFields()
5. Method[] getMethods()
5. Method[] getDeclaredMethods()
6. Constructor[] getConstructors()
6. Constructor[] getDeclaredConstructors()

#### java.lang.reflect.[Field, Method, Constructor]
1. Class getDeclaringClass() ``` // Field: class java.lang.Double```  
2. Class[] getExceptionTypes() // in constructor and method  
3. int getModifiers()  
4. String getName()  
5. Class[] getParameterTypes()
6. Class[] getReturnType()

#### java.lang.reflect.
1. static String toString(int modifiers)
2. static boolean is[Abstract, Final, Interface...](int modifiers)

isInterface 是implements了interface的class。

#### Field
```java
// 返回描述域所述类的Class对象
getType()  
```
Field的实例中， toString()方法（也就是println会调用的）会打印出信息，如：
```java
public static final double java.lang.Double.POSITIVE_INFINITY
```