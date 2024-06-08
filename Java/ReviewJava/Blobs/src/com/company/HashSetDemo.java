package com.company;

import java.util.HashSet;
import java.util.Set;

public class HashSetDemo {
    public static void main(String[] args) {
        Set<String> words = new HashSet<>();
        words.add("C");
        words.add("B");
        words.add("A");
        /* output
        A
        B
        C
        */
        for (var e :
                words) {
            System.out.println(e);
        }
    }
}
