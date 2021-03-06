package com.company;

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 * 学习《Java核心技术 卷一》并发章节，同步内容。
 * 关于ReentrantLock以及Condition的使用。
 */
public class ConcurrencyDemo {
    /**
     * 锁可以保护代码片段。
     */
    private Lock lock = new ReentrantLock();
    private Condition cond = null;

    public ConcurrencyDemo() {
        cond = lock.newCondition();
    }

    /**
     * 不带锁的线程，在r的语句块中，每一步都可能会被打断。
     */
    public void unsynchConcurrencyTest() {
        for (int i = 0; i < 100; i++) {
            Runnable r = () -> {
                try {
                    while (true) {
                        int num = (int) (100 * Math.random());
                        System.out.println(num + "_19");
                        Thread.sleep(1000);
                        System.out.println(num + "_21");
                    }
                } catch (InterruptedException e) {

                }
            };
            Thread t = new Thread(r);
            t.start();
        }
    }

    /**
     * 这是一个带锁的线程demo。
     * 可以看出：
     * 第一个循环开始的时候（也就是第一格线程被创建，一共有10个Thread被创建），
     * 第一格Thread为：Thread[Thread-6,5,main]
     * 在lock()之后，sleep()期间，执行下一个线程。
     * （猜测是t.start()之后先不管了，就是执行run，然后在开始下一个Thread，也就是这一套程序只会执行t.start()，把线程都启动/创建，
     * 接下来的就是线程自己run）
     * 在sleep（）的时候，其他线程准备闯入执行，
     * 首先是其他线程请求获取锁，然后发现没有unlock，于是被阻塞。借着其他的Thread请求，但是都在lock的地方被阻塞。
     * 接下来就T这个拥有锁的Thread（Thread[Thread-6,5,main]）开始执行，知道unlock。
     * 但是这个程序并没有unlock，所以一直都会处于Thread[Thread-6,5,main]这个线程中。
     *
     * 输出的片段：
     * Thread[Thread-6,5,main]:Try to get lock...
     * Thread[Thread-8,5,main]:Try to get lock...
     * 31
     * Thread[Thread-1,5,main]:Try to get lock...
     * Thread[Thread-2,5,main]:Try to get lock...
     * Thread[Thread-0,5,main]:Try to get lock...
     * Thread[Thread-7,5,main]:Try to get lock...
     * Thread[Thread-5,5,main]:Try to get lock...
     * Thread[Thread-9,5,main]:Try to get lock...
     * Thread[Thread-4,5,main]:Try to get lock...
     * Thread[Thread-3,5,main]:Try to get lock...
     * 31
     * Thread[Thread-6,5,main]:loop done...
     * 27
     * 27
     * Thread[Thread-6,5,main]:loop done...
     * 23
     * 23
     * Thread[Thread-6,5,main]:loop done...
     * 5
     * 5
     * Thread[Thread-6,5,main]:loop done...
     * 25
     */
    public void lockOneConcurrencyTest() {
        for (int i = 0; i < 10; i++) {
            Runnable r = () -> {
                try {
                    var cur = Thread.currentThread();
                    System.out.println(cur + ":Try to get lock...");
                    lock.lock();
                    while (true) {
                        int num = (int) (100 * Math.random());
                        System.out.println(num);
                        Thread.sleep(1000);
                        System.out.println(num);
                        System.out.println(cur + ":loop done...");
                    }
                } catch (InterruptedException e) {

                }
                finally {
                    lock.unlock();
                    System.out.println("Free lock...");
                }
            };
            Thread t = new Thread(r);
            t.start();
        }
    }

