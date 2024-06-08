package com.company;

import java.util.Collection;

public class VarargsDemo {
    public static void main(String[] args) {

    }

    @SuppressWarnings("WeakerAccess")
    public static <T> void addAll(Collection<T> coll, T... ts) {
        for (var t :
                ts) {
            coll.add(t);
        }
    }
}
