public class StringHashTest {
    public static void main(String[] args) {
        String s = "Ok";
        StringBuilder builder = new StringBuilder(s);
        System.out.println(s.hashCode() + " " + builder.hashCode()); // 2556 366712642
        String t = "Ok";
        StringBuilder builderT  = new StringBuilder(t);
        System.out.println(t.hashCode() + " " + builderT.hashCode()); // 2556 1829164700
    }
}