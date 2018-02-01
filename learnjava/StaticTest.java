package learnjava;

/**
* This demonstrate static variable,
* and some class Employee.
* @version 1.0 2017-11-13
* @author WuJing GRT
*/
public class StaticTest
{
	public static void main(String[] args)
	{

	}
}

class Employee
{
	private static int nextId = 1;

	private String name;
	private double salary;
	private int id;

	public Employee(String name, double salary)
	{
		this.name = name;
		this.salary = salary;
		id = 0;
	}

	public String getName() { return name; }

	public double getSalary() { return salary; }

	public int getId() { return id; }

	public void setId() { id = nextId++; }

	public static void main(String[] args)
	{
		Employee e = new Employee("Harry", 50000);
		System.out.println(e.getName() + " " + e.getSalary());
	}
}