package interfaces;

public class RunnableTest {
    public static void main(String[] args) {
        repeat(10, () -> System.out.println("Hello World!"));
        // Hello World! 10 times
    }

    public static void repeat(int n, Runnable action) {
        for (int i = 0; i < n; ++i) {
            action.run();
        }
    }
}