    /**
     * 确保每一次while都能够被完整的执行而不被打断。
     *
     * 每一个程序在请求锁的时候，如果它持有，那么就会先调用持有的那段代码，执行完之后，才会执行本段申请锁的之后的代码。
     * 也就是持有计数(hold count)机制，可重入机制（reentrant）。
     *
     * 可以从输出看出，在Got lock之前会有线程执行Try to get lock...
     * 也就是只有lock()到unlock()区间的代码被保护。
     * 在其他线程即将执行这一段代码(lock()和unlock()之间的代码)的时候，
     * 就会被阻塞，直到前一个调用lock的那一段执行完之后这一段才会被执行。
     *
     * 输出：
     *
     * C:\ForProgram\jdk-10.0.2\bin\java.exe "-javaagent:C:\ForProgram\JetBrains\IntelliJ IDEA Community Edition 2018.1.1\lib\idea_rt.jar=7209:C:\ForProgram\JetBrains\IntelliJ IDEA Community Edition 2018.1.1\bin" -Dfile.encoding=UTF-8 -classpath C:\Users\WuJing\Desktop\Learn\Java\ReviewJava\Blobs\out\production\Blobs com.company.ConcurrencyDemo
     * Thread[Thread-2,5,main]:Try to get lock...
     * Thread[Thread-9,5,main]:Try to get lock...
     * Thread[Thread-8,5,main]:Try to get lock...
     * Thread[Thread-6,5,main]:Try to get lock...
     * Thread[Thread-8,5,main]:Got lock...
     * Thread[Thread-4,5,main]:Try to get lock...
     * Thread[Thread-3,5,main]:Try to get lock...
     * Thread[Thread-1,5,main]:Try to get lock...
     * Thread[Thread-5,5,main]:Try to get lock...
     * 7
     * Thread[Thread-0,5,main]:Try to get lock...
     * Thread[Thread-7,5,main]:Try to get lock...
     * 7
     * Thread[Thread-8,5,main]:loop done...
     * Thread[Thread-6,5,main]:Got lock...
     * Free lock...
     * 45
     * Thread[Thread-8,5,main]:Try to get lock...
     * 45
     * Thread[Thread-6,5,main]:loop done...
     * Free lock...
     * Thread[Thread-6,5,main]:Try to get lock...
     * Thread[Thread-9,5,main]:Got lock...
     * 58
     * 58
     * Thread[Thread-9,5,main]:loop done...
     * Free lock...
     * Thread[Thread-9,5,main]:Try to get lock...
     * Thread[Thread-4,5,main]:Got lock...
     * 13
     * 13
     * Thread[Thread-4,5,main]:loop done...
     * Free lock...
     * Thread[Thread-4,5,main]:Try to get lock...
     * Thread[Thread-4,5,main]:Got lock...
     * 99
     * 99
     * Thread[Thread-4,5,main]:loop done...
     * Free lock...
     * Thread[Thread-4,5,main]:Try to get lock...
     * Thread[Thread-3,5,main]:Got lock...
     * 11
     * 11
     * Thread[Thread-3,5,main]:loop done...
     * Free lock...
     * Thread[Thread-3,5,main]:Try to get lock...
     * Thread[Thread-2,5,main]:Got lock...
     * 72
     * 72
     * Thread[Thread-2,5,main]:loop done...
     * Free lock...
     * Thread[Thread-1,5,main]:Got lock...
     * Thread[Thread-2,5,main]:Try to get lock...
     * 12
     * 12
     * Thread[Thread-1,5,main]:loop done...
     * Free lock...
     * Thread[Thread-1,5,main]:Try to get lock...
     * Thread[Thread-5,5,main]:Got lock...
     * 68
     * 68
     * Thread[Thread-5,5,main]:loop done...
     * Thread[Thread-0,5,main]:Got lock...
     * 38
     * Free lock...
     * Thread[Thread-5,5,main]:Try to get lock...
     * 38
     * Thread[Thread-0,5,main]:loop done...
     * Free lock...
     * Thread[Thread-0,5,main]:Try to get lock...
     * Thread[Thread-0,5,main]:Got lock...
     * 2
     * 2
     * Thread[Thread-0,5,main]:loop done...
     * Free lock...
     * Thread[Thread-0,5,main]:Try to get lock...
     * Thread[Thread-7,5,main]:Got lock...
     * 8
     * 8
     * Thread[Thread-7,5,main]:loop done...
     * Free lock...
     * Thread[Thread-8,5,main]:Got lock...
     * Thread[Thread-7,5,main]:Try to get lock...
     * 24
     * 24
     * Thread[Thread-8,5,main]:loop done...
     * Free lock...
     * Thread[Thread-6,5,main]:Got lock...
     * 9
     * Thread[Thread-8,5,main]:Try to get lock...
     *
     * Process finished with exit code -1
     *
     */
    public void lockConcurrencyTest() {
        for (int i = 0; i < 10; i++) {
            Runnable r = () -> {
                while (true) {
                    try {
                        var cur = Thread.currentThread();
                        System.out.println(cur + ":Try to get lock...");
                        lock.lock();
                        System.out.println(cur + ":Got lock...");
                        int num = (int) (100 * Math.random());
                        System.out.println(num);
                        Thread.sleep(1000);
                        System.out.println(num);
                        System.out.println(cur + ":loop done...");
                    } catch (InterruptedException e) {

                    }
                    finally {
                        lock.unlock();
                        System.out.println("Free lock...");
                    }
                }
            };
            Thread t = new Thread(r);
            t.start();
        }
    }

