package com.company;

import java.lang.reflect.Modifier;

/**
 * @author wujing
 */
public class ObjectAnalyzer {
    public static void main(String[] args) {
        var o = new ObjectAnalyzer("java.lang.Double");
        System.out.println(o.analyzeFields());
    }

    private String name = null;
    private Class cl = null;
    private Class superCl = null;
    private Class[] interfaceCl = null;

    public ObjectAnalyzer(Object obj) {
        cl = obj.getClass();
        name = cl.getName();
        superCl = cl.getSuperclass();
        interfaceCl = cl.getInterfaces();
    }

    public ObjectAnalyzer(String name) {
        this.name = name;
        try {
            cl = Class.forName(name);
            superCl = cl.getSuperclass();
            interfaceCl = cl.getInterfaces();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    /**
     * Analyze class name, superclass and interfaces implemented.
     * @return String type.
     */
    public String analyzeClassName() {
        StringBuilder builder = new StringBuilder(100);
        String modifiers = Modifier.toString(cl.getModifiers());
        if (modifiers.length() > 0) {
            builder.append(modifiers + " ");
        }
        builder.append("class " + name);
        if (superCl != null && superCl != Object.class) {
            builder.append(" extends " + superCl.getName());
        }
        if (interfaceCl.length != 0) {
            builder.append(" implements");
            for (var itf :
                    interfaceCl) {
                builder.append(" " + itf.getName() + ",");
            }
            builder.deleteCharAt(builder.length() - 1);
        }
        builder.append(" {\n");
        String ret = builder.toString();
        return ret;
    }

    /**
     * Analyze fields.
     * @return format String
     */
    public String analyzeFields() {
        StringBuilder builder = new StringBuilder(200);
        var fields = cl.getDeclaredFields();
        for (var f :
                fields) {
            String modifiers = Modifier.toString(f.getModifiers());
            if (modifiers.length() > 0) {
                builder.append(modifiers + " ");
            }
            builder.append(f.getType().getName() + " " + f.getName() + ";\n");
        }
        String ret = builder.toString();
        return ret;
    }

    /**
     * Anaylize constructor.
     * @return format String.
     */
    public String analyzeConstructor() {
        
    }
}
