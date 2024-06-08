package concurrency;

public class ConcurrencyTest extends Thread {
    private String name;

    public ConcurrencyTest(String name) {
        this.name = name;
    }

    @Override
    public void run() {
        for (int i = 0; i < 10; i++) {
            System.out.println(name + " running:" + i);
            try {
                sleep((int)Math.random() * 10);
            } catch(InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        ConcurrencyTest myThread1 = new ConcurrencyTest("A");
        ConcurrencyTest myThread2 = new ConcurrencyTest("B");
        myThread1.start();
        myThread2.start();
    }
}