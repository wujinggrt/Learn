package generic;

import java.util.*;
import java.time.*;

import basemethod.Employee;

public class GenericArrayTest {
    public static void main(String[] args) {
        ArrayList<Employee> staff = new ArrayList<>();
        staff.ensureCapacity(100);
        staff.add(new Employee("ZhangSan", 10000, 2018, 01, 01));
        staff.add(new Employee("LiSi", 20000, 2000, 02, 07));
        System.out.println(staff.size()); // 2
        staff.trimToSize();
        System.out.println(staff.size()); // 2
        Employee harry = new Employee("Wu", 10000000, 2018, 02, 07);
        staff.set(0, harry);
        for(Employee e : staff) {
            System.out.println(e);
        }
        // basemethod.Employee[name=Wu,salary=1.0E7,hireDay=2018-02-07]
        // basemethod.Employee[name=LiSi,salary=20000.0,hireDay=2000-02-07]
        Employee[] all = new Employee[staff.size()];
        staff.toArray(all);
        System.out.println(all.length);
        staff.add(0, new Employee("Huang", 10000, 2000, 01, 01));
        for(Employee e : staff) {
            System.out.println(e);
        }
        // basemethod.Employee[name=Huang,salary=10000.0,hireDay=2000-01-01]
        // basemethod.Employee[name=Wu,salary=1.0E7,hireDay=2018-02-07]
        // basemethod.Employee[name=LiSi,salary=20000.0,hireDay=2000-02-07]
    }
}