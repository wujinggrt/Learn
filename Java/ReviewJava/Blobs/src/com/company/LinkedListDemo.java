package com.company;

import java.util.LinkedList;

public class LinkedListDemo {
    public static void main(String[] args) {
        var l = new LinkedList<String>();
        l.add("Hello");
        l.add(" ");
        l.add("world!");
        for (var e :
                l) {
            System.out.println(e);
        }
        var it = l.iterator();
        var s1 = it.next();
        var s2 = it.next();
        it.remove();
        it.next();
        for (var e :
                l) {
            System.out.println(e);
        }
        System.out.println("hashCode:" + l.hashCode());
    }
}
