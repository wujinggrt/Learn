package generic;

public class ArrayAlg {
    public static <T> T getMiddle(T... a) {
        return a[a.length / 2];
    }

    public static void main(String[] args) {
        @SuppressWarnings ("unchecked")
        String middle = ArrayAlg.<String>getMiddle("Wu", "Zhang", "Wang");
        System.out.println(middle);
    }
}