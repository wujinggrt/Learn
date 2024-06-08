public class ConcurrencyTest1 {
    public static void main(String[] args) {
        Runnable r = () -> {
            try {
                for (int i = 0; i < 5; i++) {
                    System.out.println(i + " running!");
                    Thread.sleep((int) Math.random() * 10);
                }
            } catch (InterruptedException e) {
                    e.printStackTrace();
            }
        };
        Thread t1 = new Thread(r);
        Thread t2 = new Thread(r);
        t1.start();
        t2.start();
    }
}