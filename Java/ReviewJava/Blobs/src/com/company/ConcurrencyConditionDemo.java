package com.company;

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 * 学习《Java核心技术 卷一》并发章节，同步内容。
 * 关于ReentrantLock以及Condition的使用。
 */
public class ConcurrencyConditionDemo {
    private Lock lock = new ReentrantLock();
    private Condition cond = null;

    public ConcurrencyConditionDemo() {
        cond = lock.newCondition();
    }

    /**
     * 这个demo是关于条件对象。
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

    public static void main(String[] args) {

    }
}
