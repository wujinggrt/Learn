package com.company;

import java.util.Scanner;

public class IODemo {

    public static void main(String[] args) {
        var in = new Scanner(System.in);
        var name = in.next();
        var i = in.nextInt();
        var h = in.hasNext();
        System.out.println(name);
        System.out.println(i);
        System.out.println(h);
    }
}
