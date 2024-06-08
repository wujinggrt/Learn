# Concurrency in java

#### java.lang.Thread
1. Thread.sleep(long millis) // 毫秒
2. Thread(Runnable target)
3. void start()
4. void run() // call target method

#### await, 条件对象
```java
// one thread
// 放弃锁，被阻塞
// 但是被signal的时候，会重新被锁保护（锁可用），然后得到lock，然后unlock
while(!(ok to proceed)){
    enough.await();
}

// another
// 这个signalAll通知所有await中的thread，
// 他们继续竞争，竞争之后，如果是await的，从await的地方继续执行。
// (这儿是一个while循环，会继续判断，是执行，还是继续await，再次被阻塞)
enough.signalAll();
```
