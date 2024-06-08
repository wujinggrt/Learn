package com.company;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class MapDemo {
    public static void main(String[] args) {
        Map<String, Integer> m = new HashMap<>();
        m.put("a", 1);
        m.put("B", 2);
        m.put("c", 3);
        m.forEach((k, v) ->
                System.out.println("Key:" + k + ", Value:" + v));

        m.merge("a", 1, (a, b) -> a + b);

        Set<String> keys = m.keySet();
        Collection<Integer> values = m.values();
        Set<Map.Entry<String, Integer>> entrys = m.entrySet();
        System.out.println("keys:");
        for (var e :
                m.keySet()) {
            System.out.println(e);
        }
        System.out.println("values:");
        for (var e :
                m.values()) {
            System.out.println(e);
        }
        System.out.println("keys, values");
        for (var entry :
                m.entrySet()) {
            System.out.println("keys:" + entry.getKey() + ", values:" + entry.getValue());
        }
    }
}
