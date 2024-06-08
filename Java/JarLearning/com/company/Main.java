package com.company;

import java.util.ArrayList;

public class Main {

    private String  s = "adsd";

    public void func() {
        System.out.println("func in main.");
    }

    public static void main(String[] args) {
        //	 write your code here
        String greeting = "Hello";
        System.out.println(greeting);
        System.out.println(greeting.substring(0, 3));
        System.out.println(greeting + greeting.substring(0, 3));
        var temp = String.join(" / ", "H", "e", ";", "o");
        System.out.println(temp);
        System.out.println(greeting.length());
        var cpCount = greeting.codePointCount(0, greeting.length() - 1);
        System.out.println("codepoint:" + cpCount);
        var i = greeting.charAt(4);
        System.out.println("charat:" + i);
        var index = greeting.offsetByCodePoints(1, 3);
        System.out.println("index:" + index);
        var cp = greeting.codePointAt(index);
        System.out.println("cp:" + cp);
        var codePoints = greeting.codePoints().toArray();
        for (var e :
                codePoints) {
            System.out.println(e);

        }
        var t = new Main() {

            @Override
            public void func() {
                System.out.println("func in temp class");
            }
        };
        t.func();

        var staff = new ArrayList<String>();
        staff.ensureCapacity(20);
        staff.add("haha");
        staff.add("d");
        System.out.println(staff.size());
        staff.set(1, "hd");
        staff.remove(0);
        for (var e :
                staff) {
            System.out.printf(e + " ");
        }

        System.out.println(Integer.compare(1, 2));
        Character c = 'c';
        System.out.println(c + "adssad");
    }
}
