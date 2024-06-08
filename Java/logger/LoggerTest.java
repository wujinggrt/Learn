package logger;

import java.util.logging.Logger;

public class LoggerTest {
    public static void main(String[] args) {
        Logger.getGlobal().info("Test: Line5");
        Logger.getGlobal().info("Test: Line6");
        Logger.getGlobal().info("Test: Line7");
        Logger.getGlobal().info("Test: Line8"); 
        System.out.println("Hello");
    }
}