package interfaces;

import java.util.*;

public class EmployeeSortTest {
        public static void main(String[] args) {
            Employee[] staff = new Employee[3];

            staff[0] = new Employee("haru Hacker", 10000);
            staff[1] = new Employee("Zhangsan", 50000);
            staff[2] = new Employee("Lisi", 3000);

            Arrays.sort(staff);

            for (Employee e : staff) {
                System.out.println("name=" + e.getName() + ",salary=" + e.getSalary());
            }
            // name=Lisi,salary=3000.0
            // name=haru Hacker,salary=10000.0
            // name=Zhangsan,salary=50000.0
        }
}