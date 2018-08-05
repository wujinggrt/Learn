package com.company;

public class ConcurrencyDemo {
    public static void main(String[] args) {
        for (int i = 0; i < 100; i++) {
            Runnable r = () ->
            {
                try {
                    while (true) {
                        int num = (int) (100 * Math.random());
                        System.out.println(num);
                        Thread.sleep(1000);
                        System.out.println(num);
                    }
                } catch (InterruptedException e) {

                }
            };
            Thread t = new Thread(r);
            t.start();
        }
    }
}