    /**
     * 这是关于条件对象的demo。
     * 可能会出现deadlock的问题。
     *
     * 放弃锁，被阻塞
     * 但是被signalAll的时候，得到重新竞争资格，会重新被锁保护（锁可用），然后得到lock，然后unlock
     * 并且从await的地方开始启动
     * while(!(ok to proceed)){
     *     enough.await();
     * }
     *
     *
     * 这个signalAll通知所有await中的thread，
     * 他们继续竞争，竞争之后，如果是await的，从await的地方继续执行。
     * (这儿是一个while循环，会继续判断，是执行，还是继续await，再次被阻塞)
     * enough.signalAll();
     *
     * outputs:
     * C:\ForProgram\jdk-10.0.2\bin\java.exe "-javaagent:C:\ForProgram\JetBrains\IntelliJ IDEA Community Edition 2018.1.1\lib\idea_rt.jar=10219:C:\ForProgram\JetBrains\IntelliJ IDEA Community Edition 2018.1.1\bin" -Dfile.encoding=UTF-8 -classpath C:\Users\WuJing\Desktop\Learn\Java\ReviewJava\Blobs\out\production\Blobs com.company.ConcurrencyDemo
     * Thread[Thread-3,5,main]:Try to get lock...
     * Thread[Thread-0,5,main]:Try to get lock...
     * Thread[Thread-8,5,main]:Try to get lock...
     * Thread[Thread-2,5,main]:Try to get lock...
     * Thread[Thread-3,5,main]:Got lock...
     * Thread[Thread-5,5,main]:Try to get lock...
     * Thread[Thread-7,5,main]:Try to get lock...
     * Thread[Thread-4,5,main]:Try to get lock...
     * Thread[Thread-1,5,main]:Try to get lock...
     * Thread[Thread-9,5,main]:Try to get lock...
     * Thread[Thread-6,5,main]:Try to get lock...
     * Thread[Thread-3,5,main]:45 < 50, await and plus 5.
     * Thread[Thread-0,5,main]:Got lock...
     * Thread[Thread-0,5,main]: wake up...
     * 96
     * 96
     * Thread[Thread-0,5,main]:loop done...
     * Thread[Thread-2,5,main]:Got lock...
     * Thread[Thread-2,5,main]:37 < 50, await and plus 5.
     * Thread[Thread-5,5,main]:Got lock...
     * Thread[Thread-5,5,main]: wake up...
     * 73
     * Free lock...
     * Thread[Thread-0,5,main]:Try to get lock...
     * 73
     * Thread[Thread-5,5,main]:loop done...
     * Free lock...
     * Thread[Thread-7,5,main]:Got lock...
     * Thread[Thread-7,5,main]: wake up...
     * 79
     * Thread[Thread-5,5,main]:Try to get lock...
     * 79
     * Thread[Thread-7,5,main]:loop done...
     * Free lock...
     * Thread[Thread-7,5,main]:Try to get lock...
     * Thread[Thread-4,5,main]:Got lock...
     * Thread[Thread-4,5,main]:20 < 50, await and plus 5.
     * Thread[Thread-1,5,main]:Got lock...
     * Thread[Thread-1,5,main]:44 < 50, await and plus 5.
     * Thread[Thread-9,5,main]:Got lock...
     * Thread[Thread-9,5,main]:42 < 50, await and plus 5.
     * Thread[Thread-6,5,main]:Got lock...
     * Thread[Thread-6,5,main]:29 < 50, await and plus 5.
     * Thread[Thread-8,5,main]:Got lock...
     * Thread[Thread-8,5,main]: wake up...
     * 74
     * 74
     * Thread[Thread-8,5,main]:loop done...
     * Free lock...
     * Thread[Thread-8,5,main]:Try to get lock...
     * Thread[Thread-8,5,main]:Got lock...
     * Thread[Thread-8,5,main]: wake up...
     * 88
     * 88
     * Thread[Thread-8,5,main]:loop done...
     * Free lock...
     * Thread[Thread-8,5,main]:Try to get lock...
     * Thread[Thread-8,5,main]:Got lock...
     * Thread[Thread-8,5,main]:11 < 50, await and plus 5.
     * Thread[Thread-3,5,main]: wake up...
     * 50
     * 50
     * Thread[Thread-3,5,main]:loop done...
     * Free lock...
     * Thread[Thread-3,5,main]:Try to get lock...
     * Thread[Thread-0,5,main]:Got lock...
     * Thread[Thread-0,5,main]: wake up...
     * 74
     * 74
     * Thread[Thread-0,5,main]:loop done...
     * Free lock...
     * Thread[Thread-0,5,main]:Try to get lock...
     * Thread[Thread-0,5,main]:Got lock...
     * Thread[Thread-0,5,main]: wake up...
     * 56
     * 56
     * Thread[Thread-0,5,main]:loop done...
     * Free lock...
     * Thread[Thread-0,5,main]:Try to get lock...
     * Thread[Thread-2,5,main]:42 < 50, await and plus 5.
     * Thread[Thread-5,5,main]:Got lock...
     * Thread[Thread-5,5,main]: wake up...
     * 83
     * 83
     * Thread[Thread-5,5,main]:loop done...
     * Free lock...
     * Thread[Thread-5,5,main]:Try to get lock...
     * Thread[Thread-7,5,main]:Got lock...
     * Thread[Thread-7,5,main]: wake up...
     * 72
     * 72
     * Thread[Thread-7,5,main]:loop done...
     * Free lock...
     *
     * Process finished with exit code -1
     */
    public void conditionLockConcurrencyTest() {
        for (int i = 0; i < 10; i++) {
            Runnable r = () -> {
                while (true) {
                    try {
                        var cur = Thread.currentThread();
                        System.out.println(cur + ":Try to get lock...");
                        lock.lock();
                        System.out.println(cur + ":Got lock...");
                        int num = (int) (100 * Math.random());
                        while (num < 50) {
                            System.out.println(cur + ":" + num + " < 50, await and plus 5.");
                            num += 5;
                            cond.await();
                        }
                        System.out.println(cur + ": wake up...");
                        System.out.println(num);
                        Thread.sleep(1000);
                        System.out.println(num);
                        System.out.println(cur + ":loop done...");
                        cond.signalAll();
                    } catch (InterruptedException e) {

                    }
                    finally {
                        lock.unlock();
                        System.out.println("Free lock...");
                    }
                }
            };
            Thread t = new Thread(r);
            t.start();
        }
    }

    public static void main(String[] args) {
        ConcurrencyDemo c = new ConcurrencyDemo();
        c.conditionLockConcurrencyTest();
    }
}
