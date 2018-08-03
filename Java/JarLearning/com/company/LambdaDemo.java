package com.company;

import javax.swing.*;
import java.awt.event.ActionListener;
import java.util.Arrays;
import java.util.Date;

public class LambdaDemo {
    public static void main(String[] args) {
        String[] planets = new String[] { "Mercury" , "Venus", "Earth" , "Mars" ,
                "Jupiter" , "Saturn", "Uranus", "Neptune" };
        System.out.println(Arrays.toString(planets));
        System.out.println("sorted versiong:");
        Arrays.sort(planets);
        System.out.println(Arrays.toString(planets));
        System.out.println("sort by length:");
        Arrays.sort(planets, (first, second) -> first.length() - second.length());
        System.out.println(Arrays.toString(planets));
        var i = 1;
        System.out.println(i = 2);
        /*
        Timer t = new Timer(1000, event->
                System.out.println("Time is " + new Date()));
        t.start();
        JOptionPane.showMessageDialog(null, "Quit");
        System.exit(0);*/
    }
}
