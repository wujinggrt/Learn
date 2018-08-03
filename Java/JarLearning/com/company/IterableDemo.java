package com.company;

import java.util.Iterator;
import java.util.Spliterator;
import java.util.function.Consumer;

public class IterableDemo {
    public static void main(String[] args) {
        var ms = new MyString("asdhasjkhfjkafas");
        for (var e :
                ms) {
            System.out.println(e);
        }
    }
}

class MyString implements Iterable<String> {

    private int length = 0;
    private String str = null;

    public MyString() {
    }

    public MyString(String s) {
        this.str = s;
        this.length = s.length();
    }


    @Override
    public Iterator<String> iterator() {

        class Itr implements Iterator<String> {

            private int cur = 0;

            @Override
            public void remove() {

            }

            @Override
            public boolean hasNext() {
                return cur != length;
            }

            @Override
            public String next() {
                String ret = str.charAt(cur) + "/";
                cur++;
                return ret;
            }
        }

        return new Itr();
    }
}
