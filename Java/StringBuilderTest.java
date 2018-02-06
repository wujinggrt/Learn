public class StringBuilderTest {
    public static void main(String[] args) {
        StringBuilder  builder = new StringBuilder();
        builder.append("Hello ");
        String str = builder.toString();
        System.out.println(str); // Hello 
        builder.append("world!"); // Hwujingello world!
        builder.insert(1, "wujing"); // Hwngello world!
        String str2 = builder.toString();
        System.out.println(str2);
        builder.delete(2, 5);
        String str3 = builder.toString();
        System.out.println(str3);
    }
}