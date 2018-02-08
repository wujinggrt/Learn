import java.util.*;
/**
  To read data from console.
 */
public class ConsoleInputTest {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        while(in.hasNext()) {
            String word = in.next();
            System.out.println(word);
        }
    }
}