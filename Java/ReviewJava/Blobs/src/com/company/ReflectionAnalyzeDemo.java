package com.company;

import java.lang.reflect.Modifier;

/**
 * @author wujing
 */
public class ReflectionAnalyzeDemo {
    public static void main(String[] args) {
        var o = new ReflectionAnalyzeDemo("java.lang.Double");
        System.out.println(o);

    }

    private String name = null;
    private Class cl = null;
    private Class superCl = null;
    private Class[] interfaceCl = null;

    public ReflectionAnalyzeDemo(Object obj) {
        cl = obj.getClass();
        name = cl.getName();
        superCl = cl.getSuperclass();
        interfaceCl = cl.getInterfaces();
    }

    public ReflectionAnalyzeDemo(String name) {
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
            for (int i = 0; i < interfaceCl.length; i++) {
                builder.append(" " + interfaceCl[i].getName());
                if (i != interfaceCl.length - 1) {
                    builder.append(",");
                }
            }
        }
//        builder.append(" {\n");

        builder.trimToSize();
        return builder.toString();
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
            builder.append("\t");
            String modifiers = Modifier.toString(f.getModifiers());
            if (modifiers.length() > 0) {
                builder.append(modifiers + " ");
            }
            builder.append(f.getType().getName() + " " + f.getName() + ";\n");
        }

        builder.trimToSize();
        return builder.toString();
    }

    /**
     * Anaylize constructor.
     * @return format String.
     */
    public String analyzeConstructors() {
        var builder = new StringBuilder(200);
        var cons = cl.getDeclaredConstructors();
        for (var c :
                cons) {
            builder.append("\t");
            String modifiers = Modifier.toString(c.getModifiers());
            if (modifiers.length() > 0) {
                builder.append(modifiers + " ");
            }
            builder.append(c.getName() + "(");
            var params = c.getParameterTypes();
            for (int i = 0; i < params.length; i++) {
                builder.append(params[i].getName());
                if (i != params.length - 1) {
                    builder.append(", ");
                }
            }
            builder.append(")");
            var exc = c.getExceptionTypes();
            if (exc.length > 0) {
                builder.append(" throws ");
                for (int i = 0; i < exc.length; i++) {
                    builder.append(exc[i].getName());
                    if (i != exc.length - 1) {
                        builder.append(", ");
                    }
                }
            }
            builder.append(";\n");
        }
        builder.trimToSize();

        return builder.toString();
    }

    public String analyzeMethods() {
        var builder = new StringBuilder(200);
        var methods = cl.getDeclaredMethods();
        for (var m :
                methods) {
            builder.append("\t");
            String modifiers = Modifier.toString(m.getModifiers());
            if (modifiers.length() > 0) {
                builder.append(modifiers + " ");
            }
            builder.append(
                    m.getReturnType().getName() +
                    " " +
                    m.getName() +
                    "("
            );
            var params = m.getParameterTypes();
            for (int i = 0; i < params.length; i++) {
                builder.append(params[i].getName());
                if (i != params.length - 1) {
                    builder.append(", ");
                }
            }
            builder.append(")");
            var exc = m.getExceptionTypes();
            if (exc.length > 0) {
                builder.append(" throws ");
                for (int i = 0; i < exc.length; i++) {
                    builder.append(exc[i].getName());
                    if (i != exc.length - 1) {
                        builder.append(", ");
                    }
                }
            }
            builder.append(";\n");
        }

        builder.trimToSize();
        return builder.toString();
    }

    /**
     * Set format output.
     * @return String
     */
    public String toString() {
        var head = analyzeClassName();
        var fields = analyzeFields();
        var cons = analyzeConstructors();
        var methods = analyzeMethods();

        String ret = head + " {\n";
        ret += fields + "\n";
        ret += cons + "\n";
        ret += methods + "\n";
        ret += "}";

        return ret;
    }
}
