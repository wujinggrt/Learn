package unsynch;

import java.util.*;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Bank {

    private final double[] accounts;

    public Bank(int n, double initialBalance) {
        this.accounts = new double[n];
        Arrays.fill(accounts, initialBalance);
    }

    public synchronized void transfer(int from, int to, double amount) throws InterruptedException {
        if (accounts[from] < amount) {
            return;
        }
        while (accounts[from] < amount) {
            wait();
        }
        System.out.print(Thread.currentThread());
        accounts[from] -= amount;
        System.out.printf(" %10.2f from %d to %d", amount, from, to);
        accounts[to] += amount;
        System.out.printf(" Total balance: %10.2f%n", getTotalBalance());
        notifyAll();
    }

//    public void transfer(int from, int to, double amount) {
//        bankLock.lock();
//        try {
//            if (accounts[from] < amount) {
//                return;
//            }
//            while (accounts[from] < amount) {
//                sufficentFunds.await();
//            }
//            System.out.print(Thread.currentThread());
//            accounts[from] -= amount;
//            System.out.printf(" %10.2f from %d to %d", amount, from, to);
//            accounts[to] += amount;
//            System.out.printf(" Total balance: %10.2f%n", getTotalBalance());
//            sufficentFunds.signalAll();
//        } catch (InterruptedException e) {
//            e.printStackTrace();
//        } finally {
//            bankLock.unlock();
//        }
//    }

    public synchronized double getTotalBalance() {
        double sum = 0;
        for (double a :
                accounts) {
            sum += a;
        }
        return sum;
    }

    public int size() {
        return accounts.length;
    }
}
