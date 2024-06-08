package com.company;

import java.util.Scanner;

public class NextDemo {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = null;
        while (in.hasNext()) {
            s = in.next();
            System.out.println(s);
        }
    }
}
