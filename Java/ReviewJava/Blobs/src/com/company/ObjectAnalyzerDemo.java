package com.company;

import java.lang.reflect.AccessibleObject;
import java.lang.reflect.Array;
import java.lang.reflect.Modifier;
import java.util.ArrayList;
import java.util.Arrays;

public class ObjectAnalyzerDemo {
    public static void main(String[] args) {
        ArrayList<String> al = new ArrayList<>();
        al.add("Hello");
        al.add(" ");
        al.add("worlds");
        al.add("!");

        System.out.println(new ObjectAnalyzerDemo().toString(al));
    }

    private ArrayList<Object> visited = new ArrayList<>();

    public String toString(Object obj) {
        if (obj == null) {
            return null;
        }
        // for avoiding duplication?
        if (visited.contains(obj)) {
            return "...";
        }
        visited.add(obj);
        var cl = obj.getClass();
        if (cl == String.class) {
            return (String) obj;
        }

        if (cl.isArray()) {
            String ret = cl.getComponentType() + "[]{";
            for (int i = 0; i < Array.getLength(obj); i++) {
                if (i > 0) {
                    ret += ", ";
                }
                Object val = Array.get(obj, i);
                if (cl.getComponentType().isPrimitive()) {
                    ret += val;
                } else {
                    ret += toString(val);
                }
            }
            return ret + "}";
        }

        String ret = cl.getName();
        do {
            ret += "[";
            var fields = cl.getDeclaredFields();
            AccessibleObject.setAccessible(fields, true);
            for (var f :
                    fields) {
                if (Modifier.isStatic(f.getModifiers())) {
                    if (!ret.endsWith("[")) {
                        ret += ",";
                    }
                    ret += f.getName() + "=";
                    try {
                        var t = f.getType();
                        Object val = f.get(obj);
                        if (t.isPrimitive()) {
                            ret += val;
                        } else {
                            ret += toString(val);
                        }
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
            }
            ret += "]";
            cl = cl.getSuperclass();
        } while (cl != null);

        return ret;
    }
}
