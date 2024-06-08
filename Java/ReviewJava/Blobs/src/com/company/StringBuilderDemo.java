package com.company;

import java.util.Arrays;

/**
 * A {@code StringBuilderDemo}
 */
public class StringBuilderDemo {

    public static void main(String[] args) {
        var builder = new StringBuilder();
        builder.append(1234567);
        builder.append(" ds ");
        builder.append("dasdasd");
        System.out.println(builder.charAt(builder.length() - 1));
        var s = builder.toString();
        System.out.println(s);
        builder.replace(3, 5, "replace_str");
        var s2 = builder.toString();
        System.out.println(s2);

        int[] a = {1, 2, 3, 4};
        var cp = Arrays.copyOf(a, a.length);
        System.out.println("cp:");
        System.out.println(cp);
    }
}
