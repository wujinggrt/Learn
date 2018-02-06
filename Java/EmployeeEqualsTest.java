import java.time.*;
import java.util.*;

public class EmployeeEqualsTest {
    private String name;
    private double salary;
    private LocalDate hireDay;

    public EmployeeEqualsTest(String name, double salary, int year, int month, int day) {
        this.name = name;
        this.salary = salary;
        hireDay = LocalDate.of(year, month, day);
    }

    public boolean equals(Object otherObject) {
        if (this == otherObject) {
            return true;
        }

        if (otherObject == null) {
            return false;
        }

        if (getClass() != otherObject.getClass()) {
            return false;
        }

        EmployeeEqualsTest other = (EmployeeEqualsTest) otherObject;

        /*
        return name.equals(other.name)
            && salary == other.salary
            && hireDay.equals(other.hireDay);
        */

        // 当field为java的内部对象时，可以用Objects.equals(Objects, Objects)
        return Objects.equals(name, other.name)
            && salary == other.salary
            && Objects.equals(hireDay, other.hireDay);
    }

    public static void main(String[] args) {
        EmployeeEqualsTest e = new EmployeeEqualsTest("Haha", 10000, 2018, 01, 1);
        Object o = new Object();
        System.out.println(e.equals(o)); // false
        EmployeeEqualsTest e1 = new EmployeeEqualsTest("Haha", 10000, 2018, 01, 1);
        System.out.println(e.equals(e1)); // true
    }
}