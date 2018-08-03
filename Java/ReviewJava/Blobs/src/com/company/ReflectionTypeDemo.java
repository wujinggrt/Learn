package com.company;

import java.lang.reflect.Modifier;
import java.util.Iterator;

public class ReflectionTypeDemo {
    private Iterator<String> h = new Hehe();

    public static void main(String[] args) {
        var c = Double.class;
        var fields = c.getFields();

        System.out.println(fields[0].getDeclaringClass());

        for (var e :
                fields) {
            System.out.println(Modifier.toString(e.getModifiers()) + " " + e.getType().toString() + " " + e.getName());
            System.out.println(e.toString());
        }

        for (var e :
                c.getDeclaredMethods()) {
            System.out.println(e);
        }

        var cl = Hehe.class;
        var superCl = cl.getSuperclass();
        if (superCl != null) {
            System.out.println(superCl);
        }
        for (var e :
                cl.getInterfaces()) {
            System.out.println(e.getClass());
        }
        var temp = new ReflectionTypeDemo();
        var cc = temp.getClass();
        var ccFields = cc.getDeclaredFields();
        System.out.println("is interface?");
        for (var e :
                ccFields) {
            var m = e.getModifiers();
            System.out.println(Modifier.isInterface(m));
        }
    }
}

class Hehe implements Iterator<String>, Haha {
    @Override
    public void remove() {

    }

    @Override
    public String sayHello(String name) {
        return new String("Hello" + name);
    }

    @Override
    public boolean hasNext() {
        return false;
    }

    @Override
    public String next() {
        return null;
    }
}

interface Haha {
    String sayHello(String name);
}
