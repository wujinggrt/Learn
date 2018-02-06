package basemethod;

public class Main {
    public static void main(String[] args) {
        Employee e = new Employee("zhangsan", 10000, 2018, 1, 01); // basemethod.Employee[name=zhangsan,salary=10000.0,hireDay=2018-01-01]
        System.out.println(e);
        System.out.println(e.hashCode()); // 1279189012
    }
}